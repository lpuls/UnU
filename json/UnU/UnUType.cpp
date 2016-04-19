#include <string>
#include <iostream>

#include "UnUType.h"

using namespace UnU;

std::map<std::string, UnUType*> UnUType::__typeDict;

UnU::UnUType::~UnUType()
{
}

UnUType * UnU::UnUType::addType(std::string typeName)
{
	auto type = UnUType::__typeDict.find(typeName);
	if (UnUType::__typeDict.end() == type)
	{
		UnUType::__typeDict[typeName] = new UnUType(typeName);
	}
	return UnUType::__typeDict[typeName];
}

bool UnU::UnUType::isExit(std::string typeName)
{
	auto type = UnUType::__typeDict.find(typeName);
	if (UnUType::__typeDict.end() != type)
	{
		return true;
	}
	return false;
}

UnUType * UnU::UnUType::find(std::string typeName)
{
	auto type = UnUType::__typeDict.find(typeName);
	if (UnUType::__typeDict.end() != type)
	{
		return UnUType::__typeDict[typeName];
	}
	return nullptr;
}

void UnU::UnUType::print()
{
	for (auto item : UnUType::__typeDict)
	{
		std::cout << item.second->getType() << std::endl;
	}
}

UnU::UnUType::UnUType(std::string typeName)
{
	this->__type = typeName;
}
