/*
* �������ļ���ȡ��
* ���ߣ�xp
* ���ڣ�2016-2-28
*/
#ifndef __FILE_READER__
#define __FILE_READER__

#include <vector>


namespace XpLib
{
	class FileReader
	{
		// ����Toolsets�����߼����࿪��
		friend class Toolsets;
	public:
	private:
		/*
		* ���ܣ���ȡ�ļ�����ÿһ�б����һ���б���
		* �������ļ�·��
		* ���أ�������ÿһ�е��б�
		* ��������̬��˽�У����ɷ���
		*/
		static std::vector<std::string> reader(std::string file);


	};
}

#endif
