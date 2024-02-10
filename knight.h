//
//  knight.h
//  Lab01
//
//  Created by Kaidi Zhang on 2/10/24.
//

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
      };


};
