#include "ASTTokenNode.h"
#include "ASTOperatorNode.h"

UnUCompiler::ASTOperatorNode::ASTOperatorNode()
{
	this->_isBool = false;
}

std::string UnUCompiler::ASTOperatorNode::getChildType__(ASTExpNode * child)
{
	std::string type = "";
	auto exp = dynamic_cast<ASTOperatorNode*>(child);
	if (exp)
	{
		int result = exp->check();
		if (result == SUCCESS)
			return exp->getType();
		else
			return ERROR;
	}
	else
	{
		auto token = dynamic_cast<ASTTokenNode*>(child);
		if (token)
			return token->getType();
		else
		{
			return dynamic_cast<ASTNode*>(child)->getValueType();
		}
	}
}

UnUCompiler::ASTOperatorNode::~ASTOperatorNode()
{
	SAFE_DELETE(this->_left);
	SAFE_DELETE(this->_right);

}

int UnUCompiler::ASTOperatorNode::check()
{
	if ("" != this->_type)
		return SUCCESS;
	if (!this->_right || !this->_left)
		return NULL_CHILD;
	std::string rightType = this->getChildType__(this->_right);
	if ("" == rightType && AST_TOKEN == this->_right->getValueType())
		rightType = AST_TOKEN;
	std::string leftType = this->getChildType__(this->_left);
	if ("" == leftType || AST_TOKEN == rightType 
		|| (rightType == leftType 
		|| AST_INTEGER == rightType && AST_FLOAT == leftType 
		|| AST_INTEGER == leftType && AST_FLOAT == rightType)
		&& ERROR != rightType && ERROR != leftType)
	{
		this->_type = rightType;
		return SUCCESS;
	}
	return TYPE_ERROR;
}

void UnUCompiler::ASTOperatorNode::print()
{
	ASTExpNode::print();
	this->_left->print();
	this->_right->print();
}
