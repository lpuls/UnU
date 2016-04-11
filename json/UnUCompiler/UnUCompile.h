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

	// �������ʱ���صĽ��
	const std::string PowerTablePath = JsonPath + "/PowerTable.json";
	const int SUCCESS = -1;
	const int TYPE_ERROR = 1;

	
}

#endif
