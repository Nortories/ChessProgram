#pragma once
#include "piece.h"

class Pawn : public Piece
{
	public:
		//constructor
		Pawn(int pos) : Piece(pos, type) {};
		Pawn() : Piece(0, 'p') {};

		Pawn(int pos, bool isWhite) : Piece(pos , isWhite, type) {
		if (checkIsWhite())
		{
			type = 'P';
		}
		else
		{
			type = 'p';
		}
		};


};
