/*
* 描述：函数的抽像语法节点
* 作者：xp
* 日期：2016-4-11
*/
#ifndef __AST_FUNCTION_NODE__
#define __AST_FUNCTION_NODE__

#include "ASTNode.h"
#include "../../Tools.h"
#include "ASTBodyNode.h" 
#include "ASTParamNode.h"
#include "ASTTokenNode.h"


namespace UnUCompiler
{
	class ASTFunctionNode : public ASTNode
	{
	private:
		/*
		* 功能：构造函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		ASTFunctionNode ();

		/*
		* 功能：函数名
		* 类型：ASTTokenNode*
		* 描述：无
		*/
		DEFINE_PROTECTED(ASTTokenNode*, _funtion, Function);

		/*
		* 功能：参数列表
		* 类型：无
		* 描述：无
		*/
		DEFINE_PROTECTED(ASTParamNode*, _params, Params);

		/*
		* 功能：函数体内容
		* 类型：ASTBodyNode*
		* 描述：无
		*/
		DEFINE_PROTECTED(ASTBodyNode*, _body, Body);

	public:
		/*
		* 功能：析构函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		~ASTFunctionNode ();

		/*
		* 功能：检查方法
		* 参数：无
		* 返回：int，检查结果
		* 描述：虚方法，用来检查每一个节点的语义是否正确
		*/
		int check();
	};
}

#endif
