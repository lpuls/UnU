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
		return result;
	}
	else if (AST_ASSIGN == wordValue)  // 生成赋值节点
	{
		auto result = new ASTAssignNode();
		return result;
	}
	else if (AST_OPERATOR == wordValue)  // 生成操作符节点
	{
		auto result = new ASTOperatorNode();
		if ("+" == word || "-" == word || "*" == word || "/" == word)
			result->setIsBool(false);
		else
			result->setIsBool(true);
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
	return new ASTNode();
}
