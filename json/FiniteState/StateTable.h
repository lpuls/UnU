/*
* ������״̬ת�Ʊ�
* ���ߣ�xp
* ���ڣ�2016-2-28
*/
#ifndef __STATE_TABLE__
#define __STATE_TABLE__

#include "State.h"
#include "../Tools.h"


namespace XpLib
{
	enum TransitionType
	{
		One = 0,
		Limit = 1,
		Continue = 2
	};

	class StateTable
	{
	private:
		/*
		* ���ܣ��ñ�������
		* ���ͣ�std::string
		* ����������Ψһ��ʶһ�ű�
		*/
		DEFINE_PRIVATE(std::string, __tableName, TableName);

		/*
		* ���ܣ���ʾ��ʼ״̬
		* ���ͣ�State*
		* ��������
		*/
		DEFINE_PRIVATE(State*, __starState, StarState);

		/*
		* ���ܣ�״̬ת�Ʊ�
		* ���ͣ�std::map<std::string, State*>
		* �������ⲿֻ��ͨ���ӿڸ���״̬���õ���Ӧ��״̬
		*/
		std::map<std::string, State*> __stateTable;

	public:
		/*
		* ���ܣ����캯��
		* ������״̬ת�Ʊ��·��
		* ���أ���
		* ��������
		*/
		StateTable(std::string tablePath);

		/*
		* ���ܣ���������
		* ��������
		* ���أ���
		* ��������
		*/
		~StateTable();

		/*
		* ���ܣ�[]��������װ
		* ������״̬����
		* ���أ�״̬
		* ��������
		*/
		State* operator[](std::string stateName);


	};
}

#endif
