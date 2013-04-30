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
	whitePieces_[0] = new ChessPiece_Pawn(this, static_cast<ChessPiece_Pawn*>(board->whitePiece(0)));
	whitePieces_[1] = new ChessPiece_Pawn(this, static_cast<ChessPiece_Pawn*>(board->whitePiece(1)));
	whitePieces_[2] = new ChessPiece_Pawn(this, static_cast<ChessPiece_Pawn*>(board->whitePiece(2)));
	whitePieces_[3] = new ChessPiece_Pawn(this, static_cast<ChessPiece_Pawn*>(board->whitePiece(3)));
	whitePieces_[4] = new ChessPiece_Pawn(this, static_cast<ChessPiece_Pawn*>(board->whitePiece(4)));
	whitePieces_[5] = new ChessPiece_Pawn(this, static_cast<ChessPiece_Pawn*>(board->whitePiece(5)));
	whitePieces_[6] = new ChessPiece_Pawn(this, static_cast<ChessPiece_Pawn*>(board->whitePiece(6)));
	whitePieces_[7] = new ChessPiece_Pawn(this, static_cast<ChessPiece_Pawn*>(board->whitePiece(7)));
	
	whitePieces_[8] = new ChessPiece_Knight(this, static_cast<ChessPiece_Knight*>(board->whitePiece(8)));
	whitePieces_[9] = new ChessPiece_Knight(this, static_cast<ChessPiece_Knight*>(board->whitePiece(9)));
	
	whitePieces_[10] = new ChessPiece_Bishop(this, static_cast<ChessPiece_Bishop*>(board->whitePiece(10)));
	whitePieces_[11] = new ChessPiece_Bishop(this, static_cast<ChessPiece_Bishop*>(board->whitePiece(11)));
	
	whitePieces_[12] = new ChessPiece_Rook(this, static_cast<ChessPiece_Rook*>(board->whitePiece(12)));
	whitePieces_[13] = new ChessPiece_Rook(this, static_cast<ChessPiece_Rook*>(board->whitePiece(13)));
	
	whitePieces_[14] = new ChessPiece_Queen(this, static_cast<ChessPiece_Queen*>(board->whitePiece(14)));
	
	whitePieces_[15] = new ChessPiece_King(this, static_cast<ChessPiece_King*>(board->whitePiece(15)));
	
	//instantiate and allocate memory for black pieces
	blackPieces_[0] = new ChessPiece_Pawn(this, static_cast<ChessPiece_Pawn*>(board->blackPiece(0)));
	blackPieces_[1] = new ChessPiece_Pawn(this, static_cast<ChessPiece_Pawn*>(board->blackPiece(1)));
	blackPieces_[2] = new ChessPiece_Pawn(this, static_cast<ChessPiece_Pawn*>(board->blackPiece(2)));
	blackPieces_[3] = new ChessPiece_Pawn(this, static_cast<ChessPiece_Pawn*>(board->blackPiece(3)));
	blackPieces_[4] = new ChessPiece_Pawn(this, static_cast<ChessPiece_Pawn*>(board->blackPiece(4)));
	blackPieces_[5] = new ChessPiece_Pawn(this, static_cast<ChessPiece_Pawn*>(board->blackPiece(5)));
	blackPieces_[6] = new ChessPiece_Pawn(this, static_cast<ChessPiece_Pawn*>(board->blackPiece(6)));
	blackPieces_[7] = new ChessPiece_Pawn(this, static_cast<ChessPiece_Pawn*>(board->blackPiece(7)));
	
	blackPieces_[8] = new ChessPiece_Knight(this, static_cast<ChessPiece_Knight*>(board->blackPiece(8)));
	blackPieces_[9] = new ChessPiece_Knight(this, static_cast<ChessPiece_Knight*>(board->blackPiece(9)));
	
	blackPieces_[10] = new ChessPiece_Bishop(this, static_cast<ChessPiece_Bishop*>(board->blackPiece(10)));
	blackPieces_[11] = new ChessPiece_Bishop(this, static_cast<ChessPiece_Bishop*>(board->blackPiece(11)));
	
	blackPieces_[12] = new ChessPiece_Rook(this, static_cast<ChessPiece_Rook*>(board->blackPiece(12)));
	blackPieces_[13] = new ChessPiece_Rook(this, static_cast<ChessPiece_Rook*>(board->blackPiece(13)));
	
	blackPieces_[14] = new ChessPiece_Queen(this, static_cast<ChessPiece_Queen*>(board->blackPiece(14)));
	
	blackPieces_[15] = new ChessPiece_King(this, static_cast<ChessPiece_King*>(board->blackPiece(15)));
	
	//place the pieces on the board
	if(!whitePieces_[12]->captured())
		whitePieces_[12]->cmove(squares_[whitePieces_[12]->square()->index()]); //white left rook
	if(!whitePieces_[8]->captured())
		whitePieces_[8]->cmove(squares_[whitePieces_[8]->square()->index()]); //white left knight.
	if(!whitePieces_[10]->captured())
		whitePieces_[10]->cmove(squares_[whitePieces_[10]->square()->index()]); //white left bishop
	if(!whitePieces_[14]->captured())
		whitePieces_[14]->cmove(squares_[whitePieces_[14]->square()->index()]); //white queen
	if(!whitePieces_[15]->captured())
		whitePieces_[15]->cmove(squares_[whitePieces_[15]->square()->index()]); //white king
	if(!whitePieces_[11]->captured())
		whitePieces_[11]->cmove(squares_[whitePieces_[11]->square()->index()]); //white right bishop
	if(!whitePieces_[9]->captured())
		whitePieces_[9]->cmove(squares_[whitePieces_[9]->square()->index()]); //white right knight
	if(!whitePieces_[13]->captured())
		whitePieces_[13]->cmove(squares_[whitePieces_[13]->square()->index()]); //white right rook
	//white pawns
	if(!whitePieces_[0]->captured())
		whitePieces_[0]->cmove(squares_[whitePieces_[0]->square()->index()]);
	if(!whitePieces_[1]->captured())
		whitePieces_[1]->cmove(squares_[whitePieces_[1]->square()->index()]);
	if(!whitePieces_[2]->captured())
		whitePieces_[2]->cmove(squares_[whitePieces_[2]->square()->index()]);
	if(!whitePieces_[3]->captured())
		whitePieces_[3]->cmove(squares_[whitePieces_[3]->square()->index()]);
	if(!whitePieces_[4]->captured())
		whitePieces_[4]->cmove(squares_[whitePieces_[4]->square()->index()]);
	if(!whitePieces_[5]->captured())
		whitePieces_[5]->cmove(squares_[whitePieces_[5]->square()->index()]);
	if(!whitePieces_[6]->captured())
		whitePieces_[6]->cmove(squares_[whitePieces_[6]->square()->index()]);
	if(!whitePieces_[7]->captured())
		whitePieces_[7]->cmove(squares_[whitePieces_[7]->square()->index()]);

	//black pawns
	if(!blackPieces_[0]->captured())
		blackPieces_[0]->cmove(squares_[blackPieces_[0]->square()->index()]);
	if(!blackPieces_[1]->captured())
		blackPieces_[1]->cmove(squares_[blackPieces_[1]->square()->index()]);
	if(!blackPieces_[2]->captured())
		blackPieces_[2]->cmove(squares_[blackPieces_[2]->square()->index()]);
	if(!blackPieces_[3]->captured())
		blackPieces_[3]->cmove(squares_[blackPieces_[3]->square()->index()]);
	if(!blackPieces_[4]->captured())
		blackPieces_[4]->cmove(squares_[blackPieces_[4]->square()->index()]);
	if(!blackPieces_[5]->captured())
		blackPieces_[5]->cmove(squares_[blackPieces_[5]->square()->index()]);
	if(!blackPieces_[6]->captured())
		blackPieces_[6]->cmove(squares_[blackPieces_[6]->square()->index()]);
	if(!blackPieces_[7]->captured())
		blackPieces_[7]->cmove(squares_[blackPieces_[7]->square()->index()]);
	
	if(!blackPieces_[12]->captured())
		blackPieces_[12]->cmove(squares_[blackPieces_[12]->square()->index()]); //black left rook
	if(!blackPieces_[8]->captured())
		blackPieces_[8]->cmove(squares_[blackPieces_[8]->square()->index()]); //black left knight
	if(!blackPieces_[10]->captured())
		blackPieces_[10]->cmove(squares_[blackPieces_[10]->square()->index()]); //black left bishop
	if(!blackPieces_[14]->captured())
		blackPieces_[14]->cmove(squares_[blackPieces_[14]->square()->index()]); //black queen
	if(!blackPieces_[15]->captured())
		blackPieces_[15]->cmove(squares_[blackPieces_[15]->square()->index()]); //black king
	if(!blackPieces_[11]->captured())
		blackPieces_[11]->cmove(squares_[blackPieces_[11]->square()->index()]); //black right bishop
	if(!blackPieces_[9]->captured())
		blackPieces_[9]->cmove(squares_[blackPieces_[9]->square()->index()]); //black right knight
	if(!blackPieces_[13]->captured())
		blackPieces_[13]->cmove(squares_[blackPieces_[13]->square()->index()]); //black right rook
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
	}
	else
	{
		for(int i = 0; i < 8; ++i)
		{
			blackPieces_[i]->refresh();
		}
	}
	whitePieces_[15]->checkForCheck();
	blackPieces_[15]->checkForCheck();
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

