/***
 * Reversi - 黑白棋程序 (shell)
 * by venix, March 2023
 * 
 * shell.cpp
 * 命令解析器
***/

#include "shell.h"


/***
 * Shell::Shell(void)
 * 
 * 构造函数.
***/
Shell::Shell(void)
{
    this->status = GameStatus::NotStarted;
    this->showChessBoard = true;

    return;
}

/***
 * int Shell::exec(void)
 * 
 * 命令解析器主程序. 
 * 需要做的事情: 循环读取屏幕上的一行内容, 分拆参数并交给命令解析器之后
 * 执行具体操作, 直到退出指令出现.
***/
int Shell::exec(void)
{
    char commandBuffer[MaxStringLength];

    printWelcomeMessage();

    while(true) {
        printPrompt();
        
        std::cin.getline(commandBuffer, MaxStringLength);
        std::string command(commandBuffer);

        std::vector<std::string> arguments = analysisCommandArguments(command);
        if(processor(arguments) != 0) {
            break;
        }
    }

    return 0;
}

/***
 * int Shell::processor(std::vector<std::string> arguments)
 * 
 * 命令解析器程序. 
 * 该函数正常返回值为0, 如果输入了退出命令则返回-1.
***/
int Shell::processor(std::vector<std::string> arguments)
{
    if(arguments.size() == 0) {
        return 0;
    } else {
        if(arguments[0] == "q" || arguments[0] == "quit") {
            return cmd_quit(arguments);
        } else {
            std::cout << "reversi: " << arguments[0] << ": command not found" << std::endl;
            return 0;
        }
    }

    return 0;
}

/***
 * int Shell::cmd_quit(std::vector<std::string> arguments)
 * 
 * 退出程序命令.
***/
int Shell::cmd_quit(std::vector<std::string> arguments)
{
    char buffer[MaxStringLength];

    if(arguments.size() != 1) {
        std::cout << "too many arguments of this command." << std::endl;
        return 0; 
    }

    // 如果游戏仍在运行中, 则需要手动确认是否需要退出.
    if(status == GameStatus::Started) {
        std::cout << "Game is running. Are you confirm to quit? [y/N]"; 
        std::cin.getline(buffer, MaxStringLength);

        std::string s(buffer);
        std::transform(std::begin(s), std::end(s), std::begin(s), ::towlower);

        if(s != "y") {
            std::cout << std::endl;
            return 0; 
        }
    }

    std::cout << std::endl;
    return -1;
}