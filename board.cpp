/*****************************************************
*  board.cpp
*  TestBoardLab03
*
*  Created by Kaidi Zhang on 1/27/24.
*****************************************************/

#include "board.h"

/*****************************************************
* SELECTOR
* Select a piece and show the possible moves for that piece
*****************************************************/
void Board::selector(Interface& pUI)
{
    if (board[pUI.getSelectPosition()].move(board, pUI.getPreviousPosition(), pUI.getSelectPosition()))
        pUI.clearSelectPosition();
    else
        possible = board[pUI.getSelectPosition()].getPossibleMoves(board, pUI.getSelectPosition());

    // if we clicked on a blank spot, then it is not selected
    if (pUI.getSelectPosition() != -1 && board[pUI.getSelectPosition()].getType() == ' ')
        pUI.clearSelectPosition();
}

/***************************************************
 * DRAW
 * Draw the current state of the game
 ***************************************************/
void Board::draw(Interface& ui)
{
    ogstream gout;

    // draw the checkerboard
    gout.drawBoard();

    // draw any selections
    selector(ui);
    gout.drawHover(ui.getHoverPosition());
    gout.drawSelected(ui.getSelectPosition());

    // draw the possible moves
    set <int> ::iterator it;
    for (it = possible.begin(); it != possible.end(); ++it)
        gout.drawPossible(*it);

    // draw the pieces
    for (int i = 0; i < 64; i++)
        switch (this->board[i].getType())
        {
        case 'P':
            gout.drawPawn(i, true);
            break;
        case 'p':
            gout.drawPawn(i, false);
            break;
        case 'K':
            gout.drawKing(i, true);
            break;
        case 'k':
            gout.drawKing(i, false);
            break;
        case 'Q':
            gout.drawQueen(i, true);
            break;
        case 'q':
            gout.drawQueen(i, false);
            break;
        case 'R':
            gout.drawRook(i, true);
            break;
        case 'r':
            gout.drawRook(i, false);
            break;
        case 'B':
            gout.drawBishop(i, true);
            break;
        case 'b':
            gout.drawBishop(i, false);
            break;
        case 'N':
            gout.drawKnight(i, true);
            break;
        case 'n':
            gout.drawKnight(i, false);
            break;
        }
}



