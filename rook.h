/***********************************************************************
 * Header File:
 *    ROOK HEADER FILE
 * Author:
 *    Joshua Sooaemalelagi & Kai
 ************************************************************************/

#pragma once
#include "piece.h"

class Rook : public Piece
{
public:
   //constructor
   Rook(int pos) : Piece(pos, type) {};
   Rook() : Piece(0, 'r') {};

   Rook(int pos, bool isWhite) : Piece(pos , isWhite, type) {
      if (checkIsWhite())
         type = 'R';
      else
         type = 'r';
   };
   
   set <int> getPossibleMoves(Piece* board, int location, bool isWhiteTurn) override;
};
