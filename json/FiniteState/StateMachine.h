/*
* 描述：有限自动状态机类
* 作者：xp
* 日期：2016-2-29
*/
#ifndef __STATE_MACHINE__
#define __STATE_MACHINE__

#include <iostream>
#include <functional>

#include "StateTable.h"
#include "../Toolsets.h"


namespace XpLib
{
	class StateMachine
	{
	protected:
		/*
		* 功能：记录前一个状态的值
		* 类型：State*
		* 描述：外部不可访问
		*/
		State *_previousState;

		/*
		* 功能：状态转移表
		* 类型：StateTable*
		* 描述：只读
		*/
		DEFINE_PROTECTED_READ_ONLY(StateTable*, _stateTable, StateTable);

		/*
		* 功能：当前状态
		* 类型：State*
		* 描述：只读
		*/
		DEFINE_PROTECTED_READ_ONLY(State*, _current, Current);

		/*
		* 功能：用来表示转移状态
		* 类型：int
		* 描述：错误状态
		*/
		static const int ERROR = 0;

		/*
		* 功能：用来表示转移状态
		* 类型：int
		* 描述：正常状态
		*/
		static const int NEXT = 1;
		
		/*
		* 功能：用来表示转移状态
		* 类型：int
		* 描述：进入状态
		*/
		static const int ENTRY = 2;

		/*
		* 功能：用来表示转移状态
		* 类型：int
		* 描述：退出状态
		*/
		static const int QUIT = 3;

		/*
		* 功能：用来表示转移状态
		* 类型：int
		* 描述：转移状态
		*/
		static const int TRANSITION = 4;

		/*
		* 功能：在进入动作时处理的事件
		* 参数：输入值,运行的状态机
		* 返回：运行结果
		* 描述：若未设置，则初始为空
		*/
		virtual int _entryEvent(std::string input);

		/*
		* 功能：在退出动作时处理的事件
		* 参数：输入值， 运行的状态机
		* 返回：运行结果
		* 描述：若未设置，则初始为空
		*/
		virtual int _quitEvent(std::string input);

		/*
		* 功能：在转移动作时处理的事件
		* 参数：输入值， 运行的状态机
		* 返回：运行结果
		* 描述：若未设置，则初始为空
		*/
		virtual int _transitionEvent(std::string input);

	private:

		/*
		* 功能：进入动作
		* 参数：输入
		* 返回：无
		* 描述：无
		*/
	    int entry__(std::string input);

		/*
		* 功能：退出动作
		* 参数：输入
		* 返回：无
		* 描述：无
		*/
		int quit__(std::string input);
		
		/*
		* 功能：转移动作
		* 参数：输入
		* 返回：无
		* 描述：无
		*/
		int transition__(std::string input);

	public:


		/*
		* 功能：构造函数
		* 参数：状态表的文件路径
		* 返回：无
		* 描述：无
		*/
		StateMachine(std::string path);

		/*
		* 功能：析构函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		~StateMachine();

		/*
		* 功能：进行状态转移分析
		* 参数：std::vector<char>
		* 返回：是否完成状态转移
		* 描述：无
		*/
		bool run(std::vector<std::string> inputList);

	};
}

#endif
