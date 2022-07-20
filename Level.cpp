#include "Level.h"
///--------------Level Low--------------

void LevelLow::setComputerMove()
{
    bool valid = false;
    while (!valid)
    {
        //rand computer choice
        int computerPos = (rand() % 9) + 1;
        int row = (computerPos - 1) / 3;
        int col = (computerPos - 1) % 3;

        char pos = m_board[row][col];
        //not available pos
        if (pos == 'X' || pos == 'O') 
            continue;
        else
        {
            valid = true;
            m_board[row][col] = 'O';
        }
    }
}

///---- Level Meduim  -> Not currently supported ----