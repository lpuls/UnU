#include <functional>

#include "Lex.h"
#include "../UnUCompile.h"

using namespace std;
using namespace UnUCompiler;

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

void UnUCompiler::Lex::clearWordIterator()
{
	this->__iterator.clear();
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
		if ("\"" == this->_input && "string" == this->_current->getState())
		{
			this->__currentWord += "\"";
			this->_location += 1;
		}
		// 将记录下来的字符串转化为词汇
		Word word;
		auto result = this->__keyWordsTable.at(this->__currentWord);
		if (UnUCompiler::ERROR == result)
			word = Word(this->__currentWord, this->_current->getState());
		else
			word = Word(this->__currentWord, result);
		LEXLOG("终端节点：" + word.getWordValue() + " 节点词汇：" + word.getWord() + "\n");
		this->__iterator.push(word);
		this->__currentWord = "";
		this->_current = this->_stateTable->getStarState();
	}
	else if (" " != this->_input || "string_mid" == this->_current->getState())
	{
		this->__currentWord += this->_input;
	}
	return StateMachine::quit__();
}