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
#include "../Lex/Word.h"
#include "../../Tools.h"
#include "../AST/ASTNode.h"
#include "../AST/ASTBodyNode.h"
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
		* 功能：用来记识合并结果
		* 类型：const int
		* 描述：成功，继续下一步
		*/
		const int CONTINUE = -1;

		/*
		* 功能：用来记识合并结果
		* 类型：const int
		* 描述：本次不合并，跳过
		*/
		const int SKIP = 1;

		/*
		* 功能：用来记识合并结果
		* 类型：const int
		* 描述：本次不做任何操作
		*/
		const int DO_NOTHING = 1;

		/*
		* 功能：用来记识合并结果
		* 类型：const int
		* 描述：失败
		*/
		const int FAILED = 2;

		/*
		* 功能：符号栈
		* 类型：std::stack<std::string>
		* 描述：无
		*/
		DEFINE_PRIVATE_READ_ONLY(std::stack<ASTNode*>, __operatorStack, OperatorStack);

		/*
		* 功能：数值栈
		* 类型：std::stack<std::string>
		* 描述：无
		*/
		DEFINE_PRIVATE_READ_ONLY(std::stack<ASTNode*>, __valueStack, ValueStack);

		/*
		* 功能：添加一个操作符节点进栈中
		* 参数：Word 数值词汇
		* 返回：bool 是否添加成功
		* 描述：无
		*/
		bool pushNodeIntoOperatorStack__(Word word);

		/*
		* 功能：添加一个数值节点进数值栈中
		* 参数：Word 数值词汇
		* 返回：bool 是否添加成功
		* 描述：无
		*/
		bool pushNodeIntoValueStack__(Word word);

		/*
		* 功能：将所有AST节点合并成树
		* 参数：Word 词汇
		* 返回：最后合并成的Body节点
		* 描述：无
		*/
		int merge(Word word);

		/*
		* 功能：归约
		* 参数：Word 词汇
		* 返回：无
		* 描述：无
		*/
		int reduction(Word word);

		/*
		* 功能：特殊节点
		* 参数：Word 读取到的特殊节点
		* 返回：无
		* 描述：用来匹配括号
		*/
		void specialBracket(Word word);

		/*
		* 功能：将操作符相关的内容进行计算
		* 参数：ASTNode 要计算的操作符节点
		* 返回：ASTNode 计算完后的节点
		* 描述：无
		*/
		ASTNode* calculation(ASTNode *node);
	};
}

#endif

