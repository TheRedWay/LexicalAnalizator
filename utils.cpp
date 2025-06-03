#include "utils.h"
#include <stdexcept>


bool utils::is_number(char ch)
{
	return (ch - '0') >= 0 and (ch - '0') <= 9;
}

bool utils::is_keyword(const std::string& str)
{
	static const std::unordered_set<std::string> keywords = {
		// Основные типы данных
		"int", "char", "float", "double", "bool", "void", "auto",
		"short", "long", "signed", "unsigned",

		// Модификаторы типов
		"const", "volatile", "mutable", "static", "extern", "register",

		// Специальные типы
		"class", "struct", "enum", "union", "typedef", "typename",

		// Управление памятью
		"new", "delete",

		// Управление потоком
		"if", "else", "switch", "case", "default", "for", "while", "do",
		"break", "continue", "goto", "return",

		// Исключения
		"try", "catch", "throw",

		// ООП
		"this", "virtual", "override", "final", "friend", "explicit", "operator",
		"public", "protected", "private", "using", "namespace", "template",

		// C++11 и новее
		"nullptr", "constexpr", "decltype", "noexcept", "thread_local",
		"alignas", "alignof", "concept", "requires", "co_await", "co_yield", "co_return",

		// Логические значения
		"true", "false",

		// Другие
		"sizeof", "typeid", "asm", "export"
	};

	return keywords.find(str) != keywords.end();
}

bool utils::is_separetor(char ch)
{
	static const std::unordered_set<char> delimiters = {
		'(', ')',    // круглые скобки
		'[', ']',    // квадратные скобки
		'{', '}',    // фигурные скобки
		',',         // запятая
		';',         // точка с запятой
		':',         // двоеточие
		'.',         // точка
		'#',         // директива препроцессора
		'\\'         // обратная косая черта
	};

	return delimiters.find(ch) != delimiters.end();
}

bool utils::is_operator(const std::string& str) {
	static const std::unordered_set<std::string> operators = {
		// Односимвольные операторы
		"+", "-", "*", "/", "%", "=", "<", ">", "!", "&", "|", "~", "^", ".", ",", "?",
		// Двухсимвольные операторы
		"++", "--", "==", "!=", "<=", ">=", "&&", "||", "<<", ">>",
		"+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=", "<<=", ">>=",
		"->", "::", ".*", "->*",
		// Трехсимвольные операторы (C++20)
		"<=>"
	};

	return operators.find(str) != operators.end();
}
bool utils::is_operator(char c) {
	static const std::string opChars =
		"+-*/%=<>&|~^.,?:"; 

	return opChars.find(c) != std::string::npos;
}

bool utils::isTypeKeyword(const std::string& s)
{
	return (s == "bool" ||
		s == "char" ||
		s == "wchar" ||
		s == "short" ||
		s == "int" ||
		s == "float" ||
		s == "double" ||
		s == "long");
}

int utils::cti(char ch)
{
	return ch - '0';
}

char utils::itc(int in)
{
	return (in + '0');
}

int utils::gecsToInt(char ch)
{
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

bool utils::validateFile(std::string& filecpp)
{
	auto ptr = filecpp.find('.');
	if (
		(filecpp[ptr + 1] == 'c' and filecpp[ptr + 2] == 'p' and filecpp[ptr + 3] == 'p' and (ptr + 3) == (filecpp.size() - 1))
		or (filecpp[ptr + 1] == 'h' and (ptr + 1) == (filecpp.size() - 1))
	   )
		return true;
	else
		return false;
}




std::string utils::toString(const std::string& s)
{
	return s;
}



// Для int — используем std::to_string
std::string utils::toString(int x) {
	return std::to_string(x);
}

// Для double — тоже std::to_string (при желании можно убрать избыточные нули вручную)
std::string utils::toString(double d) {
	return std::to_string(d);
}

