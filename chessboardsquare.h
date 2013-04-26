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
		int index_;

	public:
		ChessBoardSquare(ChessBoard* board, int index);
		void setPiece(ChessPiece *piece);
		void clear();
		int index();
		ChessPiece* getPiece();

		~ChessBoardSquare();
};
#endif
