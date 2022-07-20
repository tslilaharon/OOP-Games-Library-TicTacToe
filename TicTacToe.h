#pragma once
#include <iostream>
#include "Board.h"

class TicTacToe :public Board {

public:
    TicTacToe() :Board(3, 3) {}
    void setPlayerMove(Move& m);
    bool validMove(Move& m)const;
    bool gameEnd();

private:
    //x
    bool rowWinX() const;
    bool colWinX() const;
    bool diagonalWinX() const;

    //o
    bool rowWinO() const;
    bool colWinO() const;
    bool diagonalWinO() const;

    //tie
    bool tieEnd() const;
};
