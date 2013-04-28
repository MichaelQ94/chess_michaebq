#include "guipiece.h"

GUIPiece::GUIPiece(ChessPiece *piece, GraphicsWindow *gw) : QGraphicsPixmapItem(QString("whitepawn.txt"), 0 , 0)
{
	piece_ = piece;
	gw_ = gw;
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

void GUIPiece::move(GUISquare *dest)
{
	piece_->move(dest->square());
	if(dest->guiPiece() != NULL)
		gw_->capturePiece(dest->guiPiece());
	setPos(dest->getX(), dest->getY()); //the move
	if(gsquare_ != NULL)
		gsquare_->clear();
	gsquare_ = dest;
	gsquare_->setPiece(this);
}
