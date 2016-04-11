#include "ASTValueNode.h"
#include "ASTNodeCreater.h"
#include "ASTIntegerNode.h"
#include "ASTFloatNode.h"

#include "../../Toolsets.h"

using namespace UnUCompiler;

ASTNode * UnUCompiler::ASTNodeCreater::create(std::string word, std::string wordValue)
{
	if ("integer" == wordValue)
	{
		auto result = new ASTIntegerNode();
		result->setValue(XpLib::Toolsets::strToInt(word));
		return result;
	}
	else if ("float" == wordValue)
	{
		auto result = new ASTFloatNode();
		result->setValue(XpLib::Toolsets::strToDouble(word));
		return result;
	}
	return new ASTNode();
}
