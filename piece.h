/***********************************************************************
 * Header File:
 *    PIECE HEADER FILE
 * Author:
 *    Joshua Sooaemalelagi & Kai
 ************************************************************************/

#pragma once

class Piece {
protected:
    int position;
    bool fWhite;
    bool isSpace = false;
    int nMove;
    char type;
    bool hasMoved;

public:
    // Constructor
    Piece(int pos, char type);
    Piece(int pos, bool isWhite);
    Piece(int pos, bool isWhite, char type)
    {
        position = pos;
		fWhite = isWhite;
		this->type = type;
		nMove = 0;
		hasMoved = false;
    };

    // Public methods
    void assign(int pos);
    void assignPiece(const Piece& piece);
    bool checkIsWhite() const;
    bool getHasMoved() const;
    int getNMoves() const;
    void setNMoves(int n);
    void move(int pos);
    int getPosition() const;
    char getLetter() const;
    void setType(char type);
    char getType() const;
    void display();

};

