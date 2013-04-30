#include "chessmove.h"

/**Constructor. Takes the current state of the board and makes the indicated move by moving the piece which is on the square
 * whose index is initIndex to the square whose index is finalIndex.
 * @param *board Reference to the board to be copied
 * @param initIndex The index of the square which is occupied by the piece to be moved
 * @param finalIndex The index of the square which is the intended destination of the piece to be moved
 */
ChessMove::ChessMove(ChessBoard *board, int initIndex, int finalIndex)
{
	board_ = new ChessBoard(board);
	board_->square(initIndex)->getPiece()->move(board_->square(finalIndex));
	board_->changeTurn();
}

/**Destructor. Deallocates the memory used to store the board.
 */
ChessMove::~ChessMove()
{
	delete board_;
}

/**Checks if the move made was legal for a given player by seeing if it resulted in that player being in check.
 * @return Returns true if the move is legal, false if not
 */
bool ChessMove::isLegal(char color)
{
	if(color == 'W' && board_->whiteCheck())
		return false;
	else if(color == 'B' && board_->blackCheck())
		return false;
	return true;
}
