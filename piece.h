/***********************************************************************
 * Header File:
 *    PIECE HEADER FILE
 * Author:
 *    Joshua Sooaemalelagi & Kai
 ************************************************************************/

#pragma once
#include <set>
#include <array>
#include <cassert>
#include <iostream>
#include "uiDraw.h"
#include "uiInteract.h"

using namespace std;

class Piece {
protected:
    int position;
    bool fWhite;
    bool isSpace = false;
    int nMove;
    char type;
    bool hasMoved = false;

    set <int> possible;

    struct RC
    {
        int row;
        int col;
    };


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

    bool isNotWhite(const Piece* board, int row, int col);
    bool checkIsWhite(Piece* board, int row, int col);
    bool isNotBlack(const Piece* board, int row, int col);
    bool isBlack(Piece* board, int row, int col);

    void assign(int pos);
    void assignPiece(const Piece& piece);
    bool checkIsWhite() const;
    bool getHasMoved() const;
    void HasMoved() { hasMoved = true; };
    int getNMoves() const;
    void setNMoves(int n);
    bool move(Piece* boardPieces, int positionFrom, int positionTo);
    set <int> getPossibleMoves(Piece* board, int location);
    void movePos(int pos);
    int getPosition() const;
    char getLetter() const;
    void setType(char type);
    char getType() const;
    void display();

    void draw(int i, Interface& ui) {
        
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

};

