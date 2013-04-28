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
		GUISquare *gsquare_;
		int x_, y_;
	
	public:
		GUIPiece(ChessPiece *piece, GraphicsWindow *gw);
		vector<int> legalMoves();
		void move(GUISquare *dest);
		void reset();
		int getX();
		int getY();
		char color();
		char type();
		bool enPassant();
		void promote(char type);
	
};
#endif
