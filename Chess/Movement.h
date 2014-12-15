#pragma once
#include "Point.h"

struct Move
{
	Point From;
	Point To;
	ChessPiece PieceFrom;
	ChessPiece PieceTo;
};