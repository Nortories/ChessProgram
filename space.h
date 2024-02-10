#pragma once
#include "piece.h"

class Space : public Piece
{
	public:
	char type = ' ';
	//constructor
	Space(int pos) : Piece(pos, type) {};
	Space() : Piece(0, ' ') {};
	void draw() {
		std::cout << " ";
	}
};
