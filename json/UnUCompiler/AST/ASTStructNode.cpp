#include "ASTStructNode.h"

UnUCompiler::ASTStructNode::ASTStructNode()
{
}

UnUCompiler::ASTStructNode::~ASTStructNode()
{
	SAFE_DELETE(this->_left);
	SAFE_DELETE(this->_right);
}

int UnUCompiler::ASTStructNode::check()
{
	// 先检测左子树是否为Bool表达式
	if (this->_left->getIsBool())
	{
		auto result = this->_left->check();
		if (SUCCESS == result)
		{		
			// 检测右子树
			return this->_right->check();
		}
		return result;
	}
	else
	{
		return UNKNOW_BOOL;
	}
}
