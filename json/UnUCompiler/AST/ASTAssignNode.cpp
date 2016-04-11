#include "ASTAssignNode.h"
#include "ASTOperatorNode.h"

UnUCompiler::ASTAssignNode::ASTAssignNode()
{
	this->_valueType = AST_ASSIGN;
}

int UnUCompiler::ASTAssignNode::check()
{
	auto rightValueOperatorNode = dynamic_cast<ASTOperatorNode*>(this->__right);
	// 检测是否为数值操作符
	if (rightValueOperatorNode && rightValueOperatorNode->getValueType() == AST_OPERATOR)
	{
		auto result = rightValueOperatorNode->check();
		if (SUCCESS == result)
		{
			this->__left->setType(rightValueOperatorNode->getType());
			return SUCCESS;
		}
	}
	else  // 数值类型的节点
	{
		std::string type = "";
		auto rightNode = ((ASTValueNode<int>*)(this->__right));
		// 检测是否转换成功
		if (!rightNode)
			return TYPE_ERROR;
		auto rightValueType = rightNode->getValueType();
		// 检测右值是否为AST_Token
		if (rightValueType != AST_TOKEN)
		{
			this->__left->setType(rightValueType);
			return SUCCESS;
		}
		else // 右值为AST_Token
		{
			// 取出AST_Token的类型
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
