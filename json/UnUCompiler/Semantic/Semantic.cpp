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
#include "../AST/ASTStandNode.h"

#include "../../Toolsets.h"

using namespace UnUCompiler;

#define SEMLOG(var) XpLib::Toolsets::getInstance()->log(var, "Semantic");
#define CALCULATION(var, nodeType) return CreateASTNode(ASTNode*, var, nodeType);


Semantic::Semantic()
{
	PowerTable::init();
}

Semantic::~Semantic()
{
}

ASTNode * UnUCompiler::Semantic::analysis(WordIterator wordIterator)
{
	// 将所有节点生成为AST语法树节点
	for (int i = 0; i < wordIterator.total(); i++)
	{
		// 数值入栈
		if (PowerTable::getPowerByKey(wordIterator.get(i).getWordValue()) < 0)
		{
			this->pushNodeIntoValueStack__(wordIterator.get(i));
		}
		else
		{
			// 特殊节点，如{}这种前后必需相对应的节点	
			if (0 == this->__operatorStack.size()  // 比较与栈顶节点的权值，权值大的先运算
				|| PowerTable::getPowerByKey(wordIterator.get(i).getWordValue()) > PowerTable::getPowerByKey(this->__operatorStack.top()->getValueType()))
			{
				// 新节点比栈顶节点权值大,入栈
				this->pushNodeIntoOperatorStack__(wordIterator.get(i));
			}
			else  // 新的点节不比栈顶节点权值大，对栈顶节点进行归约
			{
				if (Semantic::CONTINUE != this->reduction(wordIterator.get(i)))
					return nullptr;
			}
		}
	}
	// 收尾,先检测是否所的有操作符都使用过了，再将生成的所有值压入主函数代码段
	if (!this->__operatorStack.empty())
	{
		// 收层时，压入一个极小的值
		this->reduction(Word("over", "token"));
		this->__operatorStack.pop();
	}
	auto mainBody = CreateASTNode(ASTBodyNode*, "main", AST_BODY);
	while (!this->__valueStack.empty())
	{
		mainBody->addChild(this->__valueStack.top());
		this->__valueStack.pop();
	}
	return mainBody;
}

bool UnUCompiler::Semantic::pushNodeIntoOperatorStack__(Word word)
{
	if ("{" != word.getWord())
	{
		auto value = CreateASTNode(ASTNode*, word.getWord(), word.getWordValue());
		if (value)
		{
			this->__operatorStack.push(value);
		}
	}
	// 括号类操作符要做特殊处理，在符号栈中添加标记
	if ("}" == word.getWord() || "{" == word.getWord())
	{
		this->__valueStack.push(CreateASTNode(ASTStandNode*, "stand", AST_STAND));
	}
	return false;
}

bool UnUCompiler::Semantic::pushNodeIntoValueStack__(Word word)
{
	auto value = CreateASTNode(ASTNode*, word.getWord(), word.getWordValue());
	if (value)
	{
		this->__valueStack.push(value);
		return true;
	}
	return false;
}

