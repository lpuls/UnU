/*
* ������������¼ÿһ���ڵ�����ͺ���Ӧ��λ��
* ���ߣ�xp
* ���ڣ�2016-4-10
*/
#ifndef __RECORD_NODE__
#define __RECORD_NODE__

#include <iostream>

#include "../../Toolsets.h"


namespace UnUCompiler
{
	class RecordNode
	{
	public:
		/*
		* ���ܣ����캯��
		* ��������
		* ���أ���
		* ��������
		*/
		RecordNode();

		/*
		* ���ܣ���������
		* ��������
		* ���أ���
		* ��������
		*/
		~RecordNode();

	private:
		/*
		* ���ܣ�������¼��Ҫת����ʲô���͵�AST
		* ���ͣ�std::string
		* ��������
		*/
		DEFINE_PRIVATE(std::string, __type, Type);

		/*
		* ���ܣ�������¼����ʻ�Ŀ�ʼλ��
		* ���ͣ�int
		* ��������
		*/
		DEFINE_PRIVATE(int, __start, Start);

		/*
		* ���ܣ�������¼����ʻ�Ľ���λ��
		* ���ͣ�int
		* ��������
		*/
		DEFINE_PRIVATE(int, __end, End);
	};
}

#endif
