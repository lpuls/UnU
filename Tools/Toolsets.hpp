/*
* ���������߼����������ֹ��ߵļ���
* ���ߣ�xp
* ���ڣ�2016-2-7
*/
#ifndef __TOOLSETS__
#define __TOOLSETS__

#include "Log/ToolLog.hpp"
#include "FileReader/FileReader.hpp"


namespace XpLib
{
	/*
	* ���ܣ����߼��࣬��һ�������ķ�ʽ���������еĹ��ߣ�ʹ���պ��޸Ĺ������Ľӿ�ʹ�����øı���ʹ�ù��Ĵ���
	* �����������࣬�ڳ�������ʱ�����ͷſռ��ķ�������֤�����ڴ�д©
	*/
	class Toolsets
	{
	private:
		/*
		* ���ܣ����߼��ĵ���
		* ���ͣ�Toolsets*
		* ����������������ͨ���ӿڻ�ȡ
		*/
		static Toolsets* __instance;

		/*
		* ���ܣ���־��
		* ���ͣ�ToolLog*
		* ������˽���Ҳ��ɷ��ʣ�ͨ��������װ����ʹ���ⲿ�ܵ����䷽��
		*/
		ToolLog* __log;
		
		/*
		* ���ܣ����캯��
		* ��������
		* ���أ���
		* ��������
		*/
		Toolsets();	

		/*
		* ���ܣ���������
		* ��������
		* ���أ���
		* ��������
		*/
		~Toolsets();

	public:
		/*
		* ���ܣ���ȡ����
		* ��������
		* ���أ�Toolsets���ĵ���
		* ��������
		*/
		static Toolsets* getInstance();

		/*
		* ���ܣ��ͷŵ������ڴ��ռ�
		* ��������
		* ���أ���
		* ��������
		*/
		static void releaseInstance();

		/*
		* ���ܣ����ӿ���
		* ������������������ֵ��Ĭ��Ϊ�棩
		* ���أ��Ƿ����ӳɹ�
		* ��������
		*/
		bool addSwitch(std::string switchName);

		/*
		* ���ܣ����ÿ���ֵ
		* ������������
		* ���أ���
		* ��������
		*/
		void setSwitch(std::string switchName, bool siwtchValue);

		/*
		* ���ܣ���ӡ��־
		* ������Ҫ��ӡ�Ľ�����������
		* ���أ���
		* ��������
		*/
		void log(std::string logValue, std::string switchName);

		/*
		* ���ܣ���intת��Ϊstring
		* ������Ҫת��������
		* ���أ�ת�����ַ���
		* ��������̬����
		*/
		static std::string intToStr(int value);

		/*
		* ���ܣ���stringת��Ϊint
		* ������Ҫת�����ַ���
		* ���أ�ת��������
		* ��������̬����
		*/
		static int strToInt(std::string value);

		/*
		* ���ܣ���doubleת��Ϊstring
		* ������Ҫת���ĸ�����
		* ���أ�ת�����ַ���
		* ��������̬����
		*/
		static std::string doubleToStr(double value);

		/*
		* ���ܣ���stringת��Ϊdouble
		* ������Ҫת�����ַ���
		* ���أ�ת���ĸ�����
		* ��������̬����
		*/
		static double strToDouble(std::string value);

		/*
		* ���ܣ�������ֵת��Ϊ�ַ���
		* ������Ҫת���Ĳ���ֵ
		* ���أ�ת�����ַ���
		* ��������̬����
		*/
		static std::string boolToStr(bool value);

		/*
		* ���ܣ���charתΪstring
		* ������Ҫת�����ַ�
		* ���أ�ת�����ַ���
		* ��������̬����
		*/
		static std::string charToStr(char value);

		/*
		* ���ܣ���ȡ�ļ�����ÿһ�б�����һ���б���
		* �������ļ�·��
		* ���أ�������ÿһ�е��б�
		* ��������̬��˽�У����ɷ���
		*/
		static std::vector<std::string> reader(std::string file);
	};
}

#endif
