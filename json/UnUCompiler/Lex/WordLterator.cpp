#include <iostream>

#include "WordLterator.h"

using namespace UnUCompiler;

UnUCompiler::WordIterator::WordIterator()
{
}

UnUCompiler::WordIterator::~WordIterator()
{
	std::cout << "»ØÊÕ" << std::endl;
	for (auto item : this->__lterator)
	{
		SAFE_DELETE(item);
	}
	this->__lterator.clear();
}

void UnUCompiler::WordIterator::push(Word * word)
{
	this->__lterator.push_back(word);
}

unsigned UnUCompiler::WordIterator::total()
{
	return this->__lterator.size();
}

Word * UnUCompiler::WordIterator::get(int index)
{
	if (index >= 0 && index < this->__lterator.size())
	{
		auto temp = this->__lterator[index];
		return temp;
	}
	return nullptr;
}

void UnUCompiler::WordIterator::clear()
{
	for (auto item : this->__lterator)
	{
		SAFE_DELETE(item);
	}
	this->__lterator.clear();
}
