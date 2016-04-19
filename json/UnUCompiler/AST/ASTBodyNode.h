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
#include "ASTTokenTable.h"


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
		* 功能：无
		* 类型：无
		* 描述：无
		*/
		ASTTokenTable *_tokenTable;

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
		* 功能：根据下标得到对应的孩子节点
		* 参数：unsigned int， 节点的下标
		* 返回：ASTNode*，下标对应的节点
		* 描述：无
		*/
		ASTNode* getChild(unsigned int location);

		/*
		* 功能：获取子节点总数
		* 参数：无
		* 返回：int，子节点总数
		* 描述：无
		*/
		unsigned int getChildTotal();

		/*
		* 功能：检查方法
		* 参数：无
		* 返回：int，检查结果
		* 描述：虚方法，用来检查每一个节点的语义是否正确
		*/
		int check();

		/*
		* 功能：提供给子节点查看是否存在变量名
		* 参数：std::String 变量名
		* 返回：bool 检测结果
		* 描述：无
		*/
		bool isExit(std::string token);

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
