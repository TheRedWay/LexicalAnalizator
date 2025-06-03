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

bool SourceStream::readWord()
{

	char c;
	
	while (input.peek() != EOF) {
		buffer.clear();
		skipSpace();
		c = input.get();

		std::string pos = std::to_string((int)input.tellg());

		char next;
		switch (c)
		{


		case '/':
			next = input.peek();
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
					return 1;
			}
			errors.push_back("Ошибка: отсутсвует парная ковычка символа" + pos);
			return ((input.peek() == EOF) ? 0 : 1);




		default:
			
			if (std::isalpha(c)) {
				buffer.push_back(c);
				for (c = input.peek(); c != EOF and (std::isalpha(c)); c = input.peek())
				{
					buffer.push_back(input.get());
				}
				if (!utils::is_keyword(buffer)) {
					skipSpace();
					if (input.peek() == '(')
					{
						buffer.push_back(input.get());
						buffer.push_back(')');

						while (input.peek() != ')') { input.get(); }
						input.get();
					}
				}
				return ((c == EOF) ? 0 : 1);
			}



			else if (std::isdigit(c)) {
				buffer.push_back(c);
				bool oneDot = 1;
				for (c = input.peek(); c != EOF and (std::isdigit(c) or (c == '.' and oneDot)); c = input.peek())
				{
					if (c == '.') oneDot = 0;
					buffer.push_back(input.get());
				}
				return ((c == EOF) ? 0 : 1);
			}



			else if (utils::is_operator(c)) {

				buffer.push_back(c);
				for (c = input.peek(); c != EOF and (utils::is_operator(c)); c = input.peek())
				{
					buffer.push_back(input.get());
				}
				return ((c == EOF) ? 0 : 1);
			}



			else {
				buffer = c;
				return 1;
			}
			
		}
	}
	return 0;
}


bool SourceStream::skipComment(char& mode)
{
	switch (mode)
	{
	case '/':
		input.ignore(INT64_MAX, '\n');
		return true;
	case '*':
		char c;
		while (input.peek()!= EOF)
		{
			if (input.peek() != '*')
				input.get();
			else {
				input.get();
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



inline void SourceStream::skipSpace()
{
	char c = input.peek();
	while (c != EOF and std::isspace(c)) { input.get(); c = input.peek();
	}
}

inline bool SourceStream::is_forSkip(char& ch)
{
	
	return std::isspace(ch);
}
