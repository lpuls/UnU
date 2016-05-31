/*
* ������LOG�࣬�ṩ������ӡ������˽�У�����Tool����Ԫ
* ���ߣ�xp
* ���ڣ�2016-2-6
*/
#ifndef __TOOL_LOG__
#define __TOOL_LOG__

#include <map>

#include "../Tools.hpp"


namespace XpLib
{
	/*
	* ���ܣ����������࣬����������������ת������
	* ��������ȫ˽�У����Թ�����Tool�࿪��
	*/
	class ToolLog
	{
		// ����Toolsets�����߼����࿪��
		friend class Toolsets;
	private:
		/*
		* ���ܣ�������¼ĳЩֵ�Ƿ�����
		* ���ͣ�std::map<string, bool>
		* ��������
		*/
		std::map<std::string, bool> __switchMap;
		
		/*
		* ���ܣ����캯��
		* ��������
		* ���أ���
		* ��������
		*/
		ToolLog();

		/*
		* ���ܣ���������
		* ��������
		* ���أ���
		* ��������
		*/
		~ToolLog() = default;

		/*
		* ���ܣ����ӿ���
		* ������������,����ֵ��Ĭ��Ϊ�棩
		* ���أ��Ƿ��ɹ�����
		* ���������ӳɹ���Ĭ��ֵΪ������������ʧ����˵������
		*/
		bool addSwitch(std::string switchName);

		/*
		* ���ܣ���������ֵ
		* ������������������ֵ
		* ���أ���
		* ������ͨ�����������ÿ��ص�ֵ
		*/
		void setSwitch(std::string switchName, bool switchValue);

		/*
		* ���ܣ���ӡ��־
		* ��������ӡ������������
		* ���أ���
		* ���������ǿ���ֵΪ����������ӡ�����䣬���򲻴�ӡ
		*/
		void log(std::string logValue, std::string switchName);

	public:

	};
}

#endif
