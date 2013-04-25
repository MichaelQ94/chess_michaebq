#include "chessboard.h"

ChessBoard::ChessBoard()
{
	//instantiate white pieces
	WP1 = new ChessPiece_Pawn('W');
	WP2 = new ChessPiece_Pawn('W');
	WP3 = new ChessPiece_Pawn('W');
	WP4 = new ChessPiece_Pawn('W');
	WP5 = new ChessPiece_Pawn('W');
	WP6 = new ChessPiece_Pawn('W');
	WP7 = new ChessPiece_Pawn('W');
	WP8 = new ChessPiece_Pawn('W');
	
	WN1 = new ChessPiece_Knight('W');
	WN2 = new ChessPiece_Knight('W');
	
	WB1 = new ChessPiece_Bishop('W');
	WB2 = new ChessPiece_Bishop('W');
	
	WQ = new ChessPiece_Queen('W');
	
	WK = new ChessPiece_King('W');
	
	//instantiate black pieces
	BP1 = new ChessPiece_Pawn('B');
	BP2 = new ChessPiece_Pawn('B');
	BP3 = new ChessPiece_Pawn('B');
	BP4 = new ChessPiece_Pawn('B');
	BP5 = new ChessPiece_Pawn('B');
	BP6 = new ChessPiece_Pawn('B');
	BP7 = new ChessPiece_Pawn('B');
	BP8 = new ChessPiece_Pawn('B');
	
	BN1 = new ChessPiece_Knight('B');
	BN2 = new ChessPiece_Knight('B');
	
	BB1 = new ChessPiece_Bishop('B');
	BB2 = new ChessPiece_Bishop('B');
	
	BQ = new ChessPiece_Queen('B');
	
	BK = new ChessPiece_King('B');
	
	
	//create the board squares and place the pieces on them
	for(int i = 0; i < 64; ++i)
	{
		squares_[i] = new ChessBoardSquare(this);
	}
	
	squares_[0]->setPiece(WR1);
	squares_[1]->setPiece(WN1);
	squares_[2]->setPiece(WN1);
	squares_[3]->setPiece(WQ);
	squares_[4]->setPiece(WK);
	squares_[5]->setPiece(WB2);
	squares_[6]->setPiece(WN2);
	squares_[7]->setPiece(WR2);
	squares_[8]->setPiece(WP1);
	squares_[9]->setPiece(WP2);
	squares_[10]->setPiece(WP3);
	squares_[11]->setPiece(WP4);
	squares_[12]->setPiece(WP5);
	squares_[13]->setPiece(WP6);
	squares_[14]->setPiece(WP7);
	squares_[15]->setPiece(WP8);
	
	squares_[48]->setPiece(BP1);
	squares_[49]->setPiece(BP2);
	squares_[50]->setPiece(BP3);
	squares_[51]->setPiece(BP4);
	squares_[52]->setPiece(BP5);
	squares_[53]->setPiece(BP6);
	squares_[54]->setPiece(BP7);
	squares_[55]->setPiece(BP8);
	squares_[56]->setPiece(BR1);
	squares_[57]->setPiece(BN1);
	squares_[58]->setPiece(BB1);
	squares_[59]->setPiece(BQ);
	squares_[60]->setPiece(BK);
	squares_[63]->setPiece(BB2);
	squares_[62]->setPiece(BN2);
	squares_[63]->setPiece(BR2);
}
