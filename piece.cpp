/***********************************************************************
 * Cpp File:
 *    PIECE  : Piece class
 * Author:
 *    Joshua Sooaemalelagi & Kai
 ************************************************************************/

#include "piece.h"
#include "point.h"

Piece::Piece(int pos, char type): position(pos), type(type) {
    this->isSpace = true;
	this->fWhite = true;
	this->nMove = 0;
	this->hasMoved = false;
}
Piece::Piece(int pos, bool isWhite) : position(pos), fWhite(isWhite) {
	this->isSpace = true;
	this->nMove = 0;
	this->hasMoved = false;
}
void Piece::assign(int pos) {
    this->position = pos;
}

void Piece::assignPiece(const Piece& piece) {
    this->position = piece.position;
    this->fWhite = piece.fWhite;
    this->nMove = piece.nMove;
    this->type = piece.type;
}

bool Piece::checkIsWhite() const { 
    return this->fWhite;
}

bool Piece::getHasMoved() const {
    return this-> hasMoved;
}

void Piece::move(int pos) {
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
int Piece::getPosition() const {
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
