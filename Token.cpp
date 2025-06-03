#include "Token.h"




template<typename type>
ConstToken<type>::ConstToken()
{
}

template<typename type>
ConstToken<type>::ConstToken(type in) : value(std::move(in))
{
}
template class ConstToken<int>;
template class ConstToken<double>;
template class ConstToken<std::string>;

template<typename type>
std::string ConstToken<type>::getType() const
{
	return "Константа";
}

template<typename type>
std::string ConstToken<type>::getValue() const
{
	return utils::toString(value);
}

indType IdentifierToken::getType(std::string s)
{
	if (s == "bool")     return indType::_bool;
	else if (s == "char")    return indType::_char;
	else if (s == "wchar")   return indType::_wchar;
	else if (s == "short")   return indType::_short;
	else if (s == "int")     return indType::_int;
	else if (s == "float")   return indType::_float;
	else if (s == "double")  return indType::_double;
	else if (s == "long")    return indType::_long;
	else
		throw std::invalid_argument("Неизвестный тип: " + s);
}

IdentifierToken::IdentifierToken()
	: value("undefined") {
}

IdentifierToken::IdentifierToken(indType inType, const std::string& inName, const std::string& inValue)
	: type(inType), name(inName), value(inValue) {
}

IdentifierToken::IdentifierToken(indType inType, const std::string& inName)
	: type(inType), name(inName), value("undefined") {
}

std::string IdentifierToken::getType() const
{
	return "Идентификатор";
}

std::string IdentifierToken::getValue() const
{
	return value;
}

OperationToken::OperationToken()
	: value("") {
}

OperationToken::OperationToken(std::string in)
	: value(in) {
}

std::string OperationToken::getType() const
{
	return "Оператор";
}

std::string OperationToken::getValue() const
{
	return value;
}

SeparetorToken::SeparetorToken()
	: separetor('\0') {
}

SeparetorToken::SeparetorToken(std::string in)
	: separetor(in[0]) {
}

SeparetorToken::SeparetorToken(char in)
	: separetor(in) {
}

std::string SeparetorToken::getType() const
{
	return "Разделитель";
}

std::string SeparetorToken::getValue() const
{
	return std::string();
}

KeywordToken::KeywordToken()
	: value("") {
}

KeywordToken::KeywordToken(std::string in)
	: value(in) {
}

std::string KeywordToken::getType() const
{
	return "Ключевое слово";
}

std::string KeywordToken::getValue() const
{
	return std::string();
}
