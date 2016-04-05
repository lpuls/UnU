#include <functional>

#include "Lex.h"
#include "../UnUCompile.h"

using namespace std;
using namespace UnUCompiler;

Lex * Lex::__instance = nullptr;

#define LEXLOG(var) Toolsets::getInstance()->log(var, "LEX");

UnUCompiler::Lex::Lex(std::string path) : StateMachine(path)
{
	this->__keyWordsTable = KeyWordsTable(keyWordPath);
	this->__currentWord = "";
	
}

UnUCompiler::Lex::~Lex()
{
	StateMachine::~StateMachine();
}

int UnUCompiler::Lex::entry__()
{
	return StateMachine::entry__();
}

int UnUCompiler::Lex::quit__()
{
	// 转移为零，则说明为结端节点
	if (0 == this->_current->getTransitionTotal())
	{
		if (" " != this->_input)
			this->_location -= 1;
		LEXLOG("终端节点：" + this->_current->getState() + " 节点词汇：" + this->__currentWord + "\n");
		// 将记录下来的字符串转化为词汇
		Word *word = nullptr;
		auto result = this->__keyWordsTable.at(this->__currentWord);
		if (UnUCompiler::ERROR == result)
			word = new Word(this->__currentWord, this->_current->getState());
		else
			word = new Word(this->__currentWord, result);
		this->__iterator.push(word);
		this->__currentWord = "";
		this->_current = this->_stateTable->getStarState();
	}
	else
	{
		this->__currentWord += this->_input;
	}
	return StateMachine::quit__();
}

Lex * UnUCompiler::Lex::getInstance()
{
	if (nullptr == Lex::__instance)
		Lex::__instance = new Lex(LexPath);
	return Lex::__instance;
}

void UnUCompiler::Lex::releaseInstance()
{
	SAFE_DELETE(Lex::__instance);
}