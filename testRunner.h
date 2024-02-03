#pragma once

#include <Windows.h>
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
			//windows pop up message box to show that all test cases have passed
			MessageBox(NULL, "Finished Unit test, Entering Game", "Notification", MB_OK | MB_ICONINFORMATION);

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