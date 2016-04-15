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
#include "../AST/ASTBodyNode.h"
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
		* ���ܣ�������ʶ�ϲ����
		* ���ͣ�const int
		* �������ɹ���������һ��
		*/
		const int CONTINUE = -1;

		/*
		* ���ܣ�������ʶ�ϲ����
		* ���ͣ�const int
		* ���������β��ϲ�������
		*/
		const int SKIP = 1;

		/*
		* ���ܣ�������ʶ�ϲ����
		* ���ͣ�const int
		* ���������β����κβ���
		*/
		const int DO_NOTHING = 1;

		/*
		* ���ܣ�������ʶ�ϲ����
		* ���ͣ�const int
		* ������ʧ��
		*/
		const int FAILED = 2;

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
		* ���ܣ����һ���������ڵ��ջ��
		* ������Word ��ֵ�ʻ�
		* ���أ�bool �Ƿ���ӳɹ�
		* ��������
		*/
		bool pushNodeIntoOperatorStack__(Word word);

		/*
		* ���ܣ����һ����ֵ�ڵ����ֵջ��
		* ������Word ��ֵ�ʻ�
		* ���أ�bool �Ƿ���ӳɹ�
		* ��������
		*/
		bool pushNodeIntoValueStack__(Word word);

		/*
		* ���ܣ�������AST�ڵ�ϲ�����
		* ������Word �ʻ�
		* ���أ����ϲ��ɵ�Body�ڵ�
		* ��������
		*/
		int merge(Word word);

		/*
		* ���ܣ���Լ
		* ������Word �ʻ�
		* ���أ���
		* ��������
		*/
		int reduction(Word word);

		/*
		* ���ܣ�����ڵ�
		* ������Word ��ȡ��������ڵ�
		* ���أ���
		* ����������ƥ������
		*/
		void specialBracket(Word word);

		/*
		* ���ܣ�����������ص����ݽ��м���
		* ������ASTNode Ҫ����Ĳ������ڵ�
		* ���أ�ASTNode �������Ľڵ�
		* ��������
		*/
		ASTNode* calculation(ASTNode *node);
	};
}

#endif

