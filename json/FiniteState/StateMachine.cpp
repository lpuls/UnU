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
	// ���ζ�ȡÿһ������
	do
	{
		// ���ݽ���任��һ��Ҫ���еĶ���
		switch (result)
		{
		case StateMachine::ENTRY:  // ִ�н���״̬����
			result = this->entry__(item);
			break;
		case StateMachine::QUIT:   // ִ���˳�״̬����
			result = this->quit__(item);
			break;
		case StateMachine::TRANSITION:  // ״̬ת�ƶ���
			result = this->transition__(item);
			break;
		case StateMachine::NEXT:  // ��ȡ��һ������
			// ����Ƿ񳬳��������
			if (inputLocation + 1 <= inputList.size())
				item = inputList[inputLocation++];
			else
				inputLocation++;
			// ״̬�任Ϊ����
			result = StateMachine::ENTRY;
			break;
		case StateMachine::ERROR:  // ����״̬
			return false;
		default:
			break;
		}
	}while (inputLocation <= inputList.size());
	// ��β
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
	// ����Ƿ�Ϊ����״̬
	if (0 == this->_current->getTransitionTotal())
	{
		// �����˳��¼�
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
	// ���ж���ת��,����ǰ�����޽�������ж�Ϊ��������
	this->_previousState = this->_current;
	this->_current = this->_current->getStateByInput(input);
	// ����Ƿ��Ƿ�ɹ�����
	if (nullptr != this->_current)
	{
		// ���ý����¼�
		this->_transitionEvent(input);
		return StateMachine::QUIT;
	}
	else
	{
		return StateMachine::ERROR;
	}
}

