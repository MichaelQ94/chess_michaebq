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
#include <QString>
#include <vector>
#include <QGraphicsSceneMouseEvent>
#include "graphicswindow.h"
#include "guipiece.h"
#include "chessboardsquare.h"

class GraphicsWindow;

class GUISquare : public QGraphicsRectItem
{	
	private:
		GraphicsWindow *gw_;
		ChessBoardSquare *square_;
		int x_, y_;
	
	public:
		GUISquare(GraphicsWindow*, ChessBoardSquare*, int x, int y, int w);
		int getX();
		int getY();
		
	public slots:
		void mousePressEvent(QGraphicsSceneMouseEvent *c);
};
#endif
