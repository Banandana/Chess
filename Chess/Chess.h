/*
 * Chess.h
 *
 *  Created on: Sep 23, 2014
 *      Author: mc146u04
 */

#pragma once
#include "ChessPiece.h"
#include "common.h"
#include "Movement.h"

class Chess {
  ChessPiece** board;

  Move lastMove;

  Team currentTurn;

  bool quitting;
  int turncount = 0;

  void Render();
  void Restart();
  void Undo();
  void InitializeGameBoard();
  int GetCriticalPieceCount(Team);
  int GetPointTotal(Team);
  Move GrabMovementData();
  void HandleTeamMovement();
 public:
  Chess();
  virtual ~Chess();
  void Play();
};