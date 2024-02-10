//
//  king.h
//  Lab01
//
//  Created by Kaidi Zhang on 2/10/24.
//

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
      };


};
