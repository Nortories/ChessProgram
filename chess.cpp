/**********************************************************************
 * Chess Board - Main
 * Authors: Kai Smith and Josh Sooaemalelagi
 * 
 * This is the main file for the chess board. It will create the board
 * and run the game.
 * 
 **********************************************************************/

#include "uiInteract.h"   // for Interface
#include "uiDraw.h"       // for draw*
#include "testRunner.h"     // for testing
#include "board.h"		 // for board
using namespace std;

/*************************************
 * CALLBACK
 * 
 * This is the callback function that will be called by the
 * interface.  It will be passed a pointer to the interface
 * and a pointer to the board.  It will then draw the board.
 * 
 **************************************/
void callBack(Interface *pUI, void * p)
{
   Board* pBoard = static_cast<Board*>(p);
   pBoard->draw(*pUI);
}

/*********************************
 * MAIN
 * 
 * Main is pretty sparse. Just create the interface
 * and run it. It will call the callback function
 * which will then draw the board.
 *
 *********************************/

int main(int argc, char** argv)
{
    /********************************
    * TESTING SPACE FOR TEST RUNNERS
    ********************************/
    
//    TestRunner tr;
//    tr.runAll();

    // Line below is for testing purposes
    cout << "Ready to go! pawns" << endl;

   Interface ui("Kai & Josh Chess Board");    // Create a window
   Board board;

   // set everything into action
   ui.run( callBack, &board);             

   return 0;
}
