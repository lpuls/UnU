/*
* 描述：Token的AST节点
* 作者：xp
* 日期：---
*/
#ifndef __AST_TOKEN_NODE__
#define __AST_TOKEN_NODE__

#include "../../Tools.h"
#include "ASTValueNode.h"

namespace UnUCompiler
{
	class ASTTokenNode : public ASTValueNode<std::string>
	{
		friend class ASTNodeCreater;
	private:
		/*
		* 功能：构造函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		ASTTokenNode();

	public:
		/*
		* 功能：析构函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		~ASTTokenNode();
	};
}

#endif
