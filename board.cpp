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
    if (this->board[pUI.getSelectPosition()].move(this->board, pUI.getPreviousPosition(), pUI.getSelectPosition(), this->isWhiteTurn()))
    {
        this->takeTurn();
        if (castle())
		{
			cout << "castled!" << endl;
		}
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

bool Board::castle()
{
	if (this->board[ui.getSelectPosition()].getType() == 'K' || this->board[ui.getSelectPosition()].getType() == 'k')
	{
        int selected = ui.getSelectPosition();
        //white king side
		if (ui.getSelectPosition() == 6 && ui.getPreviousPosition() == 4)
		{
			this->board[selected] = King(6, false);
			this->board[selected -1]= Rook(5, false);
            this->board[selected +1] = Space();
            this->board[selected -2] = Space();
			return true;
		}
        //white queen side
		if (ui.getSelectPosition() == 2 && ui.getPreviousPosition() == 4)
		{
            this->board[selected] = King(2, false);
            this->board[selected + 1] = Rook(5, false);
            this->board[selected - 1] = Space();
            this->board[selected + 2] = Space();
            this->board[selected - 2] = Space();
            return true;
		}
        //black king side
		if (ui.getSelectPosition() == 62 && ui.getPreviousPosition() == 60)
		{
            this->board[selected] = King(62, true);
            this->board[selected - 1] = Rook(63, true);
            this->board[selected + 1] = Space();
            this->board[selected - 2] = Space();
            return true;
		}
        // black queen side
		if (ui.getSelectPosition() == 58 && ui.getPreviousPosition() == 60)
		{
            this->board[selected] = King(58, true);
            this->board[selected + 1] = Rook(57, true);
            this->board[selected - 1] = Space();
            this->board[selected + 2] = Space();
            this->board[selected - 2] = Space();
            return true;
		}
	}
	return false;
}