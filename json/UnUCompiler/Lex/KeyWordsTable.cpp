#include "json\json.h"
#include "../UnUCompile.h"
#include "KeyWordsTable.h"
#include "../../Toolsets.h"

using namespace XpLib;

#define KWTLOG(var) Toolsets::getInstance()->log(var, "KeyWordsTable");


UnUCompiler::KeyWordsTable::KeyWordsTable(std::string path)
{
	Json::Reader reader;
	Json::Value root;
	auto lines = Toolsets::reader(path);
	// ����Ҫ��һ������
	if (lines.size() > 0)
	{
		auto jsonStr = lines[0];
		// ����json�ļ�
		if (reader.parse(jsonStr, root))
		{
			// ��ȡ�ؼ��ּ�������ȡ��ֵ
			auto keyList = root["key"];
			auto valueDict = root["value"];
			for (auto item : keyList)
			{
				this->__keyWordTable[item.asString()] = valueDict[item.asString()].asString();
			}
		}
		else
		{
			KWTLOG("�����json�ļ�");
		}
	}
}

UnUCompiler::KeyWordsTable::~KeyWordsTable()
{
}

std::string UnUCompiler::KeyWordsTable::at(std::string keyWord)
{
	auto result = this->__keyWordTable.find(keyWord);
	if (this->__keyWordTable.end() != result)
	{
		return this->__keyWordTable[keyWord];

	}
	return UnUCompiler::ERROR;
}
