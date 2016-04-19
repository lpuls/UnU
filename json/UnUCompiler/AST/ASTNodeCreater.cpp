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
		result->setValue(word);
		return result;
	}
	else if (AST_ASSIGN == wordValue)  // ���ɸ�ֵ�ڵ�
	{
		auto result = new ASTAssignNode();
		return result;
	}
	else if (AST_BOOL_OPERATOR == wordValue || AST_VALUE_OPERATOR == wordValue)  // ���ɲ������ڵ�
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
	else if (AST_BODY == wordValue)  // ���ɽṹ�ڵ�
	{
		auto result = new ASTBodyNode();
		return result;
	}
	else if (AST_IF == wordValue || AST_LOOP == wordValue)  // �����жϽڵ� or ����ѭ���ڵ�
	{
		auto result = new ASTStructNode();
		result->setValueType(wordValue);
		return result;
	}
	else if (AST_PARAMS == wordValue)  // �������ɲ����б�
	{
		auto result = new ASTParamNode();
		return result;
	}
	else if (AST_FUNCTION == wordValue) // �������ɺ���
	{
		auto result = new ASTFunctionNode();
		return result;
	}
	else if (AST_STAND == wordValue)  // �������ɱ�ǽڵ�
	{
		auto result = new ASTStandNode();
		return result;
	}
	else if (AST_OUTPUT == wordValue)  // ��������ڵ�
	{
		auto result = new ASTOutputNode();
		return result;
	}
	else if (AST_INPUT == wordValue)  // ��������ڵ�
	{
		auto result = new ASTInputNode();
		return result;
	}
	return nullptr;
}
