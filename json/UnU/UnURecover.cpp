#include "UnURecover.h"

UnU::UnURecover::UnURecover()
{
	// this->__ptr = ptr;
	this->__quote = 0;
}

UnU::UnURecover::~UnURecover()
{
}

void UnU::UnURecover::addQuote()
{
	this->__quote += 1;
}

bool UnU::UnURecover::removeQuote()
{
	this->__quote -= 1;
	if (0 >= this->__quote)
	{
		return true;
	}
	return false;
}
