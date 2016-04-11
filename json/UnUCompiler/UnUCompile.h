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

	// 语义分析时返回的结果
	const std::string PowerTablePath = JsonPath + "/PowerTable.json";
	const int SUCCESS = -1;
	const int TYPE_ERROR = 1;

	
}

#endif
