/*
* ������Token��AST�ڵ�
* ���ߣ�xp
* ���ڣ�---
*/
#ifndef __AST_TOKEN_NODE__
#define __AST_TOKEN_NODE__

#include "../../Tools.h"
#include "ASTValueNode.h"

namespace UnUCompiler
{
	class ASTTokenNode : public ASTValueNode<std::string>
	{
		friend class ASTNodeCreater;
	private:
		/*
		* ���ܣ����캯��
		* ��������
		* ���أ���
		* ��������
		*/
		ASTTokenNode();

		/*
		* ���ܣ������д�ŵ�������ֵ
		* ���ͣ�std::String����ֵ���ַ������
		* ��������
		*/
		DEFINE_PROTECTED(std::string, _realValue, RealValue);

	public:
		/*
		* ���ܣ���������
		* ��������
		* ���أ���
		* ��������
		*/
		~ASTTokenNode();
	};
}

#endif
