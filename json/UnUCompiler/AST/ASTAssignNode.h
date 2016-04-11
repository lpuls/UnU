/*
* ��������ֵAST�ڵ�
* ���ߣ�xp
* ���ڣ�2016-4-11
*/
#ifndef __AST_ASSIGN_NODE__
#define __AST_ASSIGN_NODE__

#include "ASTExpNode.h"
#include "ASTTokenNode.h"
#include "../../Tools.h"

namespace UnUCompiler
{
	class ASTAssignNode : public ASTExpNode
	{
	private:
		/*
		* ���ܣ���ڵ㣬��ʾ��ֵ
		* ���ͣ���ֵ������һ��ΪToken
		* ��������
		*/
		DEFINE_PRIVATE(ASTTokenNode*, __left, Left);

		/*
		* ���ܣ��ҽڵ㣬����Ϊֵ���ű��ʽ
		* ���ͣ�ASTExpNode*
		* ��������
		*/
		DEFINE_PRIVATE(ASTExpNode*, __right, Right);

		/*
		* ���ܣ����캯��
		* ��������
		* ���أ���
		* ��������
		*/
		ASTAssignNode();

		/*
		* ���ܣ���鷽��
		* ��������
		* ���أ�int�������
		* �������鷽�����������ÿһ���ڵ�������Ƿ���ȷ
		*/
		int check();

	public:
		/*
		* ���ܣ���������
		* ��������
		* ���أ���
		* ��������
		*/
		~ASTAssignNode();


	};

}

#endif
