/*
* �������������ڵ�
* ���ߣ�xp
* ���ڣ�---
*/
#ifndef __AST_OPERATOR_NODE__
#define __AST_OPERATOR_NODE__

#include "ASTExpNode.h"
#include "../../Toolsets.h"

namespace UnUCompiler
{
	class ASTOperatorNode : public ASTExpNode
	{
		friend class ASTNodeCreater;
	private:
		/*
		* ���ܣ����캯��
		* ��������
		* ���أ���
		* ��������
		*/
		ASTOperatorNode();

		/*
		* ���ܣ��õ���֧�Ľڵ�����
		* ������Ҫ��ȡ�ķ�֧
		* ���أ�std::string��֧������
		* ��������
		*/
		std::string getChildType__(ASTExpNode * child);
	protected:
		/*
		* ���ܣ����������Bool�ͻ�����ֵ��
		* ���ͣ�bool
		* ��������
		*/
		DEFINE_PROTECTED(bool, _isBool, IsBool);

		/*
		* ���ܣ�������¼������õ�����ֵ����
		* ���ͣ�std::string
		* ��������
		*/
		DEFINE_PROTECTED(std::string, _type, Type);

		/*
		* ���ܣ���¼�������ķ���
		* ���ͣ�std::string
		* ��������
		*/
		DEFINE_PROTECTED(std::string, _operator, Operator);

		/*
		* ���ܣ���ڵ�
		* ���ͣ�ASTExpNode*
		* ��������
		*/
		DEFINE_PROTECTED(ASTExpNode*, _left, Left);

		/*
		* ���ܣ��ҽڵ�
		* ���ͣ�ASTExpNode*
		* ��������
		*/
		DEFINE_PROTECTED(ASTExpNode*, _right, Right);

	public:
		/*
		* ���ܣ���������
		* ��������
		* ���أ���
		* ��������
		*/
		~ASTOperatorNode();

		/*
		* ���ܣ���鷽��
		* ��������
		* ���أ�int�������
		* �������鷽�����������ÿһ���ڵ�������Ƿ���ȷ
		*/
		int check();
		
	};
}

#endif