#include "chesspiece.h"
using namespace std;

ChessPiece_Pawn::ChessPiece_Pawn(ChessBoard *board, char color) : ChessPiece(board, 'P', color, 1)
{
	promoted_piece = NULL;
}

vector<int> ChessPiece_Pawn::legalMoves()
{
	vector<int> legalMoves;
	if(promoted_piece == NULL) //regular pawn
	{
		int index;
	
		if(piece_color == 'W')//white
		{
			index = square_->index() + 8;
			if(board_->square(index)->getPiece() == NULL)
			{
				legalMoves.push_back(index);
				
				index += 8;
				if(!hasMoved_ && board_->square(index)->getPiece() == NULL)
				{
					legalMoves.push_back(index);
				}
			}
			
			index = square_->index() + 7;	
			if(index % 8 != 7 && ((board_->square(index)->getPiece() != NULL && 
				board_->square(index)->getPiece()->color() == 'B') || //can capture a black piece
				(board_->square(index-8)->getPiece() != NULL &&
				board_->square(index-8)->getPiece()->color() == 'B' &&
				board_->square(index-8)->getPiece()->enPassant()))) //can capture via en passant
			{
				legalMoves.push_back(index);
			}
			
			index = square_->index() + 9;
			if(index % 8 != 0 && ((board_->square(index)->getPiece() != NULL && 
				board_->square(index)->getPiece()->color() == 'B') || //can capture a black piece
				(board_->square(index-8)->getPiece() != NULL &&
				board_->square(index-8)->getPiece()->color() == 'B' &&
				board_->square(index-8)->getPiece()->enPassant()))) //can capture via en passant
			{
				legalMoves.push_back(index);
			}
			
		}
		else //black
		{
			index = square_->index() - 8;
			if(board_->square(index)->getPiece() == NULL)
			{
				legalMoves.push_back(index);
				
				index -= 8;
				if(!hasMoved_ && board_->square(index)->getPiece() == NULL)
				{
					legalMoves.push_back(index);
				}
			}
			
			index = square_->index() - 9;
			if(index % 8 != 7 && ((board_->square(index)->getPiece() != NULL && 
				board_->square(index)->getPiece()->color() == 'W') || //can capture a white piece
				(board_->square(index+8)->getPiece() != NULL &&
				board_->square(index+8)->getPiece()->color() == 'W' &&
				board_->square(index+8)->getPiece()->enPassant()))) //can capture via en passant
			{
				legalMoves.push_back(index);
			}
			
			index = square_->index() - 7;
			if(index % 8 != 0 && ((board_->square(index)->getPiece() != NULL && 
				board_->square(index)->getPiece()->color() == 'W') || //can capture a white piece
				(board_->square(index+8)->getPiece() != NULL &&
				board_->square(index+8)->getPiece()->color() == 'W' &&
				board_->square(index+8)->getPiece()->enPassant()))) //can capture via en passant
			{
				legalMoves.push_back(index);
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

void ChessPiece_Pawn::move(ChessBoardSquare *dest)
{
	if(square_ != NULL)
		square_->clear();
	if(dest->getPiece() != NULL)
		dest->getPiece()->isCaptured();
	else if(piece_color == 'W' && 
		board_->square(dest->index() - 8)->getPiece() != NULL &&
		board_->square(dest->index() - 8)->getPiece()->enPassant())
	{
		board_->square(dest->index() - 8)->getPiece()->isCaptured();
	}
	else if(piece_color == 'B' && 
		board_->square(dest->index() + 8)->getPiece() != NULL &&
		board_->square(dest->index() + 8)->getPiece()->enPassant())
	{
		board_->square(dest->index() + 8)->getPiece()->isCaptured();
	}
	square_ = dest;
	dest->setPiece(this);
	if(!hasMoved_)
		enPassant_ = true;
	hasMoved_ = true;
}

ChessPiece_Pawn::~ChessPiece_Pawn()
{
	if(promoted_piece != NULL)
		delete promoted_piece;
}
