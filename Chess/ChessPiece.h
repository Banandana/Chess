/*
 * ChessPiece.h
 *
 *  Created on: Sep 23, 2014
 *      Author: mc146u04
 */

#pragma once
#include "common.h"
#include "Point.h"

using namespace std;

enum BehaviorStyle
{
	Continuous,
	Incremental
};

enum Team
{
	None = 0,
	Black,
	White
};

enum PieceModifierType
{
	Blank,
	Movable,
	Attackable,
	Movable_Recursive,
	Attackable_Recursive
};

class ChessPiece {
	//Have a 5x5 movement and attack grid for each piece
	string name_;
	bool critical_;
	Team team_;

	

public:
	string getName();
	ChessPiece* setName(string name);
	bool isCritical();
	ChessPiece* setCritical(bool crit);
	Team getTeam();
	ChessPiece* setTeam(Team t);
	PieceModifierType** Movement_Attack_Grid;
	ChessPiece();
	~ChessPiece();
};