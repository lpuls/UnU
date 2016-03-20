/*
* ������״̬ת�Ʊ��е�״̬
* ���ߣ�xp
* ���ڣ�2016-2-28
*/
#ifndef __STATE__
#define __STATE__

#include <map>
#include <vector>
#include <iostream>

#include "../Tools.h"
#include "../Toolsets.h"

namespace XpLib
{
	class State
	{
	private:
		/*
		* ���ܣ�״̬���ֵ䣬ÿһ��״̬���Ӧһ���б��б��м�¼�Ÿ�״̬���е�����״̬
		* ���ͣ�std::map<std::string, std::vector<std::string>>
		* ��������
		*/
		static std::map<std::string, std::vector<State*>> __stateBelong;

		/*
		* ���ܣ���״̬�ڶ�Ӧ�������µ�״̬ת��
		* ���ͣ�std::map<std::string, State*>
		* ��������
		*/
		std::map<std::string, State*> __transition;

		/*
		* ���ܣ�״̬���ƣ�ÿһ��״̬��Ψһ��ʶ��
		* ���ͣ�std::string
		* ��������
		*/
		DEFINE_PRIVATE(std::string, __state, State);

		/*
		* ���ܣ�����״̬����״̬��������һ��״̬��
		* ���ͣ�std::string
		* ������ÿһ��״̬�������״̬Ψһ
		*/
		DEFINE_PRIVATE(std::string, __belong, Belong);

		/*
		* ���ܣ����캯��
		* ��������
		* ���أ���
		* ��������
		*/
		State();

		/*
		* ���ܣ����캯��
		* ������״̬����,״̬�������
		* ���أ���
		* ��������
		*/
		State(std::string stateName, std::string belong);

		/*
		* ���ܣ���������
		* ��������
		* ���أ���
		* ��������
		*/
		~State();

	public:
		/*
		* ���ܣ�����״̬�Ĺ�������
		* ������״̬���ƣ�״̬������
		* ���أ�State*
		* ��������̬
		*/
		static State* create(std::string stateName, std::string belong);

		/*
		* ���ܣ���״̬���ֵ��У���������״̬ת�Ʊ������ȡ����Ӧ��״̬
		* ������״̬���ƣ�״̬������
		* ���أ�State*
		* ��������̬
		*/
		static State* getStateByBelongAndName(std::string state, std::string belong);

		/*
		* ���ܣ����һ��״̬ת�ƹ�ϵ
		* ���������룬ת��״̬
		* ���أ��Ƿ���ӳɹ�(bool)
		* ��������
		*/
		bool addState(std::string input, State *state);

		/*
		* ���ܣ�ͨ������õ���״̬
		* ����������ֵ
		* ���أ�״̬
		* ��������
		*/
		State* getStateByInput(std::string input);

		/*
		* ���ܣ��õ�״̬ת�Ƹ���
		* ��������
		* ���أ�״̬ת�Ƶĸ���(int)
		* ��������
		*/
		int getTransitionTotal();

	};
}

#endif
