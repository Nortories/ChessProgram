/***********************************************************************
 * Header File:
 *    KNIGHT HEADER FILE
 * Author:
 *    Joshua Sooaemalelagi & Kai
 ************************************************************************/

#pragma once
#include "piece.h"

class Knight : public Piece
{
public:
   //constructor
   Knight(int pos) : Piece(pos, type) {};
   Knight() : Piece(0, 'n') {};

   Knight(int pos, bool isWhite) : Piece(pos , isWhite, type) {
   if (checkIsWhite())
      type = 'N';
   else
      type = 'n';
   }
   
   set <int> getPossibleMoves(Piece* board, int location, bool isWhiteTurn) override;
};
