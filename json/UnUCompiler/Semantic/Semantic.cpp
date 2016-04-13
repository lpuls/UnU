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
		// ��ֵ��������ֵջ
		if ("token" == word.getWordValue() || "string" == word.getWordValue() || "integer" == word.getWordValue() || "float" == word.getWordValue())
		{
			// �´������
			if (! this->pushNodeIntoValueStack(word))
			{
				SEMLOG("��Ч����ֵ");
				return nullptr;
			}
			SEMLOG("����ֵ��ջ��" + word.getWordValue());
		}
		else  // ����ֵ��Ҫ����ֵջ���в���
		{
			temp = this->__operatorStack.top();
			// ���µĽڵ����ȼ����ڵ��ھɵĽڵ㣬��һֱ��Լ�����ڵ�������Ľڵ�
			// SEMLOG(XpLib::Toolsets::intToStr(PowerTable::getPowerByKey(temp->getValueType())));
			// SEMLOG(XpLib::Toolsets::intToStr(PowerTable::getPowerByKey(word.getWordValue())));
			if (PowerTable::getPowerByKey(temp->getValueType()) <= PowerTable::getPowerByKey(word.getWordValue()))
			{					  
				int timer = 1;
				do
				{
					SEMLOG("���յ���" + word.getWordValue() + " ��ʼ���й�Լ");
					// ���й�Լ
					if (reduction())
					{
						SEMLOG("���" + XpLib::Toolsets::intToStr(timer++) + "�ι�Լ");
						// this->__operatorStack.pop();
						
					}  // end ���й�Լ
					if (this->__operatorStack.size() > 1) { temp = this->__operatorStack.top(); }
					else { break; }
				} while (PowerTable::getPowerByKey(temp->getValueType()) <= PowerTable::getPowerByKey(word.getWordValue()));
				SEMLOG("��Լ����");
				// ��ȥ;}�ͣ��⣬������ѹ��ջ
				if (";" != word.getWord() && "}" != word.getWord() && ")" != word.getWord())
				{
					if (!this->pushNodeIntoOperatoreStack(word))
					{
						SEMLOG("��Ч�Ĳ�����");
						return nullptr;
					}
				}  // end ��ȥ;}�ͣ��⣬������ѹ��ջ
			}
			else  // �ɽڵ�����µĽڵ㣬���½ڵ���ջ
			{
				if (!this->pushNodeIntoOperatoreStack(word))
				{
					SEMLOG("��Ч�Ĳ�����");
					return nullptr;
				}
				SEMLOG("����������ջ��" + word.getWordValue());
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
	// ȡ����ֵ�ڵ�
	auto valueI = this->__valueStack.top();
	this->__valueStack.pop();
	auto valueII = this->__valueStack.top();
	this->__valueStack.pop();

	// ȡ���������ڵ�
	auto operatorNode = this->__operatorStack.top();
	this->__operatorStack.pop();

	SEMLOG("��Լ���ţ�" + operatorNode->getValueType() + "    ��Լֵ��" + valueI->getValueType() + "\t" + valueII->getValueType());

	// ���ݲ��������ͣ����кϲ�
	if (AST_BOOL_OPERATOR == operatorNode->getValueType()	  // �������������ֵ
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
	else if (AST_IF == operatorNode->getValueType() || AST_LOOP == operatorNode->getValueType())  // ѭ���ṹ���жϽṹ
	{
		auto tempNode = Transtion(ASTStructNode*, operatorNode);
		this->__valueStack.push(tempNode);
	}
	else if (AST_BODY == operatorNode->getValueType())  // ���ɴ���ṹ�ڵ�
	{
		auto tempNode = Transtion(ASTBodyNode*, operatorNode);
		this->__valueStack.push(tempNode);
	}
	else if (AST_BODY_END == operatorNode->getValueType())  // �ϲ�����ṹ
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
	// ����ǰ�ڵ㵽Ŀ��ڵ㶼ȡ��
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
	// ȡ�����нڵ㣬�����б���
	while (this->__valueStack.size() > 0)
	{
		temp = this->__valueStack.top();
		this->__valueStack.pop();
		nodeList.push_back(temp);
	}
	// �����ڵ㣬�������ͣ�����
	int position = 0;
	auto mainBody = Transtion(ASTBodyNode*, nodeList[nodeList.size() - 1]);
	std::string nodeType = "";
	while (position < nodeList.size())
	{
		temp = nodeList[position++];
		nodeType = temp->getValueType();
		// ���õ�����ѭ���ṹ�����жϽṹ,��ȡ������жϽṹ������ṹ
		if (AST_IF == nodeType || AST_LOOP == nodeType)
		{
			auto structNode = Transtion(ASTStructNode*, temp);
			// bool���ʽ
			structNode->setLeft(Transtion(ASTOperatorNode*, nodeList[position - 1]));
			// ��������
			structNode->setRight(Transtion(ASTBodyNode*, nodeList[position - 2]));
			// ����ǰ�����Ϊ����ڵ���ӽڵ�
			mainBody->addChild(structNode);
		}
	}
}
