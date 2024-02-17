/***********************************************************************
 * Header File:
 *    QUEEN HEADER FILE
 * Author:
 *    Joshua Sooaemalelagi & Kai
 ************************************************************************/

#pragma once
#include "piece.h"

class Queen : public Piece
{
public:
   //constructor
   Queen(int pos) : Piece(pos, type) {};
   Queen() : Piece(0, 'q') {};

   Queen(int pos, bool isWhite) : Piece(pos , isWhite, type) {
      if (checkIsWhite())
         type = 'Q';
      else
         type = 'q';
   }
   
   set <int> getPossibleMoves(Piece* board, int location, bool isWhiteTurn) override;
};
