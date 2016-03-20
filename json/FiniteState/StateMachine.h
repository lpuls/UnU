/*
* �����������Զ�״̬����
* ���ߣ�xp
* ���ڣ�2016-2-29
*/
#ifndef __STATE_MACHINE__
#define __STATE_MACHINE__

#include <iostream>
#include <functional>

#include "StateTable.h"
#include "../Toolsets.h"


namespace XpLib
{
	class StateMachine
	{
	protected:
		/*
		* ���ܣ���¼ǰһ��״̬��ֵ
		* ���ͣ�State*
		* �������ⲿ���ɷ���
		*/
		State *_previousState;

		/*
		* ���ܣ�״̬ת�Ʊ�
		* ���ͣ�StateTable*
		* ������ֻ��
		*/
		DEFINE_PROTECTED_READ_ONLY(StateTable*, _stateTable, StateTable);

		/*
		* ���ܣ���ǰ״̬
		* ���ͣ�State*
		* ������ֻ��
		*/
		DEFINE_PROTECTED_READ_ONLY(State*, _current, Current);

		/*
		* ���ܣ�������ʾת��״̬
		* ���ͣ�int
		* ����������״̬
		*/
		static const int ERROR = 0;

		/*
		* ���ܣ�������ʾת��״̬
		* ���ͣ�int
		* ����������״̬
		*/
		static const int NEXT = 1;
		
		/*
		* ���ܣ�������ʾת��״̬
		* ���ͣ�int
		* ����������״̬
		*/
		static const int ENTRY = 2;

		/*
		* ���ܣ�������ʾת��״̬
		* ���ͣ�int
		* �������˳�״̬
		*/
		static const int QUIT = 3;

		/*
		* ���ܣ�������ʾת��״̬
		* ���ͣ�int
		* ������ת��״̬
		*/
		static const int TRANSITION = 4;

		/*
		* ���ܣ��ڽ��붯��ʱ������¼�
		* ����������ֵ,���е�״̬��
		* ���أ����н��
		* ��������δ���ã����ʼΪ��
		*/
		virtual int _entryEvent(std::string input);

		/*
		* ���ܣ����˳�����ʱ������¼�
		* ����������ֵ�� ���е�״̬��
		* ���أ����н��
		* ��������δ���ã����ʼΪ��
		*/
		virtual int _quitEvent(std::string input);

		/*
		* ���ܣ���ת�ƶ���ʱ������¼�
		* ����������ֵ�� ���е�״̬��
		* ���أ����н��
		* ��������δ���ã����ʼΪ��
		*/
		virtual int _transitionEvent(std::string input);

	private:

		/*
		* ���ܣ����붯��
		* ����������
		* ���أ���
		* ��������
		*/
	    int entry__(std::string input);

		/*
		* ���ܣ��˳�����
		* ����������
		* ���أ���
		* ��������
		*/
		int quit__(std::string input);
		
		/*
		* ���ܣ�ת�ƶ���
		* ����������
		* ���أ���
		* ��������
		*/
		int transition__(std::string input);

	public:


		/*
		* ���ܣ����캯��
		* ������״̬����ļ�·��
		* ���أ���
		* ��������
		*/
		StateMachine(std::string path);

		/*
		* ���ܣ���������
		* ��������
		* ���أ���
		* ��������
		*/
		~StateMachine();

		/*
		* ���ܣ�����״̬ת�Ʒ���
		* ������std::vector<char>
		* ���أ��Ƿ����״̬ת��
		* ��������
		*/
		bool run(std::vector<std::string> inputList);

	};
}

#endif
