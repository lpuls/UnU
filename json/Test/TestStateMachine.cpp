#include <string>

#include "TestStateMachine.h"

TestMoudle::TestStateMachine::TestStateMachine(std::string path) : StateMachine(path)
{
}

TestMoudle::TestStateMachine::~TestStateMachine()
{
	StateMachine::~StateMachine();
}

int TestMoudle::TestStateMachine::_entryEvent(std::string input)
{
	std::cout << "Run Entry Input " << input << " " << this->_current->getState() << std::endl;
	return StateMachine::TRANSITION;
}

int TestMoudle::TestStateMachine::_quitEvent(std::string input)
{
	std::cout << "Run Quit Input " << input << " " << this->_current->getState() << std::endl;
	// this->_current = this->getStateTable()->getStarState();
	return StateMachine::ENTRY;
}

int TestMoudle::TestStateMachine::_transitionEvent(std::string input)
{
	std::cout << "Run Transtion Input " << input << " " << this->_current->getState() << std::endl;
	return StateMachine::NEXT;
}

