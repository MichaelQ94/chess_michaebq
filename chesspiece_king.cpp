#include "chesspiece.h"
using namespace std;

/**Constructor. Sets the proper values in the ChessPiece class ('K' for king, -1 for score value because the king
 * will never be captured).
 * Links this piece to its parent board.
 * Sets inCheck_ and hasMoved_ to false initially.
 * @param *board The parent board to which this piece belongs
 * @param color Character representing the color of the piece (W for white, B for black)
 */
ChessPiece_King::ChessPiece_King(ChessBoard *board, char color) : ChessPiece(board, 'K', color, -1)
{
	inCheck_ = false;
	hasMoved_ = false;
}

/**'Copy' constructor. Copies the provided piece's information but links this piece to a different board.
 * @param *board The parent board to which this piece belongs
 * @param *piece The piece whose information is to be copied
 */
ChessPiece_King::ChessPiece_King(ChessBoard *board, ChessPiece_King *piece) : ChessPiece(board, piece)
{
	inCheck_ = piece->inCheck_;
	hasMoved_ = piece->hasMoved_;
}

/**Returns a vector of the indices of the squares to which this piece is allowed to move.
 * Scans each adjacent to see if it is either empty or contains an enemy piece. Also checks to make sure the king is
 * not moving into check before pushing a move to the vector.
 * If the king has not moved, checks to see if castling is possible by checking the two rooks and the squares in between.
 * @return A list of the indices of the squares to which this piece is allowed to move.
 */
vector<int> ChessPiece_King::legalMoves()
{
	vector<int> legalMoves;
	ChessMove *move;
	
	//upper left
	int index = square_->index() + 7;
	if(index < 64 && index % 8 != 7 && 
		!(board_->square(index)->getPiece() != NULL && 
		board_->square(index)->getPiece()->color() == piece_color))
	{
		move = new ChessMove(board_, square_->index(), index);
		if(move->isLegal(piece_color))
			legalMoves.push_back(index);
		delete move;
	}
	
	//left
	index = square_->index() - 1;
	if(index >= 0 && index % 8 != 7 && 
		!(board_->square(index)->getPiece() != NULL && 
		board_->square(index)->getPiece()->color() == piece_color))
	{
		move = new ChessMove(board_, square_->index(), index);
		if(move->isLegal(piece_color))
			legalMoves.push_back(index);
		delete move;
	}
	
	//lower left
	index = square_->index() - 9;
	if(index >= 0 && index % 8 != 7 && 
		!(board_->square(index)->getPiece() != NULL && 
		board_->square(index)->getPiece()->color() == piece_color))
	{
		move = new ChessMove(board_, square_->index(), index);
		if(move->isLegal(piece_color))
			legalMoves.push_back(index);
		delete move;
	}
	
	//beneath
	index = square_->index() - 8;
	if(index >= 0 && 
		!(board_->square(index)->getPiece() != NULL && 
		board_->square(index)->getPiece()->color() == piece_color))
	{
		move = new ChessMove(board_, square_->index(), index);
		if(move->isLegal(piece_color))
			legalMoves.push_back(index);
		delete move;
	}
	
	//lower right
	index = square_->index() - 7;
	if(index >= 0 && index % 8 != 0 && 
		!(board_->square(index)->getPiece() != NULL && 
		board_->square(index)->getPiece()->color() == piece_color))
	{
		move = new ChessMove(board_, square_->index(), index);
		if(move->isLegal(piece_color))
			legalMoves.push_back(index);
		delete move;
	}
	
	//right
	index = square_->index() + 1;
	if(index < 64 && index % 8 != 0 && 
		!(board_->square(index)->getPiece() != NULL && 
		board_->square(index)->getPiece()->color() == piece_color))
	{
		move = new ChessMove(board_, square_->index(), index);
		if(move->isLegal(piece_color))
			legalMoves.push_back(index);
		delete move;
	}
	
	//upper right
	index = square_->index() + 9;
	if(index < 64 && index % 8 != 0 && 
		!(board_->square(index)->getPiece() != NULL && 
		board_->square(index)->getPiece()->color() == piece_color))
	{
		move = new ChessMove(board_, square_->index(), index);
		if(move->isLegal(piece_color))
			legalMoves.push_back(index);
		delete move;
	}
	
	//above
	index = square_->index() + 8;
	if(index < 64 && 
		!(board_->square(index)->getPiece() != NULL && 
		board_->square(index)->getPiece()->color() == piece_color))
	{
		move = new ChessMove(board_, square_->index(), index);
		if(move->isLegal(piece_color))
			legalMoves.push_back(index);
		delete move;
	}
	
	//two to the right (castling only)
	index = square_->index() + 2;
	if(!inCheck_ && !hasMoved_ && board_->square(index-1)->getPiece() == NULL &&
		board_->square(index)->getPiece() == NULL &&
		board_->square(index+1)->getPiece() != NULL &&
		!board_->square(index+1)->getPiece()->hasMoved())
	{
		move = new ChessMove(board_, square_->index(), index-1);
		if(move->isLegal(piece_color)) //must make sure the king is not castling through check
		{
			delete move;
			move = new ChessMove(board_, square_->index(), index);
			if(move->isLegal(piece_color))
				legalMoves.push_back(index);
		}
		delete move;
	}
	
	//two to the left (castling only)
	index = square_->index() - 2;
	if(!inCheck_ && !hasMoved_ && board_->square(index+1)->getPiece() == NULL &&
		board_->square(index)->getPiece() == NULL &&
		board_->square(index-1)->getPiece() == NULL &&
		board_->square(index-2)->getPiece() != NULL &&
		!board_->square(index-2)->getPiece()->hasMoved())
	{
		move = new ChessMove(board_, square_->index(), index+1);
		if(move->isLegal(piece_color)) //must make sure the king is not castling through check
		{
			delete move;
			move = new ChessMove(board_, square_->index(), index);
			if(move->isLegal(piece_color))
				legalMoves.push_back(index);
		}
		delete move;
	}
	
	return legalMoves;
}

