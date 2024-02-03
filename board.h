//
//  board.h
//  TestBoardLab03
//
//  Created by Kaidi Zhang on 1/27/24.
//

#pragma once

#include "uiDraw.h"
#include "uiInteract.h"
#include "piece.h"

class Board
{   
public:

   Board() {
      currentMove = 0;
      ogstream gout;
      Interface ui;
   };

   int getBoardSize();
   int getCurrentMove();
   bool whiteTurn() {};
//   void display(gout.drawHover, gout.drawSelected);
//   Piece get();
   void reset() {};
//   void move(Move move);
   void assign() {};
   
private:
   // TODO: change the char type to Piece of the board
   char board[64] = {
      'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
      'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      // ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
      'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'
   };
   
   int currentMove;
   ogstream gout;
   Interface ui;
   
   void swap() {};
   void assertBoard() {};
};
