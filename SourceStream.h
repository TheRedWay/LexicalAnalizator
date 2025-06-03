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
	std::ifstream input;
	

	inline void skipSpace();

protected:
	std::vector<std::string> errors;
	std::string buffer;
	inline bool is_forSkip(char&);
	bool readWord();
	bool skipComment(char& mode);
	bool loadFile(std::string filename);
};


#endif // !SourceStream