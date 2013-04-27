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
class GUIPiece;

class GUISquare : public QGraphicsRectItem
{	
	private:
		GraphicsWindow *gw_;
		GUIPiece *gpiece_;
		ChessBoardSquare *square_;
		Qt::GlobalColor color_;
		int x_, y_;
		bool highlighted_;
	
	public:
		GUISquare(GraphicsWindow*, ChessBoardSquare*, int x, int y, int w);
		void setColor(Qt::GlobalColor color);
		void highlight();
		bool highlighted();
		void resetColor();
		int getX();
		int getY();
		void setPiece(GUIPiece* gpiece);
		void clear();
		int index();
		GUIPiece* guiPiece();
		ChessBoardSquare* square();
		
	public slots:
		void mousePressEvent(QGraphicsSceneMouseEvent *c);
};
#endif
