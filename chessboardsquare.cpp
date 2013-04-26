#include "chessboardsquare.h"

ChessBoardSquare::ChessBoardSquare(ChessBoard *board, int index)
{
	board_ = board;
	piece_ = NULL;
	index_ = index;
}

void ChessBoardSquare::setPiece(ChessPiece *piece)
{
	piece_ = piece;
}

void ChessBoardSquare::clear()
{
	piece_ = NULL;
}

int ChessBoardSquare::index()
{
	return index_;
}

ChessPiece* ChessBoardSquare::getPiece()
{
	return piece_;
}

ChessBoardSquare::~ChessBoardSquare() {}
