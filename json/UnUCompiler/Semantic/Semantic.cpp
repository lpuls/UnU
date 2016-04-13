#include "Semantic.h"
#include "../../Toolsets.h"
#include "../AST/ASTBodyNode.h"
#include "../AST/ASTValueNode.h"
#include "../AST/ASTNodeCreater.h"
#include "../AST/ASTIntegerNode.h"
#include "../AST/ASTFloatNode.h"
#include "../AST/ASTStringNode.h"
#include "../AST/ASTTokenNode.h"
#include "../AST/ASTAssignNode.h"
#include "../AST/ASTOperatorNode.h"
#include "../AST/ASTBodyNode.h"
#include "../AST/ASTStructNode.h"
#include "../AST/ASTParamNode.h"
#include "../AST/ASTFunctionNode.h"
#include "../AST/ASTNodeCreater.h"

#include "../../Toolsets.h"

using namespace UnUCompiler;


#define SEMLOG(var) XpLib::Toolsets::getInstance()->log(var, "Semantic");

Semantic::Semantic()
{
	PowerTable::init();
}

Semantic::~Semantic()
{
}

ASTNode * UnUCompiler::Semantic::analysis(WordIterator wordIterator)
{
	Word word;
	ASTNode *temp = nullptr;
	auto mainBody = CreateASTNode(ASTBodyNode*, "main", AST_BODY);
	this->__operatorStack.push(mainBody);
	for (int i = 0; i < wordIterator.total(); i++)
	{
		word = wordIterator.get(i);
		// 数值，加入数值栈
		if ("token" == word.getWordValue() || "string" == word.getWordValue() || "integer" == word.getWordValue() || "float" == word.getWordValue())
		{
			// 仿错误机制
			if (! this->pushNodeIntoValueStack(word))
			{
				SEMLOG("无效的数值");
				return nullptr;
			}
			SEMLOG("将数值入栈：" + word.getWordValue());
		}
		else  // 非数值，要进数值栈进行操作
		{
			temp = this->__operatorStack.top();
			// 若新的节点优先级大于等于旧的节点，则一直归约至大于等于自身的节点
			// SEMLOG(XpLib::Toolsets::intToStr(PowerTable::getPowerByKey(temp->getValueType())));
			// SEMLOG(XpLib::Toolsets::intToStr(PowerTable::getPowerByKey(word.getWordValue())));
			if (PowerTable::getPowerByKey(temp->getValueType()) <= PowerTable::getPowerByKey(word.getWordValue()))
			{					  
				int timer = 1;
				do
				{
					SEMLOG("接收到：" + word.getWordValue() + " 开始进行归约");
					// 进行归约
					if (reduction())
					{
						SEMLOG("完成" + XpLib::Toolsets::intToStr(timer++) + "次归约");
						// this->__operatorStack.pop();
						
					}  // end 进行归约
					if (this->__operatorStack.size() > 1) { temp = this->__operatorStack.top(); }
					else { break; }
				} while (PowerTable::getPowerByKey(temp->getValueType()) <= PowerTable::getPowerByKey(word.getWordValue()));
				SEMLOG("归约结束");
				// 除去;}和）外，都重新压入栈
				if (";" != word.getWord() && "}" != word.getWord() && ")" != word.getWord())
				{
					if (!this->pushNodeIntoOperatoreStack(word))
					{
						SEMLOG("无效的操作符");
						return nullptr;
					}
				}  // end 除去;}和）外，都重新压入栈
			}
			else  // 旧节点大于新的节点，则将新节点入栈
			{
				if (!this->pushNodeIntoOperatoreStack(word))
				{
					SEMLOG("无效的操作符");
					return nullptr;
				}
				SEMLOG("将操作符入栈：" + word.getWordValue());
			}
		}
	}
	this->classification();
	return mainBody;
}

bool UnUCompiler::Semantic::pushNodeIntoValueStack(Word word)
{
	auto value = CreateASTNode(ASTNode*, word.getWord(), word.getWordValue());
	if (value)
	{
		this->__valueStack.push(value);
		return true;
	}
	return false;
}

bool UnUCompiler::Semantic::pushNodeIntoOperatoreStack(Word word)
{
	auto value = CreateASTNode(ASTNode*, word.getWord(), word.getWordValue());
	if (value)
	{
		this->__operatorStack.push(value);
		return true;
	}
	return false;
}

