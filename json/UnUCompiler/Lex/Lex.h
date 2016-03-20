/*
* 描述：词法分析器
* 作者：xp
* 日期：2016-3-10
*/
#ifndef __LEX__
#define __LEX__

#include "Word.h"
#include "WordLterator.h"
#include "KeyWordsTable.h"
#include "../../Toolsets.h"
#include "../../FiniteState/StateMachine.h"

using namespace XpLib;


namespace UnUCompiler
{
	class Lex  : public StateMachine
	{
	private:
		/*
		* 功能：单例
		* 类型：Lex*
		* 描述：只能通过getInstance方法来获得
		*/
		static Lex *__instance;

		/*
		* 功能：关键字表
		* 类型：KeyWordsTable
		* 描述：完全私有，外部不可访问
		*/
		KeyWordsTable __keyWordsTable;

		/*
		* 功能：当前保存下来的词汇
		* 类型：std::string
		* 描述：私有，外部不可访问
		*/
		std::string __currentWord;

		/*
		* 功能：词汇迭代器
		* 类型：WordLterator
		* 描述：私有
		*/
		DEFINE_PRIVATE_READ_ONLY(WordLterator, __lterator, WordLterator);

		/*
		* 功能：构造函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		Lex(std::string path);

		/*
		* 功能：构造函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		~Lex();

	protected:
		/*
		* 功能：执行进入状态的动作
		* 参数：输入
		* 返回：无
		* 描述：无
		*/
		int _entryEvent(std::string input);

		/*
		* 功能：执行退出状态时的动作
		* 参数：输入
		* 返回：下一步的动作
		* 描述：无
		*/
		int _quitEvent(std::string input);

		/*
		* 功能：执行进入时的状态
		* 参数：输入
		* 返回：下一步的动作
		* 描述：无
		*/
		int _transitionEvent(std::string input);

	public:

		/*
		* 功能：获取单例
		* 参数：无
		* 返回：Lex*
		* 描述：无
		*/
		static Lex* getInstance();

		/*
		* 功能：释放单例
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		static void releaseInstance();

	};

}

#endif
