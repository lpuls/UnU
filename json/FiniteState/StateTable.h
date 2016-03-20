/*
* 描述：状态转移表
* 作者：xp
* 日期：2016-2-28
*/
#ifndef __STATE_TABLE__
#define __STATE_TABLE__

#include "State.h"
#include "../Tools.h"


namespace XpLib
{
	enum TransitionType
	{
		One = 0,
		Limit = 1,
		Continue = 2
	};

	class StateTable
	{
	private:
		/*
		* 功能：该表格的名称
		* 类型：std::string
		* 描述：用来唯一标识一张标
		*/
		DEFINE_PRIVATE(std::string, __tableName, TableName);

		/*
		* 功能：表示起始状态
		* 类型：State*
		* 描述：无
		*/
		DEFINE_PRIVATE(State*, __starState, StarState);

		/*
		* 功能：状态转移表
		* 类型：std::map<std::string, State*>
		* 描述：外部只可通过接口根据状态名得到对应的状态
		*/
		std::map<std::string, State*> __stateTable;

	public:
		/*
		* 功能：构造函数
		* 参数：状态转移表的路径
		* 返回：无
		* 描述：无
		*/
		StateTable(std::string tablePath);

		/*
		* 功能：析构函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		~StateTable();

		/*
		* 功能：[]方法的重装
		* 参数：状态名称
		* 返回：状态
		* 描述：无
		*/
		State* operator[](std::string stateName);


	};
}

#endif
