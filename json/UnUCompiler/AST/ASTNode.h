/*
* 描述：AST抽像语法树的基类
* 作者：xp
* 日期：2016-4-6
*/
#ifndef __AST_NODE__
#define __AST_NODE__

#include "../UnUCompile.h"


namespace UnUCompiler
{
	class ASTNode
	{
		friend class ASTNodeCreater;
	public:
		/*
		* 功能：析构函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		~ASTNode();

		/*
		* 功能：检查方法
		* 参数：无
		* 返回：int，检查结果
		* 描述：虚方法，用来检查每一个节点的语义是否正确
		*/
		virtual int check();

		

	protected:
		/*
		* 功能：构造函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		ASTNode();

	};
}

#endif
