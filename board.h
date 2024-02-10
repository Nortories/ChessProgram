//
//  board.h
//  TestBoardLab03
//
//  Created by Kaidi Zhang on 1/27/24.
//

#pragma once

#include <iostream>
#include "uiDraw.h"
#include "uiInteract.h"
#include "piece.h"
#include "space.h"
#include "pawn.h"
#include "knight.h"
#include "king.h"
#include "rook.h"
#include "bishop.h"
#include "queen.h"
#include <array>
#include <set>
#include <cassert>

using namespace std;

class Board
{   
public:

   Board() {
      currentMove = 0;
      ogstream gout;
      Interface ui;
   };
   //char* getBoard() { return board; };
   Piece* getBoard() { return board; };


   void selector(Interface& pUI);

   void draw( Interface& ui);

   bool isNotWhite(const Piece* board, int row, int col);
   bool checkIsWhite(Piece* board, int row, int col);
   bool isNotBlack(const Piece* board, int row, int col);
   bool isBlack(Piece* board, int row, int col);

   bool move(Piece* board, int positionFrom, int positionTo);
   set <int> getPossibleMoves(Piece* board, int location);


   int getBoardSize();
   int getCurrentMove();
   bool whiteTurn();
//   void display(gout.drawHover, gout.drawSelected);
//   Piece get();
   void reset() {};
//   void move(Move move);
   void assign() {};
   
private:
   // TODO: change the char type to Piece of the board
   // note this is upside down: 0 row is at the bottom
   //char board[64] = {
    //char board[64] = {
    //   'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
    //   'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
    //   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
    //   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
    //   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
    //   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
    //   'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
    //   'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'
    //   };

     Piece board[64] = {
       Rook(56, false), Knight(57, false), Bishop(58, false), Queen(59, false), King(60, false), Bishop(61, false), Knight(62, false), Rook(63, false),
       Pawn(48, false), Pawn(49, false), Pawn(50, false), Pawn(51, false), Pawn(52, false), Pawn(53, false), Pawn(54, false), Pawn(55, false),
       Space(), Space(), Space(), Space(), Space(), Space(), Space(), Space(),
       Space(), Space(), Space(), Space(), Space(), Space(), Space(), Space(),
       Space(), Space(), Space(), Space(), Space(), Space(), Space(), Space(),
       Space(), Space(), Space(), Space(), Space(), Space(), Space(), Space(),
       Pawn(8, true), Pawn(9, true), Pawn(10, true), Pawn(11, true), Pawn(12, true), Pawn(13, true), Pawn(14, true), Pawn(15, true),
       Rook(0, true), Knight(1, true), Bishop(2, true), Queen(3, true), King(4, true), Bishop(5, true), Knight(6, true), Rook(7, true),
   };
   
   int currentMove;
   ogstream gout;
   Interface ui;
   
   void swap() {};
   void assertBoard() {};
};
