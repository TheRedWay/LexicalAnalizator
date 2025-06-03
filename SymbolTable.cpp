#include "SymbolTable.h"
#include <iomanip>

bool SymbolTable::check_name(const std::string& in)
{
	return false;
}

IdentifierToken SymbolTable::getToken(const std::string& in)
{
	auto it = symbols.find(in);
		return it->second;
}

void SymbolTable::add(std::string name, IdentifierToken in)
{
	symbols[name] = in;
}

void SymbolTable::printAll(std::ostream& out) const
{
	const int nameW = 30;
	const int typeW = 20;
	const int valueW = 40;

	if (symbols.empty()) {
		out << "[Таблица символов пуста]\n";
		return;
	}

	out << std::left
		<< std::setw(nameW) << "Имя"
		<< std::setw(typeW) << "Тип"
		<< std::setw(valueW) << "Значение"
		<< "\n";

	out << std::string(nameW + typeW + valueW, '-') << "\n";

	for (const auto& [name, tok] : symbols) {
		std::string typeStr = IdentifierToken::typeToString(tok.getTokType());
		std::string valueStr = tok.getValue();

		out << std::left
			<< std::setw(nameW) << name.substr(0, nameW - 1)
			<< std::setw(typeW) << typeStr.substr(0, typeW - 1)
			<< std::setw(valueW) << valueStr.substr(0, valueW - 1)
			<< "\n";
	}

	out << std::string(nameW + typeW + valueW, '-') << "\n";
}


