
/*
* ���������ͱ�ʾ��
* ���ߣ�xp
* ���ڣ�2016-4-15
*/
#ifndef __UNU_TYPE__
#define __UNU_TYPE__

#include <map>

#include "UnUObject.h"

namespace UnU
{
	class UnUType : public UnUObject
	{
	public:
		/*
		* ���ܣ���������
		* ��������
		* ���أ���
		* ��������
		*/
		~UnUType();

		/*
		* ���ܣ��������һ������
		* ������string, �����͵�����
		* ���أ�UnUType* ����
		* ��������
		*/
		static UnUType* addType(std::string typeName);

		/*
		* ���ܣ����һ�������Ƿ����
		* ������string, Ҫ������������
		* ���أ�bool���Ƿ����
		* ��������
		*/
		static bool isExit(std::string typeName);

		/*
		* ���ܣ����һ�������Ƿ����
		* ������string, Ҫ������������
		* ���أ�bool���Ƿ����
		* ��������
		*/
		static UnUType* find(std::string typeName);

		/*
		* ���ܣ����뷽��
		* ��������
		* ���أ���
		* �������麯��
		*/
		void print();

	private:
		/*
		* ���ܣ����������������
		* ���ͣ�std::map<std::string, UnUType*>
		* ��������̬
		*/
		static std::map<std::string, UnUType*> __typeDict;

		/*
		* ���ܣ���������
		* ���ͣ�std::string
		* ���������У�ֻ��
		*/
		DEFINE_PROTECTED_READ_ONLY(std::string, __type, Type);
			
		/*
		* ���ܣ����캯��
		* ��������
		* ���أ���
		* ��������
		*/
		UnUType(std::string typeName);

	};
}

#endif
