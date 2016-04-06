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

int UnUCompiler::Lex::entry__()
{
	return StateMachine::entry__();
}

int UnUCompiler::Lex::quit__()
{
	// ת��Ϊ�㣬��˵��Ϊ��˽ڵ�
	if (0 == this->_current->getTransitionTotal())
	{
		if (" " != this->_input)
			this->_location -= 1;
		LEXLOG("�ն˽ڵ㣺" + this->_current->getState() + " �ڵ�ʻ㣺" + this->__currentWord + "\n");
		// ����¼�������ַ���ת��Ϊ�ʻ�
		Word word;
		auto result = this->__keyWordsTable.at(this->__currentWord);
		if (UnUCompiler::ERROR == result)
			word = Word(this->__currentWord, this->_current->getState());
		else
			word = Word(this->__currentWord, result);
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