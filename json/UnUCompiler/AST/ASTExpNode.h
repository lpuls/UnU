/*
* 描述：表达式节点
* 作者：xp
* 日期：2016-4-11
*/
#ifndef __AST_EXP_NODE__
#define __AST_EXP_NODE__

#include "ASTNode.h"

namespace UnUCompiler
{
	class ASTExpNode : public ASTNode
	{
		friend class ASTNodeCreater;
	protected:	  
		/*
		* 功能：构造函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		ASTExpNode();

	public:
		/*
		* 功能：析构函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		~ASTExpNode();


	};
}

#endif
