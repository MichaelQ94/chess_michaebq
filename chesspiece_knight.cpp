#include "chesspiece.h"
using namespace std;

/**Constructor. Sets the proper values in the ChessPiece class ('N' for knight, 3 for score value).
 * Links this piece to its parent board.
 * @param *board The parent board to which this piece belongs
 * @param color Character representing the color of the piece (W for white, B for black)
 */
ChessPiece_Knight::ChessPiece_Knight(ChessBoard *board, char color) : ChessPiece(board, 'N', color, 3)
{
}

/**'Copy' constructor. Copies the provided piece's information but links this piece to a different board.
 * @param *board The parent board to which this piece belongs
 * @param *piece The piece whose information is to be copied
 */
ChessPiece_Knight::ChessPiece_Knight(ChessBoard *board, ChessPiece_Knight *piece) : ChessPiece(board, piece)
{
}

/**Checks all of the squares to which the knight is able to move. If the square does not contain a friendly piece,
 * adds the piece to a list of allowed moves. Also checks to make sure this does not result in the owner's king being
 * put in check.
 * @return The list of the indices of the squares to which this piece is allowed to move
 */
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
