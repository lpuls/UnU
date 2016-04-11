/*
* 描述：字符串AST节点
* 作者：xp
* 日期：2016-4-11
*/
#ifndef __AST_STRING_NODE__
#define __AST_STRING_NODE__

#include "ASTValueNode.h"


namespace UnUCompiler
{
	class ASTStringNode : public ASTValueNode<std::string>
	{
		friend class ASTNodeCreater;
	public:
		/*
		* 功能：析构函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		~ASTStringNode();

	private:
		/*
		* 功能：构造函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		ASTStringNode();

	};
}

#endif
