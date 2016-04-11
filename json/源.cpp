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
	auto integer = dynamic_cast<ASTIntegerNode*>(ASTNodeCreater::create("0", "integer"));
	auto floatNumber = dynamic_cast<ASTFloatNode*>(ASTNodeCreater::create("10.0", "float"));
	auto stringValue = dynamic_cast<ASTStringNode*>(ASTNodeCreater::create("\"This is a test\"", "string"));
	
	auto token = dynamic_cast<ASTTokenNode*>(ASTNodeCreater::create("a", AST_TOKEN));
	auto token2 = dynamic_cast<ASTTokenNode*>(ASTNodeCreater::create("i", AST_TOKEN));

	auto assign = dynamic_cast<ASTAssignNode*>(ASTNodeCreater::create("=", AST_ASSIGN));  // token = token + integer
	auto assign2 = dynamic_cast<ASTAssignNode*>(ASTNodeCreater::create("=", AST_ASSIGN));  // token = integer
	assign->setLeft(token2);
	assign->setRight(floatNumber);
	assign2->setLeft(token);
	assign2->setRight(integer);
	
	// auto add = dynamic_cast<ASTOperatorNode*>(ASTNodeCreater::create("+", AST_OPERATOR));  // token + (float + string)
	auto equit = dynamic_cast<ASTOperatorNode*>(ASTNodeCreater::create("==", AST_OPERATOR));  // a == 0
	equit->setLeft(token);
	equit->setRight(integer);

	auto body = dynamic_cast<ASTBodyNode*>(ASTNodeCreater::create("body", AST_BODY));  // { token = token + integer }
	body->addChild(assign);

	auto ifStruct = dynamic_cast<ASTStructNode*>(ASTNodeCreater::create("if", AST_LOOP)); // if a == 0 { i = 10.0; }
	ifStruct->setLeft(equit);
	ifStruct->setRight(body);
	


	MAINLOG("Type:" + integer->getType() + "\t Value:" + Toolsets::intToStr(integer->getValue()));
	MAINLOG("Type:" + floatNumber->getType() + "\t Value:" + Toolsets::doubleToStr(floatNumber->getValue()));
	MAINLOG("Type:" + stringValue->getType() + "\t Value:" + stringValue->getValue());
	MAINLOG("Type:" + token->getType() + "\t Value:");

	assign2->check();
	// MAINLOG("OPERATOR Check Result : " + Toolsets::intToStr(add->check()));
	// MAINLOG("ASSIGN Check Result : " + Toolsets::intToStr(assign->check()));
	// MAINLOG("BODY Check Result : " + Toolsets::intToStr(body->check()));
	MAINLOG("IF Check Result : " + Toolsets::intToStr(ifStruct->check()));

	MAINLOG("Type:" + integer->getType() + "\t Value:" + Toolsets::intToStr(integer->getValue()));
	MAINLOG("Type:" + floatNumber->getType() + "\t Value:" + Toolsets::doubleToStr(floatNumber->getValue()));
	MAINLOG("Type:" + stringValue->getType() + "\t Value:" + stringValue->getValue());
	MAINLOG("Type:" + token->getType() + "\t Value:");

	SAFE_DELETE(integer);
	SAFE_DELETE(floatNumber);
	SAFE_DELETE(stringValue);
	SAFE_DELETE(token);
	SAFE_DELETE(assign);
	// SAFE_DELETE(add);

	MAINLOG("\n\n-------------------以下内容是进行语义生成----------------------");

	Toolsets::releaseInstance();

	system("pause");
	return 0;
}