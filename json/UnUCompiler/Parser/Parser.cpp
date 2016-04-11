#include "Parser.h"
#include "../Lex/WordLterator.h"


#define PARLOG(var) Toolsets::getInstance()->log(var, "Parser");

int UnUCompiler::Parser::matchBrackets__(std::string brackets)
{
	// �õ����ŵ�ǰ��׺
	auto bracketsPrefix = brackets.substr(0, brackets.find("_"));
	auto bracketsSuffix = brackets.substr(0, brackets.find("_") + 1);
	if (0 != this->__brackets.size())
	{
		auto top = this->__brackets.top();
		// �õ�ջ����ǰ��׺
		auto topPrefix = top.substr(0, top.find("_"));
		auto topSuffix = top.substr(top.find("_") + 1);
		// ����Ƿ�Ϊ�������
		if ("left" == bracketsSuffix)
		{
			this->__brackets.push(brackets);
			return Parser::ADD;
		}
		else if ("left" == topSuffix && bracketsPrefix == topPrefix)  // ��Ϊ�����ţ�����Ƿ���ջ��Ԫ�����
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
	// ����֮����õ����Ƿ�Ϊ�ն˽���������϶�Ϊ����
	auto result = StateMachine::run();
	if (StateMachine::SUCCESS == result)
	{
		// ����Ƿ����δ��ȫƥ����ɵ����
		if (this->_stateTable->getStarState() != this->_current)
		{
			PARLOG("Code Incomplete, Error Code��" + Toolsets::intToStr(Parser::CODE_INCOMPLETE));
			result = Parser::CODE_INCOMPLETE;
		}
		// ������Ų�ƥ�������
		if (0 != this->__brackets.size())
		{
			PARLOG("Un Match Brackets, Error Code :" + Toolsets::intToStr(Parser::BRACKETS_MATCH_ERROR));
			result = Parser::BRACKETS_MATCH_ERROR;
		}
		return result;
	}
	PARLOG("Error Code��" + Toolsets::intToStr(result));
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
		// ƥ����Ϊ���ʱ����������
		if (Parser::ADD == result || Parser::SUCCESS)
		{
			return StateMachine::quit__();
		}
		else  // ����ʧ�ܵĴ���
		{
			return Parser::BRACKETS_MATCH_ERROR;
		}
	}

}



