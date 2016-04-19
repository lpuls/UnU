/*
* 描述：判断或循环语句的节点
* 作者：xp
* 日期：2016-4-11
*/
#ifndef __AST_STRUCT_NODE__
#define __AST_STRUCT_NODE__

#include "ASTNode.h"
#include "ASTBodyNode.h"
#include "../../Tools.h"
#include "ASTOperatorNode.h"


namespace UnUCompiler
{
	class ASTStructNode : public ASTNode
	{
		friend class ASTNodeCreater;
	private:
		/*
		* 功能：Bool判断
		* 类型：ASTOperatorNode*
		* 描述：无
		*/
		DEFINE_PROTECTED(ASTExpNode*, _left, Left);

		/*
		* 功能：运行结构
		* 类型：ASTBodyNode*
		* 描述：无
		*/
		DEFINE_PROTECTED(ASTBodyNode*, _right, Right);

		/*
		* 功能：构造函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		ASTStructNode();

	public:
		/*
		* 功能：析构函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		~ASTStructNode();

		/*
		* 功能：检查方法
		* 参数：无
		* 返回：int，检查结果
		* 描述：虚方法，用来检查每一个节点的语义是否正确
		*/
		int check();

		/*
		* 功能：打印结构
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		void print();
	};
}

#endif
