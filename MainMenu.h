#pragma once
#ifndef MAINMENU
#define MAINMENU


#include "Lexer.h"

class MainMenu :
    public Lexer
{

    bool file_is_loaded;
    std::string inputFileName;
    enum funcs{fileName,start,info,exit};

    void showList();
    void showInfo();

    funcs getCommand();
public: 
    void open();
    void showTokensTable();
    void showSymbolTable();
    void showErrors();
    MainMenu(): file_is_loaded(0){}
};

#endif // !MainMenu