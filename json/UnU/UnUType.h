
/*
* 描述：类型表示类
* 作者：xp
* 日期：2016-4-15
*/
#ifndef __UNU_TYPE__
#define __UNU_TYPE__

#include <map>

#include "UnUObject.h"

namespace UnU
{
	class UnUType : public UnUObject
	{
	public:
		/*
		* 功能：析构函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		~UnUType();

		/*
		* 功能：用于添加一种类型
		* 参数：string, 该类型的名称
		* 返回：UnUType* 类型
		* 描述：无
		*/
		static UnUType* addType(std::string typeName);

		/*
		* 功能：检测一种类型是否存在
		* 参数：string, 要检测的类型名称
		* 返回：bool，是否存在
		* 描述：无
		*/
		static bool isExit(std::string typeName);

		/*
		* 功能：检测一种类型是否存在
		* 参数：string, 要检测的类型名称
		* 返回：bool，是否存在
		* 描述：无
		*/
		static UnUType* find(std::string typeName);

		/*
		* 功能：输入方法
		* 参数：无
		* 返回：无
		* 描述：虚函数
		*/
		void print();

	private:
		/*
		* 功能：用来存放类型数据
		* 类型：std::map<std::string, UnUType*>
		* 描述：静态
		*/
		static std::map<std::string, UnUType*> __typeDict;

		/*
		* 功能：类形名称
		* 类型：std::string
		* 描述：称有，只读
		*/
		DEFINE_PROTECTED_READ_ONLY(std::string, __type, Type);
			
		/*
		* 功能：构造函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		UnUType(std::string typeName);

	};
}

#endif
