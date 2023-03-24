/***
 * Reversi - 黑白棋程序 (shell)
 * by venix, March 2023
 * 
 * main.cpp
 * 命令行交互程序总入口
***/

#include "shell.h"

int main(void)
{
    Shell shell = Shell();
    return shell.exec();
}
