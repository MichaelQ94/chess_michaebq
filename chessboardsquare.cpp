#include "chessboardsquare.h"

ChessBoardSquare::ChessBoardSquare(ChessBoard *board)
{
	board_ = board;
	piece_ = NULL;
}

void ChessBoardSquare::setPiece(ChessPiece *piece)
{
	piece_ = piece;
}

void ChessBoardSquare::clear()
{
	piece_ = NULL;
}

ChessBoardSquare::~ChessBoardSquare() {}
