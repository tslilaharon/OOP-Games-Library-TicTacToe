#include <iostream>
#include "TicTacToe.h"

bool TicTacToe::validMove(Move& m) const
{
    if (m.getX() != 0 && m.getX() != 1 && m.getX() != 2)
    {
        cerr << "Invalid Move" << endl;
        return false;
    }

    if (m.getY() != 0 && m.getY() != 1 && m.getY() != 2) {
        cerr << "Invalid Move" << endl;
        return false;
    }

    if (m_board[m.getX()][m.getY()] != '-') {
        cerr << "Invalid Move" << endl;
        return false;
    }
    return true;
}

void TicTacToe::setPlayerMove(Move& m)
{
    if (!validMove(m))
        cerr << "Invalid Move";
 
    m_board[m.getX()][m.getY()] = 'X';
}

//x
bool TicTacToe::rowWinX() const
{
    int counter = 0;
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            if (m_board[i][j] == 'X')
            {
                counter++;
            }
        }
        if (counter == 3)
        {
            return true;
        }
        counter = 0;
    }
    return false;
}

bool TicTacToe::colWinX() const
{
    int counter = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (m_board[i][j] == 'X')
            {
                counter++;
            }
        }
        if (counter == 3)
        {
            return true;
        }
        counter = 0;
    }
    return false;
}

bool TicTacToe::diagonalWinX() const
{
    int counter = 0;
    for (int j = 0, i = 0; j < 3; j++, i++)
    {
        if (m_board[i][j] == 'X')
        {
            counter++;
        }
    }
    if (counter == 3)
    {
        return true;
    }
    counter = 0;

    for (int j = 0, i = 2; j < 3; j++, i--)
    {
        if (m_board[i][j] == 'X')
        {
            counter++;
        }
    }
    if (counter == 3)
    {
        return true;
    }
    return false;
}

//o
bool TicTacToe::rowWinO() const
{
    int counter = 0;
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            if (m_board[i][j] == 'O')
            {
                counter++;
            }
        }
        if (counter == 3)
        {
            return true;
        }
        counter = 0;
    }
    return false;
}

bool TicTacToe::colWinO() const
{
    int counter = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (m_board[i][j] == 'O')
            {
                counter++;
            }
        }
        if (counter == 3)
        {
            return true;
        }
        counter = 0;
    }
    return false;
}

bool TicTacToe::diagonalWinO() const
{
    int counter = 0;
    for (int j = 0, i = 0; j < 3; j++, i++)
    {
        if (m_board[i][j] == 'O')
        {
            counter++;
        }
    }
    if (counter == 3)
    {
        return true;
    }

    counter = 0;

    for (int j = 0, i = 2; j < 3; j++, i--)
    {
        if (m_board[i][j] == 'O')
        {
            counter++;
        }
    }
    if (counter == 3)
    {
        return true;
    }
    return false;
}

//tie
bool TicTacToe::tieEnd() const
{
    int counter = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (m_board[i][j] == '-')
            {
                return false;
            }
        }
    }
    return true;
}

//checking the status of game 
bool TicTacToe::gameEnd()
{
    //x -> Player Win
    if (rowWinX() || colWinX() || diagonalWinX())
    {
        m_status = PlayerWin;
        return true;
    }
    //o -> Computer Win
    else if (rowWinO() || colWinO() || diagonalWinO())
    {
        m_status = ComputerWin;
        return true;
    }
    //|| ->tie
    else if (tieEnd())
    {
        m_status = Tie;
        return true;
    }
    m_status = Progress;
    return false;
}