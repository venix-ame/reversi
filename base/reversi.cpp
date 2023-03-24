/***
 * Reversi - 黑白棋程序 (base)
 * by venix, March 2023
 * 
 * reversi.cpp
 * 黑白棋类的构造函数和杂项函数
***/

#include "reversi.h"

/***
 * Reversi::Reversi (GameMode gameMode)
 * 
 * 构造函数.
***/
Reversi::Reversi(void)
{
    this->currentPlayer = Player::BlackPlayer;
    this->chessTimes = 0;

    std::fill(std::begin(this->chessBoard), std::end(this->chessBoard), Pieces::Null);
    
    this->chessBoard[convertCoordToIndex(4, 5)] = Pieces::Black;
    this->chessBoard[convertCoordToIndex(5, 4)] = Pieces::Black;
    this->chessBoard[convertCoordToIndex(4, 4)] = Pieces::White;
    this->chessBoard[convertCoordToIndex(5, 5)] = Pieces::White;

    return;
}

/***
 * int convertCoordToIndex(int x, int y)
 * 
 * 将棋盘坐标转换为棋盘数组的下标.
***/
constexpr int convertCoordToIndex(int x, int y)
{
    return (y-1)*8+(x-1);
}
