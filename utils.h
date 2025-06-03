#pragma once
#ifndef UTILS
#define UTILS

#include <unordered_set>
#include <string>
namespace utils
{
	bool is_number(char ch);
	bool is_keyword(const std::string& str);
	bool is_separetor(char ch);
	bool is_operator(const std::string& str);
	bool is_operator(const char);

	int cti(char ch);
	char itc(int in);
	int gecsToInt(char ch);
	bool validateFile(std::string& filecpp);

	

	std::string toString(const std::string& s);
	std::string toString(int x);
	std::string toString(double d);
};

#endif // !UTILS