int UnUCompiler::Semantic::merge(Word word)
{
	std::string type = "";
	ASTNode *item = nullptr;

	// 遍历所有节点，
	item = this->__operatorStack.top();
	type = item->getValueType();
	// 控制结构节点
	if (AST_IF == type || AST_LOOP == type)
	{
		// 生成控制结构
		auto expNode = Transtion(ASTStructNode*, item);
		auto rightNode = Transtion(ASTBodyNode*, this->__valueStack.top()); this->__valueStack.pop();
		auto leftNode = Transtion(ASTOperatorNode*, this->__valueStack.top()); this->__valueStack.pop();
		expNode->setLeft(leftNode);
		expNode->setRight(rightNode);
		this->__valueStack.push(expNode);
	}
	else if (AST_VALUE_OPERATOR == type || AST_BOOL_OPERATOR == type)
	{
		auto expNode = Transtion(ASTOperatorNode*, item);
		// 数值运算中，考虚+ - * /之间的优先级
		auto expPower = PowerTable::getPowerByKey(expNode->getOperator());
		auto wordPower = PowerTable::getPowerByKey(word.getWord());
		if (AST_VALUE_OPERATOR == type && expPower < wordPower)
			return Semantic::SKIP;
		// 对运算符结点进行归约
		auto rightNode = Transtion(ASTExpNode*, this->__valueStack.top()); this->__valueStack.pop();
		auto leftNode = Transtion(ASTExpNode*, this->__valueStack.top()); this->__valueStack.pop();
		expNode->setLeft(leftNode);
		expNode->setRight(rightNode);
		// 将能计算结果计算出来
		auto result = this->calculation(expNode);
		if (result)
		{
			this->__valueStack.push(result);
			SAFE_DELETE(expNode);
		}
		else { this->__valueStack.push(expNode); }
	}
	else if (AST_BODY == type)
	{
		this->specialBracket(word);
	}
	else if (AST_STAND == type)
	{
		this->__valueStack.push(CreateASTNode(ASTStandNode*, "stand", AST_STAND));
	}
	else if (AST_ASSIGN == type)  // 赋值节点
	{
		auto expNode = Transtion(ASTAssignNode*, item);
		auto rightNode = Transtion(ASTExpNode*, this->__valueStack.top()); this->__valueStack.pop();
		auto leftNode = Transtion(ASTTokenNode*, this->__valueStack.top()); this->__valueStack.pop();
		
		if (AST_INTEGER == rightNode->getValueType())
		{
			leftNode->setValue(XpLib::Toolsets::intToStr(Transtion(ASTIntegerNode*, rightNode)->getValue()));
			leftNode->setType(AST_INTEGER);
			this->__valueStack.push(leftNode);
			expNode->setRight(rightNode);
			SAFE_DELETE(expNode);
		}
		else if (AST_FLOAT == rightNode->getValueType())
		{
			leftNode->setValue(XpLib::Toolsets::doubleToStr(Transtion(ASTFloatNode*, rightNode)->getValue()));
			leftNode->setType(AST_FLOAT);
			this->__valueStack.push(leftNode);
			expNode->setRight(rightNode);
			SAFE_DELETE(expNode);
		}
		else if (AST_STRING == rightNode->getValueType())
		{
			leftNode->setValue(Transtion(ASTStringNode*, rightNode)->getValue());
			leftNode->setType(AST_STRING);
			this->__valueStack.push(leftNode);
			expNode->setRight(rightNode);
			SAFE_DELETE(expNode);
		}
		else if (AST_TOKEN == rightNode->getValueType())
		{
			expNode->setLeft(leftNode);
			this->__valueStack.push(rightNode);
			SAFE_DELETE(expNode);
		}
		else
		{
			expNode->setLeft(leftNode);
			expNode->setRight(rightNode);
			// 做为一个数值，重新压栈
			this->__valueStack.push(expNode);
		}
	}
	else  // 没有对应节点，失败
	{
		return Semantic::FAILED;
	}
	// 括号类操作符要做特殊处理，在符号栈中添加标记
	if ("}" == word.getWord())
	{
		this->__valueStack.push(CreateASTNode(ASTStandNode*, "stand", AST_STAND));
	}
	return Semantic::CONTINUE;
}

int UnUCompiler::Semantic::reduction(Word word)
{
	SEMLOG("得到节点: " + word.getWord() + " 开始进行归约");
	int expPower, wordPower, result;
	// 循环计算直至栈顶的权值比当前词汇权值小
	while (true)
	{
		result = this->merge(word);
		if (Semantic::CONTINUE == result)
		{
			SEMLOG("本次操作成功");
			this->__operatorStack.pop();
			if (this->__operatorStack.size() == 0)
				break;
			expPower = PowerTable::getPowerByKey(this->__operatorStack.top()->getValueType());
			wordPower = PowerTable::getPowerByKey(word.getWord());
			if (wordPower > expPower)
				break;
		}
		else if (Semantic::SKIP == result)
		{
			SEMLOG("本次操作跳过");
			break;
		}
		else
		{
			SEMLOG("本次操作失败");
			return Semantic::FAILED;
		}

	}
	this->pushNodeIntoOperatorStack__(word);
	return Semantic::CONTINUE;
}

void UnUCompiler::Semantic::specialBracket(Word word)
{
	std::vector<ASTNode*> store;
	std::vector<ASTNode*> tempList;
	auto tempNode = this->__valueStack.top();
	// 找到第一个标记
	while (AST_STAND != tempNode->getValueType())
	{
		store.push_back(tempNode);
		this->__valueStack.pop();
		tempNode = this->__valueStack.top();
	}
	this->__valueStack.pop();
	// 找到第二个标记
	tempNode = this->__valueStack.top();
	while (AST_STAND != tempNode->getValueType())
	{
		tempList.push_back(tempNode);
		this->__valueStack.pop();
		tempNode = this->__valueStack.top();
	}
	this->__valueStack.pop();
	// 生成代码段，将代码放入其中
	auto body = CreateASTNode(ASTBodyNode*, "body", AST_BODY);
	for (auto item : tempList)
		body->addChild(item);
	// 做为一个数值，重新压栈
	this->__valueStack.push(body);
	SEMLOG("over");
}

