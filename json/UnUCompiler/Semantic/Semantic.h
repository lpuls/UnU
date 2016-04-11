/*
* 描述：语义分析器
* 作者：xp
* 日期：2016-4-10
*/
#ifndef __SEMANTIC__
#define __SEMANTIC__

#include <stack>
#include <vector>

#include "PowerTable.h"
#include "../../Tools.h"
#include "../AST/ASTNode.h"
#include "../Lex/WordLterator.h"

namespace UnUCompiler
{
	class Semantic
	{
	public:
		/*
		* 功能：构造函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		Semantic();

		/*
		* 功能：析构函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		~Semantic();

		/*
		* 功能：生成语法分析栈
		* 参数：WordIterator词汇迭代器
		* 返回：ASTNode*
		* 描述：无
		*/
		ASTNode* analysis(WordIterator wordIterator);

	private:
		/*
		* 功能：符号栈
		* 类型：std::stack<std::string>
		* 描述：无
		*/
		DEFINE_PRIVATE_READ_ONLY(std::stack<std::string>, __operatorStack, OperatorStack);
		
		/*
		* 功能：数值栈
		* 类型：std::stack<std::string>
		* 描述：无
		*/
		DEFINE_PRIVATE_READ_ONLY(std::stack<std::string>, __valueStack, ValueStack);
	};
}

#endif