bool ChessBoard::whiteCheckMate()
{
	if(!whiteToMove_ || whitePieces_[15]->inCheck())
		return false;
	for(int i = 0; i < 16; ++i)
	{
		if(!whitePieces_[i]->captured() && 
			whitePieces_[i]->legalMoves().size() > 0)
			return false;
	}
	
	return true;
}

bool ChessBoard::blackCheckMate()
{
	if(whiteToMove_ || !blackPieces_[15]->inCheck())
		return false;
	for(int i = 0; i < 16; ++i)
	{
		if(!blackPieces_[i]->captured() && 
			blackPieces_[i]->legalMoves().size() > 0)
			return false;
	}
	
	return true;
}

bool ChessBoard::staleMate()
{
	if(whiteToMove_ && !whitePieces_[15]->inCheck())
	{
		for(int i = 0; i < 16; ++i)
		{
			if(!blackPieces_[i]->captured() && 
				blackPieces_[i]->legalMoves().size() > 0)
			return false;
		}
		return true;
	}
	else if(!whiteToMove_ && !blackPieces_[15]->inCheck())
	{
		for(int i = 0; i < 16; ++i)
		{
			if(!blackPieces_[i]->captured() && 
				blackPieces_[i]->legalMoves().size() > 0)
			return false;
		}
		return true;
	}
	return false;
}

int ChessBoard::whiteScore()
{
	int score = 0;
	for(int i = 0; i < 15; ++i)
	{
		if(blackPieces_[i]->captured())
			score += blackPieces_[i]->value();
	}
	return score;
}

int ChessBoard::whiteRemaining()
{
	int score = 0;
	for(int i = 0; i < 15; ++i)
	{
		if(!whitePieces_[i]->captured())
			score += whitePieces_[i]->value();
	}
	return score;
}

int ChessBoard::blackScore()
{
	int score = 0;
	for(int i = 0; i < 15; ++i)
	{
		if(whitePieces_[i]->captured())
			score += whitePieces_[i]->value();
	}
	return score;
}

int ChessBoard::blackRemaining()
{
	int score = 0;
	for(int i = 0; i < 15; ++i)
	{
		if(!blackPieces_[i]->captured())
			score += blackPieces_[i]->value();
	}
	return score;
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
