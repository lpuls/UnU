
/*
* 描述：UnU字符串类型
* 作者：xp
* 日期：2016-4-18
*/
#ifndef __UNU_STRING__
#define __UNU_STRING__

#include <string>

#include "UnUValue.h"

namespace UnU
{
	class UnUString : public UnUValue<std::string>
	{
	public:
		/*
		* 功能：构造函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		UnUString(std::string value = "");

		/*
		* 功能：析构函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		~UnUString();

		/*
		* 功能：进行全局初始化
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		static void init();

		/*
		* 功能：获取一个浮点数
		* 参数：double, 要获取的整数的值
		* 返回：UnUFloat*， 得到的整数
		* 描述：静态
		*/
		static UnUString* createString(std::string value = 0);

		/*
		* 功能：加法
		* 参数：UnUValue*，要相加的值
		* 返回：UnUBase*，相加的结果
		* 描述：无
		*/
		UnUBase* calculate(std::string operatorType, UnUValue<std::string> *leftValue);
	private:

	};

}

#endif
