/***********************************************************************
 * Cpp File:
 *    King  : King class
 * Author:
 *    Joshua Sooaemalelagi & Kai
 ************************************************************************/

#include "king.h"

set <int> King::getPossibleMoves(Piece* board, int location, bool isWhiteTurn)
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
   // KING
   //
   if ((board[location].getType() == 'K' && !isWhiteTurn) || (board[location].getType() == 'k' && isWhiteTurn))
   {
       RC moves[8] =
       {
          {-1,  1}, {0,  1}, {1,  1},
          {-1,  0},          {1,  0},
          {-1, -1}, {0, -1}, {1, -1}
       };
       for (int i = 0; i < 8; i++)
       {
           r = row + moves[i].row;
           c = col + moves[i].col;
           if (amBlack && isNotBlack(board, r, c))
               possible.insert(r * 8 + c);
           if (!amBlack && isNotWhite(board, r, c))
               possible.insert(r * 8 + c);
       }
   }
   return possible;
}
