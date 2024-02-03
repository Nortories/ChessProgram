/***********************************************************************
 * Cpp File:
 *    PIECE  : Piece class
 * Author:
 *    Joshua Sooaemalelagi & Kai
 ************************************************************************/

#include "piece.h"
#include "point.h"

Piece::Piece(const Point& pos, bool isWhite): position(pos), fWhite(isWhite) {
    nMove = 0;
    type = ' ';
    hasMoved = false;
    // Implementation here
}

void Piece::assign(Point pos) {
    this->position = pos;
}

void Piece::assignPiece(const Piece& piece) {
    this->position = piece.position;
    this->fWhite = piece.fWhite;
    this->nMove = piece.nMove;
    this->type = piece.type;
}

bool Piece::isWhite() const { 
    return this->fWhite;
}

bool Piece::getHasMoved() const {
    return this-> hasMoved;
}

void Piece::move(Point& pos) {
	this->position = pos;
	this->nMove++;
	this->hasMoved = true;
};

int Piece::getNMoves() const {
    return this->nMove;
}

void Piece::setNMoves(int n) {
	this->nMove = n;
}

// Implementation of getPosition
Point Piece::getPosition() const {
    return this->position;
}

char Piece::getLetter() const {
    // Stub 
    return '\0';
}
void Piece::setType(char type) {
	this->type = type;
}

char Piece::getType() const {
    return this->type;
}

void Piece::display(/* Parameters for display, e.g., ogstream */) {
    // Stub 
}
