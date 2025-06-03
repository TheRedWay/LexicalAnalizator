#include "MainMenu.h"

void MainMenu::showList()
{

}

void MainMenu::start()
{
	bool is_start = 1;
	while (is_start) {


		funcs command = getCommand();
		switch (command)
		{
		case MainMenu::funcs::fileName:
			break;
		case MainMenu::funcs::start:
			break;
		case MainMenu::funcs::info:
			break;
		case MainMenu::funcs::exit:
			std::exit(0);
			break;
		default:
			break;
		}
	}
}
