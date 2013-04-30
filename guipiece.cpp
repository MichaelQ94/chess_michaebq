#include "guipiece.h"

/**Constructor. Initializes the member variables and chooses an image based on the piece's type and color.
 * @param *piece The piece which this GUIPiece is going to represent
 * @param *gw Reference to the parent GraphicsWindow
 */
GUIPiece::GUIPiece(ChessPiece *piece, GraphicsWindow *gw) : QGraphicsPixmapItem()
{
	piece_ = piece;
	gw_ = gw;
	pieceToCapture_ = NULL;
	gsquare_ = NULL;
	std::string filename = "";
	
	switch(piece_->color())
	{
		case 'W':
			filename += "white";
			break;
		
		case 'B':
			filename += "black";
	}
	
	switch(piece_->type())
	{
		case 'P':
			filename += "pawn";
			break;
		
		case 'N':
			filename += "knight";
			break;
		
		case 'B':
			filename += "bishop";
			break;
		
		case 'R':
			filename += "rook";
			break;
		
		case 'Q':
			filename += "queen";
			break;
		
		case 'K':
			filename += "king";
	}
	
	filename += ".png";
	
	
	
	setPixmap(QString(filename.c_str()));
	setShapeMode(BoundingRectShape);
}

/**Returns the x-coordinate of this piece's current position
 * @return The x-coordinate of this piece's current position
 */
int GUIPiece::getX()
{
	return x_;
}

/**Returns the y-coordinate of this piece's current position
 * @return The y-coordinate of this piece's current position
 */
int GUIPiece::getY()
{
	return y_;
}

/**Returns this piece's color
 * @return This piece's color
 */
char GUIPiece::color()
{
	return piece_->color();
}

/**Returns this piece's type
 * @return This piece's type
 */
char GUIPiece::type()
{
	return piece_->type();
}

/**Calls the ChessPiece's legalMoves() function and returns the list of squares to which this piece is allowed
 * to move.
 * @return The list of the indices of the squares to which this piece is allowed to move
 */
vector<int> GUIPiece::legalMoves()
{
	return piece_->legalMoves();
}

/**Resets the piece's hasMoved_ condition to false if it has one
 */
void GUIPiece::reset()
{
	piece_->reset();
}

/**Checks to see if this piece can be captured via en passant
 * @return Returns true if this piece can be captured via en passant, false if not
 */
bool GUIPiece::enPassant()
{
	return piece_->enPassant();
}

/**Promotes the piece to the given type
 * @param type The piece type to which this piece is to be promoted
 */
void GUIPiece::promote(char type)
{
	piece_->promote(type);
	std::string filename = "";
	
	switch(piece_->color())
	{
		case 'W':
			filename += "white";
			break;
		
		case 'B':
			filename += "black";
	}
	
	switch(type)
	{
		
		case 'N':
			filename += "knight";
			break;
		
		case 'B':
			filename += "bishop";
			break;
		
		case 'R':
			filename += "rook";
			break;
		
		case 'Q':
			filename += "queen";
	}
	
	filename += ".png";
	
	
	
	setPixmap(QString(filename.c_str()));
}

/**Sends the move being made by the chesspiece in algebraic chess notation to the parent GraphicsWindow
 * for printing
 * @param *dest The square to which this piece is to be moved
 * @param cap True if this piece is going to make a capture, false if not
 */
void GUIPiece::transcribeMove(GUISquare *dest, bool cap)
{
	QString move;
	if(piece_->type() != 'P')
	{
		move += piece_->type();
	}
	move += gsquare_->getCoordinates();
	if(cap)
	{
		move += "x";
	}
	else
	{
		move += "-";
	}
	move += dest->getCoordinates();
	gw_->setMove(move);
}

/**Moves this piece to the given square and animates the movement
 * @param *dest The square to which this piece is to be moved
 */
void GUIPiece::move(GUISquare *dest)
{
	if(gw_->getMove().isEmpty())
		transcribeMove(dest, dest->guiPiece() != NULL);
	destx = dest->getX();
	desty = dest->getY();
	vx_ = (destx - x_) / 60;
	vy_ = (desty - y_) / 60;
	piece_->move(dest->square());
	if(dest->guiPiece() != NULL) //capture the piece occupying the square if there is one
		pieceToCapture_ = dest->guiPiece();
	
	if(gw_->slidingPiece() == NULL)
		gw_->slidePiece(this);
	else
		gw_->slidePiece2(this);
	
	if(gsquare_ != NULL)
		gsquare_->clear();
	gsquare_ = dest;
	gsquare_->setPiece(this);
}

/**Moves this piece to the given square without animating the movement. Only used when setting up the board.
 * @param *dest The square to which this piece is to be moved
 */
void GUIPiece::cmove(GUISquare *dest)
{
	piece_->move(dest->square());
	x_ = dest->getX();
	y_ = dest->getY();
	if(dest->guiPiece() != NULL) //capture the piece occupying the square if there is one
		gw_->capturePiece(dest->guiPiece());
	setPos(dest->getX(), dest->getY()); //the move
	if(gsquare_ != NULL)
		gsquare_->clear();
	gsquare_ = dest;
	gsquare_->setPiece(this);
}

/**Increments this piece's position variables by an amount equal to the piece's velocity variables. Used to
 * animate the pieces.
 */
void GUIPiece::slide()
{
	x_ += vx_;
	y_ += vy_;
	setPos(x_, y_);
	if(x_ == destx && y_ == desty && gw_->slidingPiece() == this)
		gw_->stopSliding();
	else if(x_ == destx && y_ == desty && gw_->slidingPiece2() == this)
		gw_->stopSliding2();
	if(pieceToCapture_ != NULL && collidesWithItem(pieceToCapture_))
	{
		gw_-> capturePiece(pieceToCapture_);
		pieceToCapture_ = NULL;
	}
}
