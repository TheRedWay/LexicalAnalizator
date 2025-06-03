#pragma once
#include <string>
#include "Token.h"
#include "SourceStream.h"
class Lexer : protected SourceStream
{
	
	SymbolTable symbolTable;
	std::unique_ptr<Token> createToken();
protected:
	
	std::vector<std::unique_ptr<Token>> tokensTable;
	bool lexFile(std::string inputFile);
public:

	
};

