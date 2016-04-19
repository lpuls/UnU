#include "UnU.h"
#include "UnUInteger.h"

using namespace UnU;

bool UnUInteger::isInit = false;
std::vector<UnUInteger*> UnUInteger::__litterInteger;

UnU::UnUInteger::UnUInteger(long long int value)
{
	UnUValue<long long int>::UnUValue<long long int>();
	this->_value = value;
	this->_type = UnUType::find(UNU_INTEGER);
}

UnU::UnUInteger::~UnUInteger()
{
}

void UnU::UnUInteger::init()
{
	UnUValue<long long int>::isInit = true;
	for (int i = 0; i < UnUValue<long long int>::POOR_SIZE; i++)
	{
		UnUValue<long long int>::_memoryPoor.push_back(new UnUInteger(10086));
	}
	for (int i = LITTER_INTEGER_MIN; i < LITTER_INTEGER_MAX; i++)
	{
		UnUInteger::__litterInteger.push_back(new UnUInteger(i));
	}
}

UnUInteger * UnU::UnUInteger::createInteger(long long int value)
{
	if (value > LITTER_INTEGER_MAX || value < LITTER_INTEGER_MIN)
	{
		if (UnUValue<long long int>::_memoryPoor.size() < 0)
		{
			for (size_t i = 0; i < UnUValue<long long int>::POOR_SIZE; i++)
			{
				UnUValue<long long int>::_memoryPoor.push_back(new UnUValue());
			}
		}

		auto temp = dynamic_cast<UnUInteger*>(UnUValue<long long int>::_memoryPoor[0]);
		UnUValue<long long int>::_memoryPoor.erase(UnUValue<long long int>::_memoryPoor.begin());
		temp->setValue(value);
		return temp;
	}
	else
	{
		return UnUInteger::__litterInteger[value - LITTER_INTEGER_MIN];
	}
}

void UnU::UnUInteger::release()
{
	UnUValue<long long int>::releaseMemoryPoor();
	for (int i = 0; i < UnUInteger::__litterInteger.size(); i++)
	{
		SAFE_DELETE(UnUInteger::__litterInteger[i]);
	}
	UnUInteger::__litterInteger.clear();
}

void UnU::UnUInteger::releaseSelf()
{
	// 将自身放回内存池中
	if (this->_value > LITTER_INTEGER_MAX || this->_value < LITTER_INTEGER_MIN)
	{
		UnUValue<long long int>::releaseSelf();
	}
}

UnUBase * UnU::UnUInteger::calculate(std::string operatorType, UnUValue<long long int>* leftValue)
{
	long long int resultValue;
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
	return UnUInteger::createInteger(resultValue);
}
