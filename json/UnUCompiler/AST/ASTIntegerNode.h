/*
* 描述：整数类型
* 作者：xp
* 日期：2016-4-6
*/
#ifndef __AST_INTEGER_NODE__
#define __AST_INTEGER_NODE__

#include "ASTValueNode.h" 

namespace UnUCompiler
{
	class ASTIntegerNode : public ASTValueNode<long long int>
	{
		friend class ASTNodeCreater;
	public:	
		/*
		* 功能：析构函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		~ASTIntegerNode();

	private:
		/*
		* 功能：构造函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		ASTIntegerNode();
	};
}

#endif
