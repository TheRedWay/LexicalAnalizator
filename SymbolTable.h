#pragma once
#include <unordered_set>
#include "Token.h"
class SymbolTable
{
	std::unordered_set<IdentifierToken> symbols;
public:
	bool check_name();
};

