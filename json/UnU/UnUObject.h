/*
* ������UnU�Ļ���
* ���ߣ�xp
* ���ڣ�2016-4-15
*/
#ifndef __UNU_OBJECT__
#define __UNU_OBJECT__

#include "../Toolsets.h"

namespace UnU
{
	class UnUObject
	{
	public:
		/*
		* ���ܣ����캯��
		* ��������
		* ���أ���
		* ��������
		*/
		UnUObject();

		/*
		* ���ܣ���������
		* ��������
		* ���أ���
		* ��������
		*/
		~UnUObject();

		/*
		* ���ܣ����뷽��
		* ��������
		* ���أ���
		* �������麯��
		*/
		void print();

		/*
		* ���ܣ����Ʒ���
		* ��������
		* ���أ����ƵĽ��
		* ��������
		*/
		UnUObject* copy();

	protected:
		/*
		* ���ܣ�����ָ����һ��Ľڵ�
		* ���ͣ���
		* ��������
		*/
		DEFINE_PROTECTED(UnUObject*, _prament, Parent);

	private:

	};
}

#endif
