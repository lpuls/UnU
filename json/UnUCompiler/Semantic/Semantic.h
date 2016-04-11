/*
* ���������������
* ���ߣ�xp
* ���ڣ�2016-4-10
*/
#ifndef __SEMANTIC__
#define __SEMANTIC__

#include <stack>
#include <vector>

#include "PowerTable.h"
#include "../../Tools.h"
#include "../AST/ASTNode.h"
#include "../Lex/WordLterator.h"

namespace UnUCompiler
{
	class Semantic
	{
	public:
		/*
		* ���ܣ����캯��
		* ��������
		* ���أ���
		* ��������
		*/
		Semantic();

		/*
		* ���ܣ���������
		* ��������
		* ���أ���
		* ��������
		*/
		~Semantic();

		/*
		* ���ܣ������﷨����ջ
		* ������WordIterator�ʻ������
		* ���أ�ASTNode*
		* ��������
		*/
		ASTNode* analysis(WordIterator wordIterator);

	private:
		/*
		* ���ܣ�����ջ
		* ���ͣ�std::stack<std::string>
		* ��������
		*/
		DEFINE_PRIVATE_READ_ONLY(std::stack<std::string>, __operatorStack, OperatorStack);
		
		/*
		* ���ܣ���ֵջ
		* ���ͣ�std::stack<std::string>
		* ��������
		*/
		DEFINE_PRIVATE_READ_ONLY(std::stack<std::string>, __valueStack, ValueStack);
	};
}

#endif

