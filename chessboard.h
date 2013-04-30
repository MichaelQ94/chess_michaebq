#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "chesspiece.h"

/**Class to handle the board squares*/
class ChessBoardSquare;
/**Class to handle generic chess piece functionality*/
class ChessPiece;
/**Class to handle pawn-specific functionality*/
class ChessPiece_Pawn;
/**Class to handle knight-specific functionality*/
class ChessPiece_Knight;
/**Class to handle bishop-specific functionality*/
class ChessPiece_Bishop;
/**Class to handle rook-specific functionality*/
class ChessPiece_Rook;
/**Class to handle queen-specific functionality*/
class ChessPiece_Queen;
/**Class to handle king-specific functionality*/
class ChessPiece_King;

/**Class to handle the chess board. Contains an array of ChessBoardSquares as well as an array of white pieces
 * and an array of black pieces. Handles the changing of turns.
 */
class ChessBoard
{
	private:
		/**true on white's turn, false on black's turn*/
		bool whiteToMove_;
		/**Array of all squares on the board*/
		ChessBoardSquare* squares_[64];
		/**Array of all white pieces*/
		ChessPiece* whitePieces_[16];
		/**Array of all black pieces*/
		ChessPiece* blackPieces_[16];
		//Key:
		//0-7: pawns
		//8,9: knights
		//10,11: bishops
		//12,13: rooks
		//14: queen
		//15: king
	public:
		ChessBoard();
		ChessBoard(ChessBoard *board);
		ChessBoardSquare* square(int index);
		ChessPiece* whitePiece(int index);
		ChessPiece* blackPiece(int index);
		int whiteScore();
		int whiteRemaining();
		int blackScore();
		int blackRemaining();
		bool whiteCheck();
		bool blackCheck();
		bool whiteCheckMate();
		bool blackCheckMate();
		bool staleMate();
		bool whiteToMove();
		void changeTurn();
		~ChessBoard();
};
#endif
