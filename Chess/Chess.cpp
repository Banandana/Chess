/*
 * Chess.cpp
 *
 *  Created on: Sep 23, 2014
 *      Author: mc146u04
 */

#include "Chess.h"

Chess::Chess() {
  // TODO Auto-generated constructor stub
  //Do stuff like make teh board an 8x8 array of 0s
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      board[i][j] = 0;
    }
  }

  //Set the white to the current turn
  currentTurn = Team::White;
}

Chess::~Chess() {
  // TODO Auto-generated destructor stub
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			delete board[i][j];
		}
		delete[] board[i];
	}
}

void Chess::InitializeGameBoard()
{
	//Set the board
}

void Chess::Play()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << "[" << board[i][j] << "]";
		}
	}
}