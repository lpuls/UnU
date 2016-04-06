/*
* �������﷨������
* ���ߣ�xp
* ���ڣ�2016-4-6
*/
#ifndef __PARSER__
#define __PARSER__

#include <iostream>

#include "../../FiniteState/StateMachine.h"

using namespace XpLib;

namespace UnUCompiler
{
	class Parser : public StateMachine
	{
	private:
		/*
		* ���ܣ��ʻ������
		* ���ͣ�WordIterator
		* ��������
		*/
		std::vector<std::string> __wordIterator;

	public:
		/*
		* ���ܣ�������룬���ظ�ֵ��������
		* ���ͣ�const int
		* ���������벻����
		*/
		const int CODE_INCOMPLETE = 50;

		/*
		* ���ܣ����캯��
		* ������string��״̬��·��
		* ���أ���
		* ��������
		*/
		Parser(std::string path);

		/*
		* ���ܣ���������
		* ������string��״̬��·��
		* ���أ���
		* ��������
		*/
		~Parser();

		/*
		* ���ܣ����ôʻ��б�
		* �������ʻ��б�
		* ���أ���
		* ��������
		*/
		void setWordIterator(std::vector<std::string> wordIterator);

		/*
		* ���ܣ����дʷ�������
		* ��������
		* ���أ����н���Ĵ���
		* ��������д�����run����
		*/
		int run();

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

	};
}

#endif
