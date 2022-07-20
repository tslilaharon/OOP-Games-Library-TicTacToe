#include "Board.h"

void Board::printGameBoard(UI option) const
{
    if (option == Console)
    {
        cout << "---- + ---- + ----" << endl;

        for (int i = 0; i < m_board.size(); i++)
        {
            cout << ' ';
            for (int j = 0; j < m_board.size(); j++)
            {
                cout << ' ';
                cout << m_board[i][j];
                cout << ' ' << ' ' << "|";
                cout << ' ' << ' ';
            }
            cout << "\n---- + ---- + ----" << endl;
        }
    }
}

void Board::printTheRes(UI option) const {

    if (option == Console) {

        if (getGameStatus() == PlayerWin)
        {
            cout << "\n\n\n-------------------------" << endl;
            cout << "| You did it, you win!  |" << endl;
            cout << "|      Well done        |" << endl;
            cout << "-------------------------\n\n\n" << endl;
        }

        else if (getGameStatus() == ComputerWin)
        {
            cout << "\n\n\n----------------" << endl;
            cout << "you are looser!" << endl;
            cout << "----------------\n\n\n" << endl;
        }

        else if (getGameStatus() == Tie)
        {
            cout << "\n\n\n----------------" << endl;
            cout << "It's a Tie!" << endl;
            cout << "----------------\n\n\n" << endl;
        }

        printGameBoard(option);
        cout << endl;
    }
}

Move& Board::tryMove() {

    char comma;
    int row, col;

    cout << "\n\nPosition Table: " << endl;
    cout << "---- - ---- - ----" << endl;
    cout << " 1,1 |  1,2 |  1,3" << endl;
    cout << "---- + ---- + ----" << endl;
    cout << " 2,1 |  2,2 |  2,3" << endl;
    cout << "---- + ---- + ----" << endl;
    cout << " 3,1 |  3,2 |  3,3" << endl;
    cout << "---- - ---- - ----" << endl;

    cout << "Enter position (row, col): " << endl;
    cin >> row;
    cin >> comma;
    cin >> col;

    m_move.setX(row - 1);
    m_move.setY(col - 1);

    return m_move;
}