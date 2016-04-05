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
		* 描述：保护，外部不可访问
		*/
		State *_previousState;

		/*
		* 功能：输入的值
		* 类型：string
		* 描述：保护，外部不可访问
		*/
		std::string _input;

		/*
		* 功能：当前的输入在输入列表中的位置
		* 类型：int
		* 描述：保护，外部不可访问
		*/
		int _location;

		/*
		* 功能：输入列表
		* 类型：std::vector<std::string>
		* 描述：保护，外部不可访问
		*/
		DEFINE_PROTECTED(std::vector<std::string>*, _inputList, InputList);

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
		* 功能：进入动作
		* 参数：无
		* 返回：无
		* 描述：无
		*/
	    virtual int entry__();

		/*
		* 功能：退出动作
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		virtual int quit__();
		
		/*
		* 功能：转移动作
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		virtual int transition__();

		/*
		* 功能：输入指令
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		virtual int input_();

	public:
		/*
		* 功能：错误代码，返回该值结束运行
		* 类型：const int
		* 描述：无
		*/
		const int ERROR = 0;

		/*
		* 功能：错误代码，返回该值结束运行
		* 类型：const int
		* 描述：无
		*/
		const int CONTINUE = 1;

		/*
		* 功能：表示输入列表读取完
		* 类型：const
		* 描述：不可修改的常量
		*/
		const int INPUT_OVER = 10;

		/*
		* 功能：表示读取输入正常
		* 类型：const
		* 描述：不可修改的常量
		*/
		const int INPUT_NORMAL = 11;

		/*
		* 功能：表示输入列表为空
		* 类型：const
		* 描述：不可修改的常量
		*/
		const int INPUT_NULL = 12;

		/*
		* 功能：表示输入列表读取溢出
		* 类型：const
		* 描述：不可修改的常量
		*/
		const int INPUT_OVERFLOW = 13;

		/*
		* 功能：转移状态时的正常
		* 类型：const int
		* 描述：不可修改的常量
		*/
		const int TRANSITION_NULL_INPUT = 21;

		/*
		* 功能：转移状态时的正常
		* 类型：const int 
		* 描述：不可修改的常量
		*/
		const int TRANSITION_NORMAL = 21;

		/*
		* 功能：转移状态时的错误，无该输入对应的转移
		* 类型：const int
		* 描述：不可修改的常量
		*/
		const int TRANSITION_ERROR = 22;

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
		bool run();

	};
}

#endif
