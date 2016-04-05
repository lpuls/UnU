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

using namespace XpLib;
using namespace UnUCompiler;

#define MAINLOG(var) Toolsets::getInstance()->log(var, "Main");


int main()
{
	Toolsets::getInstance()->addSwitch("Main");
	Toolsets::getInstance()->addSwitch("StateMachine");
	Toolsets::getInstance()->addSwitch("KeyWordsTable");
	Toolsets::getInstance()->addSwitch("LEX");

	std::vector<std::string> inputList;
	std::string code = "i = 10086 + 123456 / 1.234 * 852;";
	for (auto item : code)
	{
		inputList.push_back(Toolsets::charToStr(item));
	}
	inputList.push_back(" ");


	Lex sm("Jsons/Lex.json");
	sm.setInputList(&inputList);
	sm.run();
	MAINLOG(sm.getCurrent()->getState());

	system("pause");
	return 0;
}