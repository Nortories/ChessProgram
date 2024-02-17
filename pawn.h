/***********************************************************************
 * Header File:
 *    PAWN HEADER FILE
 * Author:
 *    Joshua Sooaemalelagi & Kai
 ************************************************************************/

#pragma once
#include "piece.h"

class Pawn : public Piece
{
	public:
		//constructor
		Pawn(int pos) : Piece(pos, type) {};
		Pawn() : Piece(0, 'p') {};

		Pawn(int pos, bool isWhite) : Piece(pos , isWhite, type) {
		if (checkIsWhite())
			type = 'P';
		else
			type = 'p';
		};

   set <int> getPossibleMoves(Piece* board, int location, bool isWhiteTurn) override
   {
      set <int> possible;
      int row = location / 8;  // current location row
      int col = location % 8;  // current location column
      int r;                   // the row we are checking
      int c;                   // the column we are checking
      c = col;
      r = row - 2;
      
      /****************
       * If Black Pawn *
       *******************/
      if (!isWhiteTurn)
      {
         
         if (row == 6 && board[r * 8 + c].getType() == ' ') {
            possible.insert(r * 8 + c);  // forward two blank spaces
         }
         r = row - 1;
         if (r >= 0 && board[r * 8 + c].getType() == ' ')
            possible.insert(r * 8 + c);  // forward one blank space
         c = col - 1;
         if (checkIsWhite(board, r, c))
            possible.insert(r * 8 + c);    // attack left
         c = col + 1;
         if (checkIsWhite(board, r, c))
            possible.insert(r * 8 + c);    // attack right
      }
      
      /****************
       * If White Pawn *
       *******************/
      if (isWhiteTurn)
      {
         c = col;
         r = row + 2;
         if (row == 1 && board[r * 8 + c].getType() == ' ')
            possible.insert(r * 8 + c);  // forward two blank spaces
         r = row + 1;
         if (r < 8 && board[r * 8 + c].getType() == ' ')
            possible.insert(r * 8 + c);    // forward one blank space
         c = col - 1;
         if (isBlack(board, r, c))
            possible.insert(r * 8 + c);      // attack left
         c = col + 1;
         if (isBlack(board, r, c))
            possible.insert(r * 8 + c);      // attack right
      }
      
      return possible;
   }
};
