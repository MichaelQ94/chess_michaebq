#include "chesspiece.h"

ChessPiece::ChessPiece(char type, char color, int value)
{
	piece_type = type;
	piece_color = color;
	value_ = value;
	square_ = NULL;
	captured_ = false;
	
}

char ChessPiece::type()
{
	return piece_type;
}

char ChessPiece::color()
{
	return piece_color;
}

int ChessPiece::value()
{
	return value_;
}

bool ChessPiece::captured()
{
	return captured_;
}

void ChessPiece::isCaptured()
{
	captured_ = true;
	square_->clear();
	square_ = NULL;
}

void ChessPiece::move(ChessBoardSquare *dest)
{
	if(square_ != NULL)
		square_->clear();
	if(dest->getPiece() != NULL)
		dest->getPiece()->isCaptured();
	square_ = dest;
	dest->setPiece(this);
}
