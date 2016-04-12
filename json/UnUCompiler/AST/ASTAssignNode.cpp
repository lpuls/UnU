#include "ASTAssignNode.h"
#include "ASTOperatorNode.h"

UnUCompiler::ASTAssignNode::ASTAssignNode()
{
	this->_valueType = AST_ASSIGN;
}

int UnUCompiler::ASTAssignNode::check()
{
	if (!this->__right || !this->__left)
		return NULL_CHILD;
	auto rightValueOperatorNode = dynamic_cast<ASTOperatorNode*>(this->__right);
	// ����Ƿ�Ϊ��ֵ������
	if (rightValueOperatorNode && rightValueOperatorNode->getValueType() == AST_VALUE_OPERATOR)
	{
		auto result = rightValueOperatorNode->check();
		if (SUCCESS == result)
		{
			// ��ֵ����һ��Ҫ������ֵ���ܽ�������
			if ("" == this->__left->getType() || this->__left->getType() == rightValueOperatorNode->getType())
			{
				this->__left->setType(rightValueOperatorNode->getType());
				return SUCCESS;
			}
			else  // ��ֵ���Ͳ�������ֵ�����ʹ���
			{
				return TYPE_ERROR;
			}
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
		if (rightValueType != AST_TOKEN)  // ��ֵ��ΪToken
		{
			if ("" == this->__left->getType() || this->__left->getType() == rightValueType)
			{		
				this->__left->setType(rightValueType);
				return SUCCESS;
			}
			else
			{
				return TYPE_ERROR;
			}
		}
		else // ��ֵΪAST_Token
		{
			// ȡ��AST_Token������
			auto tokenType = dynamic_cast<ASTTokenNode*>(this->__right);
			if ("" == this->__left->getType() || tokenType->getType() == this->__left->getType())
			{
				this->__left->setType(rightValueType);
				return SUCCESS;
			}
			else
			{
				return TYPE_ERROR;
			}
		}

	}
	return TYPE_ERROR;
}

UnUCompiler::ASTAssignNode::~ASTAssignNode()
{
	SAFE_DELETE(this->__left);
	SAFE_DELETE(this->__right);
}
