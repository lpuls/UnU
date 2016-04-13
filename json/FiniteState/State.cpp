#include "State.h"

using namespace XpLib;

std::map<std::string, std::vector<State*>> State::__stateBelong;

State::State()
{
}

State::State(std::string stateName, std::string belong)
{
	this->__state = stateName;
	this->__belong = belong;
	State::__stateBelong[belong].push_back(this);
}

State::~State()
{
}

State * XpLib::State::create(std::string stateName, std::string belong)
{
	// 检查是否存在状态表，若无则创建，并测加
	auto stateTable = State::__stateBelong.find(belong);
	if (State::__stateBelong.end() == stateTable)
		State::__stateBelong[belong] = std::vector<State*>();
	// 检测列表中是否存在该状态名
	auto stateList = State::__stateBelong[belong];
	for (auto item : stateList)
		if (stateName == item->getState())
			return item;
	// 若未当前状态表中未存在该状态，则创建一个新的状态
	State *state = new State(stateName, belong);
	return state;
}

State * XpLib::State::getStateByBelongAndName(std::string state, std::string belong)
{
	auto transitionTable = State::__stateBelong.find(belong);
	// 检测是否存在该表
	if (State::__stateBelong.end() != transitionTable)
	{
		// 寻找是否存在该状态
		auto transitionTableList = State::__stateBelong[belong];
		for (auto item : transitionTableList)
		{
			if (item->getState() == state)
			{
				return item;
			}
		}
	}
	return nullptr;
}

bool XpLib::State::addState(std::string input, State * state)
{
	auto transition = this->__transition.find(input);
	// 检测该输入转移是否存在
	if (this->__transition.end() == transition)
	{
		this->__transition[input] = state;
		return true;
	}
	return false;
}

State * XpLib::State::getStateByInput(std::string input)
{
	auto transition = this->__transition.find(input);
	if (this->__transition.end() != transition)
	{
		return this->__transition[input];
	}
	return nullptr;
}

int XpLib::State::getTransitionTotal()
{
	return this->__transition.size();
}
