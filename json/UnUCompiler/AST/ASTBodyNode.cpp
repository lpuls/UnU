#include "ASTBodyNode.h"
#include "ASTTokenNode.h"


UnUCompiler::ASTBodyNode::ASTBodyNode()
{
	this->_valueType = AST_BODY;
	this->_tokenTable = new ASTTokenTable();
}

UnUCompiler::ASTBodyNode::~ASTBodyNode()
{
	SAFE_DELETE(this->_tokenTable);
}

void UnUCompiler::ASTBodyNode::addChild(ASTNode * child)
{
	child->setParent(this);
	// TODO 符号表问题
	// 若存在Token，则将其添加进符号表中
	if (AST_TOKEN == child->getValueType())
		this->_tokenTable->__tokenTable.push_back(dynamic_cast<ASTTokenNode*>(child)->getValue());
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

bool UnUCompiler::ASTBodyNode::isExit(std::string token)
{
	// 检测自身是否存在目标变量
	auto result = this->_tokenTable->isExit(token);
	// 检测父节点处是否存在目标变量
	auto parent = dynamic_cast<ASTBodyNode*>(this->_parent);
	if (parent)
	{
		return parent->isExit(token);
	}
	return false;
}

void UnUCompiler::ASTBodyNode::print()
{
	ASTNode::print();
	for (auto item : this->__children)
	{
		item->print();
	}
}
