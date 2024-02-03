#pragma once

#include "pieceTests.H"
#include "testMove.h"
#include "testMove.h"
#include "testPosition.h"
#include <iostream>

using namespace std;


class TestRunner
{
public:
	TestRunner() {
	}
	void runAll() {
		PieceTest().run();
		MoveTest().run();
		PositionTest().run();
      cout << "runPieceTest has passed" << endl;
      cout << "runMoveTest has passed" << endl;
      cout << "runPositionTest has passed" << endl;
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
