#include "chesspiece.h"
using namespace std;

ChessPiece_King::ChessPiece_King(ChessBoard *board, char color) : ChessPiece(board, 'K', color, -1)
{
	inCheck_ = false;
	hasMoved_ = false;
}

ChessPiece_King::ChessPiece_King(ChessBoard *board, ChessPiece_King *piece) : ChessPiece(board, piece)
{
	inCheck_ = piece->inCheck_;
	hasMoved_ = piece->hasMoved_;
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

void ChessPiece_King::reset()
{
	hasMoved_ = false;
}

bool ChessPiece_King::checkForCheck()
{
	//scan the diagonal to the upper right
	int index = square_->index() + 9;
	if(board_->square(index)->getPiece() != NULL &&
		board_->square(index)->getPiece()->color() != piece_color &&
		board_->square(index)->getPiece()->type() == 'P') //this square contains an enemy pawn
	{
		inCheck_ = true;
		return true;
	}
	while(index < 64 && index % 8 != 0)
	{
		if(board_->square(index)->getPiece() != NULL && 
			board_->square(index)->getPiece()->color() == piece_color) //friendly piece
			break;
		if(board_->square(index)->getPiece() != NULL && 
			(board_->square(index)->getPiece()->type() == 'B' ||
			board_->square(index)->getPiece()->type() == 'Q')) //this square contains an enemy bishop or queen
		{
			inCheck_ = true;
			return true;
		}
		index += 9;
	}
	
	//scan the diagonal to the lower left
	index = square_->index() - 9;
	while(index >= 0 && index % 8 != 7)
	{
		if(board_->square(index)->getPiece() != NULL && 
			board_->square(index)->getPiece()->color() == piece_color) //friendly piece
			break;
		if(board_->square(index)->getPiece() != NULL && 
			(board_->square(index)->getPiece()->type() == 'B' ||
			board_->square(index)->getPiece()->type() == 'Q')) //this square contains an enemy bishop or queen
		{
			inCheck_ = true;
			return true;
		}
		index -= 9;
	}
	
	//scan the diagonal to the upper left
	index = square_->index() + 7;
	if(board_->square(index)->getPiece() != NULL &&
		board_->square(index)->getPiece()->color() != piece_color &&
		board_->square(index)->getPiece()->type() == 'P') //this square contains an enemy pawn
	{
		inCheck_ = true;
		return true;
	}
	while(index < 64 && index % 8 != 7)
	{
		if(board_->square(index)->getPiece() != NULL && 
			board_->square(index)->getPiece()->color() == piece_color) //friendly piece
			break;
		if(board_->square(index)->getPiece() != NULL && 
			(board_->square(index)->getPiece()->type() == 'B' ||
			board_->square(index)->getPiece()->type() == 'Q')) //this square contains an enemy bishop or queen
		{
			inCheck_ = true;
			return true;
		}
		index += 7;
	}
	
	//scan the diagonal to the lower right
	index = square_->index() - 7;
	while(index >= 0 && index % 8 != 0)
	{
		if(board_->square(index)->getPiece() != NULL && 
			board_->square(index)->getPiece()->color() == piece_color) //friendly piece
			break;
		if(board_->square(index)->getPiece() != NULL && 
			(board_->square(index)->getPiece()->type() == 'B' ||
			board_->square(index)->getPiece()->type() == 'Q')) //this square contains an enemy bishop or queen
		{
			inCheck_ = true;
			return true;
		}
		index -= 7;
	}
	
	//right
	index = square_->index() + 1;
	while(index < 64 && index % 8 != 0)
	{
		if(board_->square(index)->getPiece() != NULL && 
			board_->square(index)->getPiece()->color() == piece_color) //friendly piece
			break;
		if(board_->square(index)->getPiece() != NULL && 
			(board_->square(index)->getPiece()->type() == 'R' ||
			board_->square(index)->getPiece()->type() == 'Q')) //this square contains an enemy rook or queen
		{
			inCheck_ = true;
			return true;
		}
		++index;
	}
	
	//left
	index = square_->index() - 1;
	while(index >= 0 && index % 8 != 7)
	{
		if(board_->square(index)->getPiece() != NULL && 
			board_->square(index)->getPiece()->color() == piece_color) //friendly piece
			break;
		if(board_->square(index)->getPiece() != NULL && 
			(board_->square(index)->getPiece()->type() == 'R' ||
			board_->square(index)->getPiece()->type() == 'Q')) //this square contains an enemy rook or queen
		{
			inCheck_ = true;
			return true;
		}
		--index;
	}
	
	//up
	index = square_->index() + 8;
	while(index < 64)
	{
		if(board_->square(index)->getPiece() != NULL && 
			board_->square(index)->getPiece()->color() == piece_color) //friendly piece
			break;
		if(board_->square(index)->getPiece() != NULL && 
			(board_->square(index)->getPiece()->type() == 'R' ||
			board_->square(index)->getPiece()->type() == 'Q')) //this square contains an enemy rook or queen
		{
			inCheck_ = true;
			return true;
		}
		index += 8;
	}
	
	//down
	index = square_->index() - 8;
	while(index >= 0)
	{
		if(board_->square(index)->getPiece() != NULL && 
			board_->square(index)->getPiece()->color() == piece_color) //friendly piece
			break;
		if(board_->square(index)->getPiece() != NULL && 
			(board_->square(index)->getPiece()->type() == 'R' ||
			board_->square(index)->getPiece()->type() == 'Q')) //this square contains an enemy rook or queen
		{
			inCheck_ = true;
			return true;
		}
		index -= 8;
	}
	
	index = square_->index() + 17;
	if(index < 64 && index % 8 != 0 && 
		board_->square(index)->getPiece() != NULL &&
		board_->square(index)->getPiece()->color() != piece_color &&
		board_->square(index)->getPiece()->type() == 'N') //this square contains an enemy knight
	{
		inCheck_ = true;
		return true;
	}
	
	index = square_->index() + 10;
	if(index < 64 && index % 8 > 1 && 
		board_->square(index)->getPiece() != NULL &&
		board_->square(index)->getPiece()->color() != piece_color &&
		board_->square(index)->getPiece()->type() == 'N') //this square contains an enemy knight
	{
		inCheck_ = true;
		return true;
	}
	
	index = square_->index() - 6;
	if(index >= 0 && index % 8 > 1 && 
		board_->square(index)->getPiece() != NULL &&
		board_->square(index)->getPiece()->color() != piece_color &&
		board_->square(index)->getPiece()->type() == 'N') //this square contains an enemy knight
	{
		inCheck_ = true;
		return true;
	}
	
	index = square_->index() - 15;
	if(index >= 0 && index % 8 != 0 && 
		board_->square(index)->getPiece() != NULL &&
		board_->square(index)->getPiece()->color() != piece_color &&
		board_->square(index)->getPiece()->type() == 'N') //this square contains an enemy knight
	{
		inCheck_ = true;
		return true;
	}
	
	index = square_->index() - 17;
	if(index >= 0 && index % 8 != 7 && 
		board_->square(index)->getPiece() != NULL &&
		board_->square(index)->getPiece()->color() != piece_color &&
		board_->square(index)->getPiece()->type() == 'N') //this square contains an enemy knight
	{
		inCheck_ = true;
		return true;
	}
	
	index = square_->index() - 10;
	if(index >= 0 && index % 8 < 6 && 
		board_->square(index)->getPiece() != NULL &&
		board_->square(index)->getPiece()->color() != piece_color &&
		board_->square(index)->getPiece()->type() == 'N') //this square contains an enemy knight
	{
		inCheck_ = true;
		return true;
	}
	
	index = square_->index() + 6;
	if(index < 64 && index % 8 < 6 && 
		board_->square(index)->getPiece() != NULL &&
		board_->square(index)->getPiece()->color() != piece_color &&
		board_->square(index)->getPiece()->type() == 'N') //this square contains an enemy knight
	{
		inCheck_ = true;
		return true;
	}
	
	index = square_->index() + 15;
	if(index < 64 && index % 8 != 7 && 
		board_->square(index)->getPiece() != NULL &&
		board_->square(index)->getPiece()->color() != piece_color &&
		board_->square(index)->getPiece()->type() == 'N') //this square contains an enemy knight
	{
		inCheck_ = true;
		return true;
	}
	
	inCheck_ = false;
	return false; //this is only reached if all the possibilites have been searched and no check was detected
}

bool ChessPiece_King::hasMoved()
{
	return hasMoved_;
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
