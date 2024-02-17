/***********************************************************************
 * Cpp File:
 *    PIECE  : Piece class
 * Author:
 *    Joshua Sooaemalelagi & Kai
 ************************************************************************/

#include "piece.h"

#include "space.h"
#include "pawn.h"
#include "knight.h"
#include "king.h"
#include "rook.h"
#include "bishop.h"
#include "queen.h"

void Piece::draw(int i, Interface& ui){
    {

        ogstream gout;

        // draw the pieces
        switch (this->getType())
        {
        case 'P':
            gout.drawPawn(i, true);
            break;
        case 'p':
            gout.drawPawn(i, false);
            break;
        case 'K':
            gout.drawKing(i, true);
            break;
        case 'k':
            gout.drawKing(i, false);
            break;
        case 'Q':
            gout.drawQueen(i, true);
            break;
        case 'q':
            gout.drawQueen(i, false);
            break;
        case 'R':
            gout.drawRook(i, true);
            break;
        case 'r':
            gout.drawRook(i, false);
            break;
        case 'B':
            gout.drawBishop(i, true);
            break;
        case 'b':
            gout.drawBishop(i, false);
            break;
        case 'N':
            gout.drawKnight(i, true);
            break;
        case 'n':
            gout.drawKnight(i, false);
            break;
        }
    };
}

bool Piece::move(Piece* board, int positionFrom, int positionTo, bool isWhiteTurn)
{
    // do not move if a move was not indicated
    if (positionFrom == -1 || positionTo == -1)
        return false;
    assert(positionFrom >= 0 && positionFrom < 64);
    assert(positionTo >= 0 && positionTo < 64);

    // find the set of possible moves from our current location
    set <int> possiblePrevious = getPossibleMoves(board, positionFrom, isWhiteTurn);

    // only move there is the suggested move is on the set of possible moves
    if (possiblePrevious.find(positionTo) != possiblePrevious.end())
    {
        board[positionTo] = board[positionFrom];
        board[positionFrom] = Space();
        this->hasMoved = true;
        cout << board[positionFrom].getType() <<" Moved from " << positionFrom << " to " << positionTo << endl;
        return true;
    }

    return false;

}

void Piece::kill(Piece* board, int selectPosition) 
{
	board[selectPosition] = Space(selectPosition);
}

set <int> Piece::getPossibleMoves(Piece* board, int location, bool isWhiteTurn)
{
}


/****************************************************
 * IS NOT WHITE
 * Is the current location valid and the piece is either
 * black (uppercase) or space
 ***************************************************/
bool Piece::isNotWhite(const Piece* board, int row, int col)
{
    // not white if we are off the board or if we are looking at a space
    if (row < 0 || row >= 8 || col < 0 || col >= 8)
        return false;
    char piece = board[row * 8 + col].getType();

    return piece == ' ' || (piece >= 'A' && piece <= 'Z');
}

/****************************************************
 * IS  WHITE
 * Is the current location valid and the piece is white
 ***************************************************/
bool Piece::checkIsWhite(Piece* board, int row, int col)
{
    // not white if we are off the board or if we are looking at a space
    if (row < 0 || row >= 8 || col < 0 || col >= 8)
        return false;
    char piece = board[row * 8 + col].getType();

    return (piece >= 'a' && piece <= 'z');
}

/****************************************************
 * IS NOT BLACK
 * Is the current location valid and the piece is either
 * white (lowercase) or space
 ***************************************************/
bool Piece::isNotBlack(const Piece* board, int row, int col)
{
    // not white if we are off the board or if we are looking at a space
    if (row < 0 || row >= 8 || col < 0 || col >= 8)
        return false;
    char piece = board[row * 8 + col].getType();

    return piece == ' ' || (piece >= 'a' && piece <= 'z');
}

/****************************************************
 * IS  BLACK
 * Is the current location valid and the piece is black
 ***************************************************/
bool Piece::isBlack(Piece* board, int row, int col)
{
    // not white if we are off the board or if we are looking at a space
    if (row < 0 || row >= 8 || col < 0 || col >= 8)
        return false;
    char piece = board[row * 8 + col].getType();

    return (piece >= 'A' && piece <= 'Z');
}


Piece::Piece(int pos, char type): position(pos), type(type)
{
    this->isSpace = true;
	this->fWhite = true;
	this->nMove = 0;
	this->hasMoved = false;
}

Piece::Piece(int pos, bool isWhite) : position(pos), fWhite(isWhite)
{
    this->type = ' ';
	this->isSpace = true;
	this->nMove = 0;
	this->hasMoved = false;
}

void Piece::assign(int pos) {
    this->position = pos;
}

void Piece::assignPiece(const Piece& piece)
{
    this->position = piece.position;
    this->fWhite = piece.fWhite;
    this->nMove = piece.nMove;
    this->type = piece.type;
}

bool Piece::checkIsWhite() const
{
    return this->fWhite;
}

bool Piece::getHasMoved() const
{
    return this-> hasMoved;
}

void Piece::movePos(int pos)
{
	this->position = pos;
	this->nMove++;
	this->hasMoved = true;
};

int Piece::getNMoves() const
{
    return this->nMove;
}

void Piece::setNMoves(int n)
{
	this->nMove = n;
}

// Implementation of getPosition
int Piece::getPosition() const
{
    return this->position;
}

char Piece::getLetter() const
{
    // Stub 
    return '\0';
}

void Piece::setType(char type)
{
	this->type = type;
}

char Piece::getType() const
{
    return this->type;
}

void Piece::display(/* Parameters for display, e.g., ogstream */)
{
    // Stub 
}