/**Returns the inCheck_ condition of the king.
 * @return Returns true if the king is in check, false if not
 */
bool ChessPiece_King::inCheck()
{
	return inCheck_;
}

/**Resets the hasMoved_ condition of the king to false. This is to be used after the king has been placed on the board
 * using the move() function.
 */
void ChessPiece_King::reset()
{
	hasMoved_ = false;
}

/**Scans all squares on which a piece attacking the king could be placed to see if there is an enemy piece.
 * Returns true if it finds even one piece which is attacking the king and sets inCheck_ to true.
 * @return Returns true if the king is in check, false if not
 */
bool ChessPiece_King::checkForCheck()
{
	//scan the diagonal to the upper right
	int index = square_->index() + 9;
	if(piece_color == 'W' && board_->square(index)->getPiece() != NULL &&
		board_->square(index)->getPiece()->color() != piece_color &&
		board_->square(index)->getPiece()->type() == 'P') //this square contains an enemy pawn
	{
		inCheck_ = true;
		return true;
	}
	while(index < 64 && index % 8 != 0)
	{
		if(board_->square(index)->getPiece() != NULL && 
			board_->square(index)->getPiece()->color() == piece_color) //friendly piece
			break;
		if(board_->square(index)->getPiece() != NULL) //contains enemy piece
		{
			if((board_->square(index)->getPiece()->type() == 'B' ||
			board_->square(index)->getPiece()->type() == 'Q')) //this square contains an enemy bishop or queen
			{
				inCheck_ = true;
				return true;
			}
			break;
		}
		index += 9;
	}
	
	//scan the diagonal to the lower left
	index = square_->index() - 9;
	if(piece_color == 'B' && board_->square(index)->getPiece() != NULL &&
		board_->square(index)->getPiece()->color() != piece_color &&
		board_->square(index)->getPiece()->type() == 'P') //this square contains an enemy pawn
	{
		inCheck_ = true;
		return true;
	}
	while(index >= 0 && index % 8 != 7)
	{
		if(board_->square(index)->getPiece() != NULL && 
			board_->square(index)->getPiece()->color() == piece_color) //friendly piece
			break;
		if(board_->square(index)->getPiece() != NULL) //contains enemy piece
		{
			if((board_->square(index)->getPiece()->type() == 'B' ||
			board_->square(index)->getPiece()->type() == 'Q')) //this square contains an enemy bishop or queen
			{
				inCheck_ = true;
				return true;
			}
			break;
		}
		index -= 9;
	}
	
	//scan the diagonal to the upper left
	index = square_->index() + 7;
	if(piece_color == 'W' && board_->square(index)->getPiece() != NULL &&
		board_->square(index)->getPiece()->color() != piece_color &&
		board_->square(index)->getPiece()->type() == 'P') //this square contains an enemy pawn
	{
		inCheck_ = true;
		return true;
	}
	while(index < 64 && index % 8 != 7)
	{
		if(board_->square(index)->getPiece() != NULL && 
			board_->square(index)->getPiece()->color() == piece_color) //friendly piece
			break;
		if(board_->square(index)->getPiece() != NULL) //contains enemy piece
		{
			if((board_->square(index)->getPiece()->type() == 'B' ||
			board_->square(index)->getPiece()->type() == 'Q')) //this square contains an enemy bishop or queen
			{
				inCheck_ = true;
				return true;
			}
			break;
		}
		index += 7;
	}
	
	//scan the diagonal to the lower right
	index = square_->index() - 7;
	if(piece_color == 'B' && board_->square(index)->getPiece() != NULL &&
		board_->square(index)->getPiece()->color() != piece_color &&
		board_->square(index)->getPiece()->type() == 'P') //this square contains an enemy pawn
	{
		inCheck_ = true;
		return true;
	}
	while(index >= 0 && index % 8 != 0)
	{
		if(board_->square(index)->getPiece() != NULL && 
			board_->square(index)->getPiece()->color() == piece_color) //friendly piece
			break;
		if(board_->square(index)->getPiece() != NULL && 
			(board_->square(index)->getPiece()->type() == 'B' ||
			board_->square(index)->getPiece()->type() == 'Q')) //this square contains an enemy bishop or queen
		{
			inCheck_ = true;
			return true;
		}
		index -= 7;
	}
	
	//right
	index = square_->index() + 1;
	while(index < 64 && index % 8 != 0)
	{
		if(board_->square(index)->getPiece() != NULL && 
			board_->square(index)->getPiece()->color() == piece_color) //friendly piece
			break;
		if(board_->square(index)->getPiece() != NULL) //contains enemy piece
		{
			if((board_->square(index)->getPiece()->type() == 'R' ||
			board_->square(index)->getPiece()->type() == 'Q')) //this square contains an enemy bishop or queen
			{
				inCheck_ = true;
				return true;
			}
			break;
		}
		++index;
	}
	
	//left
	index = square_->index() - 1;
	while(index >= 0 && index % 8 != 7)
	{
		if(board_->square(index)->getPiece() != NULL && 
			board_->square(index)->getPiece()->color() == piece_color) //friendly piece
			break;
		if(board_->square(index)->getPiece() != NULL) //contains enemy piece
		{
			if((board_->square(index)->getPiece()->type() == 'R' ||
			board_->square(index)->getPiece()->type() == 'Q')) //this square contains an enemy rook or queen
			{
				inCheck_ = true;
				return true;
			}
			break;
		}
		--index;
	}
	
	//up
	index = square_->index() + 8;
	while(index < 64)
	{
		if(board_->square(index)->getPiece() != NULL && 
			board_->square(index)->getPiece()->color() == piece_color) //friendly piece
			break;
		if(board_->square(index)->getPiece() != NULL) //contains enemy piece
		{
			if((board_->square(index)->getPiece()->type() == 'R' ||
			board_->square(index)->getPiece()->type() == 'Q')) //this square contains an enemy rook or queen
			{
				inCheck_ = true;
				return true;
			}
			break;
		}
		index += 8;
	}
	
	//down
	index = square_->index() - 8;
	while(index >= 0)
	{
		if(board_->square(index)->getPiece() != NULL && 
			board_->square(index)->getPiece()->color() == piece_color) //friendly piece
			break;
		if(board_->square(index)->getPiece() != NULL) //contains enemy piece
		{
			if((board_->square(index)->getPiece()->type() == 'R' ||
			board_->square(index)->getPiece()->type() == 'Q')) //this square contains an enemy rook or queen
			{
				inCheck_ = true;
				return true;
			}
			break;
		}
		index -= 8;
	}
	
	index = square_->index() + 17;
	if(index < 64 && index % 8 != 0 && 
		board_->square(index)->getPiece() != NULL &&
		board_->square(index)->getPiece()->color() != piece_color &&
		board_->square(index)->getPiece()->type() == 'N') //this square contains an enemy knight
	{
		inCheck_ = true;
		return true;
	}
	
	index = square_->index() + 10;
	if(index < 64 && index % 8 > 1 && 
		board_->square(index)->getPiece() != NULL &&
		board_->square(index)->getPiece()->color() != piece_color &&
		board_->square(index)->getPiece()->type() == 'N') //this square contains an enemy knight
	{
		inCheck_ = true;
		return true;
	}
	
	index = square_->index() - 6;
	if(index >= 0 && index % 8 > 1 && 
		board_->square(index)->getPiece() != NULL &&
		board_->square(index)->getPiece()->color() != piece_color &&
		board_->square(index)->getPiece()->type() == 'N') //this square contains an enemy knight
	{
		inCheck_ = true;
		return true;
	}
	
	index = square_->index() - 15;
	if(index >= 0 && index % 8 != 0 && 
		board_->square(index)->getPiece() != NULL &&
		board_->square(index)->getPiece()->color() != piece_color &&
		board_->square(index)->getPiece()->type() == 'N') //this square contains an enemy knight
	{
		inCheck_ = true;
		return true;
	}
	
	index = square_->index() - 17;
	if(index >= 0 && index % 8 != 7 && 
		board_->square(index)->getPiece() != NULL &&
		board_->square(index)->getPiece()->color() != piece_color &&
		board_->square(index)->getPiece()->type() == 'N') //this square contains an enemy knight
	{
		inCheck_ = true;
		return true;
	}
	
	index = square_->index() - 10;
	if(index >= 0 && index % 8 < 6 && 
		board_->square(index)->getPiece() != NULL &&
		board_->square(index)->getPiece()->color() != piece_color &&
		board_->square(index)->getPiece()->type() == 'N') //this square contains an enemy knight
	{
		inCheck_ = true;
		return true;
	}
	
	index = square_->index() + 6;
	if(index < 64 && index % 8 < 6 && 
		board_->square(index)->getPiece() != NULL &&
		board_->square(index)->getPiece()->color() != piece_color &&
		board_->square(index)->getPiece()->type() == 'N') //this square contains an enemy knight
	{
		inCheck_ = true;
		return true;
	}
	
	index = square_->index() + 15;
	if(index < 64 && index % 8 != 7 && 
		board_->square(index)->getPiece() != NULL &&
		board_->square(index)->getPiece()->color() != piece_color &&
		board_->square(index)->getPiece()->type() == 'N') //this square contains an enemy knight
	{
		inCheck_ = true;
		return true;
	}
	
	inCheck_ = false;
	return false; //this is only reached if all the possibilites have been searched and no check was detected
}

