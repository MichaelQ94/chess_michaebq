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
		
		bool pieceSelected_; //used to detect if a piece has been selected
	
	public:
		GraphicsWindow();
		~GraphicsWindow();
		QWidget* getViewPort();
		
};
#endif
