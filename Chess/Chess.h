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

  bool quitting;
  void Render();
  void InitializeGameBoard();
  int GetCriticalPieceCount(Team);
  void HandleTeamMovement();
 public:
  Chess();
  virtual ~Chess();
  void Play();
};