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
	// ����Ƿ�����ȷ������ֵ
	if ("" == this->_input)
		return this->TRANSITION_NULL_INPUT;
	// ����ת��
	this->_previousState = this->_current;
	auto next = this->_current->getStateByInput(this->_input);
	if (nullptr != next)
	{			 
		this->_current = next;
		STATELOG("��ǰ״̬��" + this->_previousState->getState() + " ---" + this->_input + "---> ��һ״̬��" + this->_current->getState());
		return this->TRANSITION_NORMAL;
	}
	return this->TRANSITION_ERROR;
}

int XpLib::StateMachine::input_()
{
	// ��������б��Ƿ�Ϊ��
	if (nullptr == this->_inputList)
		return this->INPUT_NULL;
	// ����Ƿ��������б��ȡ��Χ��
	if (this->_location >= 0 && this->_location < this->_inputList->size())
	{
		this->_input = this->_inputList->at(this->_location);
		this->_location += 1;
		// ����Ƿ��ȡ��ɣ�����ȡ������������Զ���
		if (this->_location == this->_inputList->size())
			return this->INPUT_OVER;
		return this->INPUT_NORMAL;
	}
	// ��ȡλ�ó����ɶ�ȡ����
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
		// ���붯��
		result = this->entry__();
		if (this->CONTINUE != result)
			return result;
		// ����״̬
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
		// ת�ƶ���
		result = this->transition__();
		if (this->TRANSITION_NORMAL != result)
		{
			STATELOG("Input Error Code : " + Toolsets::intToStr(result));
			return result;
		}
		// �˳�����
		result = this->quit__();
		if (this->CONTINUE != result)
			return result;
		// STATELOG("----------------------");
	}
	return -1;
}

