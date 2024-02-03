/***********************************************************************
 * Header File:
 *    PIECE HEADER FILE
 * Author:
 *    Joshua Sooaemalelagi & Kai
 ************************************************************************/

#pragma once

#ifndef PIECE_H
#define PIECE_H
#include "point.h"

class Piece {
protected:
    Point position;
    bool fWhite;
    int nMove;
    char type;
    bool hasMoved;

public:
    // Constructor
    Piece(const Point& pos, bool isWhite);

    // Public methods
    void assign(Point pos);
    void assignPiece(const Piece& piece);
    bool isWhite() const;
    bool getHasMoved() const;
    int getNMoves() const;
    void setNMoves(int n);
    void move(Point& pos);
    Point getPosition() const;
    char getLetter() const;
    void setType(char type);
    char getType() const;
    void display();

};

#endif // PIECE_H
