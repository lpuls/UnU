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
	// 运行之后检测得到的是否为终端结果，否则认定为错误
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
			PARLOG("Code Incomplete, Error Code：" + Toolsets::intToStr(Parser::CODE_INCOMPLETE));
			return Parser::CODE_INCOMPLETE;
		}
	}
	PARLOG("Error Code：" + Toolsets::intToStr(result));
	return false;
}

int UnUCompiler::Parser::entry__()
{
	// PARLOG("开始节点：" + this->_current->getState());
	return StateMachine::entry__();
}

int UnUCompiler::Parser::quit__()
{
	// PARLOG("下一节点：" + this->_current->getState());
	return StateMachine::quit__();
}

