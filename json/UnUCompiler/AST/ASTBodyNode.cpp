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

UnUCompiler::ASTNode * UnUCompiler::ASTBodyNode::getChild(unsigned int location)
{
	if (location >= 0 && location < this->__children.size())
		return this->__children[location];
	return nullptr;
}

unsigned int UnUCompiler::ASTBodyNode::getChildTotal()
{
	return this->__children.size();
}

int UnUCompiler::ASTBodyNode::check()
{
	int result;
	for (auto item : this->__children)
	{
		// �������ڣ��򷴻ش���
		if (item)
		{
			result = item->check();
			if (SUCCESS != result)
				return result;
		}
		else { return NULL_CHILD; }
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
