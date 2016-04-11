/*
* 描述：赋值AST节点
* 作者：xp
* 日期：2016-4-11
*/
#ifndef __AST_ASSIGN_NODE__
#define __AST_ASSIGN_NODE__

#include "ASTExpNode.h"
#include "ASTTokenNode.h"
#include "../../Tools.h"

namespace UnUCompiler
{
	class ASTAssignNode : public ASTExpNode
	{
	private:
		/*
		* 功能：左节点，表示左值
		* 类型：赋值语句左侧一定为Token
		* 描述：无
		*/
		DEFINE_PRIVATE(ASTTokenNode*, __left, Left);

		/*
		* 功能：右节点，可以为值或着表达式
		* 类型：ASTExpNode*
		* 描述：无
		*/
		DEFINE_PRIVATE(ASTExpNode*, __right, Right);

		/*
		* 功能：构造函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		ASTAssignNode();

		/*
		* 功能：检查方法
		* 参数：无
		* 返回：int，检查结果
		* 描述：虚方法，用来检查每一个节点的语义是否正确
		*/
		int check();

	public:
		/*
		* 功能：析构函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		~ASTAssignNode();


	};

}

#endif
