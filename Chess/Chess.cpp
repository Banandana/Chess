/*
 * Chess.cpp
 *
 *  Created on: Sep 23, 2014
 *      Author: mc146u04
 */

#include "Chess.h"

Chess::Chess() {
  // TODO Auto-generated constructor stub
  //Do stuff like make teh board an 8x8 array of 0s
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      board[i][j] = 0;
    }
  }
}

Chess::~Chess() {
  // TODO Auto-generated destructor stub
}

