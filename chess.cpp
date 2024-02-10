/**********************************************************************
 * GL Demo
 * Just a simple program to demonstrate how to create an Open GL window, 
 * draw something on the window, and accept simple user input
 **********************************************************************/

#include "uiInteract.h"   // for Interface
#include "uiDraw.h"       // for draw*
#include <set>            // for STD::SET
#include <cassert>        // for ASSERT
#include <fstream>        // for IFSTREAM
#include <string>         // for STRING
#include "testRunner.h"     // for testing
#include <exception>       // for exception
#include <iostream>        // for cerr
#include "board.h"		 // for board
using namespace std;

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(Interface *pUI, void * p)
{

   Board* pBoard = static_cast<Board*>(p);

   pBoard->selector(pUI);
   pBoard->draw(*pUI);
}

/*********************************
 * Main is pretty sparse.  Just initialize
 * my Demo type and call the display engine.
 * That is all!
 *********************************/

int main(int argc, char** argv)
{
    /********************************
    * TESTING SPACE FOR TEST RUNNERS
    ********************************/
    //TestRunner tr;
    //tr.runAll();

    cout << "Ready to go! ITS GREAT!!" << endl;

   Interface ui("Kai and Josh Chess Board");    

   Board board;

   // set everything into action
   ui.run( callBack, &board);             

   return 0;
}
