#include "ASTTokenTable.h"

UnUCompiler::ASTTokenTable::ASTTokenTable()
{

}

UnUCompiler::ASTTokenTable::~ASTTokenTable()
{

}

bool UnUCompiler::ASTTokenTable::isExit(std::string token)
{
	for (auto item : this->__tokenTable)
	{
		if (item == token)
			return true;
	}
	return false;
}
