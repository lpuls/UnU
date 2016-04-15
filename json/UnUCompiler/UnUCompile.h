/*
* ������UnU����������Ҫ��һЩ����
* ���ߣ�xp
* ���ڣ�2016-3-7
*/
#ifndef __UNU_COMPILE__
#define __UNU_COMPILE__

#include <string>

namespace UnUCompiler
{

#define CreateASTNode(type, value, nodeType) dynamic_cast<type>(ASTNodeCreater::create(value, nodeType))
#define Transtion(type, node) dynamic_cast<type>(node)

	// ͨ������
	const std::string JsonPath = "Jsons";
	const std::string ERROR = "error";

	// Lex������
	const std::string keyWordPath = JsonPath + "/KeyWordTable.json";
	const std::string LexPath = JsonPath + "/Lex.json";

	// AST����ֵ����
	const std::string AST_INTEGER = "integer";
	const std::string AST_FLOAT = "float";
	const std::string AST_STRING = "string";
	const std::string AST_TOKEN = "token";
	const std::string AST_EXP = "exp";
	const std::string AST_BOOL_OPERATOR = "bool_operator";
	const std::string AST_VALUE_OPERATOR = "value_operator";
	const std::string AST_ASSIGN = "assign";
	const std::string AST_BODY = "zone_right";
	const std::string AST_STAND = "zone_left";
	const std::string AST_IF = "IF";
	const std::string AST_LOOP = "WHILE";
	const std::string AST_FUNCTION = "FUHTION";
	const std::string AST_PARAMS = "spearated";

	// �������ʱ���صĽ��
	const std::string PowerTablePath = JsonPath + "/PowerTable.json";
	const int SUCCESS = -1;
	const int TYPE_ERROR = 1;  // ���ʹ���
	const int NULL_CHILD = 2;  // �յļ���֧
	const int UNKNOW_BOOL = 3;  // δ֪�Ĳ������ʽ

	
}

#endif
