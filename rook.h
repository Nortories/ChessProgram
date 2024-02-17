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
   
   set <int> getPossibleMoves(Piece* board, int location, bool isWhiteTurn) override
   {
      set <int> possible;

      // return the empty set if there simply are no possible moves
      if (location < 0 || location >= 64 || board[location].getType() == ' ')
          return possible;
      int row = location / 8;  // current location row
      int col = location % 8;  // current location column
      int r;                   // the row we are checking
      int c;                   // the column we are checking
      bool amBlack = isBlack(board, row, col); // are we black?

      //
      // ROOK
      //
      if ((board[location].getType() == 'R' && !isWhiteTurn) || (board[location].getType() == 'r' && isWhiteTurn))
      {
          RC moves[4] =
          {
                      {0,  1},
             {-1, 0},         {1, 0},
                      {0, -1}
          };
          for (int i = 0; i < 4; i++)
          {
              r = row + moves[i].row;
              c = col + moves[i].col;
              while (r >= 0 && r < 8 && c >= 0 && c < 8 &&
                  board[r * 8 + c].getType() == ' ')
              {
                  possible.insert(r * 8 + c);
                  r += moves[i].row;
                  c += moves[i].col;
              }
              if (amBlack && isNotBlack(board, r, c))
                  possible.insert(r * 8 + c);
              if (!amBlack && isNotWhite(board, r, c))
                  possible.insert(r * 8 + c);
          }
      }
      return possible;
   }
};
