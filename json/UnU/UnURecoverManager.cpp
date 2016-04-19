#include "UnURecoverManager.h"

using namespace UnU;

std::map<UnUBase*, UnURecover*> UnURecoverManager::__recoverDict;

UnURecover * UnU::UnURecoverManager::find(UnUBase * base)
{
	auto result = UnURecoverManager::__recoverDict.find(base);
	if (UnURecoverManager::__recoverDict.end() != result)
	{
		return UnURecoverManager::__recoverDict[base];
	}
	return nullptr;
}

UnURecover * UnU::UnURecoverManager::add(UnUBase * base)
{
	auto result = UnURecoverManager::__recoverDict.find(base);
	if (UnURecoverManager::__recoverDict.end() == result)
	{
		return UnURecoverManager::__recoverDict[base] = new UnURecover();
	}
	return UnURecoverManager::__recoverDict[base];
}

void UnU::UnURecoverManager::remove(UnUBase * base)
{
	auto result = UnURecoverManager::__recoverDict.find(base);
	if (UnURecoverManager::__recoverDict.end() != result)
	{
		SAFE_DELETE(UnURecoverManager::__recoverDict[base]);
		// SAFE_DELETE(base);
		base->releaseSelf();
		UnURecoverManager::__recoverDict.erase(result);
	}
}

void UnU::UnURecoverManager::addQuote(UnUBase * base)
{
	auto result = UnURecoverManager::__recoverDict.find(base);
	if (UnURecoverManager::__recoverDict.end() != result)
	{
		UnURecoverManager::__recoverDict[base]->addQuote();
	}
}

void UnU::UnURecoverManager::removeQuote(UnUBase * base)
{
	auto result = UnURecoverManager::__recoverDict.find(base);
	if (UnURecoverManager::__recoverDict.end() != result)
	{
		if (UnURecoverManager::__recoverDict[base]->removeQuote())
		{
			UnURecoverManager::remove(base);
		}
	}
}
