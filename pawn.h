#pragma once
#include "piece.h"

class Pawn : public Piece
{

	//constructor
	Pawn(int pos, bool isWhite) : Piece(pos , isWhite, type) {
	if (checkIsWhite)
	{
		type = 'P';
	}
	else
	{
		type = 'p';
	}
	};


};
