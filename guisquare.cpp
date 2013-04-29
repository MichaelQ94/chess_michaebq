#include "guisquare.h"

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

QString GUISquare::getCoordinates()
{
	return coordinates_;
}

void GUISquare::mousePressEvent(QGraphicsSceneMouseEvent *c)
{
	//must wait until animation is done before making new moves
	if(gw_->slidingPiece() != NULL || gw_->slidingPiece2() != NULL)
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
		gw_->changeTurn();
		gw_->dehighlight();
	}
}

GUIPiece* GUISquare::guiPiece()
{
	return gpiece_;
}

void GUISquare::setColor(Qt::GlobalColor color)
{
	color_ = color;
	QBrush brush(color_);
	setBrush(brush);
}

void GUISquare::highlight()
{
	setBrush(QBrush(Qt::cyan));
	highlighted_ = true;
}

bool GUISquare::highlighted()
{
	return highlighted_;
}

void GUISquare::resetColor()
{
	QBrush brush(color_);
	setBrush(brush);
	highlighted_ = false;
}

void GUISquare::setPiece(GUIPiece* gpiece)
{
	gpiece_ = gpiece;
}

void GUISquare::clear()
{
	gpiece_ = NULL;
}

int GUISquare::getX()
{
	return x_;
}

int GUISquare::getY()
{
	return y_;
}

int GUISquare::index()
{
	return square_->index();
}

ChessBoardSquare* GUISquare::square()
{
	return square_;
}
