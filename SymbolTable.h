#pragma once
#ifndef SYMBOLTABLE
#define SYMBOLTABLE


#include <set>
#include <map>
#include "Token.h"
class IdentifierToken;
class SymbolTable
{
	std::map<std::string,IdentifierToken> symbols;
public:
	bool check_name(const std::string& in);
	IdentifierToken getToken(const std::string&);
	void add(std::string name, IdentifierToken in);
	void add(IdentifierToken in);
};

#endif // !SYMBOLTABLE