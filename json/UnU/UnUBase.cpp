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
	// std::cout << "�ұ�������~" << std::endl;
}

void UnU::UnUBase::releaseSelf()
{
}
