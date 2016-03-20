#include "Toolsets.h"
#include "TypeConversion\TypeConversion.h"

using namespace XpLib;

Toolsets* Toolsets::__instance = nullptr;

XpLib::Toolsets::Toolsets()
{
	// 实例化日志类
	this->__log = new ToolLog();
}

XpLib::Toolsets::~Toolsets()
{
	if (nullptr != this->__log)
		delete(this->__log);
	this->__log = nullptr;
}

Toolsets * XpLib::Toolsets::getInstance()
{
	if (nullptr == Toolsets::__instance)
		Toolsets::__instance = new Toolsets();
	return Toolsets::__instance;
}

void XpLib::Toolsets::releaseInstance()
{
	if (nullptr != Toolsets::__instance)
		delete(Toolsets::__instance);
	Toolsets::__instance = nullptr;
}

bool XpLib::Toolsets::addSwitch(std::string switchName)
{
	if (this->__log->addSwitch(switchName))
		return true;
	return false;
}

void XpLib::Toolsets::setSwitch(std::string switchName, bool switchValue)
{
	this->__log->setSwitch(switchName, switchValue);
}

void XpLib::Toolsets::log(std::string logValue, std::string switchName)
{
	this->__log->log(logValue, switchName);
}

std::string XpLib::Toolsets::intToStr(int value)
{
	return TypeConversion::intToStr(value);
}

int XpLib::Toolsets::strToInt(std::string value)
{
	return TypeConversion::strToInt(value);
}

std::string XpLib::Toolsets::doubleToStr(double value)
{
	return TypeConversion::doubleToStr(value);
}

double XpLib::Toolsets::strToDouble(std::string value)
{
	return TypeConversion::strToDouble(value);
}

std::string XpLib::Toolsets::boolToStr(bool value)
{
	return TypeConversion::boolToStr(value);
}

std::string XpLib::Toolsets::charToStr(char value)
{
	return TypeConversion::charToStr(value);
}

std::vector<std::string> XpLib::Toolsets::reader(std::string file)
{
	return FileReader::reader(file);
}