/**Returns the hasMoved_ condition of this piece.
 * @return Returns true if king has been moved, false if not
 */
bool ChessPiece_King::hasMoved()
{
	return hasMoved_;
}

/**Moves the king to the provided square. Checks to see if the king is castling and if so, moves the corresponding rook
 * to the proper location as well.
 * @param *dest The square to which the king is to be moved
 */
void ChessPiece_King::move(ChessBoardSquare *dest)
{
	if(square_ != NULL)
	{
		//kingside castle
		if(dest->index() == square_->index() + 2)
		{
			
			board_->square(square_->index() + 3)->getPiece()->move(board_->square(square_->index() + 1));
		}
		//queenside castle
		else if(dest->index() == square_->index() - 2)
		{
			board_->square(square_->index() - 4)->getPiece()->move(board_->square(square_->index() - 1));
		}
		square_->clear();
	}
	if(dest->getPiece() != NULL && dest->getPiece() != this)
		dest->getPiece()->isCaptured();
	square_ = dest;
	dest->setPiece(this);
	hasMoved_ = true;
	
}

/**Moves the king to the destination square but does nothing to the current square. To be used with the board copy
 * constructor.
 * @param *dest The square to which the king is to be moved
 */
void ChessPiece_King::cmove(ChessBoardSquare *dest)
{
	if(dest->getPiece() != NULL && dest->getPiece() != this)
		dest->getPiece()->isCaptured();
	square_ = dest;
	dest->setPiece(this);
}
