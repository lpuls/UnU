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
#include "../AST/ASTOutputNode.h"
#include "../AST/ASTInputNode.h"

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

ASTNode * UnUCompiler::Semantic::analysis(WordIterator wordIterator, unsigned int start, unsigned int end)
{
	// �����нڵ�����ΪAST�﷨���ڵ�
	for (int i = start; i < end; i++)
	{
		// ��ֵ��ջ
		if (PowerTable::getPowerByKey(wordIterator.get(i).getWordValue()) < 0)
		{
			this->pushNodeIntoValueStack__(wordIterator.get(i));
		}
		else
		{
			if (0 == this->__operatorStack.size()  // �Ƚ���ջ���ڵ��Ȩֵ��Ȩֵ���������
				|| PowerTable::getPowerByKey(wordIterator.get(i).getWordValue()) > PowerTable::getPowerByKey(this->__operatorStack.top()->getValueType()))
			{
				// �½ڵ��ջ���ڵ�Ȩֵ��,��ջ
				this->pushNodeIntoOperatorStack__(wordIterator.get(i));
			}
			else  // �µĵ�ڲ���ջ���ڵ�Ȩֵ�󣬶�ջ���ڵ���й�Լ
			{
				if (Semantic::CONTINUE != this->reduction(wordIterator.get(i)))
					return nullptr;
				// ����ڵ㣬��{}����ǰ��������Ӧ�Ľڵ�
				if ("{" == wordIterator.get(i).getWord())
				{
					this->__operatorStack.pop();
					int endLocation = 0;
					std::stack<std::string> brackets;
					// �ҳ������ڵ�����
					for (endLocation = i; endLocation < end; endLocation++)
					{
						// ��������ջ��������ƥ��
						if ("{" == wordIterator.get(endLocation).getWord())
						{
							brackets.push("{");
						}
						else if ("}" == wordIterator.get(endLocation).getWord())
						{
							brackets.pop();
							// ��ƥ������ų�ջ֮�󣬼��ջ�Ƿ�Ϊ�գ����ǣ����ҵ���Ŀ��λ��
							if (brackets.empty())
								break;
						}
					}
					// �Դ���ν��з���
					Semantic se;
					auto codes = se.analysis(wordIterator, i + 1, endLocation);
					this->__valueStack.push(codes);
					// ��֮ǰ�����ݽ��й�Լ
					this->reduction(Word("over", "token"));
					this->__operatorStack.pop();
					i = endLocation;
				}
			}
		}
	}
	// ��β,�ȼ���Ƿ������в�������ʹ�ù��ˣ��ٽ����ɵ�����ֵѹ�������������
	if (!this->__operatorStack.empty())
	{
		// �ղ�ʱ��ѹ��һ����С��ֵ
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
	// if ("{" != word.getWord())
	// {
		auto value = CreateASTNode(ASTNode*, word.getWord(), word.getWordValue());
		if (value)
		{
			this->__operatorStack.push(value);
		}
	// }
	// �����������Ҫ�����⴦���ڷ���ջ����ӱ��
	// if ("}" == word.getWord() || "{" == word.getWord())
	// {
	//	this->__valueStack.push(CreateASTNode(ASTStandNode*, "stand", AST_STAND));
	// }
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

	// �������нڵ㣬
	item = this->__operatorStack.top();
	type = item->getValueType();
	// ���ƽṹ�ڵ�
	if (AST_IF == type || AST_LOOP == type)
	{
		// ���ɿ��ƽṹ
		auto expNode = Transtion(ASTStructNode*, item);
		auto rightNode = Transtion(ASTBodyNode*, this->__valueStack.top()); this->__valueStack.pop();
		auto leftNode = Transtion(ASTExpNode*, this->__valueStack.top()); this->__valueStack.pop();
		expNode->setLeft(leftNode);
		expNode->setRight(rightNode);
		this->__valueStack.push(expNode);
	}
	else if (AST_VALUE_OPERATOR == type || AST_BOOL_OPERATOR == type)  // ����ڵ�
	{
		auto expNode = Transtion(ASTOperatorNode*, item);
		// ��ֵ�����У�����+ - * /֮������ȼ�
		auto expPower = PowerTable::getPowerByKey(expNode->getOperator());
		auto wordPower = PowerTable::getPowerByKey(word.getWord());
		if (AST_VALUE_OPERATOR == type && expPower < wordPower)
			return Semantic::SKIP;
		// ������������й�Լ
		auto rightNode = Transtion(ASTExpNode*, this->__valueStack.top()); this->__valueStack.pop();
		auto leftNode = Transtion(ASTExpNode*, this->__valueStack.top()); this->__valueStack.pop();
		expNode->setLeft(leftNode);
		expNode->setRight(rightNode);
		// ���ܼ������������
		auto result = this->calculation(expNode);
		if (result)
		{
			this->__valueStack.push(result);
			SAFE_DELETE(expNode);
		}
		else { this->__valueStack.push(expNode); }
	}
	else if (AST_OUTPUT == type)  // ����ڵ�
	{
		auto expNode = Transtion(ASTOutputNode*, item);
		// ������Ҫ�����Ϊ���ʽ
		auto outExp = Transtion(ASTExpNode*, this->__valueStack.top()); this->__valueStack.pop();
		expNode->setOutContent(outExp);
		// ���ýڵ���Ϊ�������Ż���ֵջ
		this->__valueStack.push(expNode);
	}
	else if (AST_INPUT == type)
	{
		auto expNode = Transtion(ASTInputNode*, item);
		// ����������Ҫ��Ϊ����
		auto inToken = Transtion(ASTTokenNode*, this->__valueStack.top()); this->__valueStack.pop();
		expNode->setInput(inToken);
		// ���ýڵ���Ϊ�������Ż���ֵջ
		this->__valueStack.push(expNode);
	}
	/*else if (AST_BODY == type)
	{
		this->specialBracket(word);
	}
	else if (AST_STAND == type)
	{
		this->__valueStack.push(CreateASTNode(ASTStandNode*, "stand", AST_STAND));
	}*/
	else if (AST_ASSIGN == type)  // ��ֵ�ڵ�
	{
		auto expNode = Transtion(ASTAssignNode*, item);
		auto rightNode = Transtion(ASTExpNode*, this->__valueStack.top()); this->__valueStack.pop();
		auto leftNode = Transtion(ASTTokenNode*, this->__valueStack.top()); this->__valueStack.pop();
		
		if (AST_INTEGER == rightNode->getValueType())
		{
			leftNode->setRealValue(XpLib::Toolsets::intToStr(Transtion(ASTIntegerNode*, rightNode)->getValue()));
			leftNode->setType(AST_INTEGER);
			this->__valueStack.push(leftNode);
			expNode->setRight(rightNode);
			SAFE_DELETE(expNode);
		}
		else if (AST_FLOAT == rightNode->getValueType())
		{
			leftNode->setRealValue(XpLib::Toolsets::doubleToStr(Transtion(ASTFloatNode*, rightNode)->getValue()));
			leftNode->setType(AST_FLOAT);
			this->__valueStack.push(leftNode);
			expNode->setRight(rightNode);
			SAFE_DELETE(expNode);
		}
		else if (AST_STRING == rightNode->getValueType())
		{
			leftNode->setRealValue(Transtion(ASTStringNode*, rightNode)->getValue());
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
			// ��Ϊһ����ֵ������ѹջ
			this->__valueStack.push(expNode);
		}
	}
	else  // û�ж�Ӧ�ڵ㣬ʧ��
	{
		return Semantic::FAILED;
	}
	// �����������Ҫ�����⴦���ڷ���ջ����ӱ��
	// if ("}" == word.getWord())
	// {
	//	this->__valueStack.push(CreateASTNode(ASTStandNode*, "stand", AST_STAND));
	// }
	return Semantic::CONTINUE;
}

int UnUCompiler::Semantic::reduction(Word word)
{
	SEMLOG("�õ��ڵ�: " + word.getWord() + " ��ʼ���й�Լ");
	int expPower, wordPower, result;
	// ѭ������ֱ��ջ����Ȩֵ�ȵ�ǰ�ʻ�ȨֵС
	while (true)
	{
		result = this->merge(word);
		if (Semantic::CONTINUE == result)
		{
			SEMLOG("���β����ɹ�");
			this->__operatorStack.pop();
			if (this->__operatorStack.size() == 0)
				break;
			expPower = PowerTable::getPowerByKey(this->__operatorStack.top()->getValueType());
			wordPower = PowerTable::getPowerByKey(word.getWord());
			if (-1 == wordPower)
				wordPower = PowerTable::getPowerByKey(word.getWordValue());
			if (wordPower > expPower)
				break;
		}
		else if (Semantic::SKIP == result)
		{
			SEMLOG("���β�������");
			break;
		}
		else
		{
			SEMLOG("���β���ʧ��");
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
	// �ҵ���һ�����
	while (AST_STAND != tempNode->getValueType())
	{
		store.push_back(tempNode);
		this->__valueStack.pop();
		tempNode = this->__valueStack.top();
	}
	this->__valueStack.pop();
	// �ҵ��ڶ������
	tempNode = this->__valueStack.top();
	while (AST_STAND != tempNode->getValueType())
	{
		tempList.push_back(tempNode);
		this->__valueStack.pop();
		tempNode = this->__valueStack.top();
	}
	this->__valueStack.pop();
	// ���ɴ���Σ��������������
	auto body = CreateASTNode(ASTBodyNode*, "body", AST_BODY);
	for (auto item : tempList)
		body->addChild(item);
	// ��Ϊһ����ֵ������ѹջ
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
		if (AST_INTEGER == leftNode->getValueType() && AST_INTEGER == rightNode->getValueType())
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
		else if (AST_FLOAT == leftNode->getValueType() && AST_FLOAT == rightNode->getValueType())
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
		else if (AST_STRING == leftNode->getValueType() && AST_STRING == rightNode->getValueType())
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
