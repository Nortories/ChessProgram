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

public:
    // Constructor
    Piece(const Point& pos, bool isWhite);

    // Public methods
    void assign(const Point& pos);
    void assign(const Piece& piece);
    bool isWhite() const;
    bool isMove() const;
    int getNMoves() const;
    Point getPosition() const;
    bool justMoved() const;
    char getLetter() const;
    void setType();
    char getType() const;
    void display();
};

#endif // PIECE_H
