/*
* ���������ű�
* ���ߣ�xp
* ���ڣ�2016-4-12
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
		* ���ܣ����ű�
		* ���ͣ�vector<std::string>
		* ������ֻ������Ԫ��ASTBodyNodeʹ��
		*/
		std::vector<std::string> __tokenTable;

		/*
		* ���ܣ����캯��
		* ��������
		* ���أ���
		* ��������
		*/
		ASTTokenTable();

		/*
		* ���ܣ���������
		* ��������
		* ���أ���
		* ��������
		*/
		~ASTTokenTable();

		/*
		* ���ܣ����ĳһ�������Ƿ����
		* ������std::string Ҫ���ı�����
		* ���أ�bool �Ƿ����
		* ��������
		*/
		bool isExit(std::string token);

	};
}

#endif
