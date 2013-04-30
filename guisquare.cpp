#include "guisquare.h"

/**Constructor. Initializes the proper values and sets the location and color of the square.
 *
 */
GUISquare::GUISquare(GraphicsWindow *gw, ChessBoardSquare *square, int x, int y, int w) : QGraphicsRectItem(x, y, w, w)
{
	gw_ = gw;
	square_ = square;
	x_ = x;
	y_ = y;
	gpiece_ = NULL;
	highlighted_ = false;
	
	switch(square_->index() % 8)
	{
		case 0:
			coordinates_ += "a";
			break;
		case 1:
			coordinates_ += "b";
			break;
		case 2:
			coordinates_ += "c";
			break;
		case 3:
			coordinates_ += "d";
			break;
		case 4:
			coordinates_ += "e";
			break;
		case 5:
			coordinates_ += "f";
			break;
		case 6:
			coordinates_ += "g";
			break;
		case 7:
			coordinates_ += "h";
	}
	
	coordinates_ += QString::number((square_->index() / 8) + 1);
}

/**Returns the coordinates of this square in algebraic chess notation.
 * @return The chess notation coordinates of this square
 */
QString GUISquare::getCoordinates()
{
	return coordinates_;
}

/**Handles user input via clicking. If no piece is selected, selects the piece and highlights the appropriate
 * squares to which it is allowed to move. If a piece is selected, attempts to move the piece to this square
 * if the move is allowed.
 * @param *c The mouse event which triggered this function
 */
void GUISquare::mousePressEvent(QGraphicsSceneMouseEvent *c)
{
	//must wait until animation is done before making new moves
	if(!gw_->gameInProgress() || gw_->slidingPiece() != NULL || gw_->slidingPiece2() != NULL)
		return;
	c->pos();
	if(gw_->selectedPiece() == NULL && gpiece_ != NULL) //no selected piece and this square is occupied
	{
		if((gw_->whiteToMove() && gpiece_->color() == 'W') || 
			(!gw_->whiteToMove() && gpiece_->color() == 'B'))
		{
			highlight();
			gw_->highlightSquares(gpiece_->legalMoves());
			gw_->setSelectedPiece(gpiece_);
			gw_->setSelectedSquare(this);
		}
	}
	else if(gw_->selectedPiece() != NULL && gpiece_ != NULL && 
		gw_->selectedPiece()->color() == gpiece_->color())
		//user wishes to select a difference piece
	{
		gw_->dehighlight();
		highlight();
		gw_->highlightSquares(gpiece_->legalMoves());
		gw_->setSelectedPiece(gpiece_);
		gw_->setSelectedSquare(this);
	}
	else if(gw_->selectedPiece() != NULL && highlighted_)
	{
		//if castling
		if(gw_->selectedPiece()->type() == 'K')
		{
			if(gw_->selectedSquare()->index() == index() - 2)
			{
				gw_->castleKingSide();
				return;
			}
			else if(gw_->selectedSquare()->index() == index() + 2)
			{
				gw_->castleQueenSide();
				return;
			}
		}
		
		//if en passant
		if(gw_->selectedPiece()->type() == 'P' && gw_->selectedSquare()->index() % 8 != index() % 8)
		{
			gw_->enPassantCapture(this);
		}
		
		//move the piece
		gw_->selectedPiece()->move(this);
		
		//if promotion
		if(gw_->selectedPiece()->type() == 'P' &&
			((gw_->selectedPiece()->color() == 'W' && square_->index() / 8 == 7) ||
			(gw_->selectedPiece()->color() == 'B' && square_->index() / 8 == 0)))
		{
				gw_->promote(gw_->selectedPiece());
		}
		
		//deselect the piece and return the squares to normal
		gw_->deselectPiece();
		gw_->selectedSquare()->resetColor();
		gw_->deselectSquare();
		gw_->dehighlight();
		gw_->changeTurn();
	}
}

/**Returns a reference to the GUIPiece occupying this square
 * @return Reference to the GUIPiece occupying this square
 */
GUIPiece* GUISquare::guiPiece()
{
	return gpiece_;
}

/**Sets the color of this square.
 * @param color The color to which his square is to be set
 */
void GUISquare::setColor(Qt::GlobalColor color)
{
	color_ = color;
	QBrush brush(color_);
	setBrush(brush);
}

/**Sets the color of the square to cyan, highlighting it. Highlighted squares are used to show which square
 * is selected and which moves are allowed.
 */
void GUISquare::highlight()
{
	setBrush(QBrush(Qt::cyan));
	highlighted_ = true;
}

/**Returns true if this square is highligted
 * @return Returns true if this square is highlighted, false if not
 */
bool GUISquare::highlighted()
{
	return highlighted_;
}

/**Resets the color of this square to its original color. Used when dehighlighting squares.
 */
void GUISquare::resetColor()
{
	QBrush brush(color_);
	setBrush(brush);
	highlighted_ = false;
}

/**Sets this square's gpiece_ pointer to the given GUIPIece. Used when a piece is to be moved to this square.
 * @param *gpiece The piece to be moved to this square
 */
void GUISquare::setPiece(GUIPiece *gpiece)
{
	gpiece_ = gpiece;
}

/**Clears the piece occupying this board. Used when the piece moves away.
 */
void GUISquare::clear()
{
	gpiece_ = NULL;
}

/**Returns the x-coordinate of this square
 * @return The x-coordinate of this square
 */
int GUISquare::getX()
{
	return x_;
}

/**Returns the y-coordinate of this square
 * @return The y-coordinate of this square
 */
int GUISquare::getY()
{
	return y_;
}

/**Returns the index of this square in the array of all GUISquares contained in the GraphicsWindow
 * @return The index position of this square in the array of all GUISquares
 */
int GUISquare::index()
{
	return square_->index();
}

/**Returns the ChessBoardSquare represented by this GUISquare
 * @return A reference to the ChessBoardSquare represented by this GUISquare
 */
ChessBoardSquare* GUISquare::square()
{
	return square_;
}
