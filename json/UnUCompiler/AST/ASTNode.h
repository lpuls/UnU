/*
* ������AST�����﷨���Ļ���
* ���ߣ�xp
* ���ڣ�2016-4-6
*/
#ifndef __AST_NODE__
#define __AST_NODE__

#include <iostream>

#include "../../Tools.h"
#include "../UnUCompile.h"


namespace UnUCompiler
{
	class ASTNode
	{
		friend class ASTNodeCreater;
	public:
		/*
		* ���ܣ���������
		* ��������
		* ���أ���
		* ��������
		*/
		~ASTNode();

		/*
		* ���ܣ���鷽��
		* ��������
		* ���أ�int�������
		* �������鷽�����������ÿһ���ڵ�������Ƿ���ȷ
		*/
		virtual int check();

	protected:
		/*
		* ���ܣ�ָ�򸸽ڵ��ָ�룬��Ҫ����ָ��ASTBodyNode
		* ���ͣ�ASTNode*
		* ��������
		*/
		DEFINE_PROTECTED(ASTNode*, _parent, Parent);

		/*
		* ���ܣ����캯��
		* ��������
		* ���أ���
		* ��������
		*/
		ASTNode();

		/*
		* ���ܣ�������¼������ʲô�ڵ�
		* ���ͣ�std::string
		* ��������
		*/
		DEFINE_PROTECTED(std::string, _valueType, ValueType);
	};
}

#endif
