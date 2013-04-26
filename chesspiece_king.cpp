#include "chesspiece.h"

ChessPiece_King::ChessPiece_King(char color) : ChessPiece('K', color, -1)
{
	inCheck_ = false;
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
