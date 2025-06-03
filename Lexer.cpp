#include "Lexer.h"

bool Lexer::lexFile()
{
    while (input.peek() != EOF) {
        readWord();
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
        if (utils::isTypeKeyword(buffer))
            lastTypeToken = token.get();
    }
    else if (utils::is_separetor(buffer[0]))
    {
        token = std::make_unique<SeparetorToken>(buffer[0]);
    }
    else if (utils::is_operator(buffer))
    {
        token = std::make_unique<OperationToken>(buffer);
    }
    else
    {
        auto pos = buffer.find("()");
        if (symbolTable.check_name(buffer))
        {
            token = std::make_unique<IdentifierToken>(symbolTable.getToken(buffer));
        }
        else
        {
            // Если имя НЕ найдено, смотрим на последний токен типа:

            if (lastTypeToken->getType() == "Ключевое слово")
            {
                std::string kw = lastTypeToken->getValue();

                if (utils::isTypeKeyword(kw))
                {
                    indType t = IdentifierToken::getType(kw);
                    token = std::make_unique<IdentifierToken>(t, buffer);
                    IdentifierToken newTok = *dynamic_cast<IdentifierToken*>(token.get()); // опасный момент
                    symbolTable.add(buffer, newTok);
                }

            }
            else
                errors.push_back("Ошибка: неизвестный идентификатор " + buffer + ".");
        }
    }
    return token; /////////////////////////////////////////////// УБРАТЬ
}


