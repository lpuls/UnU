#include "Translation.h"
#include "AST\ASTTokenNode.h"
#include "AST\ASTIntegerNode.h"
#include "AST\ASTFloatNode.h"
#include "AST\ASTStringNode.h"
#include "AST\ASTNodeCreater.h"

#include "../UnU/UnU.h"
#include "../UnU/UnUIf.h"
#include "../UnU/UnUString.h"
#include "../UnU/UnUFloat.h"
#include "../UnU/UnUInteger.h"
#include "../UnU/UnUWhile.h"
#include "../UnU/UnUValueManager.h"

#include "../../Toolsets.h"

using namespace UnUCompiler;

#define UNULOG(var) XpLib::Toolsets::getInstance()->log(var, "UNU");

int UnUCompiler::Translation::translation(ASTBodyNode * node)
{
	unsigned int location = node->getChildTotal() - 1;
	UnUBase *result = nullptr;
	auto child = node->getChild(location--);
	while (child)
	{
		result = Translation::translation__(child);
		if (!result)
			return UNKOWN_ERROR;
		if (AST_IF == child->getValueType())
			SAFE_DELETE(result);
		child = node->getChild(location--);
	}
	return TRANSLATION_SUCCESS;
}

UnUBase * UnUCompiler::Translation::translation__(ASTNode * child)
{
	UnUBase *result = nullptr;
	std::string type = child->getValueType();
	if (AST_ASSIGN == type)  // ��ֵ�ڵ�
	{
		result = Translation::translationToAssign(Transtion(ASTAssignNode*, child));
		if (!result)
			return nullptr;
		// result->print();
	}
	else if (AST_TOKEN == type)  // �����ڵ� 
	{
		result = Translation::translationToToken(Transtion(ASTTokenNode*, child));
		if (!result)
			return nullptr;
		// result->print();
	}
	else if (AST_OUTPUT == type)  // ����ڵ�
	{
		UNULOG("OUTPUT");
		result = Translation::translationToOutput(Transtion(ASTOutputNode*, child));
		if (!result)
			std::cout << "NIL" << std::endl;
		else
			result->print();
	}
	else if (AST_INPUT == type)  // ����ڵ�
	{
		UNULOG("INPUT");
		result = Translation::translationToInput(Transtion(ASTInputNode*, child));
		if (!result)
			return nullptr;
		// result->print();
	}
	else if (AST_VALUE_OPERATOR == type || AST_BOOL_OPERATOR == type
		|| AST_INTEGER == type || AST_FLOAT == type || AST_STRING == type)  // ����ڵ㼰��ֵ�ڵ�
	{
		result = Translation::translationToExp(Transtion(ASTExpNode*, child));
		if (!result)
			return nullptr;
		// result->print();
	}
	else if (AST_IF == type)  // �жϽṹ
	{
		result = Translation::translationToIf(Transtion(ASTStructNode*, child));
		if (!result)
			return nullptr;
		auto runResult = result->run();
		// UNULOG("�ж����н����" + XpLib::Toolsets::intToStr(runResult));
		if (TRANSLATION_SUCCESS != runResult)
		{
			SAFE_DELETE(result);
		}
	}
	else if (AST_LOOP == type)  // ѭ���ṹ
	{
		result = Translation::translationToWhile(Transtion(ASTStructNode*, child));
		if (!result)
			return nullptr;
		auto runResult = result->run();
		// UNULOG("�ж����н����" + XpLib::Toolsets::intToStr(runResult));
		if (TRANSLATION_SUCCESS != runResult)
		{
			SAFE_DELETE(result);
		}
	}
	return result;
}

UnUBase* UnUCompiler::Translation::translationToAssign(ASTAssignNode * node)
{
	UnUBase* result = nullptr;
	UnUBase *right = nullptr;
	std::string tokenName = "";
	if (node->getLeft())
		tokenName = node->getLeft()->getValue();
	if (node->getRight())
		right = Translation::translationToExp(node->getRight());
	if (right)
	{
		// ����һ��������������Ϊ��ֵ������Ϊ��ֵ
		result = UnUValueManager::create(tokenName, right);
		// �ñ���������ʹ��ʱ���Ըñ������Ե���ֵ�����޸�
		if (!result)
		{
			UnUValueManager::replace(tokenName, right);
			result = right;
		}
		// �����Ҳ����ʱ����
		Translation::recoverTempValue(right, node->getRight());
	}
	return result;
}

