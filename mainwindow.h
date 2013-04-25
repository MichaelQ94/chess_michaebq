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

class MainWindow : public QMainWindow
{
	Q_OBJECT
	
	private:
		//GraphicsWindow *gwindow;
		QApplication *app;
		QMenu *file;
		QAction *quit, *startGame;
		QToolBar *toolBar1;
	
	public:
		MainWindow(QApplication*);
		~MainWindow();
		
	public slots:
		void start_game();
};
#endif
