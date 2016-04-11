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
	const std::string AST_OPERATOR = "operator";
	const std::string AST_VALUE_OPERATOR = "value_operator";
	const std::string AST_BOOL_OPERATOR = "bool_operator";
	const std::string AST_ASSIGN = "assign";

	// �������ʱ���صĽ��
	const std::string PowerTablePath = JsonPath + "/PowerTable.json";
	const int SUCCESS = -1;
	const int TYPE_ERROR = 1;

	
}

#endif
