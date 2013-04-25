#include "chesspiece.h"

ChessPiece::ChessPiece(char type, char color, int value)
{
	piece_type = type;
	piece_color = color;
	value_ = value;
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
	
}
