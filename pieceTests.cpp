/***********************************************************************
 * Header File:
 *    TEST PIECE : A test suite for the Piece class
 * Author:
 *    Joshua Sooaemalelagi & Kai
 ************************************************************************/

#include <Windows.h>  //needed for pop up message box

#include "pieceTests.h" // Include your test header file
#include "piece.h"     // Include the Piece class
#include <cassert>     // Include assert for testing
#include "point.h"     // Include the Point class
#include "board.h"     // Include the Board class


 // Redefine assert to throw an exception instead of aborting
#undef assert
#define assert(expression) \
    if (!(expression)) throw std::runtime_error("Assertion failed: " #expression)


/***************************************
 * TEST CONSTRUCTOR
 ***************************************/
void PieceTest::testConstructor() const
{
    // SETUP
    Point pos;
    pos.setX(1);
    bool isWhite = true;

    // EXERCISE
    Piece pieceTest(pos, isWhite);

    // VERIFY
    try {
    assert(1 == (pieceTest.getPosition()).getX());
    assert(true == pieceTest.isWhite());
}
    catch (const std::exception& e) {
        //windows pop up message box to show that all test cases have passed
        MessageBox(NULL, "testConstructor FAIL", "Notification", MB_OK | MB_ICONINFORMATION);
    }
}


/***************************************
 * TEST ASSIGN POSITION
 ***************************************/
void PieceTest::testAssignPosition() const
{
    // SETUP
    Point pos1; // Initial position
    pos1.setX(1);
    bool isWhite = true; // Initial color
    Piece pieceTest(pos1, isWhite); // Create a Piece with initial position
    Point pos2; // New position to assign to the piece
    pos2.setX(8);

    // EXERCISE
    pieceTest.assign(pos2); // Assign new position to the piece

    try {
    // VERIFY
    assert(8 == (pieceTest.getPosition()).getX()); // Verify if the piece's position is updated correctly
    assert(true == pieceTest.isWhite()); // Check if 'isWhite' attribute remains unchanged
    }
    catch (const std::exception& e) {
        //windows pop up message box to show that all test cases have passed
        MessageBox(NULL, "testAssignPosition FAIL", "Notification", MB_OK | MB_ICONINFORMATION);
    }
}

/***************************************
 * TEST ASSIGN PIECE
 ***************************************/
void PieceTest::testAssignPiece() const
{
    // SETUP
    Point pos1; // Initial position
    pos1.setX(1);
    bool isWhite1 = true; // Initial color
    Piece pieceTest1(pos1, isWhite1); // First Piece with initial attributes
    pieceTest1.setNMoves(3); // Example value for nMove

    Point pos2;
    pos2.setX(8);
    bool isWhite2 = false;
    Piece piece2(pos2, isWhite2); // Second Piece with different attributes

    // EXERCISE
    piece2.assignPiece(pieceTest1); // Assign attributes of pieceTest to piece2
    try {
        // VERIFY
        assert(piece2.getPosition().getX() == pieceTest1.getPosition().getX()); // Verify if position is copied correctly
        assert(piece2.isWhite() == pieceTest1.isWhite()); // Verify if color attribute is copied correctly
        assert(piece2.getNMoves() == pieceTest1.getNMoves()); // Verify if nMove is copied correctly
        assert(piece2.getHasMoved() == pieceTest1.getHasMoved()); // Verify if lastMove is copied correctly
    }
    catch (const std::exception& e) {
        //windows pop up message box to show that all test cases have passed
        MessageBox(NULL, "testAssignPiece FAIL", "Notification", MB_OK | MB_ICONINFORMATION);
    }
}

/***************************************
 * TEST IS WHITE
 ***************************************/
void PieceTest::testIsWhite() const
{
    // SETUP & EXERCISE
    Point pos;
    pos.setX(1);
    Piece whitePiece(pos, true); // Create a white piece
    Piece blackPiece(pos, false); // Create a black piece
    try {
        // VERIFY
        assert(whitePiece.isWhite() == true); // Verify that isWhite() returns true for a white piece
        assert(blackPiece.isWhite() == false); // Verify that isWhite() returns false for a black piece
    }
    catch (const std::exception& e) {
        //windows pop up message box to show that all test cases have passed
        MessageBox(NULL, "testIsWhite FAIL", "Notification", MB_OK | MB_ICONINFORMATION);
    }
}

/***************************************
 * TEST HAS MOVE
 ***************************************/
void PieceTest::testIsMove() const
{
    // SETUP
    Point pos;
    pos.setX(1);
    Piece piece(pos, true); // Create a piece, assuming it hasn't moved yet
    Point newPos;
    newPos.setX(2);

    try {
    // VERIFY INITIAL STATE
    assert(piece.getHasMoved() == false); // Initially, the piece has not moved, so isMove() should return false

    // EXERCISE
    piece.move(newPos); // Move the piece to a new position

    // VERIFY AFTER MOVE
    assert(piece.getHasMoved() == true); // After moving, isMove() should return true

    }
    catch (const std::exception& e) {
        //windows pop up message box to show that all test cases have passed
        MessageBox(NULL, "testIsWhite FAIL", "Notification", MB_OK | MB_ICONINFORMATION);
    }
}

/***************************************
 * TEST GET N MOVES
 ***************************************/
void PieceTest::testGetNMoves() const
{
	// SETUP
    Point pos;
    pos.setX(1);
	Piece piece(pos, true); // Create a piece, assuming it hasn't moved yet
    Point newPos;
    newPos.setX(8);

	// VERIFY INITIAL STATE
	assert(piece.getNMoves() == 0); // Initially, the piece has not moved, so getNMoves() should return 0

	// EXERCISE
	piece.move(newPos); // Move the piece to a new position

    try {
        // VERIFY AFTER MOVE
        assert(piece.getNMoves() == 1); // After moving, getNMoves() should return 1
    }
    catch (const std::exception& e) {
        //windows pop up message box to show that all test cases have passed
        MessageBox(NULL, "testGetNMoves FAIL", "Notification", MB_OK | MB_ICONINFORMATION);
    }
}

/***************************************
 * TEST GET NEW POSITION
 ***************************************/
void PieceTest::testGetNewPosition() const
{
	// SETUP
    Point pos;
    pos.setX(1);
	Piece piece(pos, true); // Create a piece, assuming it hasn't moved yet
    Point newPos;
    newPos.setX(8);

    try {
        // VERIFY INITIAL STATE
        assert(piece.getPosition().getX() == 1); // Initially, the piece has not moved, so getPosition() should return (1)

        // EXERCISE
        piece.move(newPos); // Move the piece to a new position

        // VERIFY AFTER MOVE
        assert(piece.getPosition().getX() == 8); // After moving, getPosition() should return (8)
    }
	catch (const std::exception& e) {
		//windows pop up message box to show that all test cases have passed
		MessageBox(NULL, "testGetPosition FAIL", "Notification", MB_OK | MB_ICONINFORMATION);
	}
}

/***************************************
 * TEST JUST MOVED
 ***************************************/
void PieceTest::testJustMoved() const
{
	// SETUP
    Point pos;
    pos.setX(1);
	Piece piece(pos, true); // Create a piece, justMoved() should be set to false on creation
    Point newPos;
    newPos.setX(8);

    try {
        // VERIFY INITIAL STATE
        assert(piece.getHasMoved() == false); // check that justMoved() is setup correctly before testing, should return false.

        // EXERCISE
        piece.move(newPos); // Move the piece to a new position

        // VERIFY AFTER MOVE
        assert(piece.getHasMoved() == true); // After moving, justMoved() should return true
    }
	catch (const std::exception& e) {
		//windows pop up message box to show that all test cases have passed
		MessageBox(NULL, "testJustMoved FAIL", "Notification", MB_OK | MB_ICONINFORMATION);
	}
}

/***************************************
 * TEST GET PIECE TYPE
 ***************************************/
void PieceTest::testGetType() const
{
	// SETUP
    Point pos;
    pos.setX(1);
	Piece piece(pos, false); // Create a piece, assuming it hasn't moved yet
    piece.setType('P'); // Set the piece type to Black Pawn
    Point newPos;
    newPos.setX(8);


    try {
        // VERIFY INITIAL STATE
        assert(piece.getType() == 'P'); // Initially, the piece has not moved, so getLetter() should return 'P'

        // EXERCISE
        piece.move(newPos); // Move the piece to a new position

        // VERIFY AFTER MOVE
        assert(piece.getType() == 'P'); // After moving, getLetter() should still return 'P'
    }
    catch (const std::exception& e) {
        //windows pop up message box to show that all test cases have passed
	    MessageBox(NULL, "testGetType FAIL", "Notification", MB_OK | MB_ICONINFORMATION);
    }
}

/***************************************
 * TEST GET MOVES
 ***************************************/
//void PieceTest::testGetMoves() const
//{
//    // SETUP
//    Board board;
//    Point pos;
//    pos.setX(2);
//    //board.reset(); // Reset the board to the initial state
//    Piece knight(pos, true); // Create a piece, assuming it hasn't moved yet
//    knight.setType('n'); // Set the piece at position 2 (B1) to a knight
//
//    move = knight.getMoves(board); // Get the moves for the piece at position 2 (B1)
//
//    // VERIFY
//    assert(knight.getType() == 'n'); // Verify that the piece at position 2 (B1) is a knight
//
//    // EXERCISE
//	assert(move[0] == 17); // Verify that the first move is 10 (A3)
//    assert(move[1] == 19); // Verify that the second move is 17 (C3)
//    assert(move[2] == 12); // Verify that the third move is 12 (E2) 
//
//}
