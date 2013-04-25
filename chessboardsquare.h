#ifndef CHESSBOARDSQUARE_H
#define CHESSBOARDSQUARE_H

#include <cstddef>
#include "chessboard.h"
#include "chesspiece.h"

class ChessBoard;
class ChessPiece;

class ChessBoardSquare
{	
	private:
		ChessPiece *piece_;
		ChessBoard *board_;

	public:
		ChessBoardSquare(ChessBoard* board);
		void setPiece(ChessPiece *piece);
		void clear();
		ChessPiece* getPiece();
		ChessBoard* board();
		~ChessBoardSquare();
};
#endif
