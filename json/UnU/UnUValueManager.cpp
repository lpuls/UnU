#include "UnU.h"
#include "UnUInteger.h"
#include "UnUFloat.h"
#include "UnUValueManager.h"


using namespace UnU;

std::map<std::string, UnUBase*> UnUValueManager::__valueDict;

UnUBase * UnU::UnUValueManager::create(std::string tokenName, std::string type)
{
	auto result = UnUValueManager::__valueDict.find(tokenName);
	// 不允行创建同的变量，就算是类型不同
	if (UnUValueManager::__valueDict.end() == result)
	{
		UnUBase *base = nullptr;
		if (UNU_INTEGER == type)
		{
			base = UnUInteger::__litterInteger[-LITTER_INTEGER_MIN];
			UnUValueManager::add(tokenName, base);
		}
		else if (UNU_FLOAT == type)
		{
			base = UnUFloat::createFloat();
			UnUValueManager::add(tokenName, base);
		}
		return base;
	}
	return nullptr;
}

UnUBase * UnU::UnUValueManager::create(std::string tokenName, UnUBase * base)
{
	auto result = UnUValueManager::__valueDict.find(tokenName);
	// 不允行创建同的变量，就算是类型不同
	if (UnUValueManager::__valueDict.end() == result)
	{
		UnUValueManager::add(tokenName, base);
		return base;
	}
	return nullptr;
}

UnUBase * UnU::UnUValueManager::replace(std::string tokenName, UnUBase * base)
{
	auto result = UnUValueManager::__valueDict.find(tokenName);
	if (UnUValueManager::__valueDict.end() != result)
	{
		auto original = UnUValueManager::__valueDict[tokenName];
		UnURecoverManager::removeQuote(original);
		UnUValueManager::__valueDict[tokenName] = base;
		return original;
	}
	return nullptr;
}

void UnU::UnUValueManager::remove(std::string tokenName)
{
	auto result = UnUValueManager::__valueDict.find(tokenName);
	if (UnUValueManager::__valueDict.end() != result)
	{
		UnURecoverManager::removeQuote(UnUValueManager::__valueDict[tokenName]);
		UnUValueManager::__valueDict.erase(result);
	}
}

UnUBase * UnU::UnUValueManager::find(std::string tokenName)
{
	auto result = UnUValueManager::__valueDict.find(tokenName);
	if (UnUValueManager::__valueDict.end() != result)
	{
		return UnUValueManager::__valueDict[tokenName];
	}
	return nullptr;
}

void UnU::UnUValueManager::add(std::string tokenName, UnUBase * base)
{
	auto result = UnUValueManager::__valueDict.find(tokenName);
	if (UnUValueManager::__valueDict.end() == result)
	{
		UnUValueManager::__valueDict[tokenName] = base;
		auto recover = UnURecoverManager::add(base);
		recover->addQuote();
	}
	else
	{
		auto recover = UnURecoverManager::find(base);
		recover->addQuote();
	}
}
