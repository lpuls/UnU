/*
* ����������������AST�ڵ�
* ���ߣ�xp
* ���ڣ�2016-4-10
*/
#ifndef __AST_FLOAT_NODE__
#define __AST_FLOAT_NODE__

#include "ASTValueNode.h"

namespace UnUCompiler
{
	class ASTFloatNode : public ASTValueNode<float>
	{
		friend class ASTNodeCreater;
	public:
		/*
		* ���ܣ���������
		* ��������
		* ���أ���
		* ��������
		*/
		~ASTFloatNode();

	private:
		/*
		* ���ܣ����캯��
		* ��������
		* ���أ���
		* ��������
		*/
		ASTFloatNode();

	};
}

#endif
