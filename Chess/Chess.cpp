/*
 * Chess.cpp
 *
 *  Created on: Sep 23, 2014
 *      Author: mc146u04
 */

#include "Chess.h"
#include "CinReader.h"
#include "PointPair.h"
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
		->setName("R")
		->setPointValue(3);
	board[1][0] = new ChessPiece();
	board[1][0]->setTeam(Team::Black)
		->setCritical(false)
		->setName("N")
		->setPointValue(2);
	board[2][0] = new ChessPiece();
	board[2][0]->setTeam(Team::Black)
		->setCritical(false)
		->setName("B")
		->setPointValue(4);
	board[3][0] = new ChessPiece();
	board[3][0]->setTeam(Team::Black)
		->setCritical(false)
		->setName("Q")
		->setPointValue(10);
	board[4][0] = new ChessPiece();
	board[4][0]->setTeam(Team::Black)
		->setCritical(true)
		->setName("K")
		->setPointValue(100);
	board[5][0] = new ChessPiece();
	board[5][0]->setTeam(Team::Black)
		->setCritical(false)
		->setName("B")
		->setPointValue(4);
	board[6][0] = new ChessPiece();
	board[6][0]->setTeam(Team::Black)
		->setCritical(false)
		->setName("N")
		->setPointValue(2);
	board[7][0] = new ChessPiece();
	board[7][0]->setTeam(Team::Black)
		->setCritical(false)
		->setName("R")
		->setPointValue(3);

	//Pawns
	for (int i = 0; i < 8; i++)
	{
		board[i][1] = new ChessPiece();
		board[i][1]->setTeam(Team::Black)
			->setCritical(false)
			->setName("P")
			->setPointValue(1);
	}


	//Set the bottom white row
	board[0][7] = new ChessPiece();
	board[0][7]->setTeam(Team::White)
		->setCritical(false)
		->setName("r")
		->setPointValue(3);
	board[1][7] = new ChessPiece();
	board[1][7]->setTeam(Team::White)
		->setCritical(false)
		->setName("n")
		->setPointValue(2);
	board[2][7] = new ChessPiece();
	board[2][7]->setTeam(Team::White)
		->setCritical(false)
		->setName("b")
		->setPointValue(4);
	board[4][7] = new ChessPiece();
	board[4][7]->setTeam(Team::White)
		->setCritical(false)
		->setName("q")
		->setPointValue(10);
	board[3][7] = new ChessPiece();
	board[3][7]->setTeam(Team::White)
		->setCritical(true)
		->setName("k")
		->setPointValue(100);
	board[5][7] = new ChessPiece();
	board[5][7]->setTeam(Team::White)
		->setCritical(false)
		->setName("b")
		->setPointValue(4);
	board[6][7] = new ChessPiece();
	board[6][7]->setTeam(Team::White)
		->setCritical(false)
		->setName("n")
		->setPointValue(2);
	board[7][7] = new ChessPiece();
	board[7][7]->setTeam(Team::White)
		->setCritical(false)
		->setName("r")
		->setPointValue(3);

	//Pawns
	for (int i = 0; i < 8; i++)
	{
		board[i][6] = new ChessPiece();
		board[i][6]->setTeam(Team::White)
			->setCritical(false)
			->setName("p")
			->setPointValue(1);
	}

}

void Chess::Render()
{
	//ASCII character for 'A'
	int alpha_start = 65;

	//This is the gap at 0,0 before the actual board
	cout << "[X]";

	//We then output a number column for the Xs
	for (int q = 0; q < 8; q++)
	{
		cout << "[" << q << "]";
	}

	//Depending on what team's turn it is, we
	//also conveniently output the team info
	if (currentTurn == White)
		cout << "| White's turn. (LOWERCASE)" << endl;
	else cout << "| Black's turn. (UPPERCASE)" << endl;

	//Iterate Xs
	for (int i = 0; i < 8; i++)
	{
		//Output a letter for the Y column at the
		//beginning of each X row
		cout << "[" << (char)(65 + i) << "]";
		
		//For each x in this Y row
		for (int j = 0; j < 8; j++)
		{
			//Output the name of the piece
			cout << "[" << board[j][i]->getName() << "]";
		}

		//This is a fancy way of outputting more info
		//like current number of points, etc
		if (i == 0)
			cout << "| White: " << GetPointTotal(White) << " points." << endl;
		else if (i == 1)
			cout << "| Black: " << GetPointTotal(Black) << " points." << endl;
		else if (i == 2)
			cout << "| Number of turns: " << turncount << endl;
		else cout << "|" << endl;
	}

	//Padding
	cout << endl;
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

int Chess::GetPointTotal(Team t)
{
	int point_total = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (t == board[i][j]->getTeam())
				point_total += board[i][j]->getPointValue();
		}
	}
	return point_total;
}

PointPair Chess::GrabMovementData()
{
	CinReader reader;
	//Select the piece
	while (true)
	{
		cout << "Enter the NUMBER the piece you would like to select resides in."
			<< endl;
		int X = reader.readInt(0, 7);

		cout << "Now enter the LETTER the piece you would like to select resides in."
			<< endl;

		char row = reader.readChar("ABCDEFGHabcdefgh");

		if (board[X][(int)row - 65]->getTeam() != currentTurn)
		{
			cout << "This piece is not yours." << endl;
			continue;
		}

		if (board[X][(int)row - 65]->getName() == " ")
		{
			cout << "That space is empty." << endl;
			continue;
		}

		//We have a valid selection

	}

}

void Chess::HandleTeamMovement()
{
	if (currentTurn == White)
	{
		//Only allow white to move
		cout << "White may move. ";
		
		auto movement = GrabMovementData();
		
	}
	else
	{
		//Only allow black to move
		cout << "Black may move. ";

		auto movement = GrabMovementData();
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
		turncount++;
	} while (!quitting);
}