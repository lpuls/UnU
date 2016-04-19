
/*
* ������UnU������
* ���ߣ�xp
* ���ڣ�2016-4-17
*/
#ifndef __UNU_FLOAT__
#define __UNU_FLOAT__

#include "UnUValue.h"

namespace UnU
{
	class UnUFloat : public UnUValue<double>
	{
		friend class UnUValueManager;
	public:
		/*
		* ���ܣ����캯����
		* ������double�� ��������ֵ
		* ���أ���
		* ��������
		*/
		UnUFloat(double value = 0);

		/*
		* ���ܣ���������
		* ��������
		* ���أ���
		* ��������
		*/
		~UnUFloat();

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
		static UnUFloat* createFloat(double value = 0);

		/*
		* ���ܣ��ӷ�
		* ������UnUValue*��Ҫ��ӵ�ֵ
		* ���أ�UnUBase*����ӵĽ��
		* ��������
		*/
		UnUBase* calculate(std::string operatorType, UnUValue<double> *leftValue);

	private:

	};
}

#endif
