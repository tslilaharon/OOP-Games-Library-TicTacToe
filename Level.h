#pragma once
#include <iostream>
#include "TicTacToe.h"

//Level Low 
class LevelLow : public TicTacToe
{
public:
	LevelLow() :TicTacToe() {}
	void setComputerMove();
};

//Level Meduim  -> Not currently supported
class LevelMeduim : public TicTacToe
{
public:
	//LevelMeduim() :TicTacToe() {}
	//void setComputerMove();
};