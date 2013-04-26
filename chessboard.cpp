#include "chessboard.h"

ChessBoard::ChessBoard()
{
	whiteToMove_ = true;
	
	//instantiate and allocate memory for white pieces
	whitePieces_[0] = new ChessPiece_Pawn('W');
	whitePieces_[1]  = new ChessPiece_Pawn('W');
	whitePieces_[2]  = new ChessPiece_Pawn('W');
	whitePieces_[3]  = new ChessPiece_Pawn('W');
	whitePieces_[4]  = new ChessPiece_Pawn('W');
	whitePieces_[5]  = new ChessPiece_Pawn('W');
	whitePieces_[6]  = new ChessPiece_Pawn('W');
	whitePieces_[7]  = new ChessPiece_Pawn('W');
	
	whitePieces_[8]  = new ChessPiece_Knight('W');
	whitePieces_[9]  = new ChessPiece_Knight('W');
	
	whitePieces_[10]  = new ChessPiece_Bishop('W');
	whitePieces_[11]  = new ChessPiece_Bishop('W');
	
	whitePieces_[12]  = new ChessPiece_Rook('W');
	whitePieces_[13]  = new ChessPiece_Rook('W');
	
	whitePieces_[14]  = new ChessPiece_Queen('W');
	
	whitePieces_[15]  = new ChessPiece_King('W');
	
	//instantiate and allocate memory for black pieces
	blackPieces_[0] = new ChessPiece_Pawn('B');
	blackPieces_[1] = new ChessPiece_Pawn('B');
	blackPieces_[2] = new ChessPiece_Pawn('B');
	blackPieces_[3] = new ChessPiece_Pawn('B');
	blackPieces_[4] = new ChessPiece_Pawn('B');
	blackPieces_[5] = new ChessPiece_Pawn('B');
	blackPieces_[6] = new ChessPiece_Pawn('B');
	blackPieces_[7] = new ChessPiece_Pawn('B');
	
	blackPieces_[8] = new ChessPiece_Knight('B');
	blackPieces_[9] = new ChessPiece_Knight('B');
	
	blackPieces_[10] = new ChessPiece_Bishop('B');
	blackPieces_[11] = new ChessPiece_Bishop('B');
	
	blackPieces_[12] = new ChessPiece_Rook('B');
	blackPieces_[13] = new ChessPiece_Rook('B');
	
	blackPieces_[14] = new ChessPiece_Queen('B');
	
	blackPieces_[15] = new ChessPiece_King('B');
	
	//instantiate allocate memory for board squares
	for(int i = 0; i < 64; ++i)
	{
		squares_[i] = new ChessBoardSquare(this, i);
	}
	
	//place the pieces on the board
	whitePieces_[12]->move(squares_[0]); //white left rook
	whitePieces_[8]->move(squares_[1]); //white left knight
	whitePieces_[10]->move(squares_[2]); //white left bishop
	whitePieces_[14]->move(squares_[3]); //white queen
	whitePieces_[15]->move(squares_[4]); //white king
	whitePieces_[11]->move(squares_[5]); //white right bishop
	whitePieces_[9]->move(squares_[6]); //white right knight
	whitePieces_[13]->move(squares_[7]); //white right rook
	//white pawns
	whitePieces_[0]->move(squares_[8]);
	whitePieces_[1]->move(squares_[9]);
	whitePieces_[2]->move(squares_[10]);
	whitePieces_[3]->move(squares_[11]);
	whitePieces_[4]->move(squares_[12]);
	whitePieces_[5]->move(squares_[13]);
	whitePieces_[6]->move(squares_[14]);
	whitePieces_[7]->move(squares_[15]);
	
	//black pawns
	blackPieces_[0]->move(squares_[48]);
	blackPieces_[1]->move(squares_[49]);
	blackPieces_[2]->move(squares_[50]);
	blackPieces_[3]->move(squares_[51]);
	blackPieces_[4]->move(squares_[52]);
	blackPieces_[5]->move(squares_[53]);
	blackPieces_[6]->move(squares_[54]);
	blackPieces_[7]->move(squares_[55]);
	
	blackPieces_[12]->move(squares_[56]); //black left rook
	blackPieces_[8]->move(squares_[57]); //black left knight
	blackPieces_[10]->move(squares_[58]); //black left bishop
	blackPieces_[14]->move(squares_[59]); //black queen
	blackPieces_[15]->move(squares_[60]); //black king
	blackPieces_[11]->move(squares_[61]); //black right bishop
	blackPieces_[9]->move(squares_[62]); //black right knight
	blackPieces_[13]->move(squares_[63]); //black right rook
}

bool ChessBoard::whiteToMove()
{
	return whiteToMove_;
}

void ChessBoard::changeTurn()
{
	whiteToMove_ = !whiteToMove_;
}

ChessBoardSquare* ChessBoard::square(int index)
{
	return squares_[index];
}

ChessPiece* ChessBoard::whitePiece(int index)
{
	return whitePieces_[index];
}

ChessPiece* ChessBoard::blackPiece(int index)
{
	return blackPieces_[index];
}

ChessBoard::~ChessBoard()
{
	//delete dynamically allocated squares
	for(int i = 0; i < 64; ++i)
	{
		delete squares_[i];
	}
	
	//delete dynamically allocated pieces
	for(int i = 0; i < 16; ++i)
	{
		delete whitePieces_[i];
		delete blackPieces_[i];
	}
}
