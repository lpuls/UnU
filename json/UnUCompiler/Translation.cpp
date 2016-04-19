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
	if (AST_ASSIGN == type)  // 赋值节点
	{
		result = Translation::translationToAssign(Transtion(ASTAssignNode*, child));
		if (!result)
			return nullptr;
		// result->print();
	}
	else if (AST_TOKEN == type)  // 变量节点 
	{
		result = Translation::translationToToken(Transtion(ASTTokenNode*, child));
		if (!result)
			return nullptr;
		// result->print();
	}
	else if (AST_OUTPUT == type)  // 输出节点
	{
		UNULOG("OUTPUT");
		result = Translation::translationToOutput(Transtion(ASTOutputNode*, child));
		if (!result)
			std::cout << "NIL" << std::endl;
		else
			result->print();
	}
	else if (AST_INPUT == type)  // 输入节点
	{
		UNULOG("INPUT");
		result = Translation::translationToInput(Transtion(ASTInputNode*, child));
		if (!result)
			return nullptr;
		// result->print();
	}
	else if (AST_VALUE_OPERATOR == type || AST_BOOL_OPERATOR == type
		|| AST_INTEGER == type || AST_FLOAT == type || AST_STRING == type)  // 运算节点及数值节点
	{
		result = Translation::translationToExp(Transtion(ASTExpNode*, child));
		if (!result)
			return nullptr;
		// result->print();
	}
	else if (AST_IF == type)  // 判断结构
	{
		result = Translation::translationToIf(Transtion(ASTStructNode*, child));
		if (!result)
			return nullptr;
		auto runResult = result->run();
		// UNULOG("判断运行结果：" + XpLib::Toolsets::intToStr(runResult));
		if (TRANSLATION_SUCCESS != runResult)
		{
			SAFE_DELETE(result);
		}
	}
	else if (AST_LOOP == type)  // 循环结构
	{
		result = Translation::translationToWhile(Transtion(ASTStructNode*, child));
		if (!result)
			return nullptr;
		auto runResult = result->run();
		// UNULOG("判断运行结果：" + XpLib::Toolsets::intToStr(runResult));
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
		// 创建一个变量，其名称为左值，内容为右值
		result = UnUValueManager::create(tokenName, right);
		// 该变量己经被使用时，对该变量所对的数值进行修改
		if (!result)
		{
			UnUValueManager::replace(tokenName, right);
			result = right;
		}
		// 消除右侧的临时变量
		Translation::recoverTempValue(right, node->getRight());
	}
	return result;
}

UnUBase * UnUCompiler::Translation::translationToToken(ASTTokenNode * node)
{
	UnUBase *result = nullptr;
	// 将变量转化为整数，并与变量名进行关联
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
	// 左右两侧都有值才能计算
	if (leftValue && rightValue)
	{
		auto result = Translation::calculate(leftValue, rightValue, node->getOperator());
		// 若左子数不为变量，则对临时数值进行回收
		Translation::recoverTempValue(leftValue, node->getLeft());
		// 若右子数不为变量，则对临时数值进行回收
		Translation::recoverTempValue(rightValue, node->getRight());
		return result;
	}
	return nullptr;
}

UnUBase * UnUCompiler::Translation::translationToExp(ASTExpNode * node)
{
	std::string type = node->getValueType();
	// 变量
	if (AST_TOKEN == type)
	{
		auto tokenValue = Transtion(ASTTokenNode*, node)->getValue();
		return UnUValueManager::find(tokenValue);
	}
	// 整数
	if (AST_INTEGER == type)
	{
		auto integerValue = Transtion(ASTIntegerNode*, node)->getValue();
		auto temp = UnUInteger::createInteger(integerValue);
		return temp;
	}
	// 浮点数
	if (AST_FLOAT == type)
	{
		auto floatValue = Transtion(ASTFloatNode*, node)->getValue();
		auto temp = UnUFloat::createFloat(floatValue);
		return temp;
	}
	// 字符串
	if (AST_STRING == type)
	{
		auto stringValue = Transtion(ASTStringNode*, node)->getValue();
		auto temp = UnUString::createString(stringValue);
		return temp;
	}
	// 操作符
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
	// 根据输入内容检测要生成什么样的变量
	char inputChar[2048];
	std::cin.getline(inputChar, sizeof(inputChar), '\n');
	std::string inputStr(inputChar);
	// 检测字符串内容
	std::string type = AST_INTEGER; // 1为整数， 2为小数， 3为空符串
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
	// 根据字符串类型
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
	// 同为整数时的计算
	if (UNU_INTEGER == left->getUnUType()->getType() && UNU_INTEGER == right->getUnUType()->getType())
	{
		auto leftValue = Transtion(UnUInteger*, left);
		auto rightValue = Transtion(UnUInteger*, right);
		result = leftValue->calculate(operatorType, rightValue);
	}
	else if (UNU_FLOAT == left->getUnUType()->getType() && UNU_FLOAT == right->getUnUType()->getType())  // 同时为浮点数时的计算
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
	// TODO 之后要完成其它类型的计算

	return result;
}
