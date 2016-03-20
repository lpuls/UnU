#include <functional>
#include <fstream>
#include <iostream>

#include "Toolsets.h"
#include "TypeConversion\TypeConversion.h"

#include "FiniteState\StateTable.h"
#include "FiniteState\StateMachine.h"

#include "UnUCompiler\Lex\Lex.h"
#include "UnUCompiler\Lex\KeyWordsTable.h"

#include "json\json.h"

#include "Test\TestStateMachine.h"

using namespace TestMoudle;
using namespace XpLib;
using namespace UnUCompiler;

#define MAINLOG(var) Toolsets::getInstance()->log(var, "Main");


int main()
{
	Toolsets::getInstance()->addSwitch("Main");
	Toolsets::getInstance()->addSwitch("StateMachine");
	Toolsets::getInstance()->addSwitch("KeyWordsTable");
	Toolsets::getInstance()->addSwitch("LEX");

	StateTable stateTable("Jsons/action.json");
	auto state = stateTable["action1"];
	MAINLOG(state->getStateByInput("C")->getState());
	MAINLOG(state->getStateByInput("A")->getState());
	MAINLOG(state->getStateByInput("B")->getState());
	for (int i = 0; i < 10; i++)
	{
		MAINLOG(state->getStateByInput(Toolsets::intToStr(i))->getState());
	}


	system("pause");
	return 0;
}