#ifndef GRAPHICSWINDOW_H
#define GRAPHICSWINDOW_H

#include <string>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QPushButton>
#include <QPixmap>
#include <QGraphicsScene>
#include <QMessageBox>
#include "guisquare.h"
#include "guipiece.h"
#include "chessboard.h"

class GUISquare;
class GUIPiece;

class GraphicsWindow : public QWidget
{
	Q_OBJECT
	
	private:
		ChessBoard board_;
		QGraphicsScene *scene;
		QGraphicsView *view;
		
		GUISquare* guisquares_[64];
		GUIPiece* whiteguipieces_[16];
		GUIPiece* blackguipieces_[16];
		
		GUIPiece* selectedPiece_;
		GUISquare* selectedSquare_;
	
	public:
		GraphicsWindow();
		~GraphicsWindow();
		void setSelectedPiece(GUIPiece* gpiece);
		void setSelectedSquare(GUISquare* gsquare);
		void deselectPiece();
		void deselectSquare();
		GUIPiece* selectedPiece();
		GUISquare* selectedSquare();
		void highlightSquares(vector<int> squares);
		void dehighlight();
		void capturePiece(GUIPiece *piece);
		void changeTurn();
		bool whiteToMove();
		QWidget* getViewPort();
		
};
#endif
