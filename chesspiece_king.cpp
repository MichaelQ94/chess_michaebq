#include "chesspiece.h"
using namespace std;

ChessPiece_King::ChessPiece_King(ChessBoard *board, char color) : ChessPiece(board, 'K', color, -1)
{
	inCheck_ = false;
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
