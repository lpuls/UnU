/*
* 描述：浮点数类型AST节点
* 作者：xp
* 日期：2016-4-10
*/
#ifndef __AST_FLOAT_NODE__
#define __AST_FLOAT_NODE__

#include "ASTValueNode.h"

namespace UnUCompiler
{
	class ASTFloatNode : public ASTValueNode<float>
	{
		friend class ASTNodeCreater;
	public:
		/*
		* 功能：析构函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		~ASTFloatNode();

	private:
		/*
		* 功能：构造函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		ASTFloatNode();

	};
}

#endif
