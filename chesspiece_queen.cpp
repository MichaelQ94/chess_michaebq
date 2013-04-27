#include "chesspiece.h"
using namespace std;

ChessPiece_Queen::ChessPiece_Queen(ChessBoard *board, char color) : ChessPiece(board, 'Q', color, 9)
{	
}

vector<int> ChessPiece_Queen::legalMoves()
{
	vector<int> legalMoves;
	
	//scan the diagonal to the upper right
	int index = square_->index() + 9;
	while(index < 64 && index % 8 != 0)
	{
		if(board_->square(index)->getPiece() != NULL && 
			board_->square(index)->getPiece()->color() == piece_color) //friendly piece
			break;
		legalMoves.push_back(index);
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
		legalMoves.push_back(index);
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
		legalMoves.push_back(index);
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
		legalMoves.push_back(index);
		if(board_->square(index)->getPiece() != NULL) //this square contains a piece
			break;
		index -= 7;
	}
	
	//right
	index = square_->index() + 1;
	while(index < 64 && index % 8 != 0)
	{
		if(board_->square(index)->getPiece() != NULL && 
			board_->square(index)->getPiece()->color() == piece_color) //friendly piece
			break;
		legalMoves.push_back(index);
		if(board_->square(index)->getPiece() != NULL) //this square contains an enemy piece
			break;
		++index;
	}
	
	//left
	index = square_->index() - 1;
	while(index >= 0 && index % 8 != 0)
	{
		if(board_->square(index)->getPiece() != NULL && 
			board_->square(index)->getPiece()->color() == piece_color) //friendly piece
			break;
		legalMoves.push_back(index);
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
		legalMoves.push_back(index);
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
		legalMoves.push_back(index);
		if(board_->square(index)->getPiece() != NULL) //this square contains an enemy piece
			break;
		index -= 8;
	}
	
	return legalMoves;
}
