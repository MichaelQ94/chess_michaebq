#include "mainwindow.h"

MainWindow::MainWindow(QApplication *app)
{
	setFixedSize(1000, 800);
	setWindowTitle("Chess");
	
	//Initialize members to be used later
	gwindow = NULL;
	
	//Initialize actions
	quit = new QAction("Quit", this);
	startGame = new QAction("Start Game", this);
	connect(quit, SIGNAL(triggered()), app, SLOT(quit()));
	connect(startGame, SIGNAL(triggered()), this, SLOT(start_game()));
	
	//File menu
	QMenuBar *qmb = menuBar();
	file = new QMenu("File");
	file->addAction(startGame);
	file->addAction(quit);
	qmb->addMenu(file);
	
	toolBar1 = new QToolBar();
	toolBar1->addAction(startGame);
	toolBar1->addAction(quit);
	addToolBar(toolBar1);
}

MainWindow::~MainWindow()
{
	if(gwindow != NULL)
		delete gwindow;
	delete quit;
	delete startGame;
}

void MainWindow::start_game()
{
	if(gwindow != NULL)
		delete gwindow;
	gwindow = new GraphicsWindow();
	setCentralWidget(gwindow->getViewPort());
}
