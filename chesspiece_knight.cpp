#include "chesspiece.h"
using namespace std;

ChessPiece_Knight::ChessPiece_Knight(ChessBoard *board, char color) : ChessPiece(board, 'N', color, 3)
{
}

ChessPiece_Knight::ChessPiece_Knight(ChessBoard *board, ChessPiece_Knight *piece) : ChessPiece(board, piece)
{
}
vector<int> ChessPiece_Knight::legalMoves()
{
	vector<int> legalMoves;
	ChessMove *move;
	
	int index = square_->index() + 17;
	if(index < 64 && index % 8 != 0 && 
		!(board_->square(index)->getPiece() != NULL && 
		board_->square(index)->getPiece()->color() == piece_color))
	{
		move = new ChessMove(board_, square_->index(), index);
		if(move->isLegal(piece_color))
			legalMoves.push_back(index);
		delete move;
	}
	
	index = square_->index() + 10;
	if(index < 64 && index % 8 > 1 && 
		!(board_->square(index)->getPiece() != NULL && 
		board_->square(index)->getPiece()->color() == piece_color))
	{
		move = new ChessMove(board_, square_->index(), index);
		if(move->isLegal(piece_color))
			legalMoves.push_back(index);
		delete move;
	}
	
	index = square_->index() - 6;
	if(index >= 0 && index % 8 > 1 && 
		!(board_->square(index)->getPiece() != NULL && 
		board_->square(index)->getPiece()->color() == piece_color))
	{
		move = new ChessMove(board_, square_->index(), index);
		if(move->isLegal(piece_color))
			legalMoves.push_back(index);
		delete move;
	}
	
	index = square_->index() - 15;
	if(index >= 0 && index % 8 != 0 && 
		!(board_->square(index)->getPiece() != NULL && 
		board_->square(index)->getPiece()->color() == piece_color))
	{
		move = new ChessMove(board_, square_->index(), index);
		if(move->isLegal(piece_color))
			legalMoves.push_back(index);
		delete move;
	}
	
	index = square_->index() - 17;
	if(index >= 0 && index % 8 != 7 && 
		!(board_->square(index)->getPiece() != NULL && 
		board_->square(index)->getPiece()->color() == piece_color))
	{
		move = new ChessMove(board_, square_->index(), index);
		if(move->isLegal(piece_color))
			legalMoves.push_back(index);
		delete move;
	}
	
	index = square_->index() - 10;
	if(index >= 0 && index % 8 < 6 && 
		!(board_->square(index)->getPiece() != NULL && 
		board_->square(index)->getPiece()->color() == piece_color))
	{
		move = new ChessMove(board_, square_->index(), index);
		if(move->isLegal(piece_color))
			legalMoves.push_back(index);
		delete move;
	}
	
	index = square_->index() + 6;
	if(index < 64 && index % 8 < 6 && 
		!(board_->square(index)->getPiece() != NULL && 
		board_->square(index)->getPiece()->color() == piece_color))
	{
		move = new ChessMove(board_, square_->index(), index);
		if(move->isLegal(piece_color))
			legalMoves.push_back(index);
		delete move;
	}
	
	index = square_->index() + 15;
	if(index < 64 && index % 8 != 7 && 
		!(board_->square(index)->getPiece() != NULL && 
		board_->square(index)->getPiece()->color() == piece_color))
	{
		move = new ChessMove(board_, square_->index(), index);
		if(move->isLegal(piece_color))
			legalMoves.push_back(index);
		delete move;
	}
	
	return legalMoves;
}
