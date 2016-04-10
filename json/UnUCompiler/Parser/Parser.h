/*
* �������﷨������
* ���ߣ�xp
* ���ڣ�2016-4-6
*/
#ifndef __PARSER__
#define __PARSER__

#include <stack>
#include <iostream>

#include "RecordNode.h"
#include "../../FiniteState/StateMachine.h"

using namespace XpLib;

namespace UnUCompiler
{
	class Parser : public StateMachine
	{
	private:
		/*
		* ���ܣ�����ƥ��ʧ��
		* ���ͣ�const int
		* ���������ɷ��ʣ�����
		*/
		const int FAILED = -1;

		/*
		* ���ܣ�������ŵ�ջ��
		* ���ͣ�const int
		* ���������ɷ��ʣ�����
		*/
		const int ADD = 0;

		/*
		* ���ܣ��ɹ�
		* ���ͣ�const int
		* ���������ɷ��ʣ�����
		*/
		const int SUCCESS = 1;

		/*
		* ���ܣ�������¼��ǰ���﷨�ڵ�
		* ���ͣ�RecordNode
		* ��������
		*/
		RecordNode __recordNode;

		/*
		* ���ܣ��ʻ������
		* ���ͣ�WordIterator
		* ��������
		*/
		std::vector<std::string> __wordIterator;

		/*
		* ���ܣ���¼����
		* ���ͣ�std::stack<std::string>
		* ��������
		*/
		std::stack<std::string> __brackets;

		/*
		* ���ܣ���¼�ź�
		* ���ͣ�std::stack<RecordNode>
		* ��������
		*/
		DEFINE_PRIVATE_READ_ONLY(std::vector<RecordNode>, __sign, Sign);

		/*
		* ���ܣ�����ƥ��
		* ������std::string ����
		* ���أ�int�������-1��ʧ�ܣ� 0����ӣ� 1���ɹ���
		* �������ⲿ���ɷ���
		*/
		int matchBrackets__(std::string brackets);

	public:
		/*
		* ���ܣ�������룬���ظ�ֵ��������
		* ���ͣ�const int
		* ���������벻����
		*/
		const int CODE_INCOMPLETE = 50;

		/*
		* ���ܣ�������룬���ظ�ֵ��������
		* ���ͣ�const int
		* ����������ƥ��ʧ��
		*/
		const int BRACKETS_MATCH_ERROR = 51;

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
