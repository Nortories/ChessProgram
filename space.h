#pragma once
#include "piece.h"

class Space : public Piece
{
	public:
	//constructor
	Space(int pos) : Piece(pos, type) {};
	Space() : Piece(0, ' ') {};
};
