/*
 * Chess.cpp
 *
 *  Created on: Sep 23, 2014
 *      Author: mc146u04
 */

#include "Chess.h"
#include "CinReader.h"
#include "Movement.h"
#include <string>

enum MenuChoice
{
	MovePiece,
	Undo,
	Restart,
	Quit
};

Chess::Chess() {
	// TODO Auto-generated constructor stub
	//Do stuff like make teh board an 8x8 array of 0s

	board = new ChessPiece*[8];
	for (int i = 0; i < 8; i++)
	{
		board[i] = new ChessPiece[8];
		for (int j = 0; j < 8; j++)
		{
			board[i][j] = ChessPiece();
			board[i][j].setName(" ");
		}
	}

	//Set the white to the current turn
	currentTurn = Team::White;
}

Chess::~Chess() {
	// TODO Auto-generated destructor stub
	for (int i = 0; i < 8; i++)
	{
		delete[] board[i];
	}
	delete[] board;
}

void Chess::InitializeGameBoard()
{
	//Set the board

	//This function is inherently bad.

	//Clear the board.
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			board[i][j].setName(" ")
				->setTeam(Team::None)
				->setPointValue(0)
				->setCritical(false);
		}
	}


	//Set the top black row
	board[0][0].setTeam(Team::Black)
		->setCritical(false)
		->setName("R")
		->setPointValue(3);
	board[1][0].setTeam(Team::Black)
		->setCritical(false)
		->setName("N")
		->setPointValue(2);
	board[2][0].setTeam(Team::Black)
		->setCritical(false)
		->setName("B")
		->setPointValue(4);
	board[3][0].setTeam(Team::Black)
		->setCritical(false)
		->setName("Q")
		->setPointValue(10);
	board[4][0].setTeam(Team::Black)
		->setCritical(true)
		->setName("K")
		->setPointValue(100);
	board[5][0].setTeam(Team::Black)
		->setCritical(false)
		->setName("B")
		->setPointValue(4);
	board[6][0].setTeam(Team::Black)
		->setCritical(false)
		->setName("N")
		->setPointValue(2);
	board[7][0].setTeam(Team::Black)
		->setCritical(false)
		->setName("R")
		->setPointValue(3);

	//Pawns
	for (int i = 0; i < 8; i++)
	{
		board[i][1].setTeam(Team::Black)
			->setCritical(false)
			->setName("P")
			->setPointValue(1);
	}


	//Set the bottom white row
	board[0][7].setTeam(Team::White)
		->setCritical(false)
		->setName("r")
		->setPointValue(3);
	board[1][7].setTeam(Team::White)
		->setCritical(false)
		->setName("n")
		->setPointValue(2);
	board[2][7].setTeam(Team::White)
		->setCritical(false)
		->setName("b")
		->setPointValue(4);
	board[4][7].setTeam(Team::White)
		->setCritical(false)
		->setName("q")
		->setPointValue(10);
	board[3][7].setTeam(Team::White)
		->setCritical(true)
		->setName("k")
		->setPointValue(100);
	board[5][7].setTeam(Team::White)
		->setCritical(false)
		->setName("b")
		->setPointValue(4);
	board[6][7].setTeam(Team::White)
		->setCritical(false)
		->setName("n")
		->setPointValue(2);
	board[7][7].setTeam(Team::White)
		->setCritical(false)
		->setName("r")
		->setPointValue(3);

	//Pawns
	for (int i = 0; i < 8; i++)
	{
		board[i][6].setTeam(Team::White)
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
			cout << "[" << board[j][i].getName() << "]";
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
			if (board[i][j].isCritical() &&
				t == board[i][j].getTeam()) critical_piece_count++;
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
			if (t == board[i][j].getTeam())
				point_total += board[i][j].getPointValue();
		}
	}
	return point_total;
}

Move Chess::GrabMovementData()
{
	Move ret_movement;

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

		if (board[X][(int)row - 65].getTeam() != currentTurn)
		{
			cout << "This piece is not yours." << endl;
			continue;
		}

		if (board[X][(int)row - 65].getName() == " ")
		{
			cout << "That space is empty." << endl;
			continue;
		}

		//We have a valid selection
		//Set the 'from' item

		ret_movement.From = Point(X, (int)row - 65);
		ret_movement.PieceFrom = board[X][(int)row - 65];
		break;
	}

	//Select the destination
	while (true)
	{
		cout << "Enter the NUMBER the location you would like to move to is at."
			<< endl;
		int X = reader.readInt(0, 7);

		cout << "Now enter the LETTER the location you would like to move to is at."
			<< endl;

		char row = reader.readChar("ABCDEFGHabcdefgh");

		if (board[X][(int)row - 65].getTeam() == currentTurn)
		{
			cout << "You cannot overwrite your own piece." << endl;
			continue;
		}

		//We have a valid destination
		//Set the 'from' item

		ret_movement.To = Point(X, (int)row - 65);
		ret_movement.PieceTo = board[X][(int)row - 65];
		break;
	}

	return ret_movement;
}

void Chess::HandleTeamMovement()
{
	if (currentTurn == White)
		cout << "White may move. ";
	else
		cout << "Black may move. ";
		//Get the movement data
		auto movement = GrabMovementData();
		
		//Record the last movement from the player
		lastMove = movement;

		//Set the location the piece will move to to the actual value of the
		//piece from.
		board[movement.To.X][movement.To.Y] = movement.PieceFrom;

		//Set the blank space
		board[movement.From.X][movement.From.Y] = ChessPiece();
		board[movement.From.X][movement.From.Y].setName(" ")
			->setTeam(Team::None)
			->setPointValue(0)
			->setCritical(false);
	
}

void Chess::Restart()
{
	//Reset the board
	InitializeGameBoard();
	
	//Set board to white
	currentTurn = White;
	
	//Remove undo data
	lastMove.From = Point();
	lastMove.To = Point();
	lastMove.PieceFrom = ChessPiece();
	lastMove.PieceTo = ChessPiece();

	turncount = 0;

	quitting = false;
}

void Chess::Undo()
{
	//Set the pieces to their old values
	board[lastMove.From.X][lastMove.From.Y] = lastMove.PieceFrom;
	board[lastMove.To.X][lastMove.To.Y] = lastMove.PieceTo;
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

		CinReader reader;

		cout << "Press m to move, u to undo, r to reset, or q to quit" << endl;
		char choice = tolower(reader.readChar("mMuUrRqQ"));

		if (choice == 'm')
			HandleTeamMovement();
		else if (choice == 'u')
			Undo();
		else if (choice == 'r')
			Restart();
		else quitting = true;

		//Swap turns
		if (currentTurn == Team::White) currentTurn = Team::Black;
		else currentTurn = Team::White;
		turncount++;
	} while (!quitting);
}