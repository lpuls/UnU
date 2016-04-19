/*
* �������жϻ�ѭ�����Ľڵ�
* ���ߣ�xp
* ���ڣ�2016-4-11
*/
#ifndef __AST_STRUCT_NODE__
#define __AST_STRUCT_NODE__

#include "ASTNode.h"
#include "ASTBodyNode.h"
#include "../../Tools.h"
#include "ASTOperatorNode.h"


namespace UnUCompiler
{
	class ASTStructNode : public ASTNode
	{
		friend class ASTNodeCreater;
	private:
		/*
		* ���ܣ�Bool�ж�
		* ���ͣ�ASTOperatorNode*
		* ��������
		*/
		DEFINE_PROTECTED(ASTExpNode*, _left, Left);

		/*
		* ���ܣ����нṹ
		* ���ͣ�ASTBodyNode*
		* ��������
		*/
		DEFINE_PROTECTED(ASTBodyNode*, _right, Right);

		/*
		* ���ܣ����캯��
		* ��������
		* ���أ���
		* ��������
		*/
		ASTStructNode();

	public:
		/*
		* ���ܣ���������
		* ��������
		* ���أ���
		* ��������
		*/
		~ASTStructNode();

		/*
		* ���ܣ���鷽��
		* ��������
		* ���أ�int�������
		* �������鷽�����������ÿһ���ڵ�������Ƿ���ȷ
		*/
		int check();

		/*
		* ���ܣ���ӡ�ṹ
		* ��������
		* ���أ���
		* ��������
		*/
		void print();
	};
}

#endif
