/*
* 描述：状态转移表中的状态
* 作者：xp
* 日期：2016-2-28
*/
#ifndef __STATE__
#define __STATE__

#include <map>
#include <vector>
#include <iostream>

#include "../Tools.h"
#include "../Toolsets.h"

namespace XpLib
{
	class State
	{
	private:
		/*
		* 功能：状态表字典，每一个状态表对应一个列表，列表中记录着该状态表中的所有状态
		* 类型：std::map<std::string, std::vector<std::string>>
		* 描述：无
		*/
		static std::map<std::string, std::vector<State*>> __stateBelong;

		/*
		* 功能：该状态在对应的输入下的状态转移
		* 类型：std::map<std::string, State*>
		* 描述：无
		*/
		std::map<std::string, State*> __transition;

		/*
		* 功能：状态名称，每一个状态的唯一标识符
		* 类型：std::string
		* 描述：无
		*/
		DEFINE_PRIVATE(std::string, __state, State);

		/*
		* 功能：归属状态，该状态归属于哪一个状态表
		* 类型：std::string
		* 描述：每一个状态表里面的状态唯一
		*/
		DEFINE_PRIVATE(std::string, __belong, Belong);

		/*
		* 功能：构造函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		State();

		/*
		* 功能：构造函数
		* 参数：状态名称,状态表的名称
		* 返回：无
		* 描述：无
		*/
		State(std::string stateName, std::string belong);

		/*
		* 功能：析构函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		~State();

	public:
		/*
		* 功能：创建状态的工厂方法
		* 参数：状态名称，状态表名称
		* 返回：State*
		* 描述：静态
		*/
		static State* create(std::string stateName, std::string belong);

		/*
		* 功能：从状态表字典中，按归属的状态转移表和名称取出对应的状态
		* 参数：状态名称，状态表名称
		* 返回：State*
		* 描述：静态
		*/
		static State* getStateByBelongAndName(std::string state, std::string belong);

		/*
		* 功能：添加一个状态转移关系
		* 参数：输入，转移状态
		* 返回：是否添加成功(bool)
		* 描述：无
		*/
		bool addState(std::string input, State *state);

		/*
		* 功能：通过输入得到该状态
		* 参数：输入值
		* 返回：状态
		* 描述：无
		*/
		State* getStateByInput(std::string input);

		/*
		* 功能：得到状态转移个数
		* 参数：无
		* 返回：状态转移的个数(int)
		* 描述：无
		*/
		int getTransitionTotal();

	};
}

#endif
