#include "chessboardsquare.h"

/**Constructor. Stores a reference to the parent board and copies its index in the array of all squares.
 * Sets the stored piece to NULL.
 */
ChessBoardSquare::ChessBoardSquare(ChessBoard *board, int index)
{
	board_ = board;
	piece_ = NULL;
	index_ = index;
}

/**Stores a reference to the piece currently occupying the square
 */
void ChessBoardSquare::setPiece(ChessPiece *piece)
{
	piece_ = piece;
}

/**Removes the reference to the piece occupying the square. Called when the piece moves away.
 */
void ChessBoardSquare::clear()
{
	piece_ = NULL;
}

/**Accessor. Returns the index of this square in the array of all squares contained in the parent board object.
 * @return The index of this square
 */
int ChessBoardSquare::index()
{
	return index_;
}

/**Returns a reference to the piece currently occupying this square
 * @return Reference to the piece currently occupying this square
 */
ChessPiece* ChessBoardSquare::getPiece()
{
	return piece_;
}

/**Destructor
 */
ChessBoardSquare::~ChessBoardSquare() {}
