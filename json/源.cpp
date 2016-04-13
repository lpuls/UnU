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
#include "UnUCompiler\AST\ASTFunctionNode.h"

#include "UnUCompiler\Semantic\PowerTable.h"
#include "UnUCompiler\Semantic\Semantic.h"

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
	Toolsets::getInstance()->addSwitch("Semantic");

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

	MAINLOG("\n-------------------���������ǽ��дʷ�������----------------------");
	Lex sm("Jsons/Lex.json");
	sm.setInputList(&inputList);
	if (SUCCESS == sm.run())
	{
		Word temp;
		for (unsigned int i = 0; i < sm.getWordIterator().total(); i++)
		{
			temp = sm.getWordIterator().get(i);
			MAINLOG(temp.getWord() + "\t" + temp.getWordValue());
			wordValueList.push_back(sm.getWordIterator().get(i).getWordValue());
			wordList.push_back(sm.getWordIterator().get(i).getWord());
		}
	}
	else
	{
		MAINLOG("�ʷ�����ʧ�� !!!");
		system("pause");
		return 0;
	}

	MAINLOG("-------------------���������ǽ����﷨����----------------------");
	Parser pr("Jsons/parser.json");
	pr.setInputList(&wordValueList);
	pr.setWordIterator(wordList);
	auto result = pr.run();
	if (-1 == result)
	{
		MAINLOG("Parser Success !!!");
	}
	else
	{
		MAINLOG("�﷨����ʧ�� !!!");
		system("pause");
		return 0;
	}

	MAINLOG("-------------------���������ǽ����������----------------------");
	Semantic se;
	auto mainBody = se.analysis(sm.getWordIterator());
	if (mainBody)
	{
		MAINLOG("��������ɹ� !!!");
	}
	else
	{
		MAINLOG("�������ʧ�� !!!");
		system("pause");
		return 0;
	}


	MAINLOG("-------------------���������ǽ���AST����----------------------");

	MAINLOG("Check Result : " + Toolsets::intToStr(mainBody->check()));
	
	
	SAFE_DELETE(mainBody);


	Toolsets::releaseInstance();

	system("pause");
	return 0;
}