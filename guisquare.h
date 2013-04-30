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
#include <QString>
#include "graphicswindow.h"
#include "guipiece.h"
#include "chessboardsquare.h"

/**Class used to display the board and pieces*/
class GraphicsWindow;
/**Class used to display the chess pieces*/
class GUIPiece;

/**Class used to represent a single board square and handle user input via clicking*/
class GUISquare : public QGraphicsRectItem
{	
	private:
		/**Reference to the parent GraphicsWindow*/
		GraphicsWindow *gw_;
		/**Reference to the piece occupying this square*/
		GUIPiece *gpiece_;
		/**Reference to the ChessBoardSquare represented by this GUISquare*/
		ChessBoardSquare *square_;
		/**The "natural" color of this square (either white or gray)*/
		Qt::GlobalColor color_;
		/**The x-coordinate of this square*/
		int x_;
		/**The y-coordinate of this square*/
		int y_;
		/**True if this square is highlighted, false if not*/
		bool highlighted_;
		/**Prints the coordinates of this square in algebraic chess notation*/
		QString coordinates_;
	
	public:
		GUISquare(GraphicsWindow*, ChessBoardSquare*, int x, int y, int w);
		QString getCoordinates();
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
