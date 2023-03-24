/***
 * Reversi - 黑白棋程序 (shell)
 * by venix, March 2023
 * 
 * print.cpp
 * 打印函数组
***/

#include "shell.h"


/***
 * int Shell::printAboutMessage(void) 
 * 
 * 在屏幕上打印制作者信息.
***/
int Shell::printAboutMessage(void)
{
    std::cout << "Reversi Command Line Shell" << std::endl;
    std::cout << "build_" << buildNumber << ", by venix" << std::endl;
    std::cout << std::endl;

    return 0;
}

/***
 * int Shell::printWelcomeMessage(void) 
 * 
 * 在屏幕上打印欢迎信息.
***/
int Shell::printWelcomeMessage(void)
{
    std::cout << std::endl;
    printAboutMessage();
    
    std::cout << "Welcome to Reversi game!" << std::endl;
    std::cout << "You can type command \"s\" or \"rb x\" or \"rw x\" (x = 1~3) to start a new game, " << std::endl;
    std::cout << "or type \"h\" to view more help informations. " << std::endl;
    std::cout << std::endl;

    return 0;
}

/***
 * int Shell::printPrompt(void) 
 * 
 * 打印提示符.
 * 没有开始游戏时, 提示符如下: "not started>"
 * 开始游戏时, 提示符如下: "[current player] [times]>"
 * 如: "black 0>" 或者 "white 23>".
***/
int Shell::printPrompt(void)
{
    if(status == GameStatus::NotStarted) {
        std::cout << "not started";
    }

    std::cout << '>';

    return 0;
}
