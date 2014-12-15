/*
 * ChessPiece.cpp
 *
 *  Created on: Sep 23, 2014
 *      Author: mc146u04
 */

#include "ChessPiece.h"

ChessPiece::ChessPiece() {
  // TODO Auto-generated constructor stub
	Movement_Attack_Grid = new PieceModifierType*[5];

	for (int i = 0; i < 5; i++)
	{
		Movement_Attack_Grid[i] = new PieceModifierType[5];
		for (int j = 0; j < 5; j++)
		{
			Movement_Attack_Grid[i][j] = PieceModifierType::Blank;
		}
	}
}

ChessPiece::~ChessPiece() {
  // TODO Auto-generated destructor stub
}

string ChessPiece::getName()
{
	return name_;
}

bool ChessPiece::isCritical()
{
	return critical_;
}

Team ChessPiece::getTeam()
{
	return team_;
}

ChessPiece* ChessPiece::setCritical(bool crit)
{
	critical_ = crit;
	return this;
}

ChessPiece* ChessPiece::setName(string name)
{
	name_ = name;
	return this;
}

ChessPiece* ChessPiece::setTeam(Team t)
{
	team_ = t;
	return this;
}
