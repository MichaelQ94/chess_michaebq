#ifndef CHESSBOARD_H
#define CHESSBOARD_H

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
		ChessBoardSquare* squares_[64];
		//white pieces
		ChessPiece_Pawn *WP1, *WP2, *WP3, *WP4, *WP5, *WP6, *WP7, *WP8;
		ChessPiece_Knight *WN1, *WN2;
		ChessPiece_Bishop *WB1, *WB2;
		ChessPiece_Rook *WR1, *WR2;
		ChessPiece_Queen *WQ;
		ChessPiece_King *WK;
		
		//black pieces
		ChessPiece_Pawn *BP1, *BP2, *BP3, *BP4, *BP5, *BP6, *BP7, *BP8;
		ChessPiece_Knight *BN1, *BN2;
		ChessPiece_Bishop *BB1, *BB2;
		ChessPiece_Rook *BR1, *BR2;
		ChessPiece_Queen *BQ;
		ChessPiece_King *BK;
	public:
		ChessBoard();
		~ChessBoard();
};
#endif
