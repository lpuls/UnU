#include "Parser.h"
#include "../Lex/WordLterator.h"


#define PARLOG(var) Toolsets::getInstance()->log(var, "Parser");

int UnUCompiler::Parser::matchBrackets__(std::string brackets)
{
	// 得到括号的前后缀
	auto bracketsPrefix = brackets.substr(0, brackets.find("_"));
	auto bracketsSuffix = brackets.substr(0, brackets.find("_") + 1);
	if (0 != this->__brackets.size())
	{
		auto top = this->__brackets.top();
		// 得到栈顶的前后缀
		auto topPrefix = top.substr(0, top.find("_"));
		auto topSuffix = top.substr(top.find("_") + 1);
		// 检测是否为左侧括号
		if ("left" == bracketsSuffix)
		{
			this->__brackets.push(brackets);
			return Parser::ADD;
		}
		else if ("left" == topSuffix && bracketsPrefix == topPrefix)  // 若为右括号，检测是否与栈顶元素相符
		{
			this->__brackets.pop();
			return Parser::SUCCESS;
		}
		return Parser::FAILED;
	}
	else if ("left" == bracketsSuffix)
	{
		this->__brackets.push(brackets);
		return Parser::ADD;
	}
	return Parser::FAILED;
}

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
		// 检测是否存在未完全匹配完成的情况
		if (this->_stateTable->getStarState() != this->_current)
		{
			PARLOG("Code Incomplete, Error Code：" + Toolsets::intToStr(Parser::CODE_INCOMPLETE));
			result = Parser::CODE_INCOMPLETE;
		}
		// 检测括号不匹配的问题
		if (0 != this->__brackets.size())
		{
			PARLOG("Un Match Brackets, Error Code :" + Toolsets::intToStr(Parser::BRACKETS_MATCH_ERROR));
			result = Parser::BRACKETS_MATCH_ERROR;
		}
		return result;
	}
	PARLOG("Error Code：" + Toolsets::intToStr(result));
	return result;
}

int UnUCompiler::Parser::entry__()
{
	return StateMachine::entry__();
}

int UnUCompiler::Parser::quit__()
{
	if (0 == this->_current->getTransitionTotal())
	{
		this->_current = this->_stateTable->getStarState();
		return StateMachine::quit__();
	}
	else
	{
		auto result = this->matchBrackets__(this->_input);
		// 匹配结果为添加时，正常运行
		if (Parser::ADD == result || Parser::SUCCESS)
		{
			return StateMachine::quit__();
		}
		else  // 返回失败的错误
		{
			return Parser::BRACKETS_MATCH_ERROR;
		}
	}

}



