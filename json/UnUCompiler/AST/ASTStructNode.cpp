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
	// �ȼ���������Ƿ�ΪBool���ʽ
	if (this->_left->getIsBool())
	{
		auto result = this->_left->check();
		if (SUCCESS == result)
		{		
			// ���������
			return this->_right->check();
		}
		return result;
	}
	else
	{
		return UNKNOW_BOOL;
	}
}
