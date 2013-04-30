#include "chesspiece.h"
using namespace std;

/**Constructor. Sets the proper values in the ChessPiece class ('B' for bishop, 3 for score value).
 * Links this piece to its parent board.
 * @param *board The parent board to which this piece belongs
 * @param color Character representing the color of the piece (W for white, B for black)
 */
ChessPiece_Bishop::ChessPiece_Bishop(ChessBoard *board, char color) : ChessPiece(board, 'B', color, 3)
{
}

/**'Copy' constructor. Copies the provided piece's information but links this piece to a different board.
 * @param *board The parent board to which this piece belongs
 * @param *piece The piece whose information is to be copied
 */
ChessPiece_Bishop::ChessPiece_Bishop(ChessBoard *board, ChessPiece_Bishop *piece) : ChessPiece(board, piece)
{
}

/**Returns a vector of the indices of the squares to which this piece is allowed to move.
 * Scans along all diagonals until another piece is reached. Checks to make sure moves do not end up putting the
 * owner in check before pushing them to the vector.
 * @return A list of the indices of the squares to which this piece is allowed to move
 */
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
