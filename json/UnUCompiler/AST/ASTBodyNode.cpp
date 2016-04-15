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
	// TODO ���ű�����
	// ������Token��������ӽ����ű���
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
	// ��������Ƿ����Ŀ�����
	auto result = this->_tokenTable->isExit(token);
	// ��⸸�ڵ㴦�Ƿ����Ŀ�����
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
