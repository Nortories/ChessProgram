#pragma once
#include "piece.h"

class Space : public Piece
{
	public:
	//constructor
	Space(int pos) : Piece(pos, ' ') {};
	Space() : Piece(0, ' ') {};
};
