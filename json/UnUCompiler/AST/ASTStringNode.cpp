#include "ASTStringNode.h"

UnUCompiler::ASTStringNode::~ASTStringNode()
{
}

UnUCompiler::ASTStringNode::ASTStringNode()
{
	this->_valueType = AST_STRING;
	this->_type = "string";
}
