#include <string>
#include <sstream>
#include <iostream>

#include "TypeConversion.hpp"

std::string XpLib::TypeConversion::intToStr(int value)
{
	std::string result;
	std::stringstream ss;
	ss << value;
	ss >> result;
	return result;
}

int XpLib::TypeConversion::strToInt(std::string value)
{
	int result;
	std::stringstream ss;
	ss << value;
	ss >> result;
	return result;
}

std::string XpLib::TypeConversion::doubleToStr(double value)
{
	std::string result;
	std::stringstream ss;
	ss << value;
	ss >> result;
	return result;
}

double XpLib::TypeConversion::strToDouble(std::string value)
{
	double result;
	std::stringstream ss;
	ss << value;
	ss >> result;
	return result;
}

std::string XpLib::TypeConversion::boolToStr(bool value)
{
	if (value)
		return "true";
	else
		return "false";
}

std::string XpLib::TypeConversion::charToStr(char value)
{
	std::string result;
	std::stringstream ss;
	ss << value;
	ss >> result;
	return result;
}
