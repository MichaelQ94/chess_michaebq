#include "chesspiece.h"
using namespace std;

ChessPiece::ChessPiece(ChessBoard *board, char type, char color, int value)
{
	board_ = board;
	piece_type = type;
	piece_color = color;
	value_ = value;
	square_ = NULL;
	captured_ = false;
	hasMoved_ = false;
	enPassant_ = false;
	
}

void ChessPiece::copyData(ChessPiece *piece)
{
	board_ = piece->board_;
	piece_type = piece->piece_type;
	piece_color = piece->piece_color;
	value_ = piece->value_;
	square_ = piece->square_;
	captured_ = false;
	hasMoved_ = false;
	enPassant_ = false;
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

bool ChessPiece::hasMoved()
{
	return hasMoved_;
}

bool ChessPiece::enPassant()
{
	return enPassant_;
}

void ChessPiece::reset()
{
	hasMoved_ = false;
}

void ChessPiece::refresh()
{
	
}

void ChessPiece::promote(char type)
{
	type = type;
}

void ChessPiece::move(ChessBoardSquare *dest)
{
	if(square_ != NULL)
		square_->clear();
	if(dest->getPiece() != NULL)
		dest->getPiece()->isCaptured();
	square_ = dest;
	dest->setPiece(this);
	hasMoved_ = true;
}
