#pragma once
#include <iostream>
#include "Game.h"
#include <memory>
#include <vector>

using namespace std;

class Board : public Game
{
public:
    Board(int col, int row) : m_col(col), m_row(row)
    {
        m_board.resize(m_row, vector<char>(m_col, '-'));
    }
    GameStatus getGameStatus()const { return m_status; }
    Move& tryMove();
    void printGameBoard(UI option)const;
    void printTheRes(UI option)const;

protected:
    vector<vector<char>> m_board;
    int m_col;
    int m_row;
};