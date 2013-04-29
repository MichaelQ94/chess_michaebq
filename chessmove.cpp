#include "chessmove.h"

ChessMove::ChessMove(ChessBoard *board, int initIndex, int finalIndex)
{
	board_ = new ChessBoard(board);
	board_->square(initIndex)->getPiece()->move(board_->square(finalIndex));
	board_->changeTurn();
}

ChessMove::~ChessMove()
{
	delete board_;
}

bool ChessMove::isLegal(char color)
{
	if(color == 'W' && board_->whiteCheck())
		return false;
	else if(color == 'B' && board_->blackCheck())
		return false;
	return true;
}
