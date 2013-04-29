#include "chesspiece.h"
using namespace std;

ChessPiece_Pawn::ChessPiece_Pawn(ChessBoard *board, char color) : ChessPiece(board, 'P', color, 1)
{
	promoted_piece = NULL;
	hasMoved_ = false;
	enPassant_ = false;
}

ChessPiece_Pawn::ChessPiece_Pawn(ChessBoard *board, ChessPiece_Pawn *piece) : ChessPiece(board, piece)
{
	hasMoved_ = piece->hasMoved_;
	enPassant_ = piece->enPassant_;
	promoted_piece = NULL;
	if(piece->promoted_piece != NULL)
	{
		switch(piece_type)
		{
		case 'N':
			promoted_piece = new ChessPiece_Knight(board_, piece_color);
			break;
		case 'B':
			promoted_piece = new ChessPiece_Bishop(board_, piece_color);
			break;
		case 'R':
			promoted_piece = new ChessPiece_Rook(board_, piece_color);
			break;
		case 'Q':
			promoted_piece = new ChessPiece_Queen(board_, piece_color);
		}
		
		promoted_piece->copyData(this);
	}
}

vector<int> ChessPiece_Pawn::legalMoves()
{
	vector<int> legalMoves;
	ChessMove *move;
	if(promoted_piece == NULL) //regular pawn
	{
		int index;
		if(piece_color == 'W')//white
		{
			index = square_->index() + 8;
			if(board_->square(index)->getPiece() == NULL)
			{
				move = new ChessMove(board_, square_->index(), index);
				if(move->isLegal(piece_color))
					legalMoves.push_back(index);
				delete move;
				
				index += 8;
				if(!hasMoved_ && board_->square(index)->getPiece() == NULL)
				{
					move = new ChessMove(board_, square_->index(), index);
					if(move->isLegal(piece_color))
						legalMoves.push_back(index);
					delete move;
				}
			}
			
			index = square_->index() + 7;	
			if(index % 8 != 7 && ((board_->square(index)->getPiece() != NULL && 
				board_->square(index)->getPiece()->color() == 'B') || //can capture a black piece
				(board_->square(index-8)->getPiece() != NULL &&
				board_->square(index-8)->getPiece()->color() == 'B' &&
				board_->square(index-8)->getPiece()->enPassant()))) //can capture via en passant
			{
				move = new ChessMove(board_, square_->index(), index);
				if(move->isLegal(piece_color))
					legalMoves.push_back(index);
				delete move;
			}
			
			index = square_->index() + 9;
			if(index % 8 != 0 && ((board_->square(index)->getPiece() != NULL && 
				board_->square(index)->getPiece()->color() == 'B') || //can capture a black piece
				(board_->square(index-8)->getPiece() != NULL &&
				board_->square(index-8)->getPiece()->color() == 'B' &&
				board_->square(index-8)->getPiece()->enPassant()))) //can capture via en passant
			{
				move = new ChessMove(board_, square_->index(), index);
				if(move->isLegal(piece_color))
					legalMoves.push_back(index);
				delete move;
			}
			
		}
		else //black
		{
			index = square_->index() - 8;
			if(board_->square(index)->getPiece() == NULL)
			{
				move = new ChessMove(board_, square_->index(), index);
				if(move->isLegal(piece_color))
					legalMoves.push_back(index);
				delete move;
				index -= 8;
				if(!hasMoved_ && board_->square(index)->getPiece() == NULL)
				{
					move = new ChessMove(board_, square_->index(), index);
					if(move->isLegal(piece_color))
						legalMoves.push_back(index);
					delete move;
				}
			}
			
			index = square_->index() - 9;
			if(index % 8 != 7 && ((board_->square(index)->getPiece() != NULL && 
				board_->square(index)->getPiece()->color() == 'W') || //can capture a white piece
				(board_->square(index+8)->getPiece() != NULL &&
				board_->square(index+8)->getPiece()->color() == 'W' &&
				board_->square(index+8)->getPiece()->enPassant()))) //can capture via en passant
			{
				move = new ChessMove(board_, square_->index(), index);
				if(move->isLegal(piece_color))
					legalMoves.push_back(index);
				delete move;
			}
			
			index = square_->index() - 7;
			if(index % 8 != 0 && ((board_->square(index)->getPiece() != NULL && 
				board_->square(index)->getPiece()->color() == 'W') || //can capture a white piece
				(board_->square(index+8)->getPiece() != NULL &&
				board_->square(index+8)->getPiece()->color() == 'W' &&
				board_->square(index+8)->getPiece()->enPassant()))) //can capture via en passant
			{
				move = new ChessMove(board_, square_->index(), index);
				if(move->isLegal(piece_color))
					legalMoves.push_back(index);
				delete move;
			}
			
		}
			
	}
	else //pawn has been promoted
	{
		return promoted_piece->legalMoves();
	}
	
	return legalMoves;
}

