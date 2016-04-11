#include "ASTBodyNode.h"

UnUCompiler::ASTBodyNode::ASTBodyNode()
{
	this->_valueType = AST_BODY;
}

UnUCompiler::ASTBodyNode::~ASTBodyNode()
{
}

void UnUCompiler::ASTBodyNode::addChild(ASTNode * child)
{
	this->__children.push_back(child);
}

int UnUCompiler::ASTBodyNode::check()
{
	int result;
	for (auto item : this->__children)
	{
		result = item->check();
		if (SUCCESS != result)
			return result;
	}
	return SUCCESS;
}
