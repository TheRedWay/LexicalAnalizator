#pragma once
#include "Lexer.h"
class MainMenu :
    public Lexer
{
    std::string fileName;
    enum funcs{fileName,start,info,exit};

    void showList();
    void showInfo();

    funcs getCommand();
public: 
    void start();
};

