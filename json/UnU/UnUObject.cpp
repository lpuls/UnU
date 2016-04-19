#include <iostream>
 
#include "UnU.h"
#include "UnUObject.h"

UnU::UnUObject::UnUObject()
{
}

UnU::UnUObject::~UnUObject()
{
}

void UnU::UnUObject::print()
{
	std::cout <<  static_cast<const void *>(this) << std::endl;
}

UnU::UnUObject * UnU::UnUObject::copy()
{
	return nullptr;
}

int UnU::UnUObject::run()
{
	return TRANSLATION_SUCCESS;
}
