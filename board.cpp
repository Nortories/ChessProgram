/***********************************************************************
 * Cpp File:
 *    Board  : Board class
 * Author:
 *    Joshua Sooaemalelagi & Kai
 ************************************************************************/

#include "board.h"

/*****************************************************
* SELECTOR
* Select a piece and show the possible moves for that piece
*****************************************************/
void Board::selector(Interface& pUI)
{
    if (this->board[pUI.getSelectPosition()].move(this->board, pUI.getPreviousPosition(), pUI.getSelectPosition(), this->isWhiteTurn()))
    {
        
        this->takeTurn();

        for (int i = 0; i < 64; i++) {
            char p = this->board[i].getType();
            if (p == 'p' || p == 'P') {
            this->board[i].checkEnpassant(this->board, pUI.getSelectPosition());
            }
        }
        pUI.clearSelectPosition();

        cout << "It is now " << (this->isWhiteTurn() ? "white's" : "black's") << " turn\n Game has had " << currentMove<< " moves";
    }
    else
        _possible = this->board[pUI.getSelectPosition()].getPossibleMoves(this->board, pUI.getSelectPosition(), this->isWhiteTurn());
    //cout << possible.size() << endl;

    // if we clicked on a blank spot, then it is not selected
    if (pUI.getSelectPosition() != -1 && this->board[pUI.getSelectPosition()].getType() == ' ')
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
    for (it = _possible.begin(); it != _possible.end(); ++it)
        gout.drawPossible(*it);

    for (int i = 0; i < 64; i++)
        this->board[i].draw(i, ui);
}
