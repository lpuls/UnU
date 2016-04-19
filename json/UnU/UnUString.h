
/*
* ������UnU�ַ�������
* ���ߣ�xp
* ���ڣ�2016-4-18
*/
#ifndef __UNU_STRING__
#define __UNU_STRING__

#include <string>

#include "UnUValue.h"

namespace UnU
{
	class UnUString : public UnUValue<std::string>
	{
	public:
		/*
		* ���ܣ����캯��
		* ��������
		* ���أ���
		* ��������
		*/
		UnUString(std::string value = "");

		/*
		* ���ܣ���������
		* ��������
		* ���أ���
		* ��������
		*/
		~UnUString();

		/*
		* ���ܣ�����ȫ�ֳ�ʼ��
		* ��������
		* ���أ���
		* ��������
		*/
		static void init();

		/*
		* ���ܣ���ȡһ��������
		* ������double, Ҫ��ȡ��������ֵ
		* ���أ�UnUFloat*�� �õ�������
		* ��������̬
		*/
		static UnUString* createString(std::string value = 0);

		/*
		* ���ܣ��ӷ�
		* ������UnUValue*��Ҫ��ӵ�ֵ
		* ���أ�UnUBase*����ӵĽ��
		* ��������
		*/
		UnUBase* calculate(std::string operatorType, UnUValue<std::string> *leftValue);
	private:

	};

}

#endif
