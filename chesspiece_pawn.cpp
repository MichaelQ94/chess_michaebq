#include "chesspiece.h"
using namespace std;

/**Constructor. Sets the proper values in the ChessPiece class ('P' for pawn, 1 for score value).
 * Links this piece to its parent board.
 * Initializes the promoted piece to NULL and sets hasMoved_ and enPassant_ to false.
 * @param *board The parent board to which this piece belongs
 * @param color Character representing the color of the piece (W for white, B for black)
 */
ChessPiece_Pawn::ChessPiece_Pawn(ChessBoard *board, char color) : ChessPiece(board, 'P', color, 1)
{
	promoted_piece = NULL;
	hasMoved_ = false;
	enPassant_ = false;
}

/**'Copy' constructor. Copies the provided piece's information but links this piece to a different board.
 * If the provided piece has been promoted, copies the promoted piece's information as well.
 * @param *board The parent board to which this piece belongs
 * @param *piece The piece whose information is to be copied
 */
ChessPiece_Pawn::ChessPiece_Pawn(ChessBoard *board, ChessPiece_Pawn *piece) : ChessPiece(board, piece)
{
	hasMoved_ = piece->hasMoved_;
	enPassant_ = piece->enPassant_;
	promoted_piece = NULL;
	if(piece->promoted_piece != NULL)
	{
		switch(piece_type)
		{
		case 'N':
			promoted_piece = new ChessPiece_Knight(board_, piece_color);
			break;
		case 'B':
			promoted_piece = new ChessPiece_Bishop(board_, piece_color);
			break;
		case 'R':
			promoted_piece = new ChessPiece_Rook(board_, piece_color);
			break;
		case 'Q':
			promoted_piece = new ChessPiece_Queen(board_, piece_color);
		}
		
		promoted_piece->copyData(this);
	}
}

/**Checks the square immediately ahead of the pawn to see if it can move there. Also check the square which is two spaces
 * ahead if the pawn has not yet moved. Checks the two squares in front of the pawn which are diagonally adjacent to it
 * for enemy pieces to see if the pawn can capture. Checks to make sure moves will not place the owner's king in check
 * before adding them to a list of allowed moves. If the pawn has been promoted, calls the promoted piece's legalMoves()
 * function instead.
 * @return The list of the indices of the squares to which this pawn is allowed to move
 */
vector<int> ChessPiece_Pawn::legalMoves()
{
	vector<int> legalMoves;
	ChessMove *move;
	if(promoted_piece == NULL) //regular pawn
	{
		int index;
		if(piece_color == 'W')//white
		{
			index = square_->index() + 8;
			if(board_->square(index)->getPiece() == NULL)
			{
				move = new ChessMove(board_, square_->index(), index);
				if(move->isLegal(piece_color))
					legalMoves.push_back(index);
				delete move;
				
				index += 8;
				if(!hasMoved_ && board_->square(index)->getPiece() == NULL)
				{
					move = new ChessMove(board_, square_->index(), index);
					if(move->isLegal(piece_color))
						legalMoves.push_back(index);
					delete move;
				}
			}
			
			index = square_->index() + 7;	
			if(index % 8 != 7 && ((board_->square(index)->getPiece() != NULL && 
				board_->square(index)->getPiece()->color() == 'B') || //can capture a black piece
				(board_->square(index-8)->getPiece() != NULL &&
				board_->square(index-8)->getPiece()->color() == 'B' &&
				board_->square(index-8)->getPiece()->enPassant()))) //can capture via en passant
			{
				move = new ChessMove(board_, square_->index(), index);
				if(move->isLegal(piece_color))
					legalMoves.push_back(index);
				delete move;
			}
			
			index = square_->index() + 9;
			if(index % 8 != 0 && ((board_->square(index)->getPiece() != NULL && 
				board_->square(index)->getPiece()->color() == 'B') || //can capture a black piece
				(board_->square(index-8)->getPiece() != NULL &&
				board_->square(index-8)->getPiece()->color() == 'B' &&
				board_->square(index-8)->getPiece()->enPassant()))) //can capture via en passant
			{
				move = new ChessMove(board_, square_->index(), index);
				if(move->isLegal(piece_color))
					legalMoves.push_back(index);
				delete move;
			}
			
		}
		else //black
		{
			index = square_->index() - 8;
			if(board_->square(index)->getPiece() == NULL)
			{
				move = new ChessMove(board_, square_->index(), index);
				if(move->isLegal(piece_color))
					legalMoves.push_back(index);
				delete move;
				index -= 8;
				if(!hasMoved_ && board_->square(index)->getPiece() == NULL)
				{
					move = new ChessMove(board_, square_->index(), index);
					if(move->isLegal(piece_color))
						legalMoves.push_back(index);
					delete move;
				}
			}
			
			index = square_->index() - 9;
			if(index % 8 != 7 && ((board_->square(index)->getPiece() != NULL && 
				board_->square(index)->getPiece()->color() == 'W') || //can capture a white piece
				(board_->square(index+8)->getPiece() != NULL &&
				board_->square(index+8)->getPiece()->color() == 'W' &&
				board_->square(index+8)->getPiece()->enPassant()))) //can capture via en passant
			{
				move = new ChessMove(board_, square_->index(), index);
				if(move->isLegal(piece_color))
					legalMoves.push_back(index);
				delete move;
			}
			
			index = square_->index() - 7;
			if(index % 8 != 0 && ((board_->square(index)->getPiece() != NULL && 
				board_->square(index)->getPiece()->color() == 'W') || //can capture a white piece
				(board_->square(index+8)->getPiece() != NULL &&
				board_->square(index+8)->getPiece()->color() == 'W' &&
				board_->square(index+8)->getPiece()->enPassant()))) //can capture via en passant
			{
				move = new ChessMove(board_, square_->index(), index);
				if(move->isLegal(piece_color))
					legalMoves.push_back(index);
				delete move;
			}
			
		}
			
	}
	else //pawn has been promoted
	{
		return promoted_piece->legalMoves();
	}
	
	return legalMoves;
}

