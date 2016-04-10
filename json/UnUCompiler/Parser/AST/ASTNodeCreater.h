/*
* 描述：AST节点工厂
* 作者：xp
* 日期：2016-4-6
*/
#ifndef __AST_NODE_CREATER__
#define __AST_NODE_CREATER__

#include "ASTNode.h"

namespace UnUCompiler
{
	class ASTNodeCreater
	{
	public:
		/*
		* 功能：创建一个AST节点
		* 参数：std::string 词汇, std::string 词汇值
		* 返回：无
		* 描述：无
		*/
		static ASTNode* create(std::string word = "", std::string wordValue = "");
	};
}


#endif