void ChessPiece_Pawn::refresh()
{
	enPassant_ = false;
}

bool ChessPiece_Pawn::hasMoved()
{
	return hasMoved_;
}

void ChessPiece_Pawn::reset()
{
	hasMoved_ = false;
}

bool ChessPiece_Pawn::enPassant()
{
	return enPassant_;
}

void ChessPiece_Pawn::move(ChessBoardSquare *dest)
{
	if(square_ != NULL)
	{
		square_->clear();
		if(!hasMoved_ && ((piece_color == 'W' && dest->index() == square_->index() + 16) ||
		(piece_color == 'B' && dest->index() == square_->index() - 16)))
		{
			enPassant_ = true;
		}
	}
	if(dest->getPiece() != NULL)
		dest->getPiece()->isCaptured();
	//en passant captures
	else if(promoted_piece == NULL && piece_color == 'W' && 
		board_->square(dest->index() - 8)->getPiece() != NULL &&
		board_->square(dest->index() - 8)->getPiece()->enPassant())
	{
		board_->square(dest->index() - 8)->getPiece()->isCaptured();
	}
	else if(promoted_piece == NULL && piece_color == 'B' && 
		board_->square(dest->index() + 8)->getPiece() != NULL &&
		board_->square(dest->index() + 8)->getPiece()->enPassant())
	{
		board_->square(dest->index() + 8)->getPiece()->isCaptured();
	}
	square_ = dest;
	dest->setPiece(this);
	hasMoved_ = true;
	if(promoted_piece != NULL)
	{
		promoted_piece->copyData(this);
	}
}

void ChessPiece_Pawn::cmove(ChessBoardSquare *dest)
{
	if(dest->getPiece() != NULL)
		dest->getPiece()->isCaptured();
	//en passant captures
	else if(promoted_piece == NULL && piece_color == 'W' && 
		board_->square(dest->index() - 8)->getPiece() != NULL &&
		board_->square(dest->index() - 8)->getPiece()->enPassant())
	{
		board_->square(dest->index() - 8)->getPiece()->isCaptured();
	}
	else if(promoted_piece == NULL && piece_color == 'B' && 
		board_->square(dest->index() + 8)->getPiece() != NULL &&
		board_->square(dest->index() + 8)->getPiece()->enPassant())
	{
		board_->square(dest->index() + 8)->getPiece()->isCaptured();
	}
	square_ = dest;
	dest->setPiece(this);
	if(promoted_piece != NULL)
	{
		promoted_piece->copyData(this);
	}
}

void ChessPiece_Pawn::promote(char type)
{
	switch(type)
	{
		case 'N':
			promoted_piece = new ChessPiece_Knight(board_, piece_color);
			piece_type = 'N';
			value_ = 3;
			break;
		case 'B':
			promoted_piece = new ChessPiece_Bishop(board_, piece_color);
			piece_type = 'B';
			value_ = 3;
			break;
		case 'R':
			promoted_piece = new ChessPiece_Rook(board_, piece_color);
			piece_type = 'R';
			value_ = 5;
			break;
		case 'Q':
			promoted_piece = new ChessPiece_Queen(board_, piece_color);
			piece_type = 'Q';
			value_ = 9;
	}
	
	promoted_piece->copyData(this);
}

ChessPiece_Pawn::~ChessPiece_Pawn()
{
	if(promoted_piece != NULL)
		delete promoted_piece;
}
