/***
 * Reversi - 黑白棋程序 (shell)
 * by venix, March 2023
 * 
 * shell.h
 * 定义数据结构和常量
***/

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <cstdlib>
#include <ctype.h>

#include "../base/reversi.h"

/*
    reversi shell的设计

    大概类似于这样的形式: white 13> (command)
    游戏没有开始的时候就是这样: not started> (command)
    表示棋子: a1 (a~h表示行, 1~8表示列)
*/

enum GameStatus {
    NotStarted = 0,
    Started
};

const int buildNumber = 2;

class Shell
{
public:
    Shell(void);

    int exec(void);

private:
    const int MaxStringLength = 256;

    GameStatus status;
    Reversi reversi;
    bool showChessBoard;

    int processor(std::vector<std::string> arguments);
    int cmd_quit(std::vector<std::string> arguments);

    int printAboutMessage(void);
    int printWelcomeMessage(void);
    int printPrompt(void);
};

std::vector<std::string> analysisCommandArguments(std::string command);
