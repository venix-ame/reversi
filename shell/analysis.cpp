/***
 * Reversi - 黑白棋程序 (shell)
 * by venix, March 2023
 * 
 * analysis.cpp
 * 命令行参数分拆
***/

#include "shell.h"

std::string trimCommandSpace(std::string command);

/***
 * std::vector<std::string> analysisCommandArguments(std::string command)
 * 
 * 以空格为单位分拆命令行参数, 并返回一个数组.
***/
std::vector<std::string> analysisCommandArguments(std::string command)
{
    // 消去前置空格, 反转, 消去后置空格, 反转
    // 此时可以保证命令行参数内没有前后空格.

    std::string commandTrimed = trimCommandSpace(command);
    std::reverse(std::begin(commandTrimed), std::end(commandTrimed));
    commandTrimed = trimCommandSpace(commandTrimed);
    std::reverse(std::begin(commandTrimed), std::end(commandTrimed));

    // 转换大小写.
    std::transform(std::begin(commandTrimed), std::end(commandTrimed), std::begin(commandTrimed), ::tolower);

    if(commandTrimed == "") {
        return {};
    }

    // 从参数的开头开始遍历, 直到出现第一个空格或者字符串的结束符, 视为参数结束.
    // 如果字符串未结束, 则跳过中间的空格, 直到出现第一个非空格, 设置为新参数的开头.

    std::vector<std::string> arguments;
    unsigned int argStart = 0, argEnd = 0;

    // 这里是字符串的长度+1 因为需要统计到结束符 
    while(argEnd < commandTrimed.length()+1) {
        if(commandTrimed[argEnd] == ' ' || commandTrimed[argEnd] == 0x00) {
            std::string s = commandTrimed.substr(argStart, argEnd-argStart);
            arguments.push_back(s);

            while(commandTrimed[argEnd] == ' ') {
                argEnd++;
            }

            argStart = argEnd;
        }
        
        argEnd++;
    }

    return arguments;
}

/***
 * std::string trimCommandSpace(std::string command)
 * 
 * 消去命令行参数的前置空格.
***/
std::string trimCommandSpace(std::string command)
{
    size_t pos = command.find_first_not_of(' ', 0);

    if(pos == std::string::npos) {
        return std::string();
    } else {
        return command.substr(pos, command.length()-pos);
    }
}
