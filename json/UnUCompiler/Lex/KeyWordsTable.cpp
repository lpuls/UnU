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
	// 至少要有一行数据
	if (lines.size() > 0)
	{
		auto jsonStr = lines[0];
		// 编译json文件
		if (reader.parse(jsonStr, root))
		{
			// 读取关键字集，并获取其值
			auto keyList = root["key"];
			auto valueDict = root["value"];
			for (auto item : keyList)
			{
				this->__keyWordTable[item.asString()] = valueDict[item.asString()].asString();
			}
		}
		else
		{
			KWTLOG("错误的json文件");
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
