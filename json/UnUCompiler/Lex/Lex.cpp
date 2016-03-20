#include <functional>

#include "Lex.h"
#include "../UnUCompile.h"
#include "../UnUCompilerPublicVar.h"

using namespace std;
using namespace UnUCompiler;

Lex * Lex::__instance = nullptr;

#define LEXLOG(var) Toolsets::getInstance()->log(var, "LEX");

UnUCompiler::Lex::Lex(std::string path) : StateMachine(path)
{
	this->__keyWordsTable = KeyWordsTable(keyWordPath);
	this->__currentWord = "";
	
}

UnUCompiler::Lex::~Lex()
{
	StateMachine::~StateMachine();
}

int UnUCompiler::Lex::_entryEvent(std::string input)
{
	return 0;
}

int UnUCompiler::Lex::_quitEvent(std::string input)
{
	return 0;
}

int UnUCompiler::Lex::_transitionEvent(std::string input)
{
	return 0;
}									 

Lex * UnUCompiler::Lex::getInstance()
{
	if (nullptr == Lex::__instance)
		Lex::__instance = new Lex(LexPath);
	return Lex::__instance;
}

void UnUCompiler::Lex::releaseInstance()
{
	SAFE_DELETE(Lex::__instance);
}