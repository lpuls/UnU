/*
* ��������������
* ���ߣ�xp
* ���ڣ�2016-4-15
*/
#ifndef __UNU_RECOVER__
#define __UNU_RECOVER__

#include "../Toolsets.h"

#include "UnUObject.h"


namespace UnU
{
	class UnURecover : public UnUObject
	{
	public:
		/*
		* ���ܣ����캯��
		* ��������
		* ���أ���
		* ��������
		*/
		UnURecover();

		/*
		* ���ܣ���������
		* ��������
		* ���أ���
		* ��������
		*/
		~UnURecover();

		/*
		* ���ܣ����һ������
		* ��������
		* ���أ���
		* ��������
		*/
		void addQuote();

		/*
		* ���ܣ�����һ������
		* ��������
		* ���أ�bool�������Ƿ�Ϊ��
		* ��������
		*/
		bool removeQuote();

	private:
		/*
		* ���ܣ�����ָ����֮�󶨵�����
		* ���ͣ�UnUObject*��Ҫ��֮�󶨵�Unʵ��
		* ��������
		*/
		DEFINE_PRIVATE_READ_ONLY(UnUObject*, __ptr, Ptr);

		/*
		* ���ܣ���ʾָ���ʵ���ĸ���
		* ���ͣ�int�� ָ���ʵ����ָ����
		* ����������ֵΪ�㣬������__ptr
		*/
		DEFINE_PRIVATE_READ_ONLY(int, __quote, Quote);
	};
}

#endif
