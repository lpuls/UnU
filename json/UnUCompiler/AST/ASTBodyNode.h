/*
* �������ṹ���ݵĽڵ�
* ���ߣ�xp
* ���ڣ�2016-4-11
*/
#ifndef __AST_BODY_NODE__
#define __AST_BODY_NODE__

#include <vector>

#include "ASTNode.h"
#include "../../Tools.h"


namespace UnUCompiler
{
	class ASTBodyNode : public ASTNode
	{
		friend class ASTNodeCreater;
	private:
		/*
		* ���ܣ����캯��
		* ��������
		* ���أ���
		* ��������
		*/
		ASTBodyNode();

	protected:
		/*
		* ���ܣ��ṹ�ڵ�����AST�ڵ��б�
		* ���ͣ�std::vector<ASTNode*>
		* ��������
		*/
		std::vector<ASTNode*> __children;

	public:
		/*
		* ���ܣ���������
		* ��������
		* ���أ���
		* ��������
		*/
		~ASTBodyNode();

		/*
		* ���ܣ����һ��AST�ڵ�
		* ������ASTNode*
		* ���أ���
		* ��������
		*/
		void addChild(ASTNode * child);

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
