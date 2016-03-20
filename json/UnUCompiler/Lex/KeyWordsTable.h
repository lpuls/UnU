/*
* �������ؼ��ֱ�
* ���ߣ�xp
* ���ڣ�2016-3-3
*/
#ifndef __KEY_WORDS_TABLE__
#define __KEY_WORDS_TABLE__

#include <map>
#include <string>

#include "../UnUCompile.h"
#include "../../Toolsets.h"


namespace UnUCompiler
{
	class KeyWordsTable
	{
	private:
		/*
		* ���ܣ��ؼ�������ֵ��ӳ���
		* ���ͣ�std::map<std::string, std::string>
		* ��������
		*/
		std::map<std::string, std::string> __keyWordTable;

	public:
		/*
		* ���ܣ����캯��
		* �������ؼ��ֱ�·��
		* ���أ���
		* ��������
		*/
		KeyWordsTable(std::string path = keyWordPath);

		/*
		* ���ܣ���������
		* ��������
		* ���أ���
		* ��������
		*/
		~KeyWordsTable();

		/*
		* ���ܣ�ͨ���÷�����ȡ�ؼ��ֵ�ֵ
		* �������ؼ���
		* ���أ��ؼ��ֶ�Ӧ��ֵ
		* ��������
		*/
		std::string at(std::string keyWord);


	};
}

#endif
