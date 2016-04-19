#include "ASTInputNode.h"

UnUCompiler::ASTInputNode::ASTInputNode()
{
	this->_valueType = AST_INPUT;
}

int UnUCompiler::ASTInputNode::check()
{
	return SUCCESS;
}

void UnUCompiler::ASTInputNode::print()
{
	std::cout << "Input" << std::endl;
	this->_input->print();
}

UnUCompiler::ASTInputNode::~ASTInputNode()
{

}
