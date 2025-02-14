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
    int nMove = 0;
    char type;
    bool _hasMoved = false;
    bool _enpassant = false;
    bool _dead = false;



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
		_hasMoved = false;
    };

    bool isNotWhite(const Piece* board, int row, int col);
    bool checkIsWhite(Piece* board, int row, int col);
    bool isNotBlack(const Piece* board, int row, int col);
    bool isBlack(Piece* board, int row, int col);

    void assign(int pos);
    void assignPiece(const Piece& piece);
    bool checkIsWhite() const;
    bool getHasMoved() const;
    bool hasMoved() { return _hasMoved; };
    int getNMoves() const;
    void setNMoves(int n);
    bool move(Piece* boardPieces, int positionFrom, int positionTo, bool isWhiteTurn);
    set <int> getPossibleMoves(Piece* board, int location, bool isWhiteTurn);
    void movePos(int pos);
    int getPosition() const;
    char getLetter() const;
    void setType(char type);
    char getType() const;
    void display();

    void draw(int i, Interface& ui);

    void promote(Piece* board,int positionFrom, int location);
    void kill(Piece* board, int selectPosition);
    bool canEnpassant() { return _enpassant; };
    void checkEnpassant(Piece* board, int selectPosition) {
        if (_enpassant && ((board[selectPosition + 8].getType() == 'p' || board[selectPosition + 8].getType() == 'P'))) {
            cout << "Enpassant Kill!";
            kill(board, selectPosition + 8);
        };
        if (_enpassant && ((board[selectPosition - 8].getType() == 'p' || board[selectPosition - 8].getType() == 'P'))) {
            cout << "Enpassant Kill!";
            kill(board, selectPosition - 8);
        };
    nMove--;
    if (nMove <= 0)
		_enpassant = false;
        cout << "Enpassant is now " << _enpassant << " position " << getPosition() << endl;
    };

};

