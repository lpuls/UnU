#include "StateMachine.h"

#define STATELOG(var) Toolsets::getInstance()->log(var, "StateMachine");

XpLib::StateMachine::StateMachine(std::string path)
{
	this->_previousState = nullptr;
	this->_stateTable = new StateTable(path);
	this->_current = this->_stateTable->getStarState();
}

XpLib::StateMachine::~StateMachine()
{
	SAFE_DELETE(this->_current);
}

bool XpLib::StateMachine::run(std::vector<std::string> inputList)
{
	int inputLocation = 0;
	std::string item = inputList[inputLocation++];
	int result = StateMachine::NEXT;
	std::function<int(std::string)> next = std::bind(&StateMachine::entry__, this, std::placeholders::_1);
	result = this->entry__(item);
	// 依次读取每一个输入
	do
	{
		// 根据结果变换下一次要进行的动作
		switch (result)
		{
		case StateMachine::ENTRY:  // 执行进入状态动作
			result = this->entry__(item);
			break;
		case StateMachine::QUIT:   // 执行退出状态动作
			result = this->quit__(item);
			break;
		case StateMachine::TRANSITION:  // 状态转移动作
			result = this->transition__(item);
			break;
		case StateMachine::NEXT:  // 读取下一个输入
			// 检测是否超出输入表长度
			if (inputLocation + 1 <= inputList.size())
				item = inputList[inputLocation++];
			else
				inputLocation++;
			// 状态变换为进入
			result = StateMachine::ENTRY;
			break;
		case StateMachine::ERROR:  // 错误状态
			return false;
		default:
			break;
		}
	}while (inputLocation <= inputList.size());
	// 收尾
	this->entry__(item);
	this->transition__(item);
	this->quit__(item);
	

	return true;
}

int XpLib::StateMachine::_entryEvent(std::string input)
{
	return StateMachine::NEXT;
}

int XpLib::StateMachine::_quitEvent(std::string input)
{
	return StateMachine::NEXT;
}

int XpLib::StateMachine::_transitionEvent(std::string input)
{
	return StateMachine::NEXT;
}

int XpLib::StateMachine::entry__(std::string input)
{
	return StateMachine::TRANSITION;
	
}

int XpLib::StateMachine::quit__(std::string input)
{
	// 检测是否为结束状态
	if (0 == this->_current->getTransitionTotal())
	{
		// 调用退出事件
		int result = this->_quitEvent(input);
		this->_current = this->_stateTable->getStarState();
		return result;
	}
	else
	{
		this->_entryEvent(input);
	}
	return StateMachine::NEXT;
}

int XpLib::StateMachine::transition__(std::string input)
{
	// 进行动作转移,若当前输入无结果，则判断为错误输入
	this->_previousState = this->_current;
	this->_current = this->_current->getStateByInput(input);
	// 检测是否是否成功过行
	if (nullptr != this->_current)
	{
		// 调用进入事件
		this->_transitionEvent(input);
		return StateMachine::QUIT;
	}
	else
	{
		return StateMachine::ERROR;
	}
}

