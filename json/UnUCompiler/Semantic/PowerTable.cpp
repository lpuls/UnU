#include "json\json.h"
#include "PowerTable.h"
#include "../UnUCompile.h"
#include "../../Toolsets.h"

using namespace XpLib;
using namespace UnUCompiler;

#define PTLOG(var) Toolsets::getInstance()->log(var, "PowerTable");

std::map<std::string, int> PowerTable::__powerTable;

bool UnUCompiler::PowerTable::init()
{
	if (PowerTable::__powerTable.size() <= 0)
	{
		Json::Reader reader;
		Json::Value root;
		auto line = Toolsets::reader(PowerTablePath);
		if (line.size() > 0)
		{
			auto jsonStr = line[0];
			// ����json�ļ�
			if (reader.parse(jsonStr, root))
			{
				// ��ȡ�ؼ��ּ�������ȡ��ֵ
				auto keyList = root["keys"];
				auto valueDict = root["power"];
				for (auto item : keyList)
				{
					PowerTable::__powerTable[item.asString()] = valueDict[item.asString()].asInt();
				}
				return true;
			}
			else
			{
				PTLOG("Ȩֵ��򿪴���");
			}
		}
	}
	return false;
}

int UnUCompiler::PowerTable::getPowerByKey(std::string key)
{
	auto result = PowerTable::__powerTable.find(key);
	if (result != PowerTable::__powerTable.end())
	{
		return PowerTable::__powerTable[key];
	}
	return PowerTable::ERROR;
}
