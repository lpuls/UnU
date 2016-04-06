#include <functional>
#include <fstream>
#include <iostream>

#include "Toolsets.h"
#include "TypeConversion\TypeConversion.h"

#include "FiniteState\StateTable.h"
#include "FiniteState\StateMachine.h"

#include "UnUCompiler\Lex\Lex.h"
#include "UnUCompiler\Lex\KeyWordsTable.h"
#include "UnUCompiler\Parser\Parser.h"

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
	Toolsets::getInstance()->addSwitch("Parser");

	std::vector<std::string> inputList;
	std::vector<std::string> wordValueList;
	std::vector<std::string> wordList;

	std::string code = "i == 10086";
	for (auto item : code)
	{
		if (' ' != item)
			inputList.push_back(Toolsets::charToStr(item));
		else
			inputList.push_back(" ");
	}
	inputList.push_back(" ");

	MAINLOG("\n-------------------以下内容是进行词法法分析----------------------");
	Lex sm("Jsons/Lex.json");
	sm.setInputList(&inputList);
	sm.run();
	MAINLOG(sm.getCurrent()->getState());
	Word temp;

	for (unsigned int i = 0; i < sm.getWordIterator().total(); i++)
	{
		temp = sm.getWordIterator().get(i);
		MAINLOG(temp.getWord() + "\t" + temp.getWordValue());
		wordValueList.push_back(sm.getWordIterator().get(i).getWordValue());
		wordList.push_back(sm.getWordIterator().get(i).getWord());
	}

	MAINLOG("-------------------以下内容是进行语法分析----------------------");
	Parser pr("Jsons/parser.json");
	pr.setInputList(&wordValueList);
	pr.setWordIterator(wordList);
	pr.run();

	system("pause");
	return 0;
}