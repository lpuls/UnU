#include "ASTValueNode.h"
#include "ASTNodeCreater.h"
#include "ASTIntegerNode.h"

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
	return new ASTNode();
}
