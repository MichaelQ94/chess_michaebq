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
}

ChessPiece::ChessPiece(ChessBoard *board, ChessPiece *piece)
{
	board_ = piece->board_;
	square_ = piece->square_;
	piece_type = piece->piece_type;
	piece_color = piece->piece_color;
	value_ = piece->value_;
	captured_ = piece->captured_;
}

void ChessPiece::copyData(ChessPiece *piece)
{
	board_ = piece->board_;
	piece_type = piece->piece_type;
	piece_color = piece->piece_color;
	value_ = piece->value_;
	square_ = piece->square_;
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

bool ChessPiece::hasMoved()
{
	return true;
}

bool ChessPiece::enPassant()
{
	return false;
}

void ChessPiece::reset()
{
}

void ChessPiece::refresh()
{
	
}

bool ChessPiece::inCheck()
{
	return false;
}

bool ChessPiece::checkForCheck()
{
	return false;
}

ChessBoardSquare* ChessPiece::square()
{
	return square_;
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
}
