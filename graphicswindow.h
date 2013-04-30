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

/**Handles the window of the game*/
class MainWindow;
/**Class to represent a single graphical square*/
class GUISquare;
/**Class used to represent graphical pieces*/
class GUIPiece;

/**Class used to display the board and pieces*/
class GraphicsWindow : public QWidget
{
	Q_OBJECT
	
	private:
		/**Reference to the parent mainwindow*/
		MainWindow *mw_;
		/**The board used to represent the game*/
		ChessBoard board_;
		/**Used to display the board*/
		QGraphicsScene *scene;
		/**Used to display the board*/
		QGraphicsView *view;
		/**Used to keep the time of the game*/
		QTimer *timer;
		/**Used to count the seconds*/
		int timerCount_;
		/**Used to keep track of the total time elapsed in seconds*/
		int totalTime_;
		
		/**White's second counter*/
		int whiteSec_;
		/**Whites minute counter*/
		int whiteMin_;
		/**Black's second counter*/
		int blackSec_;
		/**Black's second counter*/
		int blackMin_;
		/**Set to 1 if there is no time control, set to -1 if there is a time control*/
		int increment_;
		/**Used to write the move in algebraic chess notation*/
		QString move_;
		/**Set to true when the game has ended via checkmate, stalemate, or time out*/
		bool gameOver_;
		/**Stores the character when handling promotion*/
		char promoteChar_;
		
		/**Stores each GUISquare*/
		GUISquare* guisquares_[64];
		/**Stores all white pieces*/
		GUIPiece* whiteguipieces_[16];
		/**Stores all black pieces*/
		GUIPiece* blackguipieces_[16];
		
		/**The currently selected piece, used when making moves*/
		GUIPiece* selectedPiece_;
		/**The currently selected square, used when making moves*/
		GUISquare* selectedSquare_;
		/**The piece to be moved*/
		GUIPiece* slidingPiece_;
		/**The second piece to be moved, only used during when castling*/
		GUIPiece* slidingPiece2_;//used only for sliding 2 pieces at a time (castling)
		
		/**Used to display the white player's name*/
		QGraphicsSimpleTextItem *whiteName_;
		/**Used to display the white player's score*/
		QGraphicsSimpleTextItem *whiteScore_;
		/**Used to display the white player's remaining score*/
		QGraphicsSimpleTextItem *whiteRemaining_;
		/**Used to display the white player's time*/
		QGraphicsSimpleTextItem *whiteTime_;
		/**Used to display the black player's name*/
		QGraphicsSimpleTextItem *blackName_;
		/**Used to display the black player's score*/
		QGraphicsSimpleTextItem *blackScore_;
		/**Used to display the black player's remaining score*/
		QGraphicsSimpleTextItem *blackRemaining_;
		/**Used to display the black player's time*/
		QGraphicsSimpleTextItem *blackTime_;
	
	public:
		GraphicsWindow(MainWindow *main, QString whiteName, QString blackName, int time);
		~GraphicsWindow();
		void startGame();
		void pauseGame();
		void endGame();
		bool gameInProgress();
		QString timeToString(int time);
		void incrementTime();
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
		void promoteN();
		void promoteB();
		void promoteR();
		void promoteQ();	
};
#endif
