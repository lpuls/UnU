/*
* 描述：结构部份的节点
* 作者：xp
* 日期：2016-4-11
*/
#ifndef __AST_BODY_NODE__
#define __AST_BODY_NODE__

#include <vector>

#include "ASTNode.h"
#include "../../Tools.h"


namespace UnUCompiler
{
	class ASTBodyNode : public ASTNode
	{
		friend class ASTNodeCreater;
	private:
		/*
		* 功能：构造函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		ASTBodyNode();

	protected:
		/*
		* 功能：结构内的所有AST节点列表
		* 类型：std::vector<ASTNode*>
		* 描述：无
		*/
		std::vector<ASTNode*> __children;

	public:
		/*
		* 功能：析构函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		~ASTBodyNode();

		/*
		* 功能：添加一个AST节点
		* 参数：ASTNode*
		* 返回：无
		* 描述：无
		*/
		void addChild(ASTNode * child);

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
