#include "SymbolTable.h"

bool SymbolTable::check_name(const std::string& in)
{
	return false;
}

IdentifierToken SymbolTable::getToken(const std::string& in)
{
	auto it = symbols.find(in);
		return it->second;
}

void SymbolTable::add(std::string name, IdentifierToken in)
{
	symbols[name] = in;
}


