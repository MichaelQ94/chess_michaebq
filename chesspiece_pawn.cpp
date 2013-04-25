#include "chesspiece.h"

ChessPiece_Pawn::ChessPiece_Pawn(char color) : ChessPiece('P', color, 1)
{
	promoted_piece = NULL;
}

ChessPiece_Pawn::~ChessPiece_Pawn()
{
	delete promoted_piece;
}

void ChessPiece_Pawn::move(ChessBoardSquare *dest)
{
}
