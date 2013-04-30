#include "chesspiece.h"
using namespace std;

/**Constructor. Sets the proper values in the ChessPiece class ('Q' for queen, 9 for score value).
 * Links this piece to its parent board.
 * @param *board The parent board to which this piece belongs
 * @param color Character representing the color of the piece (W for white, B for black)
 */
ChessPiece_Queen::ChessPiece_Queen(ChessBoard *board, char color) : ChessPiece(board, 'Q', color, 9)
{	
}

/**'Copy' constructor. Copies the provided piece's information but links this piece to a different board.
 * @param *board The parent board to which this piece belongs
 * @param *piece The piece whose information is to be copied
 */
ChessPiece_Queen::ChessPiece_Queen(ChessBoard *board, ChessPiece_Queen *piece) : ChessPiece(board, piece)
{
}

/**Returns a list of the square to which the queen is allowed to move. Checks the diagonals as well as the current row
 * and current column of the queen and makes sure a move does not put the owner's queen in check before adding the move
 * to the list.
 * @return The list of the indices of the squares to which the queen is allowed to move
 */
vector<int> ChessPiece_Queen::legalMoves()
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
	
	//right
	index = square_->index() + 1;
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
