#include "chesspiece.h"
using namespace std;

ChessPiece_King::ChessPiece_King(ChessBoard *board, char color) : ChessPiece(board, 'K', color, -1)
{
	inCheck_ = false;
	hasMoved_ = false;
}

vector<int> ChessPiece_King::legalMoves()
{
	vector<int> legalMoves;
	
	//upper left
	int index = square_->index() + 7;
	if(index < 64 && index % 8 != 7 && 
		!(board_->square(index)->getPiece() != NULL && 
		board_->square(index)->getPiece()->color() == piece_color))
	{
		legalMoves.push_back(index);
	}
	
	//left
	index = square_->index() - 1;
	if(index >= 0 && index % 8 != 7 && 
		!(board_->square(index)->getPiece() != NULL && 
		board_->square(index)->getPiece()->color() == piece_color))
	{
		legalMoves.push_back(index);
	}
	
	//lower left
	index = square_->index() - 9;
	if(index >= 0 && index % 8 != 7 && 
		!(board_->square(index)->getPiece() != NULL && 
		board_->square(index)->getPiece()->color() == piece_color))
	{
		legalMoves.push_back(index);
	}
	
	//beneath
	index = square_->index() - 8;
	if(index >= 0 && 
		!(board_->square(index)->getPiece() != NULL && 
		board_->square(index)->getPiece()->color() == piece_color))
	{
		legalMoves.push_back(index);
	}
	
	//lower right
	index = square_->index() - 7;
	if(index >= 0 && index % 8 != 0 && 
		!(board_->square(index)->getPiece() != NULL && 
		board_->square(index)->getPiece()->color() == piece_color))
	{
		legalMoves.push_back(index);
	}
	
	//right
	index = square_->index() + 1;
	if(index < 64 && index % 8 != 0 && 
		!(board_->square(index)->getPiece() != NULL && 
		board_->square(index)->getPiece()->color() == piece_color))
	{
		legalMoves.push_back(index);
	}
	
	//upper right
	index = square_->index() + 9;
	if(index < 64 && index % 8 != 0 && 
		!(board_->square(index)->getPiece() != NULL && 
		board_->square(index)->getPiece()->color() == piece_color))
	{
		legalMoves.push_back(index);
	}
	
	//above
	index = square_->index() + 8;
	if(index < 64 && 
		!(board_->square(index)->getPiece() != NULL && 
		board_->square(index)->getPiece()->color() == piece_color))
	{
		legalMoves.push_back(index);
	}
	
	//two to the right (castling only)
	index = square_->index() + 2;
	if(!hasMoved_ && board_->square(index-1)->getPiece() == NULL &&
		board_->square(index)->getPiece() == NULL &&
		board_->square(index+1)->getPiece() != NULL &&
		!board_->square(index+1)->getPiece()->hasMoved())
	{
		legalMoves.push_back(index);
	}
	
	//two to the left (castling only)
	index = square_->index() - 2;
	if(!hasMoved_ && board_->square(index+1)->getPiece() == NULL &&
		board_->square(index)->getPiece() == NULL &&
		board_->square(index-1)->getPiece() == NULL &&
		board_->square(index-2)->getPiece() != NULL &&
		!board_->square(index-2)->getPiece()->hasMoved())
	{
		legalMoves.push_back(index);
	}
	
	return legalMoves;
}

bool ChessPiece_King::inCheck()
{
	return inCheck_;
}

void ChessPiece_King::check()
{
	inCheck_ = true;
}

void ChessPiece_King::outOfCheck()
{
	inCheck_ = false;
}

void ChessPiece_King::move(ChessBoardSquare *dest)
{
	if(square_ != NULL)
	{
		//kingside castle
		if(dest->index() == square_->index() + 2)
		{
			
			board_->square(square_->index() + 3)->getPiece()->move(board_->square(square_->index() + 1));
		}
		//queenside castle
		else if(dest->index() == square_->index() - 2)
		{
			board_->square(square_->index() - 4)->getPiece()->move(board_->square(square_->index() - 1));
		}
		square_->clear();
	}
	if(dest->getPiece() != NULL && dest->getPiece() != this)
		dest->getPiece()->isCaptured();
	square_ = dest;
	dest->setPiece(this);
	hasMoved_ = true;
	
}
