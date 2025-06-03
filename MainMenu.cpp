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
		case MainMenu::fileName:
			break;
		case MainMenu::start:
			break;
		case MainMenu::info:
			break;
		case MainMenu::exit:
			break;
		default:
			break;
		}
	}
}
