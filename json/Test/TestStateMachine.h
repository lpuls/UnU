/*
* 描述：用来测试自动机
* 作者：xp
* 日期：2016-3-13
*/
#ifndef __TEST_STATE_MACHINE__
#define __TEST_STATE_MACHINE__

#include <iostream>

#include "../FiniteState/StateMachine.h"


namespace TestMoudle
{
	class TestStateMachine : public XpLib::StateMachine
	{
	public:
		TestStateMachine(std::string path);
		~TestStateMachine();

	private:
	protected:
		int _entryEvent(std::string input);
		int _quitEvent(std::string input);
		int _transitionEvent(std::string input);

	};
}

#endif