ASTNode * UnUCompiler::Semantic::calculation(ASTNode * node)
{
	auto expNode = Transtion(ASTOperatorNode*, node);
	auto leftNode = expNode->getLeft();
	auto rightNode = expNode->getRight();
	if (SUCCESS == expNode->check() && AST_TOKEN != leftNode->getValueType() && AST_TOKEN != rightNode->getValueType())
	{
		if (AST_INTEGER == leftNode->getValueType())
		{
			int result;
			if ("+" == expNode->getOperator())
			{
				result = Transtion(ASTIntegerNode*, leftNode)->getValue() + Transtion(ASTIntegerNode*, rightNode)->getValue();
			}
			else if ("-" == expNode->getOperator())
			{
				result = Transtion(ASTIntegerNode*, leftNode)->getValue() - Transtion(ASTIntegerNode*, rightNode)->getValue();
			}
			else if ("*" == expNode->getOperator())
			{
				result = Transtion(ASTIntegerNode*, leftNode)->getValue() * Transtion(ASTIntegerNode*, rightNode)->getValue();
			}
			else if ("/" == expNode->getOperator())
			{
				result = Transtion(ASTIntegerNode*, leftNode)->getValue() / Transtion(ASTIntegerNode*, rightNode)->getValue();
			}
			else if ("==" == expNode->getOperator())
			{
				result = Transtion(ASTIntegerNode*, leftNode)->getValue() == Transtion(ASTIntegerNode*, rightNode)->getValue();
			}
			else if (">=" == expNode->getOperator())
			{
				result = Transtion(ASTIntegerNode*, leftNode)->getValue() >= Transtion(ASTIntegerNode*, rightNode)->getValue();
			}
			else if ("<=" == expNode->getOperator())
			{
				result = Transtion(ASTIntegerNode*, leftNode)->getValue() <= Transtion(ASTIntegerNode*, rightNode)->getValue();
			}
			CALCULATION(XpLib::Toolsets::intToStr(result), AST_INTEGER);
		}
		else if (AST_FLOAT == leftNode->getValueType())
		{
			double result;
			if ("+" == expNode->getOperator())
			{
				result = Transtion(ASTFloatNode*, leftNode)->getValue() + Transtion(ASTFloatNode*, rightNode)->getValue();
			}
			else if ("-" == expNode->getOperator())
			{
				result = Transtion(ASTFloatNode*, leftNode)->getValue() - Transtion(ASTFloatNode*, rightNode)->getValue();
			}
			else if ("*" == expNode->getOperator())
			{
				result = Transtion(ASTFloatNode*, leftNode)->getValue() * Transtion(ASTFloatNode*, rightNode)->getValue();
			}
			else if ("/" == expNode->getOperator())
			{
				result = Transtion(ASTFloatNode*, leftNode)->getValue() / Transtion(ASTFloatNode*, rightNode)->getValue();
			}
			else if ("==" == expNode->getOperator())
			{
				result = Transtion(ASTFloatNode*, leftNode)->getValue() == Transtion(ASTFloatNode*, rightNode)->getValue();
			}
			else if (">=" == expNode->getOperator())
			{
				result = Transtion(ASTFloatNode*, leftNode)->getValue() >= Transtion(ASTFloatNode*, rightNode)->getValue();
			}
			else if ("<=" == expNode->getOperator())
			{
				result = Transtion(ASTFloatNode*, leftNode)->getValue() <= Transtion(ASTFloatNode*, rightNode)->getValue();
			}
			CALCULATION(XpLib::Toolsets::doubleToStr(result), AST_FLOAT);
		}
		else if (AST_STRING == leftNode->getValueType())
		{
			std::string result = "\"";
			if ("+" == expNode->getOperator())
			{
				result += Transtion(ASTStringNode*, leftNode)->getValue() + Transtion(ASTStringNode*, rightNode)->getValue();
			}
			else if ("==" == expNode->getOperator())
			{
				result += Transtion(ASTStringNode*, leftNode)->getValue() == Transtion(ASTStringNode*, rightNode)->getValue();
			}
			else if (">=" == expNode->getOperator())
			{
				result += Transtion(ASTStringNode*, leftNode)->getValue() >= Transtion(ASTStringNode*, rightNode)->getValue();
			}
			else if ("<=" == expNode->getOperator())
			{
				result += Transtion(ASTStringNode*, leftNode)->getValue() <= Transtion(ASTStringNode*, rightNode)->getValue();
			}
			result += "\"";
			CALCULATION(result, AST_STRING);
		}
	}
	return nullptr;
}
