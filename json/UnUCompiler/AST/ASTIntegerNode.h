/*
* ��������������
* ���ߣ�xp
* ���ڣ�2016-4-6
*/
#ifndef __AST_INTEGER_NODE__
#define __AST_INTEGER_NODE__

#include "ASTValueNode.h" 

namespace UnUCompiler
{
	class ASTIntegerNode : public ASTValueNode<long long int>
	{
		friend class ASTNodeCreater;
	public:	
		/*
		* ���ܣ���������
		* ��������
		* ���أ���
		* ��������
		*/
		~ASTIntegerNode();

	private:
		/*
		* ���ܣ����캯��
		* ��������
		* ���أ���
		* ��������
		*/
		ASTIntegerNode();
	};
}

#endif
