/*
* ��������ֵ������
* ���ߣ�xp
* ���ڣ�2016-4-15
*/
#ifndef __UNU_VALUE_MANAGER__
#define __UNU_VALUE_MANAGER__

#include <map>

#include "UnUBase.h"
#include "UnURecoverManager.h"

namespace UnU
{
	class UnUValueManager
	{
	public:
		/*
		* ���ܣ���������
		* ������std::string �������� std::string ��������
		* ���أ�UnUBase* ����ʵ��
		* ��������̬
		*/
		static UnUBase* create(std::string tokenName, std::string type);

		/*
		* ���ܣ���������
		* ������std::string �������� UnUBase* UnUʵ��
		* ���أ�UnUBase* ����ʵ��
		* ��������̬
		*/
		static UnUBase* create(std::string tokenName, UnUBase* base);

		/*
		* ���ܣ����ñ�������ʵ��֮��Ĺ�ϵ
		* ������std::string �������� UnUBase* �µ�UnUʵ��
		* ���أ�UnUBase* ���滻������
		* ��������̬
		*/
		static UnUBase* replace(std::string tokenName, UnUBase* base);

		/*
		* ���ܣ������ڴ����
		* ������Ҫ���յı�����
		* ���أ���
		* ��������̬
		*/
		static void remove(std::string tokenName);

		/*
		* ���ܣ�Ѱ��һ����ֵʵ��
		* ������std::string������ֵʵ���ı�����
		* ���أ�UnUBase*���ñ�������Ӧ����ֵʵ�� 
		* ��������̬
		*/
		static UnUBase* find(std::string tokenName);



	private:
		/*
		* ���ܣ������һ��ʵ�������֮���ӳ��
		* ������std::string�� ��������UnUBase*��ʵ��
		* ���أ���
		* ��������
		*/
		static void add(std::string tokenName, UnUBase * base);
		
		/*
		* ���ܣ��������б������Ͷ�Ӧʵ��֮���ӳ��
		* ���ͣ�std::map<std::string, UnUBase*>
		* ��������
		*/
		static std::map<std::string, UnUBase*> __valueDict;
	};
}

#endif
