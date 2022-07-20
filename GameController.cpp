#include "GameController.h"

void GameController::play()
{
    cout << "------------------------------" << endl;
    cout << "-Welcome to the Games library-" << endl;
    cout << "------------------------------" << endl;

    while (1)
    {
        int chooseGame;
        cout << "-> Please choose a Game: " << endl;
        cout << "1. Tic Tac Toe" << endl;
        cout << "(New games, coming soon...)\n" << endl;
        cout << "To Exit enter -> 5\n\n" << endl;

        cin >> chooseGame;

        if (chooseGame == 5)
            return;
        while (chooseGame != 1)
        {
            cerr << "Oh no! the game you selected is not found, please try again" << endl;
            cin >> chooseGame;
        }

        int chooseNum;
        cout << "You chose the TIC - TAC - TOE game, a great choice" << endl;
        cout << "1. To Continue" << endl;
        cout << "2. To Rules" << endl;
        cout << "To Exit enter -> 5\n\n" << endl;

        cin >> chooseNum;

        if (chooseNum == 5)
            return;
        while (chooseNum != 1)
        {
            if (chooseNum == 2)
            {
                cout << "Rules for TIC - TAC - TOE game" << endl;
                cout << "1. The game is played on a grid that's 3 squares by 3 squares." << endl;
                cout << "2. You, your friend or the computer is O.Players take turns putting their marks in empty squares." << endl;
                cout << "3. The first player to get 3 of her marks in a row(up, down, across, or diagonally) is the winner." << endl;
                cout << "4. When all 9 squares are full, the game is over.If no player has 3 marks in a row, the game ends in a tie.\n\n" << endl;
                break;
            }
            else
            {
                cerr << "try again" << endl;
                cin >> chooseNum;
            }
        }


        UI optionUI;
        int chooseUI;
        cout << "-> Please choose view option: " << endl;
        cout << "1. Console " << endl;
        cout << "2. GUI \n" << endl;
        cout << "To Exit enter -> 5\n\n" << endl;

        cin >> chooseUI;

        if (chooseUI == 5)
            return;
        while (chooseUI != 1)
        {
            if (chooseUI == 2)
            {
                cerr << "Ooh! the GUI option be available soon, try the console option\n" << endl;
                break;
            }
            else
            {
                cerr << "try again" << endl;
                cin >> chooseUI;
            }
        }
        optionUI = Console;

        int chooseLevel;
        cout << "-> Please choose Level: " << endl;
        cout << "1. Low " << endl;
        cout << "2. Meduim \n" << endl;
        cout << "To Exit enter -> 5\n\n" << endl;


        cin >> chooseLevel;

        if (chooseLevel == 5)
            return;
        while (chooseLevel != 1 && chooseLevel != 2)
        {
            cerr << "the level you selected is not found, please try again" << endl;
            cin >> chooseLevel;
        }

        if (chooseGame == 1)
        {
            if (chooseLevel == 1)
                m_game = shared_ptr<Game>(new LevelLow());

            else if (chooseLevel == 2)
            {
                cerr << "Ooh! the Meduim level option be available soon, try the Low level option\n" << endl;
                m_game = shared_ptr<Game>(new LevelLow);
            }
        }

   
        Move playerMove;
        cout << "----------------------------------" << endl;
        cout << " The -TIC - TAC - TOE- game start" << endl;
        cout << "----------------------------------" << endl;
        while (chooseGame == 1 && !m_game->gameEnd())
        {         
            m_game->printGameBoard(optionUI);

            do {playerMove = m_game->tryMove();} 
            while (!(m_game->validMove(playerMove)));

            m_game->setPlayerMove(playerMove);

            if (m_game->gameEnd())
            {
                m_game->printTheRes(optionUI);
                break;
            }
            m_game->setComputerMove();

            if (m_game->gameEnd())
            {
                m_game->printTheRes(optionUI);
                break;
            }
        }

    }
}