#include "SourceStream.h"

bool SourceStream::loadFile(std::string filename)
{
	
	input.open(filename, std::ios::in);

	if (!input.is_open()) {
		std::cerr << "Ошибка при открытии файла: " << filename << std::endl;
		// Проверка на конкретные ошибки
		if (input.bad()) {
			std::cerr << "Фатальная ошибка: badbit установлен." << std::endl;
			return false;
		}
		if (input.fail()) {
			std::cerr << "Ошибка деталей.";
			return false;
		}
	}
	return true;
}

void SourceStream::readWord()
{
	buffer.clear();
	char c;

	while (std::isspace(input.peek())) { input.ignore(1); }

	c = input.get();
	std::string pos = std::to_string((int)input.tellg());
	if (c != EOF) {
		switch (c)
		{
		case '/':
			char next = input.peek();
			if (skipComment(next)) {
				break;
			}
			else
				errors.push_back("Ошибка в символе " + pos + ". Неопознаный \'/\'.");
			break;
		case '\"':
			buffer.push_back(c);
			while (input.peek() != EOF) {
				c = input.get();
				buffer.push_back(c);
				if (c == '\"')
					return;
			}
			errors.push_back("Ошибка: отсутсвует парная ковычка символа" + pos);
		default:
			break;
		}
	}
}


bool SourceStream::skipComment(char& mode)
{
	switch (mode)
	{
	case '/':
		input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return true;
	case '*':
		char c;
		while (input.peek()!= EOF)
		{
			if (input.peek() != '*')
				input.ignore(1);
			else {
				input.ignore(1);
				if (input.get() == '/') {
					return true;
				}
				else continue;
			}
		}
		errors.push_back("Ошибка: многострочный комментарий не закрыт;");
		return true;
	default:
		return false;
	}
}



inline bool SourceStream::is_forSkip(char& ch)
{
	
	return std::isspace(ch);
}
