/*
* 描述：UnU的基类
* 作者：xp
* 日期：2016-4-15
*/
#ifndef __UNU_OBJECT__
#define __UNU_OBJECT__

#include "../Toolsets.h"

namespace UnU
{
	class UnUObject
	{
	public:
		/*
		* 功能：构造函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		UnUObject();

		/*
		* 功能：析构函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		~UnUObject();

		/*
		* 功能：输入方法
		* 参数：无
		* 返回：无
		* 描述：虚函数
		*/
		virtual void print();

		/*
		* 功能：复制方法
		* 参数：无
		* 返回：复制的结果
		* 描述：无
		*/
		virtual UnUObject* copy();

		/*
		* 功能：运行代码
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		virtual int run();

	protected:
		/*
		* 功能：用来指向上一层的节点
		* 类型：无
		* 描述：无
		*/
		DEFINE_PROTECTED(UnUObject*, _prament, Parent);

	private:

	};
}

#endif
