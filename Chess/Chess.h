/*
 * Chess.h
 *
 *  Created on: Sep 23, 2014
 *      Author: mc146u04
 */

#pragma once
#include "ChessPiece.h"
#include "common.h"

class Chess {
  ChessPiece* board[8][8];
  Team currentTurn;
 public:
  Chess();
  virtual ~Chess();

  void Render();
  void Play();
  void InitializeGameBoard();

};