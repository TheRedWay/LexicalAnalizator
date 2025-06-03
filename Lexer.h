#pragma once
#ifndef LEXER
#define LEXER


#include "SourceStream.h"
class Lexer : protected SourceStream
{
	
	SymbolTable symbolTable;

	std::unique_ptr<Token> createToken();
	Token* lastTypeToken;

protected:
	
	std::vector<std::unique_ptr<Token>> tokensTable;
	bool lexFile();
public:

	
};

#endif // !LEXER