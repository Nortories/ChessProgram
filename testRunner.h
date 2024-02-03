#pragma once

#include <Windows.h>
#include "pieceTests.H"
#include "testMove.h"
#include "testPosition.h"
#include "boardTest.h"
#include <iostream>

using namespace std;


class TestRunner
{
public:
	TestRunner() {
	}
	void runAll() {
			PieceTest().run();
				cout << "runPieceTest has passed" << endl;
			MoveTest().run();
				cout << "runMoveTest has passed" << endl;
			PositionTest().run();
				cout << "runPositionTest has passed" << endl;
			BoardTest().run();
				cout << "boardTest has passed" << endl;

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