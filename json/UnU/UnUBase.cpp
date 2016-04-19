#include <iostream>

#include "UnU.h"
#include "UnUBase.h"
#include "UnURecoverManager.h"

UnU::UnUBase::UnUBase()
{
	this->_type = UnUType::addType(UNU_BASE);
}

UnU::UnUBase::~UnUBase()
{
	// std::cout << "我被清理啦~" << std::endl;
}

void UnU::UnUBase::releaseSelf()
{
}
