#include <string>
#include <iostream>

#include "ToolLog.h"

XpLib::ToolLog::ToolLog()
{
}

bool XpLib::ToolLog::addSwitch(std::string switchName)
{
#ifdef __Debug__
	auto result = this->__switchMap.find(switchName);
	if (this->__switchMap.end() == result)
	{
		this->__switchMap[switchName] = true;
		return true;
	}
#endif
	return false;
}

void XpLib::ToolLog::setSwitch(std::string switchName, bool switchValue)
{
#ifdef __Debug__
	auto result = this->__switchMap.find(switchName);
	if (this->__switchMap.end() != result)
	{
		this->__switchMap[switchName] = switchValue;
	}	 
#endif
}

void XpLib::ToolLog::log(std::string logValue, std::string switchName)
{
#ifdef __Debug__
	auto result = this->__switchMap.find(switchName);
	if (this->__switchMap.end() != result)
	{
		if (this->__switchMap[switchName])
		{
			std::cout << logValue << std::endl;
		}
	}
#endif
}
