#include "Word.h"

UnUCompiler::Word::Word()
{
}

UnUCompiler::Word::Word(std::string word, std::string value)
{
	this->__word = word;
	this->__wordValue = value;
}

UnUCompiler::Word::~Word()
{
}
