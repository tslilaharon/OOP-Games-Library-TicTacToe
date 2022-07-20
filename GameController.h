#pragma once
#include <iostream>
#include "Level.h"
#include <memory>

using namespace std;

class GameController
{
public:
    void play();

private:
    shared_ptr<Game> m_game;
};