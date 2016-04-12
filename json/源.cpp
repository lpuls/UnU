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
#include "UnUCompiler\AST\ASTValueNode.h"
#include "UnUCompiler\AST\ASTNodeCreater.h"
#include "UnUCompiler\AST\ASTIntegerNode.h"
#include "UnUCompiler\AST\ASTFloatNode.h"
#include "UnUCompiler\AST\ASTStringNode.h"
#include "UnUCompiler\AST\ASTTokenNode.h"
#include "UnUCompiler\AST\ASTAssignNode.h"
#include "UnUCompiler\AST\ASTOperatorNode.h"
#include "UnUCompiler\AST\ASTBodyNode.h"
#include "UnUCompiler\AST\ASTStructNode.h"

#include "UnUCompiler\Semantic\PowerTable.h"

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
	Toolsets::getInstance()->addSwitch("AST");
	Toolsets::getInstance()->addSwitch("PowerTable");

	std::vector<std::string> inputList;
	std::vector<std::string> wordValueList;
	std::vector<std::string> wordList;

	
	auto code = Toolsets::getInstance()->reader("Jsons/unu.unu")[0];
	MAINLOG(code);
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
	auto result = pr.run();
	if (-1 == result)
		MAINLOG("Parser Success !!!");

	MAINLOG("-------------------以下内容是进行AST生成----------------------");
	auto tokenI = CreateASTNode(ASTTokenNode*, "a", AST_TOKEN);
	auto operatorI = CreateASTNode(ASTOperatorNode*, "+", AST_VALUE_OPERATOR);
	auto integerI = CreateASTNode(ASTIntegerNode*, "10", AST_INTEGER);
	operatorI->setLeft(tokenI);
	operatorI->setRight(integerI);
	MAINLOG("Check Result : " + Toolsets::intToStr(operatorI->check()));


	MAINLOG("\n\n-------------------以下内容是进行语义生成----------------------");

	Toolsets::releaseInstance();

	system("pause");
	return 0;
}