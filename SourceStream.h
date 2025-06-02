#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Token.h"
class SourceStream
{
	std::ifstream input;
	std::vector<std::string> errors;



protected:
	std::string buffer;
	inline bool is_forSkip(char&);
	void readWord();
	bool skipComment(char& mode);
	bool loadFile(std::string filename);
};

