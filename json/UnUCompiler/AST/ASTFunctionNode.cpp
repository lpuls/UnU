#include "ASTFunctionNode.h"

UnUCompiler::ASTFunctionNode::ASTFunctionNode()
{
	this->_valueType = AST_FUNCTION;
}

UnUCompiler::ASTFunctionNode::~ASTFunctionNode()
{
	SAFE_DELETE(this->_params);
	SAFE_DELETE(this->_body);
}

int UnUCompiler::ASTFunctionNode::check()
{
	auto bodyResult = this->_body->check();
	return bodyResult;
}
