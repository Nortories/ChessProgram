/***********************************************************************
 * Header File:
 *    PIECE TEST : test the Piece class
 * Author:
 *    Joshua Sooaemalelagi & Kai
 ************************************************************************/


#pragma once

 /***************************************************
  * Piece TEST
  * Test the Piece class
  ***************************************************/
class PieceTest
{
public:
    void run() const
    {
		testConstructor();
		testAssignPosition();
		testAssignPiece();
		testIsWhite();
		testIsMove();
		testGetNMoves();
		testGetPosition();
		testJustMoved();
		testGetLetter();
	}

private:
    void testConstructor() const;
    void testAssignPosition() const;
    void testAssignPiece() const;
    void testIsWhite() const;
    void testIsMove() const;
    void testGetNMoves() const;
    void testGetPosition() const;
    void testJustMoved() const;
    void testGetLetter() const;
};