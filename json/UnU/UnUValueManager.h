/*
* 描述：数值管理器
* 作者：xp
* 日期：2016-4-15
*/
#ifndef __UNU_VALUE_MANAGER__
#define __UNU_VALUE_MANAGER__

#include <map>

#include "UnUBase.h"
#include "UnURecoverManager.h"

namespace UnU
{
	class UnUValueManager
	{
	public:
		/*
		* 功能：创建函数
		* 参数：std::string 变量名； std::string 变量类型
		* 返回：UnUBase* 变量实体
		* 描述：静态
		*/
		static UnUBase* create(std::string tokenName, std::string type);

		/*
		* 功能：创建函数
		* 参数：std::string 变量名； UnUBase* UnU实体
		* 返回：UnUBase* 变量实体
		* 描述：静态
		*/
		static UnUBase* create(std::string tokenName, UnUBase* base);

		/*
		* 功能：重置变量名与实例之间的关系
		* 参数：std::string 变量名； UnUBase* 新的UnU实体
		* 返回：UnUBase* 被替换下来的
		* 描述：静态
		*/
		static UnUBase* replace(std::string tokenName, UnUBase* base);

		/*
		* 功能：变量内存回收
		* 参数：要回收的变量名
		* 返回：无
		* 描述：静态
		*/
		static void remove(std::string tokenName);

		/*
		* 功能：寻找一个数值实例
		* 参数：std::string，该数值实例的变量名
		* 返回：UnUBase*，该变量名对应的数值实例 
		* 描述：静态
		*/
		static UnUBase* find(std::string tokenName);



	private:
		/*
		* 功能：在添加一对实体与变量之间的映射
		* 参数：std::string， 变量名；UnUBase*，实体
		* 返回：无
		* 描述：无
		*/
		static void add(std::string tokenName, UnUBase * base);
		
		/*
		* 功能：用来进行变量名和对应实体之间的映射
		* 类型：std::map<std::string, UnUBase*>
		* 描述：无
		*/
		static std::map<std::string, UnUBase*> __valueDict;
	};
}

#endif
