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
	// 检测是否为数值操作符
	if (rightValueOperatorNode && rightValueOperatorNode->getValueType() == AST_VALUE_OPERATOR)
	{
		auto result = rightValueOperatorNode->check();
		if (SUCCESS == result)
		{
			// 左值类型一定要等于右值才能进行运算
			if ("" == this->__left->getType() || this->__left->getType() == rightValueOperatorNode->getType())
			{
				this->__left->setType(rightValueOperatorNode->getType());
				return SUCCESS;
			}
			else  // 左值类型不等于右值，类型错误
			{
				return TYPE_ERROR;
			}
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
		if (rightValueType != AST_TOKEN)  // 右值不为Token
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
		else // 右值为AST_Token
		{
			// 取出AST_Token的类型
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
