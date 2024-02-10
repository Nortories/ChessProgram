//
//  bishop.h
//  Lab01
//
//  Created by Kaidi Zhang on 2/10/24.
//

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


};
