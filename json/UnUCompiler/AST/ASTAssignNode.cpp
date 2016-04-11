#include "ASTAssignNode.h"
#include "ASTOperatorNode.h"

UnUCompiler::ASTAssignNode::ASTAssignNode()
{
	this->_valueType = AST_ASSIGN;
}

int UnUCompiler::ASTAssignNode::check()
{
	auto rightValueOperatorNode = dynamic_cast<ASTOperatorNode*>(this->__right);
	// ����Ƿ�Ϊ��ֵ������
	if (rightValueOperatorNode && rightValueOperatorNode->getValueType() == AST_OPERATOR)
	{
		auto result = rightValueOperatorNode->check();
		if (SUCCESS == result)
		{
			this->__left->setType(rightValueOperatorNode->getType());
			return SUCCESS;
		}
	}
	else  // ��ֵ���͵Ľڵ�
	{
		std::string type = "";
		auto rightNode = ((ASTValueNode<int>*)(this->__right));
		// ����Ƿ�ת���ɹ�
		if (!rightNode)
			return TYPE_ERROR;
		auto rightValueType = rightNode->getValueType();
		// �����ֵ�Ƿ�ΪAST_Token
		if (rightValueType != AST_TOKEN)
		{
			this->__left->setType(rightValueType);
			return SUCCESS;
		}
		else // ��ֵΪAST_Token
		{
			// ȡ��AST_Token������
			auto tokenType = dynamic_cast<ASTTokenNode*>(this->__right);
			if (tokenType->getType() == this->__left->getType())
			{
				this->__left->setType(rightValueType);
				return SUCCESS;
			}
		}

	}
	return TYPE_ERROR;
}

UnUCompiler::ASTAssignNode::~ASTAssignNode()
{
}
