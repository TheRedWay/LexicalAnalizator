#pragma once
namespace utils
{
	bool is_number(char ch) {
		return (ch - '0') >= 0 and (ch - '0') <= 9;
	}
	int cti(char ch) {
		return ch - '0';
	}
	char itc(int in) {
		return (in + '0'); 
	}
	int gecsToInt(char ch) {
		switch (ch)
		{
		case 'A':
		case 'a':
			return 10;
		case 'B':
		case 'b':
			return 11;
		case 'C':
		case 'c':
			return 12;
		case 'D':
		case 'd':
			return 13;
		case 'E':
		case 'e':
			return 14;
		case 'F':
		case 'f':
			return 15;
		default:
			return 0;
		}
	}
};

