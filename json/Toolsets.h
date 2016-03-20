/*
* 描述：工具集，包括多种工具的集合
* 作者：xp
* 日期：2016-2-7
*/
#ifndef __TOOLSETS__
#define __TOOLSETS__

#include "Log\ToolLog.h"
#include "FileReader\FileReader.h"


namespace XpLib
{
	/*
	* 功能：工具集类，以一个单例的方式包含着所有的工具，使得日后修改工具类的接口使而不用改变其使用过的代码
	* 描述：单例类，在程序结束时调用释放空间的方法来保证不会内存写漏
	*/
	class Toolsets
	{
	private:
		/*
		* 功能：工具集的单例
		* 类型：Toolsets*
		* 描述：单例，仅可通过接口获取
		*/
		static Toolsets* __instance;

		/*
		* 功能：日志类
		* 类型：ToolLog*
		* 描述：私有且不可访问，通过该类封装方法使得外部能调用其方法
		*/
		ToolLog* __log;
		
		/*
		* 功能：构造函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		Toolsets();	

		/*
		* 功能：析构函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		~Toolsets();

	public:
		/*
		* 功能：获取单例
		* 参数：无
		* 返回：Toolsets类的单例
		* 描述：无
		*/
		static Toolsets* getInstance();

		/*
		* 功能：释放单例的内存空间
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		static void releaseInstance();

		/*
		* 功能：添加开关
		* 参数：开关名。开关值（默认为真）
		* 返回：是否添加成功
		* 描述：无
		*/
		bool addSwitch(std::string switchName);

		/*
		* 功能：设置开关值
		* 参数：开关名
		* 返回：无
		* 描述：无
		*/
		void setSwitch(std::string switchName, bool siwtchValue);

		/*
		* 功能：打印日志
		* 参数：要打印的结果，开关名
		* 返回：无
		* 描述：无
		*/
		void log(std::string logValue, std::string switchName);

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
