#include "ASTIntegerNode.h"
#include "../../Toolsets.h"

#define ASTLOG(var) XpLib::Toolsets::getInstance()->log(var, "AST");

UnUCompiler::ASTIntegerNode::~ASTIntegerNode()
{
	this->_type = "integer";
}

UnUCompiler::ASTIntegerNode::ASTIntegerNode()
{
	ASTLOG("ªÿ ’");
}
