#ifndef CHESSMOVE_H
#define CHESSMOVE_H

#include "chessboard.h"
#include "chessboardsquare.h"
#include "chesspiece.h"

/**Class to handle the collection of all squares and pieces*/
class ChessBoard;
/**Class used to represent a single square on the board*/
class ChessBoardSquare;
/**Class used to handle chess piece functions*/
class ChessPiece;

/**Class used to represent a single move made on the board*/
class ChessMove
{
	private:
		/**A board which is to be dynamically allocated when a ChessMove object is created
		 * Represent's the board after a specific move has been made.
		 */
		ChessBoard *board_;
		
	public:
		ChessMove(ChessBoard *board, int initIndex, int finalIndex);
		~ChessMove();
		bool isLegal(char color);
};
#endif
