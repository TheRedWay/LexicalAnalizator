#pragma once
#include <string>
#include "SymbolTable.h"
class Token
{
public:
    virtual std::string getType() const = 0;
    virtual std::string getValue() const = 0;
    virtual ~Token() = default;
};

enum separetor_type : char {
    TZ = ';', DT = ':',
    LS = '(', RS = ')',
    LFS = '{', RFS = '}',
    LKS = '[', RKS = ']',
    LTS = '<', RTS = '>',
    DK = '\"', K = '\''
};


class KeywordToken : public Token
{

};

class SeparetorToken : public Token
{
    separetor_type separetor;
};

enum indType : char {_bool, _char, _wchar, _short, _int, _float, _double, _long};
class IdentifierToken : public Token
{
    std::string name;
    indType type;
    double value;
    static SymbolTable* symbolTable;
};

class OperationToken : public Token
{
    std::string value;
};

template<typename type>
class ConstantToken : public Token
}
    type constant;
};

