/*
* 描述：参数节点
* 作者：xp
* 日期：---
*/
#ifndef __AST_PARAM_NODE__
#define __AST_PARAM_NODE__

#include <vector>

#include "ASTNode.h"
#include "../../Tools.h"
#include "ASTTokenNode.h"


namespace UnUCompiler
{
	class ASTParamNode : public ASTNode
	{
	private:
		/*
		* 功能：构造函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		ASTParamNode();

		/*
		* 功能：参数列表
		* 类型：无
		* 描述：无
		*/
		std::vector<ASTTokenNode*> __params;

	public:
		/*
		* 功能：析构函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		~ASTParamNode();

		/*
		* 功能：添加一个参数到参数列表中
		* 参数：ASTTokenNode*
		* 返回：无
		* 描述：无
		*/
		void addParam(ASTTokenNode* param);

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
