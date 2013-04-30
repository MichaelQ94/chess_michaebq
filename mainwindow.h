#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QPushButton>
#include <QRadioButton>
#include <QPixmap>
#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include <QToolBar>
#include <QLineEdit>
#include <QDockWidget>
#include <QFormLayout>
#include <QGraphicsScene>
#include <QListView>
#include <QStringList>
#include <QStringListModel>
#include <QMessageBox>
#include "graphicswindow.h"
#include "formwindow.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT
	
	private:
		/**The number of moves which has been made*/
		int movecount;
		/**True if the game is paused, false if not*/
		bool paused_;
		/**Stores the last move made by white*/
		QString whiteMove_;
		/**Stores the last move made by white and the last move made by black*/
		QString fullMove_;
		/**A list of strings to be used to display the moves made over the course of the game*/
		QStringList stringlist;
		/**To be used with the leftdockwidget to display the list of moves*/
		QStringListModel *listmodel;
		
		/**GraphicsWindow used to display the board and pieces*/
		GraphicsWindow *gwindow;
		/**Reference to the parent QApplication*/
		QApplication *app;
		
		/**File menu*/
		QMenu *file;
		/**Exits the game*/
		QAction *quit;
		/**Starts the game*/
		QAction *startGame;
		/**Pauses the game*/
		QAction *pause;
		/**Toolbar to hold the buttons*/
		QToolBar *toolBar1;
		
		//forms for names and time control
		FormWindow *forms;
		QDockWidget *userinput;
		
		/**Textbox to output the list of moves*/
		QListView *textbox;
		/**QDockWidget to output the list of moves*/
		QDockWidget *moveList;
		
		
	public:
		MainWindow(QApplication*);
		void printMove(QString move);
		~MainWindow();
		
	public slots:
		void start_game();
		void pause_game();
};
#endif
