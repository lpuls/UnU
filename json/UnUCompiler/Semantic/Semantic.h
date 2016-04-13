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
#include "../Lex/Word.h"
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
		DEFINE_PRIVATE_READ_ONLY(std::stack<ASTNode*>, __operatorStack, OperatorStack);
		
		/*
		* ���ܣ���ֵջ
		* ���ͣ�std::stack<std::string>
		* ��������
		*/
		DEFINE_PRIVATE_READ_ONLY(std::stack<ASTNode*>, __valueStack, ValueStack);

		/*
		* ���ܣ����һ����ֵ�ڵ����ֵջ��
		* ������Word ��ֵ�ʻ�
		* ���أ�bool �Ƿ���ӳɹ�
		* ��������
		*/
		bool pushNodeIntoValueStack(Word word);

		/*
		* ���ܣ����һ�����̷��ڵ�������ջ��
		* ������Word ��ֵ�ʻ�
		* ���أ�bool �Ƿ���ӳɹ�
		* ��������
		*/
		bool pushNodeIntoOperatoreStack(Word word);

		/*
		* ���ܣ���Լ
		* ��������
		* ���أ�bool �Ƿ��Լ�ɹ�
		* ��������
		*/
		bool reduction();

		/*
		* ���ܣ��ϲ���ǰ�ڵ㵽Ŀ��ڵ������AST�ڵ�
		* ������std::string Ŀ��ڵ�����
		* ���أ�bool �Ƿ�ϲ��ɹ�
		* ��������
		*/
		std::vector<ASTNode*> getMergeList(std::string astType);

		/*
		* ���ܣ��Խڵ���࣬���ڵ�ϲ������ṹ
		* ��������
		* ���أ���
		* ��������
		*/
		void classification();
	};
}

#endif

