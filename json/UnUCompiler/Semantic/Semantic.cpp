#include "Semantic.h"
#include "../AST/ASTNodeCreater.h"

using namespace UnUCompiler;

Semantic::Semantic()
{
	PowerTable::init();
}

Semantic::~Semantic()
{
}

ASTNode * UnUCompiler::Semantic::analysis(WordIterator wordIterator)
{
	std::string wordValue = "";
	ASTNode *root = ASTNodeCreater::create("root");
	for (unsigned int i = 0; i < wordIterator.total(); i++)
	{
		wordValue = wordIterator.get(i).getWordValue();
		// 数值，加入数值栈
		if ("token" == wordValue || "string" == wordValue || "integer" == wordValue || "float" == wordValue)
		{
			this->__valueStack.push(wordValue);
		}
	}
	return nullptr;
}
