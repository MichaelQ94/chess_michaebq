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

/**Class used to display the board and handle gameplay*/
class GraphicsWindow;
/**Class used to display a single square on the board*/
class GUISquare;

/**Class used to display a single chess piece and handle movement of chess pieces*/
class GUIPiece : public QGraphicsPixmapItem
{
	
	private:
		/**Refrence to the parent GraphicsWindow*/
		GraphicsWindow *gw_;
		/**Reference to the piece which this GUIPiece represents*/
		ChessPiece *piece_;
		/**Reference to the GUISquare occupied by this piece*/
		GUISquare *gsquare_;
		/**Reference to the piece to be captured by this piece*/
		GUIPiece *pieceToCapture_;
		
		/**x-coordinate of this piece's current position*/
		int x_;
		/**y-coordinate of this piece's current position*/
		int y_;
		/**x-component of this piece's current velocity*/
		int vx_;
		/**y-component of this piece's current velocity*/
		int vy_;
		/**x-coordinate of this piece's destination (used for movement)*/
		int destx;
		/**y-coordinate of this piece's destination (used for movement)*/
		int desty;
	
	public:
		GUIPiece(ChessPiece *piece, GraphicsWindow *gw);
		vector<int> legalMoves();
		void transcribeMove(GUISquare *dest, bool cap);
		void cmove(GUISquare *dest);
		void move(GUISquare *dest);
		void reset();
		int getX();
		int getY();
		char color();
		char type();
		bool enPassant();
		void slide();
		void promote(char type);
	
};
#endif
