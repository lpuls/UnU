#include "Parser.h"
#include "../Lex/WordLterator.h"


#define PARLOG(var) Toolsets::getInstance()->log(var, "Parser");

UnUCompiler::Parser::Parser(std::string path) : StateMachine(path)
{
}

UnUCompiler::Parser::~Parser()
{
	StateMachine::~StateMachine();
}

void UnUCompiler::Parser::setWordIterator(std::vector<std::string> wordIterator)
{
	this->__wordIterator = wordIterator;
}

int UnUCompiler::Parser::run()
{
	// ����֮����õ����Ƿ�Ϊ�ն˽���������϶�Ϊ����
	auto result = StateMachine::run();
	if (StateMachine::SUCCESS == result)
	{
		if (0 == this->_current->getTransitionTotal())
		{
			PARLOG("Success");
			return -1;
		}
		else
		{
			PARLOG("Code Incomplete, Error Code��" + Toolsets::intToStr(Parser::CODE_INCOMPLETE));
			return Parser::CODE_INCOMPLETE;
		}
	}
	PARLOG("Error Code��" + Toolsets::intToStr(result));
	return false;
}

int UnUCompiler::Parser::entry__()
{
	// PARLOG("��ʼ�ڵ㣺" + this->_current->getState());
	return StateMachine::entry__();
}

int UnUCompiler::Parser::quit__()
{
	// PARLOG("��һ�ڵ㣺" + this->_current->getState());
	return StateMachine::quit__();
}

