#include "StateTable.h"
#include "../Toolsets.h"
#include "json\json.h"

using namespace XpLib;

XpLib::StateTable::StateTable(std::string tablePath)
{
	State *state = nullptr;
	// ��ȡJson,������json�ļ�ֻ��һ��
	auto lines = Toolsets::reader(tablePath);
	if (lines.size() > 0)
	{
		Json::Reader reader;
		Json::Value value;
		auto jsonStr = lines[0];
		// std::cout << jsonStr << std::endl;
		// ����json�ļ�
		if (reader.parse(jsonStr, value))
		{
			this->__tableName = value["name"].asString();
			// ��ȡ״̬����
			std::vector<std::string> states;
			auto tableContent = value["state"];
			for (auto item : tableContent)
			{
				states.push_back(item.asString());
				state = State::create(item.asString(), this->__tableName);
				this->__stateTable[state->getState()] = state;
			}
			// ������ʼ״̬
			this->__starState = this->__stateTable[value["start"].asString()];
			// ����״̬��ȡÿ��״̬������ת��
			tableContent = value["table"];
			for (auto item : states)
			{
				state = this->__stateTable[item];
				for (auto var : tableContent[item])
				{
					if (TransitionType::One == var[0].asInt())  // ����һ����һ�����Ӧ��һ״̬
					{
						state->addState(var[2].asString(), this->__stateTable[var[1].asString()]);
					}
					else if (TransitionType::Limit == var[0].asInt())  // ���Ͷ��� ��һ״̬��Ӧ�����ͬ������
					{
						// ѭ����ÿ������ȡ����ʹ����״̬��Ӧ
						for (size_t i = 2; i < var.size(); i++)
						{
							state->addState(var[i].asString(), this->__stateTable[var[1].asString()]);
						}
					}
					else if (TransitionType::Continue == var[0].asInt())  // �������� ��һ״̬��Ӧ���������ϵ������
					{
						int start = (int)var[2].asString()[0];
						int end = (int)var[3].asString()[0];
						// ������ϵ������Ҫʹ��ֵΪ����
						for (auto i = start; i <= end; i++)
						{
							state->addState(Toolsets::charToStr(((char)i)), this->__stateTable[var[1].asString()]);
						}
					}
				}
			}
		}
	}
	else  // ������json�ļ�
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
