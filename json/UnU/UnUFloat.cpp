#include "UnU.h" 
#include "UnUFloat.h"

using namespace UnU;

UnU::UnUFloat::UnUFloat(double value)
{
	UnUValue<double>::UnUValue<double>();
	this->_value = value;
	this->_type = UnUType::find(UNU_FLOAT);
}

UnU::UnUFloat::~UnUFloat()
{
}

void UnU::UnUFloat::init()
{
	for (size_t i = 0; i < UnUValue<double>::POOR_SIZE; i++)
	{
		UnUValue<double>::_memoryPoor.push_back(new UnUFloat());
	}
}

UnUFloat * UnU::UnUFloat::createFloat(double value)
{
	if (UnUValue<double>::_memoryPoor.size() < 0)
	{
		for (size_t i = 0; i < UnUValue<double>::POOR_SIZE; i++)
		{
			UnUValue<double>::_memoryPoor.push_back(new UnUFloat());
		}
	}
	auto temp = dynamic_cast<UnUFloat*>(UnUValue<double>::_memoryPoor[0]);
	UnUValue<double>::_memoryPoor.erase(UnUValue<double>::_memoryPoor.begin());
	temp->setValue(value);
	return temp;
}

UnUBase * UnU::UnUFloat::calculate(std::string operatorType, UnUValue<double> *leftValue)
{
	double resultValue;
	if ("+" == operatorType)
		resultValue = this->getValue() + leftValue->getValue();
	else if ("-" == operatorType)
		resultValue = this->getValue() - leftValue->getValue();
	else if ("*" == operatorType)
		resultValue = this->getValue() * leftValue->getValue();
	else if ("/" == operatorType)
		resultValue = this->getValue() / leftValue->getValue();
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
	return UnUFloat::createFloat(resultValue);
}
