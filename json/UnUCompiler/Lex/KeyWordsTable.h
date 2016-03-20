/*
* 描述：关键字表
* 作者：xp
* 日期：2016-3-3
*/
#ifndef __KEY_WORDS_TABLE__
#define __KEY_WORDS_TABLE__

#include <map>
#include <string>

#include "../UnUCompile.h"
#include "../../Toolsets.h"


namespace UnUCompiler
{
	class KeyWordsTable
	{
	private:
		/*
		* 功能：关键字与其值的映射表
		* 类型：std::map<std::string, std::string>
		* 描述：无
		*/
		std::map<std::string, std::string> __keyWordTable;

	public:
		/*
		* 功能：构造函数
		* 参数：关键字表路径
		* 返回：无
		* 描述：无
		*/
		KeyWordsTable(std::string path = keyWordPath);

		/*
		* 功能：析构函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		~KeyWordsTable();

		/*
		* 功能：通过该方法获取关键字的值
		* 参数：关键字
		* 返回：关键字对应的值
		* 描述：无
		*/
		std::string at(std::string keyWord);


	};
}

#endif
