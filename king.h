/***********************************************************************
 * Header File:
 *    KING HEADER FILE
 * Author:
 *    Joshua Sooaemalelagi & Kai
 ************************************************************************/

#pragma once
#include "piece.h"

class King : public Piece
{
public:
   //constructor
   King(int pos) : Piece(pos, type) {};
   King() : Piece(0, 'k') {};

   King(int pos, bool isWhite) : Piece(pos , isWhite, type) {
   if (checkIsWhite())
      type = 'K';
   else
      type = 'k';
   }
   
   set <int> getPossibleMoves(Piece* board, int location, bool isWhiteTurn) override;
};
