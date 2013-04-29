#include "guipiece.h"

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

int GUIPiece::getX()
{
	return x_;
}

int GUIPiece::getY()
{
	return y_;
}

char GUIPiece::color()
{
	return piece_->color();
}

char GUIPiece::type()
{
	return piece_->type();
}

vector<int> GUIPiece::legalMoves()
{
	return piece_->legalMoves();
}

void GUIPiece::reset()
{
	piece_->reset();
}

bool GUIPiece::enPassant()
{
	return piece_->enPassant();
}

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

void GUIPiece::move(GUISquare *dest)
{
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
