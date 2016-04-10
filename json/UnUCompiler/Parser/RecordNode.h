/*
* 描述：用来记录每一个节点的类型和相应的位置
* 作者：xp
* 日期：2016-4-10
*/
#ifndef __RECORD_NODE__
#define __RECORD_NODE__

#include <iostream>

#include "../../Toolsets.h"


namespace UnUCompiler
{
	class RecordNode
	{
	public:
		/*
		* 功能：构造函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		RecordNode();

		/*
		* 功能：析构函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		~RecordNode();

	private:
		/*
		* 功能：用来记录将要转换成什么类型的AST
		* 类型：std::string
		* 描述：无
		*/
		DEFINE_PRIVATE(std::string, __type, Type);

		/*
		* 功能：用来记录输入词汇的开始位置
		* 类型：int
		* 描述：无
		*/
		DEFINE_PRIVATE(int, __start, Start);

		/*
		* 功能：用来记录输入词汇的结束位置
		* 类型：int
		* 描述：无
		*/
		DEFINE_PRIVATE(int, __end, End);
	};
}

#endif
