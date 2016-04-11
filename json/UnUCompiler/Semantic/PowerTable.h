/*
* 描述：符号权值表
* 作者：xp
* 日期：2016-4-10
*/
#ifndef __POWER_TABLE__
#define __POWER_TABLE__

#include <map>

namespace UnUCompiler
{
	class PowerTable
	{
	private:
		/*
		* 功能：记录词汇和权值的字典
		* 类型：std::map<std::string, int>
		* 描述：无
		*/
		static std::map<std::string, int> __powerTable;
	public:
		/*
		* 功能：无对应权值的标志
		* 类型：const int 
		* 描述：无
		*/
		static const int ERROR = -1;

		/*
		* 功能：初始化数据
		* 参数：无
		* 返回：是否初始化成功
		* 描述：无
		*/
		static bool init();

		/*
		* 功能：通过key值得到权值
		* 参数：std::string 关键字值
		* 返回：int 权值
		* 描述：无
		*/
		static int getPowerByKey(std::string key);

	};
}

#endif
