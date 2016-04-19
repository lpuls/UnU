#include "UnU.h"
#include "UnUString.h"

using namespace UnU;

UnU::UnUString::UnUString(std::string value)
{
	UnUValue<std::string>::UnUValue<std::string>();
	this->_value = value;
	this->_type = UnUType::find(UNU_STRING);
}

UnU::UnUString::~UnUString()
{
}

void UnU::UnUString::init()
{
	for (size_t i = 0; i < UnUValue<std::string>::POOR_SIZE; i++)
	{
		UnUValue<std::string>::_memoryPoor.push_back(new UnUString());
	}
}

UnUString * UnU::UnUString::createString(std::string value)
{
	if (UnUValue<std::string>::_memoryPoor.size() < 0)
	{
		for (size_t i = 0; i < UnUValue<std::string>::POOR_SIZE; i++)
		{
			UnUValue<std::string>::_memoryPoor.push_back(new UnUString());
		}
	}
	auto temp = dynamic_cast<UnUString*>(UnUValue<std::string>::_memoryPoor[0]);
	UnUValue<std::string>::_memoryPoor.erase(UnUValue<std::string>::_memoryPoor.begin());
	temp->setValue(value);
	return temp;
}

UnUBase * UnU::UnUString::calculate(std::string operatorType, UnUValue<std::string>* leftValue)
{
	std::string resultValue;
	if ("+" == operatorType)
		resultValue = this->getValue() + leftValue->getValue();
	else if (">=" == operatorType)
		resultValue = this->getValue() >= leftValue->getValue();
	else if ("<=" == operatorType)
		resultValue = this->getValue() <= leftValue->getValue();
	else if ("==" == operatorType)
		resultValue = this->getValue() == leftValue->getValue();
	else if (">" == operatorType)
		resultValue = this->getValue() > leftValue->getValue();
	else if ("<" == operatorType)
		resultValue = this->getValue() < leftValue->getValue();
	else
		return nullptr;
	return UnUString::createString(resultValue);
}