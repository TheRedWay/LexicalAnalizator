#pragma once
#ifndef SOURCESTREAM
#define SOURCESTREAM

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>
#include "Token.h"
#include "utils.h"
class SourceStream
{
	
	bool skipComment(char& mode);
	inline bool is_forSkip(char&);
	inline void skipSpace();

protected:
	std::ifstream input;
	std::vector<std::string> errors;
	std::string buffer;
	
	bool readWord();
	
	bool loadFile(std::string filename);
};


#endif // !SourceStream