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
		DEFINE_PRIVATE_READ_ONLY(std::stack<ASTNode*>, __operatorStack, OperatorStack);
		
		/*
		* 功能：数值栈
		* 类型：std::stack<std::string>
		* 描述：无
		*/
		DEFINE_PRIVATE_READ_ONLY(std::stack<ASTNode*>, __valueStack, ValueStack);

		/*
		* 功能：添加一个数值节点进数值栈中
		* 参数：Word 数值词汇
		* 返回：bool 是否添加成功
		* 描述：无
		*/
		bool pushNodeIntoValueStack(Word word);

		/*
		* 功能：添加一个运逄符节点进运算符栈中
		* 参数：Word 数值词汇
		* 返回：bool 是否添加成功
		* 描述：无
		*/
		bool pushNodeIntoOperatoreStack(Word word);

		/*
		* 功能：归约
		* 参数：无
		* 返回：bool 是否归约成功
		* 描述：无
		*/
		bool reduction();

		/*
		* 功能：合并当前节点到目标节点的所有AST节点
		* 参数：std::string 目标节点类型
		* 返回：bool 是否合并成功
		* 描述：无
		*/
		std::vector<ASTNode*> getMergeList(std::string astType);

		/*
		* 功能：对节点分类，将节点合并进主结构
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		void classification();
	};
}

#endif

