#pragma once

#include "pieceTests.H"
#include "testMove.h"
#include "testMove.h"
#include "testPosition.h"


class TestRunner
{
public:
	TestRunner() {
	}
	void runAll() {
		PieceTest().run();
		MoveTest().run();
		PositionTest().run();
	}
	void runPieceTest() {
		PieceTest().run();
	}
	void runMoveTest() {
		MoveTest().run();
	}
	void runPositionTest() {
		PositionTest().run();
	}
	
};