#ifndef GUIPIECE_H
#define GUIPIECE_H

#include <string>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsSimpleTextItem>
#include <QTimer>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QPushButton>
#include <QPixmap>
#include <QString>
#include <QGraphicsPixmapItem>
#include <vector>
#include <QGraphicsSceneMouseEvent>
#include "graphicswindow.h"
#include "guisquare.h"
#include "chesspiece.h"

class GraphicsWindow;
class GUISquare;

class GUIPiece : public QGraphicsPixmapItem
{
	
	private:
		GraphicsWindow *gw_;
		ChessPiece *piece_;
		int x_, y_;
	
	public:
		GUIPiece(ChessPiece *piece, GraphicsWindow *gw);
		void move(GUISquare *dest);
		int getX();
		int getY();
	
};
#endif
