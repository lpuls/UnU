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
		* �������������ⲿ���ɷ���
		*/
		State *_previousState;

		/*
		* ���ܣ������ֵ
		* ���ͣ�string
		* �������������ⲿ���ɷ���
		*/
		std::string _input;

		/*
		* ���ܣ���ǰ�������������б��е�λ��
		* ���ͣ�int
		* �������������ⲿ���ɷ���
		*/
		int _location;

		/*
		* ���ܣ������б�
		* ���ͣ�std::vector<std::string>
		* �������������ⲿ���ɷ���
		*/
		DEFINE_PROTECTED(std::vector<std::string>*, _inputList, InputList);

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
		* ���ܣ����붯��
		* ��������
		* ���أ���
		* ��������
		*/
	    virtual int entry__();

		/*
		* ���ܣ��˳�����
		* ��������
		* ���أ���
		* ��������
		*/
		virtual int quit__();
		
		/*
		* ���ܣ�ת�ƶ���
		* ��������
		* ���أ���
		* ��������
		*/
		virtual int transition__();

		/*
		* ���ܣ�����ָ��
		* ��������
		* ���أ���
		* ��������
		*/
		virtual int input_();

	public:
		/*
		* ���ܣ�������룬���ظ�ֵ��������
		* ���ͣ�const int
		* ��������
		*/
		const int ERROR = 0;

		/*
		* ���ܣ�������룬���ظ�ֵ��������
		* ���ͣ�const int
		* ��������
		*/
		const int CONTINUE = 1;

		/*
		* ���ܣ���ʾ�����б��ȡ��
		* ���ͣ�const
		* �����������޸ĵĳ���
		*/
		const int INPUT_OVER = 10;

		/*
		* ���ܣ���ʾ��ȡ��������
		* ���ͣ�const
		* �����������޸ĵĳ���
		*/
		const int INPUT_NORMAL = 11;

		/*
		* ���ܣ���ʾ�����б�Ϊ��
		* ���ͣ�const
		* �����������޸ĵĳ���
		*/
		const int INPUT_NULL = 12;

		/*
		* ���ܣ���ʾ�����б��ȡ���
		* ���ͣ�const
		* �����������޸ĵĳ���
		*/
		const int INPUT_OVERFLOW = 13;

		/*
		* ���ܣ�ת��״̬ʱ������
		* ���ͣ�const int
		* �����������޸ĵĳ���
		*/
		const int TRANSITION_NULL_INPUT = 21;

		/*
		* ���ܣ�ת��״̬ʱ������
		* ���ͣ�const int 
		* �����������޸ĵĳ���
		*/
		const int TRANSITION_NORMAL = 21;

		/*
		* ���ܣ�ת��״̬ʱ�Ĵ����޸������Ӧ��ת��
		* ���ͣ�const int
		* �����������޸ĵĳ���
		*/
		const int TRANSITION_ERROR = 22;

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
		bool run();

	};
}

#endif
