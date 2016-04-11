/*
* 描述：操作符节点
* 作者：xp
* 日期：---
*/
#ifndef __AST_OPERATOR_NODE__
#define __AST_OPERATOR_NODE__

#include "ASTExpNode.h"
#include "../../Toolsets.h"

namespace UnUCompiler
{
	class ASTOperatorNode : public ASTExpNode
	{
		friend class ASTNodeCreater;
	private:
		/*
		* 功能：构造函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		ASTOperatorNode();

		/*
		* 功能：得到分支的节点类型
		* 参数：要获取的分支
		* 返回：std::string分支的类型
		* 描述：无
		*/
		std::string getChildType__(ASTExpNode * child);
	protected:
		/*
		* 功能：用来标记是Bool型还是数值型
		* 类型：bool
		* 描述：无
		*/
		DEFINE_PROTECTED(bool, _isBool, IsBool);

		/*
		* 功能：用来记录是运算得到的数值类型
		* 类型：std::string
		* 描述：无
		*/
		DEFINE_PROTECTED(std::string, _type, Type);

		/*
		* 功能：记录操作符的符号
		* 类型：std::string
		* 描述：无
		*/
		DEFINE_PROTECTED(std::string, _operator, Operator);

		/*
		* 功能：左节点
		* 类型：ASTExpNode*
		* 描述：无
		*/
		DEFINE_PROTECTED(ASTExpNode*, _left, Left);

		/*
		* 功能：右节点
		* 类型：ASTExpNode*
		* 描述：无
		*/
		DEFINE_PROTECTED(ASTExpNode*, _right, Right);

	public:
		/*
		* 功能：析构函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		~ASTOperatorNode();

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