#include "ASTIntegerNode.h"
#include "../../Toolsets.h"

#define ASTLOG(var) XpLib::Toolsets::getInstance()->log(var, "AST");

UnUCompiler::ASTIntegerNode::~ASTIntegerNode()
{
	
}

UnUCompiler::ASTIntegerNode::ASTIntegerNode()
{
	this->_type = "integer";
	this->_valueType = AST_INTEGER;
}
