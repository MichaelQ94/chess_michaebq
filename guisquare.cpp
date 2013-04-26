#include "guisquare.h"

GUISquare::GUISquare(GraphicsWindow *gw, ChessBoardSquare *square, int x, int y, int w) : QGraphicsRectItem(x, y, w, w)
{
	gw_ = gw;
	square_ = square;
	x_ = x;
	y_ = y;
}

void GUISquare::mousePressEvent(QGraphicsSceneMouseEvent *c)
{
	c->pos();
	this->setBrush(QBrush(Qt::cyan));
}

int GUISquare::getX()
{
	return x_;
}

int GUISquare::getY()
{
	return y_;
}
