/*
* ��������ǽڵ�
* ���ߣ�xp
* ���ڣ�2016-4-13
*/
#ifndef __AST_STAND_NODE__
#define __AST_STAND_NODE__

#include "ASTNode.h"

namespace UnUCompiler
{
	class ASTStandNode : public ASTNode
	{
		friend class ASTNodeCreater;
	private:
		/*
		* ���ܣ����캯��
		* ��������
		* ���أ���
		* ��������
		*/
		ASTStandNode();

	public:
		/*
		* ���ܣ���������
		* ��������
		* ���أ���
		* ��������
		*/
		~ASTStandNode();

		 
	};
}

#endif
