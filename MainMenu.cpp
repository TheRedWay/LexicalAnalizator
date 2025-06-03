#include "MainMenu.h"

void MainMenu::showList()
{

}

MainMenu::funcs MainMenu::getCommand()
{

	char c;
	bool notAcommand = 1;
	do {
		std::cout << "\n>";
		c = std::cin.get(); std::cin.get();
		std::cout << std::endl;
		switch (c)
		{
		case '0':
			return MainMenu::funcs::fileName;
		case '1':
			return MainMenu::funcs::start;
		case '2':
			return MainMenu::funcs::info;
		case '3':
			return MainMenu::funcs::exit;

		default:
			std::cout << "Неверная команда. \n";
		}
	} while (notAcommand);
}

void MainMenu::open()
{
	setlocale(0, "rus");
	bool is_start = 1;
	while (is_start) {

		void showList();
		
		funcs command = getCommand();
		switch (command)
		{
		case MainMenu::funcs::fileName:
			std::cout << "\nВведите название файла: ";
			std::cin >> inputFileName;
			if (utils::validateFile(inputFileName)) {
				file_is_loaded = 0;
				if (loadFile(inputFileName))
				{
					std::cout << "\nФайл " + inputFileName + " упешно загружен.\n";
					file_is_loaded = 1;
				}
				else
				{
					std::cout << "\nПовторите попытку заргузки файла.\n";
					file_is_loaded = 0;
					continue;
				}
			}
			else {
				std::cout << "\nНеверный формат файла.\n";
				file_is_loaded = 0;
			}
			break;
		case MainMenu::funcs::start:
			if (file_is_loaded) 
			{
				lexFile();
			}
			else
				std::cout << "Невозможно запустить лексер, файл не загружен.\n";
			break;
		case MainMenu::funcs::info:
			break;
			void showInfo();
		case MainMenu::funcs::exit:
			std::exit(0);
			break;
		default:
			break;
		}
	}
}
