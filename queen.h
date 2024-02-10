//
//  queen.h
//  Lab01
//
//  Created by Kaidi Zhang on 2/10/24.
//

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
      };


};