bool UnUCompiler::Semantic::reduction()
{
	// 取出数值节点
	auto valueI = this->__valueStack.top();
	this->__valueStack.pop();
	auto valueII = this->__valueStack.top();
	this->__valueStack.pop();

	// 取出操作符节点
	auto operatorNode = this->__operatorStack.top();
	this->__operatorStack.pop();

	SEMLOG("归约符号：" + operatorNode->getValueType() + "    归约值：" + valueI->getValueType() + "\t" + valueII->getValueType());

	// 根据操作符类型，进行合并
	if (AST_BOOL_OPERATOR == operatorNode->getValueType()	  // 处理操作符，赋值
		|| AST_VALUE_OPERATOR == operatorNode->getValueType()
		|| AST_ASSIGN == operatorNode->getValueType())
	{
		auto expI = Transtion(ASTExpNode*, valueI);
		auto expII = Transtion(ASTExpNode*, valueII);
		if (AST_BOOL_OPERATOR == operatorNode->getValueType())
		{
			auto tempNode = Transtion(ASTOperatorNode*, operatorNode);
			tempNode->setLeft(expI);
			tempNode->setRight(expII);
			this->__valueStack.push(tempNode);
		}
		else if (AST_VALUE_OPERATOR == operatorNode->getValueType())
		{
			auto tempNode = Transtion(ASTOperatorNode*, operatorNode); 
			tempNode->setLeft(expI);
			tempNode->setRight(expII);
			this->__valueStack.push(tempNode);
		}
		else if (AST_ASSIGN == operatorNode->getValueType())
		{
			auto tempNode = Transtion(ASTAssignNode*, operatorNode);
			tempNode->setLeft(Transtion(ASTTokenNode*, valueII));
			tempNode->setRight(expI);
			this->__valueStack.push(tempNode);
		}
		else
			return false;
	}
	else if (AST_IF == operatorNode->getValueType() || AST_LOOP == operatorNode->getValueType())  // 循环结构和判断结构
	{
		auto tempNode = Transtion(ASTStructNode*, operatorNode);
		this->__valueStack.push(tempNode);
	}
	else if (AST_BODY == operatorNode->getValueType())  // 生成代码结构节点
	{
		auto tempNode = Transtion(ASTBodyNode*, operatorNode);
		this->__valueStack.push(tempNode);
	}
	else if (AST_BODY_END == operatorNode->getValueType())  // 合并代码结构
	{
		auto nodeList = this->getMergeList(AST_BODY);
		auto bodyNode = Transtion(ASTBodyNode*, nodeList[nodeList.size() - 1]);
		for (int i = nodeList.size() - 1; i >= 0; i--)
		{
			bodyNode->addChild(nodeList[i]);
		}
	}

	return true;
}

std::vector<ASTNode*> UnUCompiler::Semantic::getMergeList(std::string astType)
{
	ASTNode *tempNode = nullptr;
	// 将当前节点到目标节点都取出
	std::vector<ASTNode*> tempList;
	while (true)
	{
		tempNode = this->__valueStack.top();
		tempList.push_back(tempNode);
		if (astType == tempNode->getValueType())
		{																										 
			break;
		}
		else
		{
			this->__valueStack.pop();
		}
	}
	return tempList;
}

void UnUCompiler::Semantic::classification()
{
	ASTNode *temp = nullptr;
	std::vector<ASTNode*> nodeList;
	// 取出所有节点，放入列表中
	while (this->__valueStack.size() > 0)
	{
		temp = this->__valueStack.top();
		this->__valueStack.pop();
		nodeList.push_back(temp);
	}
	// 遍历节点，根据类型，处理
	int position = 0;
	auto mainBody = Transtion(ASTBodyNode*, nodeList[nodeList.size() - 1]);
	std::string nodeType = "";
	while (position < nodeList.size())
	{
		temp = nodeList[position++];
		nodeType = temp->getValueType();
		// 若得到的是循环结构或着判断结构,读取后面的判断结构和主体结构
		if (AST_IF == nodeType || AST_LOOP == nodeType)
		{
			auto structNode = Transtion(ASTStructNode*, temp);
			// bool表达式
			structNode->setLeft(Transtion(ASTOperatorNode*, nodeList[position - 1]));
			// 代码主体
			structNode->setRight(Transtion(ASTBodyNode*, nodeList[position - 2]));
			// 将当前结果设为主体节点的子节点
			mainBody->addChild(structNode);
		}
	}
}
