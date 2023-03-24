/***
 * Reversi - 黑白棋程序 (base)
 * by venix, March 2023
 * 
 * reversi.h
 * 定义数据结构和常量
***/

#pragma once

#include <array>
#include <algorithm>

enum Player {
    BlackPlayer = 0,
    WhitePlayer
};

enum Pieces {
    Null = 0,
    Black,
    White
};

// 对于黑白棋游戏的逻辑抽象类, 需要实现以下功能:
// 1. 实现开始游戏函数.
// 2. 实现落子函数, 判定落子结果是正常落子, 违反规则还是无落子  

class Reversi {
public:
    Reversi(void);

private:
    Player currentPlayer;
    std::array<Pieces, 64> chessBoard;

    int chessTimes;
};

constexpr int convertCoordToIndex(int x, int y);