/**Sets the enPassant_ condition to false. This is called at the beginning of the owner's turn to ensure that a pawn is
 * only allowed to be captured via en passant during the move immediately after it has made its two-square advance.
 */
void ChessPiece_Pawn::refresh()
{
	enPassant_ = false;
}

/**Accessor. Returns the hasMoved_ condition of the pawn.
 * @return Returns true if the pawn has been moved, false if not
 */
bool ChessPiece_Pawn::hasMoved()
{
	return hasMoved_;
}

/**Resets the hasMoved_ boolean to false. This is to be called after the piece has been placed on the board using the move()
 * function.
 */
void ChessPiece_Pawn::reset()
{
	hasMoved_ = false;
}

/**Returns the enPassant_ boolean of the piece.
 * @return Returns true if the pawn can be captured via en passant, false if not
 */
bool ChessPiece_Pawn::enPassant()
{
	return enPassant_;
}

/**Moves the pawn to the destination square. Sets enPassant_ to true if the pawn is making a two-square advance.
 * Checks to see if the pawn is performing an en passant capture.
 * @param *dest The square to which the pawn is to be moved
 */
void ChessPiece_Pawn::move(ChessBoardSquare *dest)
{
	if(square_ != NULL)
	{
		square_->clear();
		if(!hasMoved_ && ((piece_color == 'W' && dest->index() == square_->index() + 16) ||
		(piece_color == 'B' && dest->index() == square_->index() - 16)))
		{
			enPassant_ = true;
		}
	}
	if(dest->getPiece() != NULL)
		dest->getPiece()->isCaptured();
	//en passant captures
	else if(promoted_piece == NULL && piece_color == 'W' && 
		board_->square(dest->index() - 8)->getPiece() != NULL &&
		board_->square(dest->index() - 8)->getPiece()->enPassant())
	{
		board_->square(dest->index() - 8)->getPiece()->isCaptured();
	}
	else if(promoted_piece == NULL && piece_color == 'B' && 
		board_->square(dest->index() + 8)->getPiece() != NULL &&
		board_->square(dest->index() + 8)->getPiece()->enPassant())
	{
		board_->square(dest->index() + 8)->getPiece()->isCaptured();
	}
	square_ = dest;
	dest->setPiece(this);
	hasMoved_ = true;
	if(promoted_piece != NULL)
	{
		promoted_piece->copyData(this);
	}
}

/**Moves the pawn to the destination square but leaves the current square alone. To be used with the board class's copy
 * constructor.
 * @param *dest The square to which the pawn is to be moved
 */
void ChessPiece_Pawn::cmove(ChessBoardSquare *dest)
{
	if(dest->getPiece() != NULL)
		dest->getPiece()->isCaptured();
	//en passant captures
	else if(promoted_piece == NULL && piece_color == 'W' && 
		board_->square(dest->index() - 8)->getPiece() != NULL &&
		board_->square(dest->index() - 8)->getPiece()->enPassant())
	{
		board_->square(dest->index() - 8)->getPiece()->isCaptured();
	}
	else if(promoted_piece == NULL && piece_color == 'B' && 
		board_->square(dest->index() + 8)->getPiece() != NULL &&
		board_->square(dest->index() + 8)->getPiece()->enPassant())
	{
		board_->square(dest->index() + 8)->getPiece()->isCaptured();
	}
	square_ = dest;
	dest->setPiece(this);
	if(promoted_piece != NULL)
	{
		promoted_piece->copyData(this);
	}
}


/**Promotes the pawn by instantiating the promoted_piece to the proper piece type.
 * Also updates the pawn's information.
 * @param type The type of the piece to which the pawn is to be promoted
 */
void ChessPiece_Pawn::promote(char type)
{
	switch(type)
	{
		case 'N':
			promoted_piece = new ChessPiece_Knight(board_, piece_color);
			piece_type = 'N';
			value_ = 3;
			break;
		case 'B':
			promoted_piece = new ChessPiece_Bishop(board_, piece_color);
			piece_type = 'B';
			value_ = 3;
			break;
		case 'R':
			promoted_piece = new ChessPiece_Rook(board_, piece_color);
			piece_type = 'R';
			value_ = 5;
			break;
		case 'Q':
			promoted_piece = new ChessPiece_Queen(board_, piece_color);
			piece_type = 'Q';
			value_ = 9;
	}
	
	promoted_piece->copyData(this);
}

/**Destructor. Deletes the promoted piece if the pawn has been promoted.
 */
ChessPiece_Pawn::~ChessPiece_Pawn()
{
	if(promoted_piece != NULL)
		delete promoted_piece;
}
