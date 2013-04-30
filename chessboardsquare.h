#ifndef CHESSBOARDSQUARE_H
#define CHESSBOARDSQUARE_H

#include <cstddef>
#include "chessboard.h"
#include "chesspiece.h"

/**Class to handle the collection of all squares and pieces*/
class ChessBoard;

/**Class to handle chesspiece functions*/
class ChessPiece;

/**Class to represent a single square on the board. Contains a refrence to the piece occupying the square (NULL if none) as
 * well as a reference to the board to which it belongs.
 */
class ChessBoardSquare
{	
	private:
		/**The piece occupying this square (NULL if none)*/
		ChessPiece *piece_;
		/**The board to which this square belongs*/
		ChessBoard *board_;
		/**The index of this square in the array of all squares contained in the board*/
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
