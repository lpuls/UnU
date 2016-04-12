/*
* �����������ĳ����﷨�ڵ�
* ���ߣ�xp
* ���ڣ�2016-4-11
*/
#ifndef __AST_FUNCTION_NODE__
#define __AST_FUNCTION_NODE__

#include "ASTNode.h"
#include "../../Tools.h"
#include "ASTBodyNode.h" 
#include "ASTParamNode.h"
#include "ASTTokenNode.h"


namespace UnUCompiler
{
	class ASTFunctionNode : public ASTNode
	{
	private:
		/*
		* ���ܣ����캯��
		* ��������
		* ���أ���
		* ��������
		*/
		ASTFunctionNode ();

		/*
		* ���ܣ�������
		* ���ͣ�ASTTokenNode*
		* ��������
		*/
		DEFINE_PROTECTED(ASTTokenNode*, _funtion, Function);

		/*
		* ���ܣ������б�
		* ���ͣ���
		* ��������
		*/
		DEFINE_PROTECTED(ASTParamNode*, _params, Params);

		/*
		* ���ܣ�����������
		* ���ͣ�ASTBodyNode*
		* ��������
		*/
		DEFINE_PROTECTED(ASTBodyNode*, _body, Body);

	public:
		/*
		* ���ܣ���������
		* ��������
		* ���أ���
		* ��������
		*/
		~ASTFunctionNode ();

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
