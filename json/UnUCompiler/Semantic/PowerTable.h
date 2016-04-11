/*
* ����������Ȩֵ��
* ���ߣ�xp
* ���ڣ�2016-4-10
*/
#ifndef __POWER_TABLE__
#define __POWER_TABLE__

#include <map>

namespace UnUCompiler
{
	class PowerTable
	{
	private:
		/*
		* ���ܣ���¼�ʻ��Ȩֵ���ֵ�
		* ���ͣ�std::map<std::string, int>
		* ��������
		*/
		static std::map<std::string, int> __powerTable;
	public:
		/*
		* ���ܣ��޶�ӦȨֵ�ı�־
		* ���ͣ�const int 
		* ��������
		*/
		static const int ERROR = -1;

		/*
		* ���ܣ���ʼ������
		* ��������
		* ���أ��Ƿ��ʼ���ɹ�
		* ��������
		*/
		static bool init();

		/*
		* ���ܣ�ͨ��keyֵ�õ�Ȩֵ
		* ������std::string �ؼ���ֵ
		* ���أ�int Ȩֵ
		* ��������
		*/
		static int getPowerByKey(std::string key);

	};
}

#endif
