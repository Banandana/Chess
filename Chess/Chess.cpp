/*
 * Chess.cpp
 *
 *  Created on: Sep 23, 2014
 *      Author: mc146u04
 */

#include "Chess.h"
#include <string>
Chess::Chess() {
	// TODO Auto-generated constructor stub
	//Do stuff like make teh board an 8x8 array of 0s
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			board[i][j] = new ChessPiece();
			board[i][j]->setName(" ");
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

	//This function is inherently bad.

	//Set the top black row
	board[0][0] = new ChessPiece();
	board[0][0]->setTeam(Team::Black)
		->setCritical(false)
		->setName("R");
	board[1][0] = new ChessPiece();
	board[1][0]->setTeam(Team::Black)
		->setCritical(false)
		->setName("N");
	board[2][0] = new ChessPiece();
	board[2][0]->setTeam(Team::Black)
		->setCritical(false)
		->setName("B");
	board[3][0] = new ChessPiece();
	board[3][0]->setTeam(Team::Black)
		->setCritical(false)
		->setName("Q");
	board[4][0] = new ChessPiece();
	board[4][0]->setTeam(Team::Black)
		->setCritical(true)
		->setName("K");
	board[5][0] = new ChessPiece();
	board[5][0]->setTeam(Team::Black)
		->setCritical(false)
		->setName("B");
	board[6][0] = new ChessPiece();
	board[6][0]->setTeam(Team::Black)
		->setCritical(false)
		->setName("N");
	board[7][0] = new ChessPiece();
	board[7][0]->setTeam(Team::Black)
		->setCritical(false)
		->setName("R");

	//Pawns
	for (int i = 0; i < 8; i++)
	{
		board[i][1] = new ChessPiece();
		board[i][1]->setTeam(Team::Black)
			->setCritical(false)
			->setName("P");
	}


	//Set the bottom white row
	board[0][7] = new ChessPiece();
	board[0][7]->setTeam(Team::White)
		->setCritical(false)
		->setName("r");
	board[1][7] = new ChessPiece();
	board[1][7]->setTeam(Team::White)
		->setCritical(false)
		->setName("n");
	board[2][7] = new ChessPiece();
	board[2][7]->setTeam(Team::White)
		->setCritical(false)
		->setName("b");
	board[3][7] = new ChessPiece();
	board[3][7]->setTeam(Team::White)
		->setCritical(false)
		->setName("q");
	board[4][7] = new ChessPiece();
	board[4][7]->setTeam(Team::White)
		->setCritical(true)
		->setName("k");
	board[5][7] = new ChessPiece();
	board[5][7]->setTeam(Team::White)
		->setCritical(false)
		->setName("b");
	board[6][7] = new ChessPiece();
	board[6][7]->setTeam(Team::White)
		->setCritical(false)
		->setName("n");
	board[7][7] = new ChessPiece();
	board[7][7]->setTeam(Team::White)
		->setCritical(false)
		->setName("r");

	//Pawns
	for (int i = 0; i < 8; i++)
	{
		board[i][6] = new ChessPiece();
		board[i][6]->setTeam(Team::White)
			->setCritical(false)
			->setName("p");
	}

}

void Chess::Render()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << "[" << board[j][i]->getName() << "]";
		}
		cout << endl;
	}
}

int Chess::GetCriticalPieceCount(Team t)
{
	int critical_piece_count = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[i][j]->isCritical() &&
				t == board[i][j]->getTeam()) critical_piece_count++;
		}
	}
	return critical_piece_count;
}

void Chess::HandleTeamMovement()
{
	if (currentTurn == White)
	{
		//Only allow white to move
		cout << "White may move. Please enter an X and Y value of what"
			<< "piece you would like to select.";


	}
	else
	{
		//Only allow black to move
	}
}

void Chess::Play()
{
	//init here
	InitializeGameBoard();

	//Count critical pieces
	int crit_piece_count_white = GetCriticalPieceCount(White);
	int crit_piece_count_black = GetCriticalPieceCount(Black);

	do {
		//Render
		Render();

		//Do game logic here
		if (crit_piece_count_black > GetCriticalPieceCount(Black))
		{
			//White wins
			cout << "White wins. A critical black piece was destroyed.";
		}
		if (crit_piece_count_white > GetCriticalPieceCount(White))
		{
			//Black wins
			cout << "Black wins. A critical white piece was destroyed.";
		}

		HandleTeamMovement();

		//Swap turns
		if (currentTurn == Team::White) currentTurn = Team::Black;
		else currentTurn = Team::White;
	} while (!quitting);
}