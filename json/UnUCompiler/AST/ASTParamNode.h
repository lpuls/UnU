/*
* �����������ڵ�
* ���ߣ�xp
* ���ڣ�---
*/
#ifndef __AST_PARAM_NODE__
#define __AST_PARAM_NODE__

#include <vector>

#include "ASTNode.h"
#include "../../Tools.h"
#include "ASTTokenNode.h"


namespace UnUCompiler
{
	class ASTParamNode : public ASTNode
	{
	private:
		/*
		* ���ܣ����캯��
		* ��������
		* ���أ���
		* ��������
		*/
		ASTParamNode();

		/*
		* ���ܣ������б�
		* ���ͣ���
		* ��������
		*/
		std::vector<ASTTokenNode*> __params;

	public:
		/*
		* ���ܣ���������
		* ��������
		* ���أ���
		* ��������
		*/
		~ASTParamNode();

		/*
		* ���ܣ����һ�������������б���
		* ������ASTTokenNode*
		* ���أ���
		* ��������
		*/
		void addParam(ASTTokenNode* param);

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
