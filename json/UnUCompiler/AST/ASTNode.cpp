#include "ASTNode.h"

using namespace UnUCompiler;


UnUCompiler::ASTNode::~ASTNode()
{
}

int UnUCompiler::ASTNode::check()
{
	return SUCCESS;
}

void UnUCompiler::ASTNode::print()
{
	std::cout << this->_valueType << std::endl;
}

UnUCompiler::ASTNode::ASTNode()
{
}
