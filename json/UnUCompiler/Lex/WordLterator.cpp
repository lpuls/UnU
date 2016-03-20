#include "WordLterator.h"

using namespace UnUCompiler;

UnUCompiler::WordLterator::WordLterator()
{
}

UnUCompiler::WordLterator::~WordLterator()
{
	for (auto item : this->__lterator)
	{
		SAFE_DELETE(item);
	}
	this->__lterator.clear();
}

void UnUCompiler::WordLterator::push(Word * word)
{
	this->__lterator.push_back(word);
}

unsigned UnUCompiler::WordLterator::total()
{
	return this->__lterator.size();
}

Word * UnUCompiler::WordLterator::get(int index)
{
	if (index >= 0 && index < this->__lterator.size())
	{
		return this->__lterator[index];
	}
	return nullptr;
}

void UnUCompiler::WordLterator::clear()
{
	for (auto item : this->__lterator)
	{
		SAFE_DELETE(item);
	}
	this->__lterator.clear();
}
