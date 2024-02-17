/***********************************************************************
 * Header File:
 *    BISHOP HEADER FILE
 * Author:
 *    Joshua Sooaemalelagi & Kai
 ************************************************************************/

#pragma once
#include "piece.h"

class Bishop : public Piece
{
public:
   //constructor
   Bishop(int pos) : Piece(pos, type) {};
   Bishop() : Piece(0, 'b') {};

   Bishop(int pos, bool isWhite) : Piece(pos , isWhite, type) {
   if (checkIsWhite())
      type = 'B';
   else
      type = 'b';
   };
   
   set <int> getPossibleMoves(Piece* board, int location, bool isWhiteTurn) override;
};
