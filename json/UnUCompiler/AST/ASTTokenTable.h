/*
* 描述：符号表
* 作者：xp
* 日期：2016-4-12
*/
#ifndef __AST_TOKEN_TABLE__
#define __AST_TOKEN_TABLE__

#include <vector>


namespace UnUCompiler
{
	class ASTTokenTable
	{
		friend class ASTBodyNode;
	private:
		/*
		* 功能：符号表
		* 类型：vector<std::string>
		* 描述：只可由友元类ASTBodyNode使用
		*/
		std::vector<std::string> __tokenTable;

		/*
		* 功能：构造函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		ASTTokenTable();

		/*
		* 功能：析构函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		~ASTTokenTable();

		/*
		* 功能：检测某一变量名是否存在
		* 参数：std::string 要检测的变量名
		* 返回：bool 是否存在
		* 描述：无
		*/
		bool isExit(std::string token);

	};
}

#endif
