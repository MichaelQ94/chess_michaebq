#ifndef GUISQUARE_H
#define GUISQUARE_H

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
#include <vector>
#include <QGraphicsSceneMouseEvent>
#include "graphicswindow.h"
#include "chessboardsquare.h"

class GraphicsWindow;

class GUISquare : public QGraphicsRectItem
{	
	private:
		GraphicsWindow *gw_;
		ChessBoardSquare *square_;
	
	public:
		
	
};
#endif
