/***********************************************************************
 * Cpp File:
 *    Bishop  : Bishop class
 * Author:
 *    Joshua Sooaemalelagi & Kai
 ************************************************************************/

#include "bishop.h"

set <int> Bishop::getPossibleMoves(Piece* board, int location, bool isWhiteTurn)
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
   // BISHOP
   //
   if ((board[location].getType() == 'B' && !isWhiteTurn )|| (board[location].getType() == 'b' && isWhiteTurn))
   {
       RC moves[4] =
       {
          {-1,  1}, {1,  1},
          {-1, -1}, {1, -1}
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
