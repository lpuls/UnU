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
	auto integer = dynamic_cast<ASTIntegerNode*>(ASTNodeCreater::create("10086", "integer"));
	auto floatNumber = dynamic_cast<ASTFloatNode*>(ASTNodeCreater::create("100.86", "float"));
	auto stringValue = dynamic_cast<ASTStringNode*>(ASTNodeCreater::create("\"This is a test\"", "string"));
	auto token = dynamic_cast<ASTTokenNode*>(ASTNodeCreater::create("a", AST_TOKEN));

	auto assign = dynamic_cast<ASTAssignNode*>(ASTNodeCreater::create("=", AST_ASSIGN));
	assign->setLeft(token);
	

	auto add = dynamic_cast<ASTOperatorNode*>(ASTNodeCreater::create("+", AST_OPERATOR));
	auto add_I = dynamic_cast<ASTOperatorNode*>(ASTNodeCreater::create("+", AST_OPERATOR));
	auto add_II = dynamic_cast<ASTOperatorNode*>(ASTNodeCreater::create("+", AST_OPERATOR));
	add->setLeft(add_I);
	add->setRight(add_II);
	add_I->setLeft(integer);
	add_I->setRight(integer);
	add_II->setLeft(floatNumber);
	add_II->setRight(floatNumber);

	assign->setRight(add_I);
	

	MAINLOG("Type:" + integer->getType() + "\t Value:" + Toolsets::intToStr(integer->getValue()));
	MAINLOG("Type:" + floatNumber->getType() + "\t Value:" + Toolsets::doubleToStr(floatNumber->getValue()));
	MAINLOG("Type:" + stringValue->getType() + "\t Value:" + stringValue->getValue());
	MAINLOG("Type:" + token->getType() + "\t Value:");
	MAINLOG("Check Result : " + Toolsets::intToStr(assign->check()));
	MAINLOG("Check Result : " + Toolsets::intToStr(add->check()));

	SAFE_DELETE(integer);
	SAFE_DELETE(floatNumber);
	SAFE_DELETE(stringValue);
	SAFE_DELETE(token);
	SAFE_DELETE(assign);
	SAFE_DELETE(add);
	SAFE_DELETE(add_I);
	SAFE_DELETE(add_II);

	MAINLOG("\n\n-------------------以下内容是进行语义生成----------------------");

	Toolsets::releaseInstance();

	system("pause");
	return 0;
}