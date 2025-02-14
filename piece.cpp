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

void Piece::promote(Piece* board, int positionFrom, int positionTo) {
    cout << board[positionFrom].getType() << " positionTo " << positionTo << endl;

    // Check for valid promotion conditions and ensure positionFrom points to a valid object
    if (board[positionFrom].getType() == 'P' && positionTo < 8) {
        cout << "Promotion up" << endl;
        Piece thisBoard = board[positionTo];
        thisBoard = Queen(positionTo, true);
    }
    //else if (board[positionFrom].getType() == 'p' && positionTo > 55) {
    //    cout << "Promotion down" << endl;
    //    delete board[positionTo]; // Correct if board[positionTo] was dynamically allocated
    //    board[positionTo] = new Queen(positionTo, false); // Dynamically allocate a new Queen
    //}
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
        promote(board, positionFrom, positionTo);
        board[positionTo] = board[positionFrom];
        board[positionFrom] = Space();
        this->_hasMoved = true;
        cout << board[positionFrom].getType() <<" Moved from " << positionFrom << " to " << positionTo << endl;

        // Check for valid promotion conditions and ensure positionFrom points to a valid object
        if (board[positionTo].getType() == 'p' && (positionTo >= 56 && positionTo <= 63))
        { board[positionTo] = Queen(positionTo, false);}
        if (board[positionTo].getType() == 'P' && (positionTo >= 0 && positionTo <= 7))
        { board[positionTo] = Queen(positionTo, true);}
        return true;
    }

    return false;

}
void Piece::kill(Piece* board, int selectPosition) {
	board[selectPosition] = Space(selectPosition);
}
set <int> Piece::getPossibleMoves(Piece* board, int location, bool isWhiteTurn)
{
    //cout << location;
    //cout << "getPossibleMoves of: " << board[location].getType() <<endl;
    set <int> possible;

    // return the empty set if there simply are no possible moves
    if (location < 0 || location >= 64 || board[location].getType() == ' ')
        return possible;
    int row = location / 8;  // current location row
    int col = location % 8;  // current location column
    int r;                   // the row we are checking
    int c;                   // the column we are checking
    bool amBlack = isBlack(board, row, col); // are we black?

    //
    // PAWN
    //
    if (board[location].getType() == 'P' && !isWhiteTurn)
    {
        
        c = col;
        r = row - 2;
        if (row == 6 && board[r * 8 + c].getType() == ' ') {
            possible.insert(r * 8 + c);  // forward two blank spaces
            _enpassant = true;
            nMove= 2;
        }
        r = row - 1;
        if (r >= 0 && board[r * 8 + c].getType() == ' ')
            possible.insert(r * 8 + c);  // forward one black space
        c = col - 1;
        if (checkIsWhite(board, r, c))
            possible.insert(r * 8 + c);    // attack left
        c = col + 1;
        if (checkIsWhite(board, r, c))
            possible.insert(r * 8 + c);    // attack right

        // what about en-passant and pawn promotion
        // En Passant for black pawn
        if (!isWhiteTurn && row == 3) {
            if (col > 0 && checkIsWhite(board, row, col-1) && (board[location-1].canEnpassant())) { // Check left for en passant
                possible.insert((row - 1) * 8 + (col - 1)); // Capture en passant

            }
            if (col < 7 && checkIsWhite(board, row, col+1) && (board[location + 1].canEnpassant()))  { // Check right for en passant
                possible.insert((row - 1) * 8 + (col + 1)); // Capture en passant
            }
        }


    }
    if (board[location].getType() == 'p' && isWhiteTurn)
    {
        c = col;
        r = row + 2;
        if (row == 1 && board[r * 8 + c].getType() == ' ')
            possible.insert(r * 8 + c);  // forward two blank spaces
            _enpassant = true;
            nMove = 2;
        r = row + 1;
        if (r < 8 && board[r * 8 + c].getType() == ' ')
            possible.insert(r * 8 + c);    // forward one blank space
        c = col - 1;
        if (isBlack(board, r, c))
            possible.insert(r * 8 + c);      // attack left
        c = col + 1;
        if (isBlack(board, r, c))
            possible.insert(r * 8 + c);      // attack right
        // what about en-passant and pawn promotion
        if (isWhiteTurn && row == 4) {
            if (col > 0 && !checkIsWhite(board, row, col - 1) && (board[location - 1].canEnpassant())) { // Check left for en passant
                possible.insert((row + 1) * 8 + (col - 1)); // Capture en passant

            }
            if (col < 7 && !checkIsWhite(board, row, col + 1) && (board[location + 1].canEnpassant())) { // Check right for en passant
                possible.insert((row + 1) * 8 + (col + 1)); // Capture en passant
            }
        }
    }

    //
    // KNIGHT
    //
    if ((board[location].getType() == 'N' && !isWhiteTurn) || (board[location].getType() == 'n' && isWhiteTurn))
    {
        RC moves[8] =
        {
                 {-1,  2}, { 1,  2},
        {-2,  1},                    { 2,  1},
        {-2, -1},                    { 2, -1},
                 {-1, -2}, { 1, -2}
        };
        for (int i = 0; i < 8; i++)
        {
            r = row + moves[i].row;
            c = col + moves[i].col;
            if (amBlack && isNotBlack(board, r, c))
                possible.insert(r * 8 + c);
            if (!amBlack && isNotWhite(board, r, c))
                possible.insert(r * 8 + c);
        }
    }

    //
    // KING
    //
    if ((board[location].getType() == 'K' && !isWhiteTurn) || (board[location].getType() == 'k' && isWhiteTurn))
    {
        RC moves[8] =
        {
           {-1,  1}, {0,  1}, {1,  1},
           {-1,  0},          {1,  0},
           {-1, -1}, {0, -1}, {1, -1}
        };
        for (int i = 0; i < 8; i++)
        {
            r = row + moves[i].row;
            c = col + moves[i].col;
            if (amBlack && isNotBlack(board, r, c))
                possible.insert(r * 8 + c);
            if (!amBlack && isNotWhite(board, r, c)) {
                possible.insert(r * 8 + c);
            }
        }
        // what about castling
        if (!board[location].hasMoved()) {
            // castling for black king

            //black king side
            if (board[location].getType() == 'k') {

                if ((board[location + 1].getType() == ' ' && board[location + 2].getType() == ' ' && !board[location + 3].hasMoved())) {
                    possible.insert(location + 2);
                }
                // white queen side
                if (board[location - 1].getType() == ' ' && board[location - 2].getType() == ' ' && board[location - 3].getType() == ' ' && !board[location - 4].hasMoved()) {
                    possible.insert(location - 2);
                }
            }
            // castling for white king

            //white king side
            if (board[location].getType() == 'K') {

                if ((board[location + 1].getType() == ' ' && board[location + 2].getType() == ' ' && !board[location + 3].hasMoved())) {
                    possible.insert(location + 2);
                }
                // white queen side
                if (board[location - 1].getType() == ' ' && board[location - 2].getType() == ' ' && board[location - 3].getType() == ' ' && !board[location - 4].hasMoved()) {
                    possible.insert(location - 2);
                }
            }
		}
    }

    //
    // QUEEN
    //
    if ((board[location].getType() == 'Q' && !isWhiteTurn) || (board[location].getType() == 'q' && isWhiteTurn))
    {
        RC moves[8] =
        {
           {-1,  1}, {0,  1}, {1,  1},
           {-1,  0},          {1,  0},
           {-1, -1}, {0, -1}, {1, -1}
        };
        for (int i = 0; i < 8; i++)
        {
            r = row + moves[i].row;
            c = col + moves[i].col;
            while (r >= 0 && r < 8 && c >= 0 && c < 8 &&
                board[r * 8 + c].getType() == ' ')
            {
                possible.insert(r * 8 + c);
                r += moves[i].row;
                c += moves[i].col;
            }
            if (amBlack && isNotBlack(board, r, c))
                possible.insert(r * 8 + c);
            if (!amBlack && isNotWhite(board, r, c))
                possible.insert(r * 8 + c);
        }
    }

    //
    // ROOK
    //
    if ((board[location].getType() == 'R' && !isWhiteTurn) || (board[location].getType() == 'r' && isWhiteTurn))
    {
        RC moves[4] =
        {
                    {0,  1},
           {-1, 0},         {1, 0},
                    {0, -1}
        };
        for (int i = 0; i < 4; i++)
        {
            r = row + moves[i].row;
            c = col + moves[i].col;
            while (r >= 0 && r < 8 && c >= 0 && c < 8 &&
                board[r * 8 + c].getType() == ' ')
            {
                possible.insert(r * 8 + c);
                r += moves[i].row;
                c += moves[i].col;
            }
            if (amBlack && isNotBlack(board, r, c))
                possible.insert(r * 8 + c);
            if (!amBlack && isNotWhite(board, r, c))
                possible.insert(r * 8 + c);
        }
    }

    //
    // BISHOP
    //
    if ((board[location].getType() == 'B' && !isWhiteTurn )|| (board[location].getType() == 'b' && isWhiteTurn))
    {
        RC moves[4] =
        {
           {-1,  1}, {1,  1},
           {-1, -1}, {1, -1}
        };
        for (int i = 0; i < 4; i++)
        {
            r = row + moves[i].row;
            c = col + moves[i].col;
            while (r >= 0 && r < 8 && c >= 0 && c < 8 &&
                board[r * 8 + c].getType() == ' ')
            {
                possible.insert(r * 8 + c);
                r += moves[i].row;
                c += moves[i].col;
            }
            if (amBlack && isNotBlack(board, r, c))
                possible.insert(r * 8 + c);
            if (!amBlack && isNotWhite(board, r, c))
                possible.insert(r * 8 + c);
        }
    }

    return possible;
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
	this->_hasMoved = false;
}

Piece::Piece(int pos, bool isWhite) : position(pos), fWhite(isWhite)
{
    this->type = ' ';
	this->isSpace = true;
	this->nMove = 0;
	this->_hasMoved = false;
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
    return this-> _hasMoved;
}

void Piece::movePos(int pos)
{
	this->position = pos;
	this->nMove++;
	this->_hasMoved = true;
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
