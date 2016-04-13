/*
* 描述：语法分析器
* 作者：xp
* 日期：2016-4-6
*/
#ifndef __PARSER__
#define __PARSER__

#include <stack>
#include <iostream>

#include "../../FiniteState/StateMachine.h"

using namespace XpLib;

namespace UnUCompiler
{
	class Parser : public StateMachine
	{
	private:
		/*
		* 功能：括号匹配失败
		* 类型：const int
		* 描述：不可访问，常量
		*/
		const int FAILED = -1;

		/*
		* 功能：添加括号到栈中
		* 类型：const int
		* 描述：不可访问，常量
		*/
		const int ADD = 0;

		/*
		* 功能：成功
		* 类型：const int
		* 描述：不可访问，常量
		*/
		const int SUCCESS = 1;

		/*
		* 功能：词汇迭代器
		* 类型：WordIterator
		* 描述：无
		*/
		std::vector<std::string> __wordIterator;

		/*
		* 功能：记录括号
		* 类型：std::stack<std::string>
		* 描述：无
		*/
		std::stack<std::string> __brackets;

		/*
		* 功能：括号匹配
		* 参数：std::string 括号
		* 返回：int，结果（-1：失败， 0：添加， 1：成功）
		* 描述：外部不可访问
		*/
		int matchBrackets__(std::string brackets);

	public:
		/*
		* 功能：错误代码，返回该值结束运行
		* 类型：const int
		* 描述：代码不完整
		*/
		const int CODE_INCOMPLETE = 50;

		/*
		* 功能：错误代码，返回该值结束运行
		* 类型：const int
		* 描述：括号匹配失败
		*/
		const int BRACKETS_MATCH_ERROR = 51;

		/*
		* 功能：构造函数
		* 参数：string，状态表路径
		* 返回：无
		* 描述：无
		*/
		Parser(std::string path);

		/*
		* 功能：析构函数
		* 参数：string，状态表路径
		* 返回：无
		* 描述：无
		*/
		~Parser();

		/*
		* 功能：设置词汇列表
		* 参数：词汇列表
		* 返回：无
		* 描述：无
		*/
		void setWordIterator(std::vector<std::string> wordIterator);

		/*
		* 功能：运行词法分析器
		* 参数：无
		* 返回：运行结果的代码
		* 描述：重写基类的run方法
		*/
		int run();

	protected:
		/*
		* 功能：进入动作
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		int entry__();

		/*
		* 功能：退出动作
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		int quit__();

	};
}

#endif
