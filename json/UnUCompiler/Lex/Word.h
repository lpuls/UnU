/*
* 描述：单词类
* 作者：xp
* 日期：2016-3-7
*/
#ifndef __WORD__
#define __WORD__

#include <string>

#include "../../Tools.h"


namespace UnUCompiler
{
	class Word
	{
	private:
		/*
		* 功能：记录词汇
		* 类型：std::string
		* 描述：无
		*/
		DEFINE_PRIVATE(std::string, __word, Word);

		/*
		* 功能：记录词汇值
		* 类型：std::string
		* 描述：无
		*/
		DEFINE_PRIVATE(std::string, __wordValue, WordValue);
	public:
		/*
		* 功能：构造函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		Word();

		/*
		* 功能：构造函数
		* 参数：词汇内容，词汇值
		* 返回：无
		* 描述：无
		*/
		Word(std::string word, std::string value);

		/*
		* 功能：析构函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		~Word();


	};
}

#endif
