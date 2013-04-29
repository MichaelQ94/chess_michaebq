#include "chesspiece.h"
using namespace std;

ChessPiece_Bishop::ChessPiece_Bishop(ChessBoard *board, char color) : ChessPiece(board, 'B', color, 3)
{
}

ChessPiece_Bishop::ChessPiece_Bishop(ChessBoard *board, ChessPiece_Bishop *piece) : ChessPiece(board, piece)
{
}

vector<int> ChessPiece_Bishop::legalMoves()
{
	vector<int> legalMoves;
	ChessMove *move;
	
	//scan the diagonal to the upper right
	int index = square_->index() + 9;
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
		index += 9;
	}
	
	//scan the diagonal to the lower left
	index = square_->index() - 9;
	while(index >= 0 && index % 8 != 7)
	{
		if(board_->square(index)->getPiece() != NULL && 
			board_->square(index)->getPiece()->color() == piece_color) //friendly piece
			break;
			
		move = new ChessMove(board_, square_->index(), index);
		if(move->isLegal(piece_color))
			legalMoves.push_back(index);
		delete move;
		
		if(board_->square(index)->getPiece() != NULL) //this square contains a piece
			break;
		index -= 9;
	}
	
	//scan the diagonal to the upper left
	index = square_->index() + 7;
	while(index < 64 && index % 8 != 7)
	{
		if(board_->square(index)->getPiece() != NULL && 
			board_->square(index)->getPiece()->color() == piece_color) //friendly piece
			break;
			
		move = new ChessMove(board_, square_->index(), index);
		if(move->isLegal(piece_color))
			legalMoves.push_back(index);
		delete move;
		
		if(board_->square(index)->getPiece() != NULL) //this square contains a piece
			break;
		index += 7;
	}
	
	//scan the diagonal to the lower right
	index = square_->index() - 7;
	while(index >= 0 && index % 8 != 0)
	{
		if(board_->square(index)->getPiece() != NULL && 
			board_->square(index)->getPiece()->color() == piece_color) //friendly piece
			break;
			
		move = new ChessMove(board_, square_->index(), index);
		if(move->isLegal(piece_color))
			legalMoves.push_back(index);
		delete move;
		
		if(board_->square(index)->getPiece() != NULL) //this square contains a piece
			break;
		index -= 7;
	}
	
	return legalMoves;
}
