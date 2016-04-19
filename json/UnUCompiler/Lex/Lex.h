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
		DEFINE_PRIVATE_READ_ONLY(WordIterator, __iterator, WordIterator);

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

		/*
		* 功能：清理词汇迭代器
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		void clearWordIterator();

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

	public:
	};

}

#endif
