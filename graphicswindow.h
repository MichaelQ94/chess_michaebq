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
#include <QGraphicsSimpleTextItem>
#include <QGraphicsScene>
#include <QMessageBox>
#include <QString>
#include "guisquare.h"
#include "guipiece.h"
#include "chessboard.h"
#include "mainwindow.h"

class MainWindow;
class GUISquare;
class GUIPiece;

class GraphicsWindow : public QWidget
{
	Q_OBJECT
	
	private:
		MainWindow *mw_;
		ChessBoard board_;
		QGraphicsScene *scene;
		QGraphicsView *view;
		QTimer *timer;
		int timerCount_;
		QString move_;
		
		GUISquare* guisquares_[64];
		GUIPiece* whiteguipieces_[16];
		GUIPiece* blackguipieces_[16];
		
		GUIPiece* selectedPiece_;
		GUISquare* selectedSquare_;
		GUIPiece* slidingPiece_;
		GUIPiece* slidingPiece2_;//used only for sliding 2 pieces at a time (castling)
		
		QGraphicsSimpleTextItem *whiteName_, *whiteScore_, *whiteRemaining_, *whiteTime_;
		QGraphicsSimpleTextItem *blackName_, *blackScore_, *blackRemaining_, *blackTime_;
	
	public:
		GraphicsWindow(MainWindow *main, QString whiteName, QString blackName, int time);
		~GraphicsWindow();
		void setMove(QString move);
		QString getMove();
		void setSelectedPiece(GUIPiece* gpiece);
		void setSelectedSquare(GUISquare* gsquare);
		void deselectPiece();
		void deselectSquare();
		GUIPiece* selectedPiece();
		GUISquare* selectedSquare();
		GUIPiece* slidingPiece();
		GUIPiece* slidingPiece2();
		void slidePiece(GUIPiece *piece);
		void slidePiece2(GUIPiece *piece);
		void stopSliding();
		void stopSliding2();
		void highlightSquares(vector<int> squares);
		void dehighlight();
		void capturePiece(GUIPiece *piece);
		void changeTurn();
		bool whiteToMove();
		void castleKingSide();
		void castleQueenSide();
		void enPassantCapture(GUISquare* gsquare);
		void promote(GUIPiece* gpiece);
		QWidget* getViewPort();
		
	public slots:
		void handleTimer();	
};
#endif
