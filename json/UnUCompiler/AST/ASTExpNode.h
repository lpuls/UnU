/*
* ���������ʽ�ڵ�
* ���ߣ�xp
* ���ڣ�2016-4-11
*/
#ifndef __AST_EXP_NODE__
#define __AST_EXP_NODE__

#include "ASTNode.h"

namespace UnUCompiler
{
	class ASTExpNode : public ASTNode
	{
		friend class ASTNodeCreater;
	protected:	  
		/*
		* ���ܣ����캯��
		* ��������
		* ���أ���
		* ��������
		*/
		ASTExpNode();

	public:
		/*
		* ���ܣ���������
		* ��������
		* ���أ���
		* ��������
		*/
		~ASTExpNode();


	};
}

#endif
