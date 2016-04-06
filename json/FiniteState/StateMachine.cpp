#include "StateMachine.h"

#define STATELOG(var) Toolsets::getInstance()->log(var, "StateMachine");

int XpLib::StateMachine::entry__()
{
	// STATELOG(this->_current->getState())
	return this->CONTINUE;
}

int XpLib::StateMachine::quit__()
{
	// STATELOG(this->_current->getState())
	return this->CONTINUE;
}

int XpLib::StateMachine::transition__()
{
	// 检测是否有正确的输入值
	if ("" == this->_input)
		return this->TRANSITION_NULL_INPUT;
	// 进行转移
	this->_previousState = this->_current;
	auto next = this->_current->getStateByInput(this->_input);
	if (nullptr != next)
	{			 
		this->_current = next;
		STATELOG("当前状态：" + this->_previousState->getState() + " ---" + this->_input + "---> 下一状态：" + this->_current->getState());
		return this->TRANSITION_NORMAL;
	}
	return this->TRANSITION_ERROR;
}

int XpLib::StateMachine::input_()
{
	// 检测输入列表是否为空
	if (nullptr == this->_inputList)
		return this->INPUT_NULL;
	// 检测是否在输入列表读取范围内
	if (this->_location >= 0 && this->_location < this->_inputList->size())
	{
		this->_input = this->_inputList->at(this->_location);
		this->_location += 1;
		// 检测是否读取完成，若读取完成则跳结束自动机
		if (this->_location == this->_inputList->size())
			return this->INPUT_OVER;
		return this->INPUT_NORMAL;
	}
	// 读取位置超出可读取长度
	return StateMachine::INPUT_OVERFLOW;
}

XpLib::StateMachine::StateMachine(std::string path)
{
	this->_previousState = nullptr;
	this->_stateTable = new StateTable(path);
	this->_current = this->_stateTable->getStarState();
	this->_inputList = nullptr;
	this->_input = "";
	this->_location = 0;
}

XpLib::StateMachine::~StateMachine()
{
	SAFE_DELETE(this->_current);
}

int XpLib::StateMachine::run()
{
	bool isContinue = true;
	int result = -1;
	while (isContinue)
	{
		// 进入动作
		result = this->entry__();
		if (this->CONTINUE != result)
			return result;
		// 输入状态
		result = this->input_();  
		if (this->INPUT_OVER == result)
		{
			isContinue = false;
		}
		else if (this->INPUT_NORMAL != result)
		{
			STATELOG("Transition Error Code : " + Toolsets::intToStr(result));
			return result;
		}
		// 转移动作
		result = this->transition__();
		if (this->TRANSITION_NORMAL != result)
		{
			STATELOG("Input Error Code : " + Toolsets::intToStr(result));
			return result;
		}
		// 退出动作
		result = this->quit__();
		if (this->CONTINUE != result)
			return result;
		// STATELOG("----------------------");
	}
	return -1;
}

