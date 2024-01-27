/***********************************************************************
 * Cpp File:
 *    PIECE  : Piece class
 * Author:
 *    Joshua Sooaemalelagi & Kai
 ************************************************************************/

#include "piece.h"

class Piece {
protected:
    Position position;
    bool fWhite;
    int nMove;
    int lastMove;
    char type;

public:
    // Constructor
    Piece(const Position& pos, bool isWhite) : position(pos), fWhite(isWhite), nMove(0), lastMove(0), type('') {}

    // Public methods as per the test file
    void assign(const Position& pos) {
        // Stub 
    }

    void assign(const Piece& piece) {
        // Stub 
    }

    bool isWhite() const {
        // Stub 
        return false;
    }

    bool isMove() const {
        // Stub 
        return false;
    }

    int getNMoves() const {
        // Stub 
        return 0;
    }

    Position getPosition() const {
        // Stub 
        return Position(); 
    }

    bool justMoved() const {
        // Stub 
        return false;
    }

    char getLetter() const {
        // Stub 
        return '\0';
    }
    void setType() {
		// Stub
	}

    char getType() const {
        // Stub
        return '';
    }

    void display(/* Parameters for display, e.g., ogstream */) {
        // Stub 
    }

};
