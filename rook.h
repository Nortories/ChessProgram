//
//  rook.h
//  Lab01
//
//  Created by Kaidi Zhang on 2/10/24.
//

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


};
