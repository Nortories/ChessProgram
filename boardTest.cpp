///***********************************************************************
// * CPP File:
// *    TEST BOARD : test the Board class
// * Author:
// *    Josh and Kai
// ************************************************************************/
//#include <Windows.h>  //needed for pop up message box
//#include "boardTest.h" // Include the test header file
//#include "board.h"     // Include the Board class
//#include <cassert>     // Include assert for testing
//
//#include <iostream>
//using namespace std;
//
//
///*************************************
// * Constructor
// **************************************/
//void BoardTest::constructor() const
//{
//   // SETUP
//   // EXERCISE
//   Board newBoard; // default constructor
//   // VERIFY
//   try {
//   assert(newBoard.getBoardSize() == 64);
//   assert(newBoard.getCurrentMove() == 0);
//   }
//   catch (const std::exception& e) {
//       //windows pop up message box to show that all test cases have passed
//       MessageBox(NULL, "testConstructor FAIL", "Notification", MB_OK | MB_ICONINFORMATION);
//   }
//}
/////***************************************************
//// * Board
//// ***************************************************/
////void BoardTest::boardLess64() const
////{
////   // SETUP
////   Board board;
////   board.board[63];
////   // EXERCISE
////   board = board.board[63];
////   // VERIFY
////   assert((sizeof(board) / sizeof(board[0])) < 64);
////   // TEARDOWN
////}
////
////void BoardTest::boardEqual64() const
////{
////   // SETUP
////   Board board;
////   board.board[64];
////   // EXERCISE
////   board = board.board[64];
////   // VERIFY
////   assert((sizeof(board) / sizeof(board[0])) == 64);
////   // TEARDOWN
////}
////
////void BoardTest::boardGreater64() const
////{
////   // SETUP
////   Board board;
////   board.board[65];
////   // EXERCISE
////   board = board.board[65];
////   // VERIFY
////   assert((sizeof(board) / sizeof(board[0])) > 64);
////   // TEARDOWN
////}
////
///***************************************************
// * Move
// ***************************************************/
////void BoardTest::getCurrentMove() const
////{
////   // SETUP
////   Board board;
////   board.board[64];
////   board.currentMove = 1;
////   board.posHover = 1;
////   board.posSel = 1;
////   Move move(7);
////   // EXERCISE
////   currentMove = board.move(move);
////   // VERIFY
////   assert(currentMove == 2);
////   // TEARDOWN
////}
////
/////***************************************************
//// * Display
//// ***************************************************/
////void BoardTest::correctDisplay() const
////{
////   // SETUP
////   Board board;
////   board.board[64];
////   board.currentMove = 1;
////   board.posHover = 1;
////   board.posSel = 1;
////   // EXERCISE
////   // VERIFY
////   assert(board.postHover == board[1]);
////   assert(board.posSel == board[1]);
////   // TEARDOWN
////}
////
/////***************************************************
//// * Piece
//// ***************************************************/
////void BoardTest::getRightPiece() const
////{
////   // SETUP
////   Board board;
////   board.board[64];
////   board.currentMove = 2;
////   board.posHover = 1;
////   board.posSel = 1;
////   // EXERCISE
////   rightPiece = board.get(Position(1));
////   // VERIFY
////   assert(rightPiece.getType() == 'r');
////   // TEARDOWN
////}
////
/////***************************************************
//// * Reset
//// ***************************************************/
////void BoardTest::boardReset() const
////{
////   // SETUP
////   Board board;
////   // EXERCISE
////   board.reset();
////   // VERIFY
////   assert(SPACE == board[20])
////   assert(rook1 == board[1]);
////   assert(knight1 == board[2]);
////   assert(bishop1 == board[3]);
////   assert(queen1 == board[4]);
////   assert(king1 == board[5]);
////   assert(pawn1 == board[9]);
////   // TEARDOWN
////}
////
/////***************************************************
//// * Assign
//// ***************************************************/
////void BoardTest::boardAssign() const
////{
////   // SETUP
////   Board board;
////   board.board[64];
////   board.posHover = 9;
////   board.posSel = 9;
////   // EXERCISE
////   board.posHover = 17;
////   board.posSel = 17;
////   board.assign(pawn1);
////   // VERIFY
////   assert(SPACE == board[9]);
////   assert(pawn1 == board[17]);
////   // TEARDOWN
////}
////
/////***************************************************
//// * Swap
//// ***************************************************/
////void BoardTest::pieceSwap() const
////{
////   // SETUP
////   Board board;
////   board.board[64];
////   board.currentMove = 2;
////   board.posHover = 1;
////   board.posSel = 1;
////   board[2] = SPACE;
////   board[3] = SPACE;
////   board[4] = SPACE;
////   // EXERCISE
////   board.swap();
////   // VERIFY
////   assert(board[1] == SPACE);
////   assert(board[4] == SPACE);
////   assert(rook1 == board[3]);
////   assert(king1 == board[2]);
////   // TEARDOWN
////}
