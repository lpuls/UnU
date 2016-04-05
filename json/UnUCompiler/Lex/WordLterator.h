/*
* �������ʻ������
* ���ߣ�xp
* ���ڣ�2016-3-7
*/
#ifndef __WORD_LTERATOR__
#define __WORD_LTERATOR__

#include <vector>

#include "Word.h"


namespace UnUCompiler
{
	class WordIterator
	{
	private:
		/*
		* ���ܣ��ʻ��б�
		* ���ͣ�std::vector<Word>
		* ��������
		*/
		std::vector<Word*> __lterator;

	public:
		/*
		* ���ܣ����캯��
		* ��������
		* ���أ���
		* ��������
		*/
		WordIterator();

		/*
		* ���ܣ���������
		* ��������
		* ���أ���
		* ��������
		*/
		~WordIterator();

		/*
		* ���ܣ����һ���´ʻ㵽β��
		* ������Word*
		* ���أ���
		* ��������
		*/
		void push(Word* word);

		/*
		* ���ܣ���ȡ�ʻ���
		* ��������
		* ���أ��ʻ�����
		* ��������
		*/
		unsigned total();

		/*
		* ���ܣ���ȡָ��λ�õĴʻ�
		* ������ָ��λ��
		* ���أ��ʻ�
		* ��������
		*/
		Word* get(int index);

		/*
		* ���ܣ���������������
		* ��������
		* ���أ���
		* ��������
		*/
		void clear();
	};
}

#endif
