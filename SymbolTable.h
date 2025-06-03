#pragma once
#ifndef SYMBOLTABLE
#define SYMBOLTABLE


#include <set>
#include "Token.h"
class IdentifierToken;
class SymbolTable
{
	std::set<IdentifierToken> symbols;
public:
	bool check_name();
	
};

#endif // !SYMBOLTABLE