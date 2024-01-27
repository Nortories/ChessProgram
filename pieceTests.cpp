/***********************************************************************
 * Header File:
 *    TEST PIECE : A test suite for the Piece class
 * Author:
 *    Joshua Sooaemalelagi & Kai
 ************************************************************************/

#include "testPiece.h" // Include your test header file
#include "piece.h"     // Include the Piece class
#include <cassert>     // Include assert for testing


class PieceTest
{
public:
    void testConstructor();
    void testAssignPosition();
    void testAssignPiece();
    void testIsWhite();
    void testIsMove();
    void testGetNMoves();
    void testGetPosition();
    void testJustMoved();
    void testGetLetter();
};

/***************************************
 * TEST CONSTRUCTOR
 ***************************************/
void PieceTest::testConstructor() const
{
    // SETUP
    Position pos(1);
    bool isWhite = true;

    // EXERCISE
    Piece pieceTest(pos, isWhite);

    // VERIFY
    assert(pos == pieceTest.getPosition());
    assert(isWhite == pieceTest.isWhite());
}


/***************************************
 * TEST ASSIGN POSITION
 ***************************************/
void PieceTest::testAssignPosition() const
{
    // SETUP
    Position firstPosition(1); // Initial position
    bool isWhite = true; // Initial color
    Piece pieceTest(firstPosition, isWhite); // Create a Piece with initial position
    Position newPosition(2); // New position to assign to the piece

    // EXERCISE
    pieceTest.assign(newPosition); // Assign new position to the piece

    // VERIFY
    assert(newPosition == pieceTest.getPosition()); // Verify if the piece's position is updated correctly
    assert(isWhite == pieceTest.isWhite()); // Check if 'isWhite' attribute remains unchanged
}

/***************************************
 * TEST ASSIGN PIECE
 ***************************************/
void PieceTest::testAssignPiece() const
{
    // SETUP
    Position firstPosition(1); // Initial position
    bool isWhite1 = true; // Initial color
    Piece piece1(firstPosition, isWhite1); // First Piece with initial attributes
    piece1.nMove = 3; // Example value for nMove
    piece1.lastMove = 5; // Example value for lastMove

    Position position2(8);
    bool isWhite2 = false;
    Piece piece2(position2, isWhite2); // Second Piece with different attributes

    // EXERCISE
    piece2.assign(piece1); // Assign attributes of piece1 to piece2

    // VERIFY
    assert(piece2.getPosition() == piece1.getPosition()); // Verify if position is copied correctly
    assert(piece2.isWhite() == piece1.isWhite()); // Verify if color attribute is copied correctly
    assert(piece2.getNMoves() == piece1.getNMoves()); // Verify if nMove is copied correctly
    assert(piece2.justMoved() == piece1.justMoved()); // Verify if lastMove is copied correctly
}

/***************************************
 * TEST IS WHITE
 ***************************************/
void PieceTest::testIsWhite() const
{
    // SETUP & EXERCISE
    Piece whitePiece(Position(1), true); // Create a white piece
    Piece blackPiece(Position(2), false); // Create a black piece

    // VERIFY
    assert(whitePiece.isWhite() == true); // Verify that isWhite() returns true for a white piece
    assert(blackPiece.isWhite() == false); // Verify that isWhite() returns false for a black piece
}

/***************************************
 * TEST IS MOVE
 ***************************************/
void PieceTest::testIsMove() const
{
    // SETUP
    Piece piece(Position(1), true); // Create a piece, assuming it hasn't moved yet

    // VERIFY INITIAL STATE
    assert(piece.isMove() == false); // Initially, the piece has not moved, so isMove() should return false

    // EXERCISE
    piece.makeMove(Position(1, 2)); // Move the piece to a new position

    // VERIFY AFTER MOVE
    assert(piece.isMove() == true); // After moving, isMove() should return true
}

/***************************************
 * TEST GET N MOVES
 ***************************************/
void PieceTest::testGetNMoves() const
{
	// SETUP
	Piece piece(Position(1), true); // Create a piece, assuming it hasn't moved yet

	// VERIFY INITIAL STATE
	assert(piece.getNMoves() == 0); // Initially, the piece has not moved, so getNMoves() should return 0

	// EXERCISE
	piece.assign(Position(8)); // Move the piece to a new position

	// VERIFY AFTER MOVE
	assert(piece.getNMoves() == 1); // After moving, getNMoves() should return 1
}

/***************************************
 * TEST GET POSITION
 ***************************************/
void PieceTest::testGetPosition() const
{
	// SETUP
	Piece piece(Position(1), true); // Create a piece, assuming it hasn't moved yet

	// VERIFY INITIAL STATE
	assert(piece.getPosition() == Position(1)); // Initially, the piece has not moved, so getPosition() should return (1)

	// EXERCISE
	piece.assign(Position(8)); // Move the piece to a new position

	// VERIFY AFTER MOVE
	assert(piece.getPosition() == Position(8)); // After moving, getPosition() should return (8)
}

/***************************************
 * TEST JUST MOVED
 ***************************************/
void PieceTest::testJustMoved() const
{
	// SETUP
	Piece piece(Position(1), true); // Create a piece, justMoved() should be set to false on creation

	// VERIFY INITIAL STATE
	assert(piece.justMoved() == false); // check that justMoved() is setup correctly before testing, should return false.

	// EXERCISE
	piece.assign(Position(8)); // Move the piece to a new position

	// VERIFY AFTER MOVE
	assert(piece.justMoved() == true); // After moving, justMoved() should return true
}

/***************************************
 * TEST GET PIECE
 ***************************************/
void PieceTest::testGetType() const
{
	// SETUP
	Piece piece(Position(1), false); // Create a piece, assuming it hasn't moved yet
    piece.setType('P'); // Set the piece type to Black Pawn

	// VERIFY INITIAL STATE
	assert(piece.getType() == 'P'); // Initially, the piece has not moved, so getLetter() should return 'P'

	// EXERCISE
	piece.assign(Position(8)); // Move the piece to a new position

	// VERIFY AFTER MOVE
	assert(piece.getType() == 'P'); // After moving, getLetter() should return 'P'
}

/***************************************
 * TEST GET MOVES
 ***************************************/
void PieceTest::testGetMoves() const
{
    // SETUP
    Board board();
    board.reset(); // Reset the board to the initial state
    knight = board.getPosition(2); // Get the piece at position 2 (B1) 
    move = knight.getMoves(board); // Get the moves for the piece at position 2 (B1)

    // VERIFY
    assert(knight.getType() == 'n'); // Verify that the piece at position 2 (B1) is a knight

    // EXERCISE
	assert(move[0] == 17); // Verify that the first move is 10 (A3)
    assert(move[1] == 19); // Verify that the second move is 17 (C3)
    assert(move[2] == 12); // Verify that the third move is 12 (E2) 

}
