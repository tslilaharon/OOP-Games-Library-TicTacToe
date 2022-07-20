#pragma once
#include <iostream>
#include "Move.h"

enum GameStatus 
{ 
    PlayerWin, 
    ComputerWin, 
    Tie, 
    Progress 
};

enum UI 
{ 
    Console, 
    GUI
};

class Game
{
public:
    virtual void setPlayerMove(Move& m) = 0;
    virtual void setComputerMove() = 0;

    virtual GameStatus getGameStatus()const = 0;
    virtual bool validMove(Move& m) const = 0;
    virtual Move& tryMove() = 0;

    virtual bool gameEnd() = 0;
    virtual void printGameBoard(UI option) const = 0;
    virtual void printTheRes(UI option) const = 0;

protected:
    Move m_move;
    GameStatus m_status;
};