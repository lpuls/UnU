/*
* 描述：标记节点
* 作者：xp
* 日期：2016-4-13
*/
#ifndef __AST_STAND_NODE__
#define __AST_STAND_NODE__

#include "ASTNode.h"

namespace UnUCompiler
{
	class ASTStandNode : public ASTNode
	{
		friend class ASTNodeCreater;
	private:
		/*
		* 功能：构造函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		ASTStandNode();

	public:
		/*
		* 功能：析构函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		~ASTStandNode();

		 
	};
}

#endif
