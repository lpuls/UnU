/*
* 描述：类型转换类
* 作者：xp
* 日期：2016-2-6
*/
#ifndef __TYPE_CONVERSION__
#define __TYPE_CONVERSION__

#include <iostream>

#include "../Tools.h"


namespace XpLib
{
	/*
	* 功能：类型转换类，用于类型的转换
	* 描述：完全私有，仅对工具集类进行开放
	*/
	class TypeConversion
	{
		// 仅对Toolsets（工具集）类开放
		friend class Toolsets;
	public:
	private:
		/*
		* 功能：将int转换为string
		* 参数：要转换的整数
		* 返回：转换的字符串
		* 描述：静态方法
		*/
		static std::string intToStr(int value);

		/*
		* 功能：将string转换为int
		* 参数：要转换的字符串
		* 返回：转换的整数
		* 描述：静态方法
		*/
		static int strToInt(std::string value);

		/*
		* 功能：将double转换为string
		* 参数：要转换的浮点数
		* 返回：转换的字符串
		* 描述：静态方法
		*/
		static std::string doubleToStr(double value);

		/*
		* 功能：将string转换为double
		* 参数：要转换的字符串
		* 返回：转换的浮点数
		* 描述：静态方法
		*/
		static double strToDouble(std::string value);

		/*
		* 功能：将布尔值转换为字符串
		* 参数：要转换的布尔值
		* 返回：转换的字符串
		* 描述：静态方法
		*/
		static std::string boolToStr(bool value);

		/*
		* 功能：将char转为string
		* 参数：要转换的字符
		* 返回：转换的字符串
		* 描述：静态方法
		*/
		static std::string charToStr(char value);

	};
}


#endif
