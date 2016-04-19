/*
* 描述：垃圾回收
* 作者：xp
* 日期：2016-4-15
*/
#ifndef __UNU_RECOVER__
#define __UNU_RECOVER__

#include "../Toolsets.h"

#include "UnUObject.h"


namespace UnU
{
	class UnURecover : public UnUObject
	{
	public:
		/*
		* 功能：构造函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		UnURecover();

		/*
		* 功能：析构函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		~UnURecover();

		/*
		* 功能：添加一次引用
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		void addQuote();

		/*
		* 功能：减少一次引用
		* 参数：无
		* 返回：bool，引用是否为零
		* 描述：无
		*/
		bool removeQuote();

	private:
		/*
		* 功能：用来指向与之绑定的数据
		* 类型：UnUObject*，要与之绑定的Un实例
		* 描述：无
		*/
		DEFINE_PRIVATE_READ_ONLY(UnUObject*, __ptr, Ptr);

		/*
		* 功能：表示指向该实例的个数
		* 类型：int， 指向该实例的指针数
		* 描述：当该值为零，则消销__ptr
		*/
		DEFINE_PRIVATE_READ_ONLY(int, __quote, Quote);
	};
}

#endif
