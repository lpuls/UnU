#include "ASTValueNode.h"
#include "ASTNodeCreater.h"
#include "ASTIntegerNode.h"
#include "ASTFloatNode.h"
#include "ASTStringNode.h"
#include "ASTTokenNode.h"
#include "ASTAssignNode.h"
#include "ASTOperatorNode.h"
#include "ASTBodyNode.h"
#include "ASTStructNode.h"
#include "ASTParamNode.h"
#include "ASTFunctionNode.h"
#include "ASTStandNode.h"
#include "ASTOutputNode.h"
#include "ASTInputNode.h"

#include "../../Toolsets.h"
#include "../UnUCompile.h"

using namespace UnUCompiler;

ASTNode * UnUCompiler::ASTNodeCreater::create(std::string word, std::string wordValue)
{
	if (AST_INTEGER == wordValue)  // 生成整数
	{
		auto result = new ASTIntegerNode();
		result->setValue(XpLib::Toolsets::strToInt(word));
		return result;
	}
	else if (AST_FLOAT == wordValue)  // 生成浮点数
	{
		auto result = new ASTFloatNode();
		result->setValue(XpLib::Toolsets::strToDouble(word));
		return result;
	}
	else if (AST_STRING == wordValue)  // 生成字符串
	{
		auto result = new ASTStringNode();
		word.erase(word.begin());
		word.erase(word.end() - 1);
		result->setValue(word);
		return result;
	}
	else if (AST_TOKEN == wordValue)  // 生成Token
	{
		auto result = new ASTTokenNode();
		result->setValue(word);
		return result;
	}
	else if (AST_ASSIGN == wordValue)  // 生成赋值节点
	{
		auto result = new ASTAssignNode();
		return result;
	}
	else if (AST_BOOL_OPERATOR == wordValue || AST_VALUE_OPERATOR == wordValue)  // 生成操作符节点
	{
		auto result = new ASTOperatorNode();
		if (AST_VALUE_OPERATOR == wordValue)
		{
			result->setIsBool(false);
		}
		else
		{
			result->setIsBool(true);
		}
		result->setValueType(wordValue);
		result->setOperator(word);
		return result;
	}
	else if (AST_BODY == wordValue)  // 生成结构节点
	{
		auto result = new ASTBodyNode();
		return result;
	}
	else if (AST_IF == wordValue || AST_LOOP == wordValue)  // 生成判断节点 or 生成循环节点
	{
		auto result = new ASTStructNode();
		result->setValueType(wordValue);
		return result;
	}
	else if (AST_PARAMS == wordValue)  // 用来生成参数列表
	{
		auto result = new ASTParamNode();
		return result;
	}
	else if (AST_FUNCTION == wordValue) // 用来生成函数
	{
		auto result = new ASTFunctionNode();
		return result;
	}
	else if (AST_STAND == wordValue)  // 用来生成标记节点
	{
		auto result = new ASTStandNode();
		return result;
	}
	else if (AST_OUTPUT == wordValue)  // 生成输出节点
	{
		auto result = new ASTOutputNode();
		return result;
	}
	else if (AST_INPUT == wordValue)  // 生成输入节点
	{
		auto result = new ASTInputNode();
		return result;
	}
	return nullptr;
}
