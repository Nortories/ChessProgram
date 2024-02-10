#pragma once

class SmithNotation
{
// Smith Notation stuff we might use in a stretch


	/********************************************************
 * PARSE
 * Determine the nature of the move based on the input.
 * This is the only function understanding Smith notation
 *******************************************************/
 //void parse(const string& textMove, int& positionFrom, int& positionTo)
 //{
 //   string::const_iterator it = textMove.cbegin();
 //
 //   // get the source
 //   int col = *it - 'a';
 //   it++;
 //   int row = *it - '1';
 //   it++;
 //   positionFrom = row * 8 + col;
 //
 //   // get the destination
 //   col = *it - 'a';
 //   it++;
 //   row = *it - '1';
 //   it++;
 //   positionTo = row * 8 + col;
 //
 //   // capture and promotion information
 //   char capture = ' ';
 //   char piecePromotion = ' ';
 //   bool castleK = false;
 //   bool castleQ = false;
 //   bool enpassant = false;
 //   for (; it != textMove.end(); ++it)
 //   {
 //      switch (*it)
 //      {
 //      case 'p':   // capture a pawn
 //      case 'n':   // capture a knight
 //      case 'b':   // capture a bishop
 //      case 'r':   // capture a rook
 //      case 'q':   // capture a queen
 //      case 'k':   // !! you can't capture a king you silly!
 //         capture = tolower(*it);
 //         break;
 //
 //      case 'c':  // short castling or king's castle
 //         castleK = true;
 //         break;
 //      case 'C':  // long castling or queen's castle
 //         castleQ = true;
 //         break;
 //      case 'E':  // En-passant
 //         enpassant = true;
 //         break;
 //
 //      case 'N':  // Promote to knight
 //      case 'B':  // Promote to Bishop
 //      case 'R':  // Promote to Rook
 //      case 'Q':  // Promote to Queen
 //         piecePromotion = *it;
 //         break;
 //
 //      }
 //   }
 //
 //   // error checking
 //   if (positionFrom < 0 || positionFrom >= 64 ||
 //       positionTo   < 0 || positionTo   >= 64)
 //      positionFrom = positionTo = -1;
 //}

 ///********************************************************
 // * READ FILE
 // * Read a file where moves are encoded in Smith notation
 // *******************************************************/
 //void readFile(const char* fileName, char* board)
 //{
 //   // open the file
 //   ifstream fin(fileName);
 //   if (fin.fail())
 //      return;
 //
 //   // read the file, one move at a time
 //   string textMove;
 //   bool valid = true;
 //   while (valid && fin >> textMove)
 //   {
 //      int positionFrom;
 //      int positionTo;
 //      parse(textMove, positionFrom, positionTo);
 //      valid = move(board, positionFrom, positionTo);
 //   }
 //
 //   // close and done
 //   fin.close();
 //}
};