/*
* 描述：UnU编译中所需要的一些数据
* 作者：xp
* 日期：2016-3-7
*/
#ifndef __UNU_COMPILE__
#define __UNU_COMPILE__

#include <string>

namespace UnUCompiler
{
	// 通用数据
	const std::string JsonPath = "Jsons";
	const std::string ERROR = "error";

	// Lex的数据
	const std::string keyWordPath = JsonPath + "/KeyWordTable.json";
	const std::string LexPath = JsonPath + "/Lex.json";

	// AST的数值类型
	const std::string AST_INTEGER = "integer";
	const std::string AST_FLOAT = "float";
	const std::string AST_STRING = "string";
	const std::string AST_TOKEN = "token";
	const std::string AST_EXP = "exp";
	const std::string AST_OPERATOR = "operator";
	const std::string AST_ASSIGN = "assign";
	const std::string AST_BODY = "body";
	const std::string AST_IF = "if";
	const std::string AST_LOOP = "loop";

	// 语义分析时返回的结果
	const std::string PowerTablePath = JsonPath + "/PowerTable.json";
	const int SUCCESS = -1;
	const int TYPE_ERROR = 1;  // 类型错误
	const int NULL_CHILD = 2;  // 空的检测分支
	const int UNKNOW_BOOL = 3;  // 未知的布尔表达式

	
}

#endif
