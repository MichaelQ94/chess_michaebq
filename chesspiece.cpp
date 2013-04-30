#include "chesspiece.h"
using namespace std;

/**Constructor. Initializes all values. Square is initially set to null.
 * @param *board Reference to the parent ChessBoard
 * @param type Character indicating the type of the piece (see key)
 * @param color Character indicating the color of the piece (see key)
 * @param value the score value of the piece (see key)
 */
ChessPiece::ChessPiece(ChessBoard *board, char type, char color, int value)
{
	board_ = board;
	piece_type = type;
	piece_color = color;
	value_ = value;
	square_ = NULL;
	captured_ = false;
}

/**Effectively a copy constructor. Copies all of the information of the provided piece, except this piece will be
 * linked to a different board object. Intended to be used with the ChessMove class to create copies of the board
 * and pieces so that moves can be tested.
 * @param *board The board on which this piece will be placed
 * @param *piece The piece to be copied
 */
ChessPiece::ChessPiece(ChessBoard *board, ChessPiece *piece)
{
	board_ = board;
	square_ = piece->square_;
	piece_type = piece->piece_type;
	piece_color = piece->piece_color;
	value_ = piece->value_;
	captured_ = piece->captured_;
}

/**Copies all information from the provided piece to this one. Intended to be used with pawn promotion so that the pawn's
 * promotedPiece_ object will have the same information as the pawn itself.
 * @param *piece The piece to be copied
 */
void ChessPiece::copyData(ChessPiece *piece)
{
	board_ = piece->board_;
	piece_type = piece->piece_type;
	piece_color = piece->piece_color;
	value_ = piece->value_;
	square_ = piece->square_;
	captured_ = false;
}

/**Accessor. Returns a character corresponding to the type of the piece (see key).
 * @return The piece type
 */
char ChessPiece::type()
{
	return piece_type;
}

/**Accessor. Returns a charactor corresponding to the color of the piece (see key).
 * @return The piece color
 */
char ChessPiece::color()
{
	return piece_color;
}

/**Accessor. Returns the score value of the piece
 * @return The value of the piece
 */
int ChessPiece::value()
{
	return value_;
}

/**Accessor. Returns true if the piece has been captured, false if not
 * @return The status of the piece (captured or free)
 */
bool ChessPiece::captured()
{
	return captured_;
}

/**Sets the captured status of the piece to true and removes the piece from the board.
 */
void ChessPiece::isCaptured()
{
	captured_ = true;
	square_->clear();
	square_ = NULL;
}

/**Accessor. Only pawns, rooks, and kings have a 'hasMoved_' member so they have their own versions of this function.
 * This one returns true by default.
 * @return Always returns true
 */
bool ChessPiece::hasMoved()
{
	return true;
}

/**Accessor. Only pawns have a 'hasPassant_' member so the pawn class has its own version of this function.
 * This one returns false by default.
 * @return Always returns false
 */
bool ChessPiece::enPassant()
{
	return false;
}

/**Only to be implemented with classes which have a 'hasMoved_' member. This function does nothing.
 */
void ChessPiece::reset()
{
}

/**Only to be implemented with the pawn class becuase it has an 'enPassant_' member.
 */
void ChessPiece::refresh()
{
}

/**Only the king class has an inCheck_ method so it has its own version of this function.
 * This one returns false by default.
 * @return Always returns false
 */
bool ChessPiece::inCheck()
{
	return false;
}

/**Only the king class can check to see if it is in check so it has its own version of this function.
 * This one returns false by default.
 * @return Always returns false
 */
bool ChessPiece::checkForCheck()
{
	return false;
}

/**Accessor. Returns a reference to the square which this piece occupies.
 * @return Reference to the square occupied by this piece (NULL if none)
 */
ChessBoardSquare* ChessPiece::square()
{
	return square_;
}

/**Only the pawn class is able to promote so this is simply a placeholder because all pieces are handled as ChessPiece
 * pointers. This function does nothing.
 */
void ChessPiece::promote(char type)
{
}

/**Moves the piece from its current square (if there is one) to the given square. Sets the square_ variable to point to
 * the new location and sets the current square's piece_ member to NULL.
 * @param *dest The square to which this piece is to be moved.
 */
void ChessPiece::move(ChessBoardSquare *dest)
{
	if(square_ != NULL)
		square_->clear();
	if(dest->getPiece() != NULL)
		dest->getPiece()->isCaptured();
	square_ = dest;
	dest->setPiece(this);
}

/**Places the piece on its destination square, but does nothing to its current square. To be used with the copy constructor
 * in the board class to prevent two different boards from affecting each other.
 * @param *dest The square on which this piece is to be placed.
 */
void ChessPiece::cmove(ChessBoardSquare *dest)
{
	if(dest->getPiece() != NULL)
		dest->getPiece()->isCaptured();
	square_ = dest;
	dest->setPiece(this);
}
