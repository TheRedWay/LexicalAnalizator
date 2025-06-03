#include "MainMenu.h"
#include <iomanip>

void MainMenu::showList()
{
	std::cout << "\n=== ������� ���� ===\n";
	std::cout << "0) ��������� ����\n";
	std::cout << "1) ��������� ����������� ������\n";
	std::cout << "2) ����\n";
	std::cout << "3) �����\n";
	std::cout << "�������� �����: \n";
}

void MainMenu::showInfo()
{
	std::cout << "\n--- ��������� ��������� ---\n";
	if (file_is_loaded and input.good()) {
		std::cout << "���� ��������: \"" << inputFileName << "\"\n";
	}
	else {
		std::cout << "���� ��� �� ��������.\n";
	}

	if (file_is_loaded and input.good()) {
		std::cout << "������ ����� � �������.\n";
	}
	else {
		std::cout << "������ �� ����� (������� ��������� ����).\n";
	}
	std::cout << "---------------------------\n";
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
			std::cout << "�������� �������. \n";
		}
	} while (notAcommand);
}

void MainMenu::open()
{
	setlocale(0, "rus");
	bool is_start = 1;
	while (is_start) {

		showList();
		
		funcs command = getCommand();
		switch (command)
		{
		case MainMenu::funcs::fileName:
			std::cout << "\n������� �������� �����: ";
			std::cin >> inputFileName; std::cin.get();
			if (utils::validateFile(inputFileName)) {
				file_is_loaded = 0;
				if (loadFile(inputFileName))
				{
					std::cout << "\n���� " + inputFileName + " ������ ��������.\n";
					file_is_loaded = 1;
				}
				else
				{
					std::cout << "\n��������� ������� �������� �����.\n";
					file_is_loaded = 0;
					continue;
				}
			}
			else {
				std::cout << "\n�������� ������ �����.\n";
				file_is_loaded = 0;
			}
			break;
		case MainMenu::funcs::start:
			if (file_is_loaded) 
			{
				lexFile();
				showTokensTable();
				showSymbolTable();
				showErrors();
				input.close();
			}
			else
				std::cout << "���������� ��������� ������, ���� �� ��������.\n";
			break;
		case MainMenu::funcs::info:
			showInfo();
			break;
		case MainMenu::funcs::exit:
			std::exit(0);
			break;
		default:
			break;
		}
	}
}

void MainMenu::showTokensTable()
{
	if (tokensTable.empty()) {
		std::cout << "\n[������� ������� �����]\n";
		return;
	}

	// ������ ������� ��� ��������������
	const int idxW = 5;   // ������� �
	const int typeW = 25;  // ������� ��� ������
	const int valueW = 40;  // ������� ��������

	std::cout << "\n=== ������� ������� ===\n";
	std::cout << std::left
		<< std::setw(idxW) << "�"
		<< std::setw(typeW) << "��� ������"
		<< std::setw(valueW) << "��������"
		<< "\n";

	std::cout << std::string(idxW + typeW + valueW, '-') << "\n";

	for (size_t i = 0; i < tokensTable.size(); ++i) {
		const Token* tok = tokensTable[i].get();
		if (tok) {
			std::string typeStr = tok->getType();
			std::string valueStr = tok->getValue();

			if (typeStr.length() > static_cast<size_t>(typeW - 1))  typeStr = typeStr.substr(0, typeW - 1);
			if (valueStr.length() > static_cast<size_t>(valueW - 1)) valueStr = valueStr.substr(0, valueW - 1);
			std::cout << std::left
				<< std::setw(idxW) << (i + 1)
				<< std::setw(typeW) << typeStr
				<< std::setw(valueW) << valueStr
				<< "\n";
		}

		
		
	}

	std::cout << std::string(idxW + typeW + valueW, '-') << "\n";
}

//------------------------------------------------------------------------------
// 4) ����� symbolTable: ��� �������, ��� (������), �������� (������)
//    ��������������, ��� SymbolTable ������������� �����:
//      const std::map<std::string, IdentifierToken>& getAll() const;
//------------------------------------------------------------------------------

void MainMenu::showSymbolTable()
{
	std::cout << "\n=== ������� �������� ===\n";
	symbolTable.printAll(std::cout);
}

//------------------------------------------------------------------------------
// 5) ����� ������ ������ (std::vector<std::string> errors)
//------------------------------------------------------------------------------

void MainMenu::showErrors()
{
	if (errors.empty()) {
		std::cout << "\n[������ ���]\n";
		return;
	}

	std::cout << "\n=== ������ ������ ===\n";
	for (size_t i = 0; i < errors.size(); ++i) {
		std::cout << " " << (i + 1) << ") " << errors[i] << "\n";
	}
	std::cout << "=====================\n";
}