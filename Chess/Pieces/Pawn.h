/*
 * Pawn.h
 *
 *  Created on: Sep 23, 2014
 *      Author: mc146u04
 */

#pragma once

#include "../common.h"
#include "../ChessPiece.h"

using namespace std;

class Pawn : public ChessPiece {
 public:
  string getName() { return "Pawn"; };
  bool isCritical() { return true; };

  bool verifyAttackAbility(Point, Point);
  bool verifyMovementAbility(Point, Point);

  Pawn();
  virtual ~Pawn();
};
