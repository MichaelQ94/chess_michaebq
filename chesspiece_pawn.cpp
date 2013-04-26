#include "chesspiece.h"

ChessPiece_Pawn::ChessPiece_Pawn(char color) : ChessPiece('P', color, 1)
{
	promoted_piece = NULL;
}

ChessPiece_Pawn::~ChessPiece_Pawn()
{
	if(promoted_piece != NULL)
		delete promoted_piece;
}
