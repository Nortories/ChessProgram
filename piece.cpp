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
    // Implementation here
}

    bool Piece::isWhite() const { 
        return this->fWhite;
    }

    bool Piece::isMove() const {
        // Stub 
        return false;
    }

    int Piece::getNMoves() const {
        // Stub 
        return 0;
    }

    // Implementation of getPosition
    Point Piece::getPosition() const {
        return this->position;
    }

    bool Piece::justMoved() const {
        // Stub 
        return false;
    }

    char Piece::getLetter() const {
        // Stub 
        return '\0';
    }
    void Piece::setType() {
		// Stub
	}

    char Piece::getType() const {
        // Stub
        char empty = ' ';
        return empty;
    }

    void Piece::display(/* Parameters for display, e.g., ogstream */) {
        // Stub 
    }
