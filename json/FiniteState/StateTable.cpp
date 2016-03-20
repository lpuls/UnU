#include "StateTable.h"
#include "../Toolsets.h"
#include "json\json.h"

using namespace XpLib;

XpLib::StateTable::StateTable(std::string tablePath)
{
	State *state = nullptr;
	// 读取Json,理论上json文件只有一行
	auto lines = Toolsets::reader(tablePath);
	if (lines.size() > 0)
	{
		Json::Reader reader;
		Json::Value value;
		auto jsonStr = lines[0];
		// std::cout << jsonStr << std::endl;
		// 编译json文件
		if (reader.parse(jsonStr, value))
		{
			this->__tableName = value["name"].asString();
			// 读取状态集合
			std::vector<std::string> states;
			auto tableContent = value["state"];
			for (auto item : tableContent)
			{
				states.push_back(item.asString());
				state = State::create(item.asString(), this->__tableName);
				this->__stateTable[state->getState()] = state;
			}
			// 设置起始状态
			this->__starState = this->__stateTable[value["start"].asString()];
			// 跟据状态读取每个状态的输入转移
			tableContent = value["table"];
			for (auto item : states)
			{
				state = this->__stateTable[item];
				for (auto var : tableContent[item])
				{
					if (TransitionType::One == var[0].asInt())  // 类型一，单一输入对应单一状态
					{
						state->addState(var[2].asString(), this->__stateTable[var[1].asString()]);
					}
					else if (TransitionType::Limit == var[0].asInt())  // 类型二， 单一状态对应多个不同的输入
					{
						// 循环将每个输入取出并使其与状态对应
						for (size_t i = 2; i < var.size(); i++)
						{
							state->addState(var[i].asString(), this->__stateTable[var[1].asString()]);
						}
					}
					else if (TransitionType::Continue == var[0].asInt())  // 类型三， 单一状态对应多个连续关系的输入
					{
						int start = (int)var[2].asString()[0];
						int end = (int)var[3].asString()[0];
						// 连续关系的输入要使其值为数字
						for (auto i = start; i <= end; i++)
						{
							state->addState(Toolsets::charToStr(((char)i)), this->__stateTable[var[1].asString()]);
						}
					}
				}
			}
		}
	}
	else  // 不存在json文件
	{
		std::cout << "Error Json" << std::endl;
	}
}

XpLib::StateTable::~StateTable()
{
	this->__starState = nullptr;
	for (auto item : this->__stateTable)
	{
		SAFE_DELETE(item.second);
		this->__stateTable[item.first] = nullptr;
	}
}

State * XpLib::StateTable::operator[](std::string stateName)
{
	auto result = this->__stateTable.find(stateName);
	if (this->__stateTable.end() != result)
	{
		return this->__stateTable[stateName];
	}
	return nullptr;
}
