/*
* ������AST�ڵ㹤��
* ���ߣ�xp
* ���ڣ�2016-4-6
*/
#ifndef __AST_NODE_CREATER__
#define __AST_NODE_CREATER__

#include "ASTNode.h"

namespace UnUCompiler
{
	class ASTNodeCreater
	{
	public:
		/*
		* ���ܣ�����һ��AST�ڵ�
		* ������std::string �ʻ�, std::string �ʻ�ֵ
		* ���أ���
		* ��������
		*/
		static ASTNode* create(std::string word = "", std::string wordValue = "");
	};
}


#endif
