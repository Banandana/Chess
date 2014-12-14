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
  Black,
  White
};

class ChessPiece {
 public:
  virtual string getName() = 0;
  virtual bool isCritical() = 0;
  virtual bool isBlank() = 0;
  virtual Team getTeam() = 0;

  ChessPiece();
  virtual ~ChessPiece();
};