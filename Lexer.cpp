#include "Lexer.h"

bool Lexer::lexFile()
{
    while (readWord()) {
        tokensTable.push_back(createToken());
    }


    return true;
}



std::unique_ptr<Token> Lexer::createToken()
{
    std::unique_ptr<Token> token = nullptr;
    char c = buffer[0];
    
    if (utils::is_number(c)) 
    {
        if (buffer.find('.') == std::string::npos) 
        {
            int result;
            std::from_chars(buffer.data(), buffer.data() + buffer.size(), result);
            token = std::make_unique<ConstToken<int>>(result);
        }
        else 
        {
            double result;
            std::from_chars(buffer.data(), buffer.data() + buffer.size(), result);
            token = std::make_unique<ConstToken<double>>(result);
        }
    }
    else if (c == '\"' or c == '\'')
    {
        token = std::make_unique<ConstToken<std::string>>(buffer);
    }
    else if (utils::is_keyword(buffer)) 
    {
        token = std::make_unique<KeywordToken>(buffer);
    }
    else if (utils::is_separetor(buffer[0])) 
    {
        token = std::make_unique<SeparetorToken>(buffer[0]);
    }
    else if (utils::is_operator(buffer)) {
        token = std::make_unique<OperationToken>(buffer);
    }
    else
    {
        //идентификаторы
    }
    return token; /////////////////////////////////////////////// УБРАТЬ
}


