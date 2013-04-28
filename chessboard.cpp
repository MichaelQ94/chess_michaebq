#include "chessboard.h"

ChessBoard::ChessBoard()
{
	whiteToMove_ = true;
	
	//instantiate and allocate memory for board squares
	for(int i = 0; i < 64; ++i)
	{
		squares_[i] = new ChessBoardSquare(this, i);
	}
	
	//instantiate and allocate memory for white pieces
	whitePieces_[0] = new ChessPiece_Pawn(this, 'W');
	whitePieces_[1]  = new ChessPiece_Pawn(this, 'W');
	whitePieces_[2]  = new ChessPiece_Pawn(this, 'W');
	whitePieces_[3]  = new ChessPiece_Pawn(this, 'W');
	whitePieces_[4]  = new ChessPiece_Pawn(this, 'W');
	whitePieces_[5]  = new ChessPiece_Pawn(this, 'W');
	whitePieces_[6]  = new ChessPiece_Pawn(this, 'W');
	whitePieces_[7]  = new ChessPiece_Pawn(this, 'W');
	
	whitePieces_[8]  = new ChessPiece_Knight(this, 'W');
	whitePieces_[9]  = new ChessPiece_Knight(this, 'W');
	
	whitePieces_[10]  = new ChessPiece_Bishop(this, 'W');
	whitePieces_[11]  = new ChessPiece_Bishop(this, 'W');
	
	whitePieces_[12]  = new ChessPiece_Rook(this, 'W');
	whitePieces_[13]  = new ChessPiece_Rook(this, 'W');
	
	whitePieces_[14]  = new ChessPiece_Queen(this, 'W');
	
	whitePieces_[15]  = new ChessPiece_King(this, 'W');
	
	//instantiate and allocate memory for black pieces
	blackPieces_[0] = new ChessPiece_Pawn(this, 'B');
	blackPieces_[1] = new ChessPiece_Pawn(this, 'B');
	blackPieces_[2] = new ChessPiece_Pawn(this, 'B');
	blackPieces_[3] = new ChessPiece_Pawn(this, 'B');
	blackPieces_[4] = new ChessPiece_Pawn(this, 'B');
	blackPieces_[5] = new ChessPiece_Pawn(this, 'B');
	blackPieces_[6] = new ChessPiece_Pawn(this, 'B');
	blackPieces_[7] = new ChessPiece_Pawn(this, 'B');
	
	blackPieces_[8] = new ChessPiece_Knight(this, 'B');
	blackPieces_[9] = new ChessPiece_Knight(this, 'B');
	
	blackPieces_[10] = new ChessPiece_Bishop(this, 'B');
	blackPieces_[11] = new ChessPiece_Bishop(this, 'B');
	
	blackPieces_[12] = new ChessPiece_Rook(this, 'B');
	blackPieces_[13] = new ChessPiece_Rook(this, 'B');
	
	blackPieces_[14] = new ChessPiece_Queen(this, 'B');
	
	blackPieces_[15] = new ChessPiece_King(this, 'B');
	
	
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

ChessBoard::ChessBoard(ChessBoard *board)
{
	whiteToMove_ = board->whiteToMove_;
	//instantiate and allocate memory for board squares
	for(int i = 0; i < 64; ++i)
	{
		squares_[i] = new ChessBoardSquare(this, i);
	}
	
	//instantiate and allocate memory for white pieces
	whitePieces_[0] = new ChessPiece_Pawn(this, dynamic_cast<ChessPiece_Pawn*>(board->whitePiece(0)));
	whitePieces_[1] = new ChessPiece_Pawn(this, dynamic_cast<ChessPiece_Pawn*>(board->whitePiece(1)));
	whitePieces_[2] = new ChessPiece_Pawn(this, dynamic_cast<ChessPiece_Pawn*>(board->whitePiece(2)));
	whitePieces_[3] = new ChessPiece_Pawn(this, dynamic_cast<ChessPiece_Pawn*>(board->whitePiece(3)));
	whitePieces_[4] = new ChessPiece_Pawn(this, dynamic_cast<ChessPiece_Pawn*>(board->whitePiece(4)));
	whitePieces_[5] = new ChessPiece_Pawn(this, dynamic_cast<ChessPiece_Pawn*>(board->whitePiece(5)));
	whitePieces_[6] = new ChessPiece_Pawn(this, dynamic_cast<ChessPiece_Pawn*>(board->whitePiece(6)));
	whitePieces_[7] = new ChessPiece_Pawn(this, dynamic_cast<ChessPiece_Pawn*>(board->whitePiece(7)));
	
	whitePieces_[8] = new ChessPiece_Knight(this, dynamic_cast<ChessPiece_Knight*>(board->whitePiece(8)));
	whitePieces_[9] = new ChessPiece_Knight(this, dynamic_cast<ChessPiece_Knight*>(board->whitePiece(9)));
	
	whitePieces_[10] = new ChessPiece_Bishop(this, dynamic_cast<ChessPiece_Bishop*>(board->whitePiece(10)));
	whitePieces_[11] = new ChessPiece_Bishop(this, dynamic_cast<ChessPiece_Bishop*>(board->whitePiece(11)));
	
	whitePieces_[12] = new ChessPiece_Rook(this, dynamic_cast<ChessPiece_Rook*>(board->whitePiece(12)));
	whitePieces_[13] = new ChessPiece_Rook(this, dynamic_cast<ChessPiece_Rook*>(board->whitePiece(13)));
	
	whitePieces_[14] = new ChessPiece_Queen(this, dynamic_cast<ChessPiece_Queen*>(board->whitePiece(14)));
	
	whitePieces_[15] = new ChessPiece_King(this, dynamic_cast<ChessPiece_King*>(board->whitePiece(15)));
	
	//instantiate and allocate memory for black pieces
	blackPieces_[0] = new ChessPiece_Pawn(this, dynamic_cast<ChessPiece_Pawn*>(board->blackPiece(0)));
	blackPieces_[1] = new ChessPiece_Pawn(this, dynamic_cast<ChessPiece_Pawn*>(board->blackPiece(1)));
	blackPieces_[2] = new ChessPiece_Pawn(this, dynamic_cast<ChessPiece_Pawn*>(board->blackPiece(2)));
	blackPieces_[3] = new ChessPiece_Pawn(this, dynamic_cast<ChessPiece_Pawn*>(board->blackPiece(3)));
	blackPieces_[4] = new ChessPiece_Pawn(this, dynamic_cast<ChessPiece_Pawn*>(board->blackPiece(4)));
	blackPieces_[5] = new ChessPiece_Pawn(this, dynamic_cast<ChessPiece_Pawn*>(board->blackPiece(5)));
	blackPieces_[6] = new ChessPiece_Pawn(this, dynamic_cast<ChessPiece_Pawn*>(board->blackPiece(6)));
	blackPieces_[7] = new ChessPiece_Pawn(this, dynamic_cast<ChessPiece_Pawn*>(board->blackPiece(7)));
	
	blackPieces_[8] = new ChessPiece_Knight(this, dynamic_cast<ChessPiece_Knight*>(board->blackPiece(8)));
	blackPieces_[9] = new ChessPiece_Knight(this, dynamic_cast<ChessPiece_Knight*>(board->blackPiece(9)));
	
	blackPieces_[10] = new ChessPiece_Bishop(this, dynamic_cast<ChessPiece_Bishop*>(board->blackPiece(10)));
	blackPieces_[11] = new ChessPiece_Bishop(this, dynamic_cast<ChessPiece_Bishop*>(board->blackPiece(11)));
	
	blackPieces_[12] = new ChessPiece_Rook(this, dynamic_cast<ChessPiece_Rook*>(board->blackPiece(12)));
	blackPieces_[13] = new ChessPiece_Rook(this, dynamic_cast<ChessPiece_Rook*>(board->blackPiece(13)));
	
	blackPieces_[14] = new ChessPiece_Queen(this, dynamic_cast<ChessPiece_Queen*>(board->blackPiece(14)));
	
	blackPieces_[15] = new ChessPiece_King(this, dynamic_cast<ChessPiece_King*>(board->blackPiece(15)));
	
	//place the pieces on the board
	whitePieces_[12]->move(whitePieces_[12]->square()); //white left rook
	whitePieces_[8]->move(whitePieces_[8]->square()); //white left knight
	whitePieces_[10]->move(whitePieces_[10]->square()); //white left bishop
	whitePieces_[14]->move(whitePieces_[14]->square()); //white queen
	whitePieces_[15]->move(whitePieces_[15]->square()); //white king
	whitePieces_[11]->move(whitePieces_[11]->square()); //white right bishop
	whitePieces_[9]->move(whitePieces_[9]->square()); //white right knight
	whitePieces_[13]->move(whitePieces_[13]->square()); //white right rook
	//white pawns
	whitePieces_[0]->move(whitePieces_[0]->square());
	whitePieces_[1]->move(whitePieces_[1]->square());
	whitePieces_[2]->move(whitePieces_[2]->square());
	whitePieces_[3]->move(whitePieces_[3]->square());
	whitePieces_[4]->move(whitePieces_[4]->square());
	whitePieces_[5]->move(whitePieces_[5]->square());
	whitePieces_[6]->move(whitePieces_[6]->square());
	whitePieces_[7]->move(whitePieces_[7]->square());
	
	//black pawns
	blackPieces_[0]->move(blackPieces_[0]->square());
	blackPieces_[1]->move(blackPieces_[1]->square());
	blackPieces_[2]->move(blackPieces_[2]->square());
	blackPieces_[3]->move(blackPieces_[3]->square());
	blackPieces_[4]->move(blackPieces_[4]->square());
	blackPieces_[5]->move(blackPieces_[5]->square());
	blackPieces_[6]->move(blackPieces_[6]->square());
	blackPieces_[7]->move(blackPieces_[7]->square());
	
	blackPieces_[12]->move(blackPieces_[12]->square()); //black left rook
	blackPieces_[8]->move(blackPieces_[8]->square()); //black left knight
	blackPieces_[10]->move(blackPieces_[10]->square()); //black left bishop
	blackPieces_[14]->move(blackPieces_[14]->square()); //black queen
	blackPieces_[15]->move(blackPieces_[15]->square()); //black king
	blackPieces_[11]->move(blackPieces_[11]->square()); //black right bishop
	blackPieces_[9]->move(blackPieces_[9]->square()); //black right knight
	blackPieces_[13]->move(blackPieces_[13]->square()); //black right rook
}

bool ChessBoard::whiteToMove()
{
	return whiteToMove_;
}

void ChessBoard::changeTurn()
{
	whiteToMove_ = !whiteToMove_;
	if(whiteToMove_)
	{
		for(int i = 0; i < 8; ++i)
		{
			whitePieces_[i]->refresh();
		}
		whitePieces_[15]->checkForCheck();
		std::cout << whiteCheck() << std::endl;
	}
	else
	{
		for(int i = 0; i < 8; ++i)
		{
			blackPieces_[i]->refresh();
		}
		blackPieces_[15]->checkForCheck();
	}
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

bool ChessBoard::whiteCheck()
{
	return whitePieces_[15]->inCheck();
}

bool ChessBoard::blackCheck()
{
	return blackPieces_[15]->inCheck();
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
