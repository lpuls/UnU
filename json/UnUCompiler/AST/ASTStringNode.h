/*
* �������ַ���AST�ڵ�
* ���ߣ�xp
* ���ڣ�2016-4-11
*/
#ifndef __AST_STRING_NODE__
#define __AST_STRING_NODE__

#include "ASTValueNode.h"


namespace UnUCompiler
{
	class ASTStringNode : public ASTValueNode<std::string>
	{
		friend class ASTNodeCreater;
	public:
		/*
		* ���ܣ���������
		* ��������
		* ���أ���
		* ��������
		*/
		~ASTStringNode();

	private:
		/*
		* ���ܣ����캯��
		* ��������
		* ���أ���
		* ��������
		*/
		ASTStringNode();

	};
}

#endif
