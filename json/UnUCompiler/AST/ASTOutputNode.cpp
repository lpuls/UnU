#include "../UnUCompile.h"
#include "ASTOutputNode.h"

UnUCompiler::ASTOutputNode::ASTOutputNode()
{
	this->_valueType = AST_OUTPUT;
}

int UnUCompiler::ASTOutputNode::check()
{
	return SUCCESS;
}

void UnUCompiler::ASTOutputNode::print()
{
	std::cout << "Output" << std::endl;
	this->_outContent->print();
}

UnUCompiler::ASTOutputNode::~ASTOutputNode()
{
}
