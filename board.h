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
       Space(), Space(), Space(), Space(), Space(), Space(), Space(), Space(),
       Space(), Space(), Space(), Space(), Space(), Space(), Space(), Space(),
       Space(), Space(), Space(), Space(), Space(), Space(), Space(), Space(),
       Space(), Space(), Space(), Space(), Space(), Space(), Space(), Space(),
       Space(), Space(), Space(), Space(), Space(), Space(), Space(), Space(),
       Space(), Space(), Space(), Space(), Space(), Space(), Space(), Space(),
       Space(), Space(), Space(), Space(), Space(), Space(), Space(), Space(),
       Space(), Space(), Space(), Space(), Space(), Space(), Space(), Space(),
   };
   
   int currentMove;
   ogstream gout;
   Interface ui;
   
   void swap() {};
   void assertBoard() {};
};
