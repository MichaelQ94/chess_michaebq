#include "guipiece.h"

GUIPiece::GUIPiece(ChessPiece *piece, GraphicsWindow *gw) : QGraphicsPixmapItem(QString("whitepawn.txt"), 0 , 0)
{
	piece_ = piece;
	gw_ = gw;
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
	setPos(0, 0);
}

int GUIPiece::getX()
{
	return x_;
}

int GUIPiece::getY()
{
	return y_;
}

void GUIPiece::move(GUISquare *dest)
{
	setPos(dest->getX(), dest->getY());
}
