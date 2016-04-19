/*
* �������ʷ�������
* ���ߣ�xp
* ���ڣ�2016-3-10
*/
#ifndef __LEX__
#define __LEX__

#include "Word.h"
#include "WordLterator.h"
#include "KeyWordsTable.h"
#include "../../Toolsets.h"
#include "../../FiniteState/StateMachine.h"

using namespace XpLib;


namespace UnUCompiler
{
	class Lex  : public StateMachine
	{
	private:

		/*
		* ���ܣ��ؼ��ֱ�
		* ���ͣ�KeyWordsTable
		* ��������ȫ˽�У��ⲿ���ɷ���
		*/
		KeyWordsTable __keyWordsTable;

		/*
		* ���ܣ���ǰ���������Ĵʻ�
		* ���ͣ�std::string
		* ������˽�У��ⲿ���ɷ���
		*/
		std::string __currentWord;

		/*
		* ���ܣ��ʻ������
		* ���ͣ�WordLterator
		* ������˽��
		*/
		DEFINE_PRIVATE_READ_ONLY(WordIterator, __iterator, WordIterator);

		/*
		* ���ܣ����캯��
		* ��������
		* ���أ���
		* ��������
		*/
		Lex(std::string path);

		/*
		* ���ܣ����캯��
		* ��������
		* ���أ���
		* ��������
		*/
		~Lex();

		/*
		* ���ܣ�����ʻ������
		* ��������
		* ���أ���
		* ��������
		*/
		void clearWordIterator();

	protected:
		/*
		* ���ܣ����붯��
		* ��������
		* ���أ���
		* ��������
		*/
		int entry__();

		/*
		* ���ܣ��˳�����
		* ��������
		* ���أ���
		* ��������
		*/
		int quit__();

	public:
	};

}

#endif
