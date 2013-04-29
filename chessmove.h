#ifndef CHESSMOVE_H
#define CHESSMOVE_H

#include "chessboard.h"
#include "chessboardsquare.h"
#include "chesspiece.h"

class ChessBoard;
class ChessBoardSquare;
class ChessPiece;

class ChessMove
{
	private:
		ChessBoard *board_;
		
	public:
		ChessMove(ChessBoard *board, int initIndex, int finalIndex);
		~ChessMove();
		bool isLegal(char color);
};
#endif
