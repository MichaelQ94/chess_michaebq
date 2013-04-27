#include "chesspiece.h"
using namespace std;

ChessPiece_Pawn::ChessPiece_Pawn(ChessBoard *board, char color) : ChessPiece(board, 'P', color, 1)
{
	promoted_piece = NULL;
	hasMoved_ = false;
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
			if(index % 8 != 7 && (board_->square(index)->getPiece() != NULL && 
				board_->square(index)->getPiece()->color() == 'B')) //can capture a black piece
			{
				legalMoves.push_back(index);
			}
			
			index = square_->index() + 9;
			if(index % 8 != 0 && (board_->square(index)->getPiece() != NULL && 
				board_->square(index)->getPiece()->color() == 'B')) //can capture a black piece
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
			if(index % 8 != 7 && (board_->square(index)->getPiece() != NULL && 
				board_->square(index)->getPiece()->color() == 'W')) //can capture a white piece
			{
				legalMoves.push_back(index);
			}
			
			index = square_->index() - 7;
			if(index % 8 != 0 && (board_->square(index)->getPiece() != NULL && 
				board_->square(index)->getPiece()->color() == 'W')) //can capture a white piece
			{
				legalMoves.push_back(index);
			}
			
		}
	}
	else //pawn has been promoted
	{
		//implement later
	}
	
	return legalMoves;
}

ChessPiece_Pawn::~ChessPiece_Pawn()
{
	if(promoted_piece != NULL)
		delete promoted_piece;
}
