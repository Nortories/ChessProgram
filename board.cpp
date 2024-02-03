//
//  board.cpp
//  TestBoardLab03
//
//  Created by Kaidi Zhang on 1/27/24.
//
#include "board.h"

int Board::getBoardSize() { return sizeof(board) / sizeof(board[0]); };

int Board::getCurrentMove()
{
	return this->currentMove;
}

//Board::whiteTurn()
//{
//
//}
//
//Board::display()
//{
//
//}
//
//Board::reset()
//{
//
//}
//
//Board::move()
//{
//
//}
//
//Board::assign()
//{
//
//}
