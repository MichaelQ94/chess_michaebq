#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <iostream>
#include "chesspiece.h"

class ChessBoardSquare;
class ChessPiece;
class ChessPiece_Pawn;
class ChessPiece_Knight;
class ChessPiece_Bishop;
class ChessPiece_Rook;
class ChessPiece_Queen;
class ChessPiece_King;

class ChessBoard
{
	private:
		bool whiteToMove_; //true on white's turn, false on black's turn
		ChessBoardSquare* squares_[64];
		ChessPiece* whitePieces_[16];
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
		bool whiteCheck();
		bool blackCheck();
		bool whiteToMove();
		void changeTurn();
		~ChessBoard();
};
#endif
