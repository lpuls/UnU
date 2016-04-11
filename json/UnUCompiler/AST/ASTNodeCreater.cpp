#include "ASTValueNode.h"
#include "ASTNodeCreater.h"
#include "ASTIntegerNode.h"
#include "ASTFloatNode.h"
#include "ASTStringNode.h"
#include "ASTTokenNode.h"
#include "ASTAssignNode.h"
#include "ASTOperatorNode.h"

#include "../../Toolsets.h"
#include "../UnUCompile.h"

using namespace UnUCompiler;

ASTNode * UnUCompiler::ASTNodeCreater::create(std::string word, std::string wordValue)
{
	if (AST_INTEGER == wordValue)  // ��������
	{
		auto result = new ASTIntegerNode();
		result->setValue(XpLib::Toolsets::strToInt(word));
		return result;
	}
	else if (AST_FLOAT == wordValue)  // ���ɸ�����
	{
		auto result = new ASTFloatNode();
		result->setValue(XpLib::Toolsets::strToDouble(word));
		return result;
	}
	else if (AST_STRING == wordValue)  // �����ַ���
	{
		auto result = new ASTStringNode();
		word.erase(word.begin());
		word.erase(word.end() - 1);
		result->setValue(word);
		return result;
	}
	else if (AST_TOKEN == wordValue)  // ����Token
	{
		auto result = new ASTTokenNode();
		return result;
	}
	else if (AST_ASSIGN == wordValue)  // ���ɸ�ֵ�ڵ�
	{
		auto result = new ASTAssignNode();
		return result;
	}
	else if (AST_OPERATOR == wordValue)  // ���ɲ������ڵ�
	{
		auto result = new ASTOperatorNode();
		if ("+" == word || "-" == word || "*" == word || "/" == word)
			result->setIsBool(false);
		else
			result->setIsBool(true);
		return result;
	}
	return new ASTNode();
}
