#include "chesspiece.h"
using namespace std;

/**Constructor. Sets the proper values in the ChessPiece class ('R' for rook, 5 for score value).
 * Links this piece to its parent board.
 * Sets hasMoved_ to false initially.
 * @param *board The parent board to which this piece belongs
 * @param color Character representing the color of the piece (W for white, B for black)
 */
ChessPiece_Rook::ChessPiece_Rook(ChessBoard *board, char color) : ChessPiece(board, 'R', color, 5)
{
	hasMoved_ = false;
}

/**'Copy' constructor. Copies the provided piece's information but links this piece to a different board.
 * @param *board The parent board to which this piece belongs
 * @param *piece The piece whose information is to be copied
 */
ChessPiece_Rook::ChessPiece_Rook(ChessBoard *board, ChessPiece_Rook *piece) : ChessPiece(board, piece)
{
	hasMoved_ = piece->hasMoved_;
}

/**Returns a list of the squares to which the rook is allowed to move. Checks the current row and current column of the
 * and makes sure a move does not put the owner's king in check before adding it to the list.
 * @return The list of the indices of the squares to which the rook is allowed to move
 */
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

/**Moves the rook to the provided square and clears the current square.
 * @param *dest The square to which the rook is to be moved
 */
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

/**Moves the rook to the provided square but does nothing to the current square.
 * To be used with the board class's copy constructor.
 * @param *dest The square to which the rook is to be moved
 */
void ChessPiece_Rook::cmove(ChessBoardSquare *dest)
{
	if(dest->getPiece() != NULL)
		dest->getPiece()->isCaptured();
	square_ = dest;
	dest->setPiece(this);
}

/**Returns the hasMoved_ boolean of the rook
 * @return Returns true if the rook has been moved, false if not
 */
bool ChessPiece_Rook::hasMoved()
{
	return hasMoved_;
}

/**Sets the hasMoved_ boolean to false. To be used after the rook has been placed on the board using move().
 */
void ChessPiece_Rook::reset()
{
	hasMoved_ = false;
}
