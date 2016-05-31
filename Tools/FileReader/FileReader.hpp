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
		friend class Toolsets;
	public:
	private:
		static std::vector<std::string> reader(std::string file);


	};
}

#endif
