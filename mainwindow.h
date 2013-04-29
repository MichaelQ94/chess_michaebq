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
		int movecount;
		QString whiteMove_, fullMove_;
		QStringList stringlist;
		QStringListModel *listmodel;
		
		GraphicsWindow *gwindow;
		QApplication *app;
		
		//basic game actions
		QMenu *file;
		QAction *quit, *startGame, *pause;
		QToolBar *toolBar1;
		
		//forms for names and time control
		FormWindow *forms;
		QDockWidget *userinput;
		
		//outputting score and movelist
		QListView *textbox;
		QDockWidget *moveList;
		
		//Piece selection during promotion
		QRadioButton *knight, *bishop, *rook, *queen;
		QAction *promote;
	
	public:
		MainWindow(QApplication*);
		void printMove(QString move);
		~MainWindow();
		
	public slots:
		void start_game();
		void pause_game();
};
#endif
