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
	// ����Ƿ����״̬�������򴴽��������
	auto stateTable = State::__stateBelong.find(belong);
	if (State::__stateBelong.end() == stateTable)
		State::__stateBelong[belong] = std::vector<State*>();
	// ����б����Ƿ���ڸ�״̬��
	auto stateList = State::__stateBelong[belong];
	for (auto item : stateList)
		if (stateName == item->getState())
			return item;
	// ��δ��ǰ״̬����δ���ڸ�״̬���򴴽�һ���µ�״̬
	State *state = new State(stateName, belong);
	return state;
}

State * XpLib::State::getStateByBelongAndName(std::string state, std::string belong)
{
	auto transitionTable = State::__stateBelong.find(belong);
	// ����Ƿ���ڸñ�
	if (State::__stateBelong.end() != transitionTable)
	{
		// Ѱ���Ƿ���ڸ�״̬
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
	// ��������ת���Ƿ����
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
