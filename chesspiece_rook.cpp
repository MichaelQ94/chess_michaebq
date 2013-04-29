#include "chesspiece.h"
using namespace std;

ChessPiece_Rook::ChessPiece_Rook(ChessBoard *board, char color) : ChessPiece(board, 'R', color, 5)
{
	hasMoved_ = false;
}

ChessPiece_Rook::ChessPiece_Rook(ChessBoard *board, ChessPiece_Rook *piece) : ChessPiece(board, piece)
{
	hasMoved_ = piece->hasMoved_;
}

vector<int> ChessPiece_Rook::legalMoves()
{
	vector<int> legalMoves;
	ChessMove *move;
	
	//right
	int index = square_->index() + 1;
	while(index < 64 && index % 8 != 0)
	{
		if(board_->square(index)->getPiece() != NULL && 
			board_->square(index)->getPiece()->color() == piece_color) //friendly piece
			break;
		
		move = new ChessMove(board_, square_->index(), index);
		if(move->isLegal(piece_color))
			legalMoves.push_back(index);
		delete move;
		
		if(board_->square(index)->getPiece() != NULL) //this square contains an enemy piece
			break;
		++index;
	}
	
	//left
	index = square_->index() - 1;
	while(index >= 0 && index % 8 != 7)
	{
		if(board_->square(index)->getPiece() != NULL && 
			board_->square(index)->getPiece()->color() == piece_color) //friendly piece
			break;
		
		move = new ChessMove(board_, square_->index(), index);
		if(move->isLegal(piece_color))
			legalMoves.push_back(index);
		delete move;
		
		if(board_->square(index)->getPiece() != NULL) //this square contains an enemy piece
			break;
		--index;
	}
	
	//up
	index = square_->index() + 8;
	while(index < 64)
	{
		if(board_->square(index)->getPiece() != NULL && 
			board_->square(index)->getPiece()->color() == piece_color) //friendly piece
			break;
		
		move = new ChessMove(board_, square_->index(), index);
		if(move->isLegal(piece_color))
			legalMoves.push_back(index);
		delete move;
		
		if(board_->square(index)->getPiece() != NULL) //this square contains an enemy piece
			break;
		index += 8;
	}
	
	//down
	index = square_->index() - 8;
	while(index >= 0)
	{
		if(board_->square(index)->getPiece() != NULL && 
			board_->square(index)->getPiece()->color() == piece_color) //friendly piece
			break;
		
		move = new ChessMove(board_, square_->index(), index);
		if(move->isLegal(piece_color))
			legalMoves.push_back(index);
		delete move;
		
		if(board_->square(index)->getPiece() != NULL) //this square contains an enemy piece
			break;
		index -= 8;
	}
	
	return legalMoves;
}

void ChessPiece_Rook::move(ChessBoardSquare *dest)
{
	if(square_ != NULL)
		square_->clear();
	if(dest->getPiece() != NULL)
		dest->getPiece()->isCaptured();
	square_ = dest;
	dest->setPiece(this);
	hasMoved_ = true;
}

void ChessPiece_Rook::cmove(ChessBoardSquare *dest)
{
	if(dest->getPiece() != NULL)
		dest->getPiece()->isCaptured();
	square_ = dest;
	dest->setPiece(this);
}

bool ChessPiece_Rook::hasMoved()
{
	return hasMoved_;
}

void ChessPiece_Rook::reset()
{
	hasMoved_ = false;
}