UnUBase * UnUCompiler::Translation::translationToToken(ASTTokenNode * node)
{
	UnUBase *result = nullptr;
	// ������ת��Ϊ������������������й���
	if (AST_INTEGER == node->getType())
	{
		auto integerValue = XpLib::Toolsets::strToInt(node->getRealValue());
		auto integerBase = UnUInteger::createInteger(integerValue);
		if (UnUValueManager::find(node->getValue())) 
		{
			UnUValueManager::replace(node->getValue(), integerBase);
			return integerBase;
		}
		else { return UnUValueManager::create(node->getValue(), integerBase); }
	}
	else if (AST_FLOAT == node->getType())
	{
		auto floatValue = XpLib::Toolsets::strToDouble(node->getRealValue());
		auto floatBase = UnUFloat::createFloat(floatValue);
		if (UnUValueManager::find(node->getValue())) 
		{ 
			UnUValueManager::replace(node->getValue(), floatBase);
			return floatBase;
		}
		else { return UnUValueManager::create(node->getValue(), floatBase); }
	}
	else if (AST_STRING == node->getType())
	{
		auto stringValue = node->getRealValue();
		auto stringBase = UnUString::createString(stringValue);
		if (UnUValueManager::find(node->getValue()))
		{
			UnUValueManager::replace(node->getValue(), stringBase); 
			return stringBase;
		}
		else { return UnUValueManager::create(node->getValue(), stringBase); }
	}
	return nullptr;
}

UnUBase * UnUCompiler::Translation::translationToOperator(ASTOperatorNode * node)
{
	UnUBase * leftValue = nullptr;
	UnUBase * rightValue = nullptr;
	if (node->getLeft())
		leftValue = Translation::translationToExp(node->getLeft());
	if (node->getRight())
		rightValue = Translation::translationToExp(node->getRight());
	// �������඼��ֵ���ܼ���
	if (leftValue && rightValue)
	{
		auto result = Translation::calculate(leftValue, rightValue, node->getOperator());
		// ����������Ϊ�����������ʱ��ֵ���л���
		Translation::recoverTempValue(leftValue, node->getLeft());
		// ����������Ϊ�����������ʱ��ֵ���л���
		Translation::recoverTempValue(rightValue, node->getRight());
		return result;
	}
	return nullptr;
}

UnUBase * UnUCompiler::Translation::translationToExp(ASTExpNode * node)
{
	std::string type = node->getValueType();
	// ����
	if (AST_TOKEN == type)
	{
		auto tokenValue = Transtion(ASTTokenNode*, node)->getValue();
		return UnUValueManager::find(tokenValue);
	}
	// ����
	if (AST_INTEGER == type)
	{
		auto integerValue = Transtion(ASTIntegerNode*, node)->getValue();
		auto temp = UnUInteger::createInteger(integerValue);
		return temp;
	}
	// ������
	if (AST_FLOAT == type)
	{
		auto floatValue = Transtion(ASTFloatNode*, node)->getValue();
		auto temp = UnUFloat::createFloat(floatValue);
		return temp;
	}
	// �ַ���
	if (AST_STRING == type)
	{
		auto stringValue = Transtion(ASTStringNode*, node)->getValue();
		auto temp = UnUString::createString(stringValue);
		return temp;
	}
	// ������
	if (AST_VALUE_OPERATOR == type || AST_BOOL_OPERATOR == type)
	{
		auto expValue = Translation::translationToOperator(Transtion(ASTOperatorNode*, node));
		return expValue;
	}
	return nullptr;
}

UnUBase * UnUCompiler::Translation::translationToOutput(ASTOutputNode * node)
{
	if (node) return Translation::translationToExp(node->getOutContent());
	else return nullptr;
}

