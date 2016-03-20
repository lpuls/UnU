/*
* 描述：文件读取类
* 作者：xp
* 日期：2016-2-28
*/
#ifndef __FILE_READER__
#define __FILE_READER__

#include <vector>


namespace XpLib
{
	class FileReader
	{
		// 仅对Toolsets（工具集）类开放
		friend class Toolsets;
	public:
	private:
		/*
		* 功能：读取文件并将每一行保存进一个列表中
		* 参数：文件路径
		* 返回：保存着每一行的列表
		* 描述：静态，私有，不可访问
		*/
		static std::vector<std::string> reader(std::string file);


	};
}

#endif
