#pragma once
#ifndef TOKEN
#define TOKEN


#include <string>
#include <stdexcept>
#include "SymbolTable.h"
#include "utils.h"
class Token
{
public:
    virtual std::string getType() const = 0;
    virtual std::string getValue() const = 0;
    virtual ~Token() = default;
};



class KeywordToken : public Token
{
    std::string value;
public:
    KeywordToken();
    KeywordToken(std::string in);

    std::string getType() const override;
    std::string getValue() const override;
};

class SeparetorToken : public Token
{
    char separetor;
public:
    SeparetorToken();
    SeparetorToken(std::string in);
    SeparetorToken(char in);

    std::string getType() const override;
    std::string getValue() const override;
};

enum indType : char {_bool, _char, _wchar, _short, _int, _float, _double, _long};
class IdentifierToken : public Token
{
    indType type;
    std::string name;


   

public:
    static indType getType(std::string);
    IdentifierToken();
    IdentifierToken(indType inType, const std::string& inName);
    IdentifierToken(const IdentifierToken&) = default;
    IdentifierToken& operator=(const IdentifierToken&) = default;

    std::string getType() const override;
    std::string getValue() const override;
};

class OperationToken : public Token
{
    std::string value;
public:
    OperationToken();
    OperationToken(std::string in);

    std::string getType() const override;
    std::string getValue() const override;
};

template<typename type>
class ConstToken : public Token
{
    type value;
public:
    ConstToken();
    ConstToken(type in);
    std::string getType() const override;
    std::string getValue() const override;



};
#endif // !TOKEN


