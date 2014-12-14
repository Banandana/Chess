/*
 * Chess.h
 *
 *  Created on: Sep 23, 2014
 *      Author: mc146u04
 */

#pragma once
#include "ChessPiece.h"


class Chess {
  ChessPiece* board[8][8];

 public:
  Chess();
  virtual ~Chess();

  void Play();

};