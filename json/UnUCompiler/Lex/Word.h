/*
* ������������
* ���ߣ�xp
* ���ڣ�2016-3-7
*/
#ifndef __WORD__
#define __WORD__

#include <string>

#include "../../Tools.h"


namespace UnUCompiler
{
	class Word
	{
	private:
		/*
		* ���ܣ���¼�ʻ�
		* ���ͣ�std::string
		* ��������
		*/
		DEFINE_PRIVATE(std::string, __word, Word);

		/*
		* ���ܣ���¼�ʻ�ֵ
		* ���ͣ�std::string
		* ��������
		*/
		DEFINE_PRIVATE(std::string, __wordValue, WordValue);
	public:
		/*
		* ���ܣ����캯��
		* ��������
		* ���أ���
		* ��������
		*/
		Word();

		/*
		* ���ܣ����캯��
		* �������ʻ����ݣ��ʻ�ֵ
		* ���أ���
		* ��������
		*/
		Word(std::string word, std::string value);

		/*
		* ���ܣ���������
		* ��������
		* ���أ���
		* ��������
		*/
		~Word();


	};
}

#endif
