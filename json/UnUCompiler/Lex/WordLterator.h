/*
* 描述：词汇迭代器
* 作者：xp
* 日期：2016-3-7
*/
#ifndef __WORD_LTERATOR__
#define __WORD_LTERATOR__

#include <vector>

#include "Word.h"


namespace UnUCompiler
{
	class WordIterator
	{
	private:
		/*
		* 功能：词汇列表
		* 类型：std::vector<Word>
		* 描述：无
		*/
		std::vector<Word*> __lterator;

	public:
		/*
		* 功能：构造函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		WordIterator();

		/*
		* 功能：析构函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		~WordIterator();

		/*
		* 功能：添加一个新词汇到尾部
		* 参数：Word*
		* 返回：无
		* 描述：无
		*/
		void push(Word* word);

		/*
		* 功能：获取词汇量
		* 参数：无
		* 返回：词汇数量
		* 描述：无
		*/
		unsigned total();

		/*
		* 功能：获取指定位置的词汇
		* 参数：指定位置
		* 返回：词汇
		* 描述：无
		*/
		Word* get(int index);

		/*
		* 功能：清理整个迭代器
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		void clear();
	};
}

#endif
