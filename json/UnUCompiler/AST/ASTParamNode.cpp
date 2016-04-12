#include "../../Tools.h"
#include "ASTParamNode.h"

UnUCompiler::ASTParamNode::ASTParamNode()
{
}

UnUCompiler::ASTParamNode::~ASTParamNode()
{
	for (unsigned int i = 0; i < this->__params.size(); i++)
	{
		SAFE_DELETE(this->__params[i]);
	}
	this->__params.clear();
}

void UnUCompiler::ASTParamNode::addParam(ASTTokenNode * param)
{
	this->__params.push_back(param);
}

int UnUCompiler::ASTParamNode::check()
{
	return SUCCESS;
}