UnUBase * UnUCompiler::Translation::translationToInput(ASTInputNode * node)
{
	// if (node) { inputToken = Translation::translationToExp(node->getInput()); }
	// �����������ݼ��Ҫ����ʲô���ı���
	char inputChar[2048];
	std::cin.getline(inputChar, sizeof(inputChar), '\n');
	std::string inputStr(inputChar);
	// ����ַ�������
	std::string type = AST_INTEGER; // 1Ϊ������ 2ΪС���� 3Ϊ�շ���
	for (auto item : inputStr)
	{
		if ((item >= '9' || item <= '0') && '.' != item)
		{
			type = AST_STRING;
			break;
		}
		else if ('.' == item)
		{
			if (AST_FLOAT == AST_STRING)
			{
				type = 3;
				break;
			}
			type = AST_FLOAT;
		}
	}
	// �����ַ�������
	auto inputToken = Transtion(ASTTokenNode*, node->getInput());
	inputToken->setType(type);
	inputToken->setRealValue(inputStr);
	UnUBase *result = Translation::translationToToken(node->getInput());
	return result;
}

UnUBase * UnUCompiler::Translation::translationToIf(ASTStructNode * node)
{  
	UnUIf *ifStatements = new UnUIf();
	ifStatements->setCondition(node->getLeft());
	ifStatements->setBody(node->getRight());
	return ifStatements;
}

UnUBase * UnUCompiler::Translation::translationToWhile(ASTStructNode * node)
{
	UnUWhile *whileStatements = new UnUWhile();
	whileStatements->setCondition(node->getLeft());
	whileStatements->setBody(node->getRight());
	return whileStatements;
}

void UnUCompiler::Translation::recoverTempValue(UnUBase * value, ASTNode * node)
{
	if (AST_TOKEN != node->getValueType()
		&& AST_BOOL_OPERATOR != node->getValueType()
		&& AST_VALUE_OPERATOR != node->getValueType())
	{
		value->releaseSelf();
	}
}

UnUBase * UnUCompiler::Translation::calculate(UnUBase * left, UnUBase * right, std::string operatorType)
{
	UnUBase *result = nullptr;
	// ͬΪ����ʱ�ļ���
	if (UNU_INTEGER == left->getUnUType()->getType() && UNU_INTEGER == right->getUnUType()->getType())
	{
		auto leftValue = Transtion(UnUInteger*, left);
		auto rightValue = Transtion(UnUInteger*, right);
		result = leftValue->calculate(operatorType, rightValue);
	}
	else if (UNU_FLOAT == left->getUnUType()->getType() && UNU_FLOAT == right->getUnUType()->getType())  // ͬʱΪ������ʱ�ļ���
	{
		auto leftValue = Transtion(UnUFloat*, left);
		auto rightValue = Transtion(UnUFloat*, right);
		result = leftValue->calculate(operatorType, rightValue);
	}
	else if (UNU_FLOAT == left->getUnUType()->getType() && UNU_INTEGER == right->getUnUType()->getType()
		|| UNU_INTEGER == left->getUnUType()->getType() && UNU_FLOAT == right->getUnUType()->getType())
	{
		UnUFloat *floatInstall = nullptr;
		UnUFloat *integerInstall = nullptr;
		if (UNU_FLOAT == left->getUnUType()->getType() && UNU_INTEGER == right->getUnUType()->getType())
		{
			floatInstall = Transtion(UnUFloat*, left);
			integerInstall = UnUFloat::createFloat(Transtion(UnUInteger*, right)->getValue());
		}
		else
		{
			floatInstall = Transtion(UnUFloat*, right);
			integerInstall = UnUFloat::createFloat(Transtion(UnUInteger*, left)->getValue());
		}
		result = floatInstall->calculate(operatorType, integerInstall);
		integerInstall->releaseSelf();
	}
	else if (UNU_STRING == left->getUnUType()->getType() && UNU_STRING == left->getUnUType()->getType())
	{
		auto leftValue = Transtion(UnUString*, left);
		auto rightValue = Transtion(UnUString*, right);
		result = leftValue->calculate(operatorType, rightValue);
	}
	// TODO ֮��Ҫ����������͵ļ���

	return result;
}
