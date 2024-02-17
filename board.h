/*****************************************************
*  board.h
*  TestBoardLab03
*
*  Created by Kaidi Zhang on 1/27/24.
*****************************************************/

#pragma once
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


class Board
{   
public:

   Board() 
   {
      currentMove = 0;
      ogstream gout;
      Interface ui;
   };

   Piece* getBoard() { return board; };

   void selector(Interface& pUI);
   void draw( Interface& ui);

   void takeTurn() { currentMove++; };
   bool isWhiteTurn() {return currentMove % 2 == 0;};

   
private:

   
    // member variables
    // board is a 1D array of 64 pieces (8x8) chess board
     Piece board[64] = {
       Rook(56, false), Knight(57, false), Bishop(58, false), Queen(59, false), King(60, false), Bishop(61, false), Knight(62, false), Rook(63, false),

       Pawn(48, false), Pawn(49, false),   Pawn(50, false),   Pawn(51, false),  Pawn(52, false), Pawn(53, false),   Pawn(54, false),   Pawn(55, false),
       
       Space(40),       Space(41),         Space(42),         Space(43),        Space(44),       Space(45),         Space(46),         Space(47),

       Space(32),       Space(33),         Space(34),         Space(35),        Space(36),       Space(37),         Space(38),         Space(39),

       Space(24),       Space(25),         Space(26),         Space(27),        Space(28),       Space(29),         Space(30),         Space(31),

       Space(16),       Space(17),         Space(18),         Space(19),        Space(20),       Space(21),         Space(22),         Space(23),

       Pawn(8, true),   Pawn(9, true),     Pawn(10, true),    Pawn(11, true),   Pawn(12, true),  Pawn(13, true),    Pawn(14, true),    Pawn(15, true),

       Rook(0, true),   Knight(1, true),   Bishop(2, true),   Queen(3, true),   King(4, true),   Bishop(5, true),   Knight(6, true),   Rook(7, true)
       }; 

    set <int> _possible;
    int currentMove;
    ogstream gout;
    Interface ui;

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
};
