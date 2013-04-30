#include "mainwindow.h"

/**Constructor. Initializes window size and menu buttons.
*/
MainWindow::MainWindow(QApplication *app)
{
	paused_ = false;
	setFixedSize(800, 740);
	setWindowTitle("Chess");
	listmodel = NULL;
	movecount = 1;
	
	//Initialize members to be used later
	gwindow = NULL;
	
	//Initialize actions
	quit = new QAction("Quit", this);
	startGame = new QAction("Start Game", this);
	pause = new QAction("Pause", this);
	connect(quit, SIGNAL(triggered()), app, SLOT(quit()));
	connect(startGame, SIGNAL(triggered()), this, SLOT(start_game()));
	connect(pause, SIGNAL(triggered()), this, SLOT(pause_game()));
	
	//File menu
	QMenuBar *qmb = menuBar();
	file = new QMenu("File");
	file->addAction(startGame);
	file->addAction(pause);
	file->addAction(quit);
	qmb->addMenu(file);
	
	//first toolbar
	toolBar1 = new QToolBar();
	toolBar1->addAction(startGame);
	toolBar1->addAction(pause);
	toolBar1->addAction(quit);
	addToolBar(toolBar1);
	
	//Text fields for game initialization
	forms = new FormWindow();
	userinput = new QDockWidget();
	userinput->setWidget(forms);
	userinput->setFixedSize(800, 120);
	addDockWidget(Qt::TopDockWidgetArea, userinput);
	userinput->setFeatures(QDockWidget::NoDockWidgetFeatures);
	
	textbox = new QListView();
	moveList = new QDockWidget();
	moveList->setWidget(textbox);
	moveList->setFixedSize(250, 480);
	moveList->setFeatures(QDockWidget::NoDockWidgetFeatures);
}

/**Destructor. Deletes all memory allocated using 'new'*/
MainWindow::~MainWindow()
{
	if(gwindow != NULL)
		delete gwindow;
	delete quit;
	delete pause;
	delete startGame;
	
	delete file;
	delete toolBar1;
	
	delete forms;
	delete userinput;
	
	delete textbox;
	delete moveList;
}

/**Starts the game and displays the board*/
void MainWindow::start_game()
{
	paused_ = false;
	QString whiteName = forms->getWhiteName();
	QString blackName = forms->getBlackName();
	int time = forms->getTime();
	
	if(whiteName.isEmpty())
	{
		QMessageBox errorMessage;
		errorMessage.setText("Please enter the white player's name.");
		errorMessage.exec();
		return;
	}
	
	if(blackName.isEmpty())
	{
		QMessageBox errorMessage;
		errorMessage.setText("Please enter the black player's name.");
		errorMessage.exec();
		return;
	}
	
	if(time == -1)
	{
		QMessageBox errorMessage;
		errorMessage.setText("Please enter a positive integer for the time control (or 0 for no time control).");
		errorMessage.exec();
		return;
	}
	
	if(gwindow != NULL)
		delete gwindow;
	gwindow = new GraphicsWindow(this, whiteName, blackName, time);
	setCentralWidget(gwindow->getViewPort());
	addDockWidget(Qt::RightDockWidgetArea, moveList);
	textbox->setModel(NULL); //clear the text box
}

/**Pauses the game timer and hides the board*/
void MainWindow::pause_game()
{
	if(gwindow != NULL)
	{
		if(paused_)
		{
			gwindow->startGame();
			pause->setText("Pause");
			paused_ = false;
		}
		else
		{
			gwindow->pauseGame();
			pause->setText("Unpause");
			paused_ = true;
		}
	}
}

/**Prints the last move made to the list of moves
 * @param move_ The move to be printed
 */
void MainWindow::printMove(QString move_)
{
	if(listmodel != NULL)
	{
		textbox->setModel(NULL);
		delete listmodel;
	}
	if(whiteMove_.isEmpty())
	{
		whiteMove_ = move_;
		stringlist.append(QString(QString::number(movecount) + ".  " + whiteMove_));
	}
	else
	{
		stringlist.removeLast();
		fullMove_ = whiteMove_;
		for(int i = 0; i < 20 - whiteMove_.length(); ++i)
		{
			fullMove_ += " ";
		}
		fullMove_ += move_;
		stringlist.append(QString(QString::number(movecount) + ".  " +  fullMove_));
		++movecount;
		fullMove_.clear();
		whiteMove_.clear();
	}
	listmodel = new QStringListModel(stringlist);
	textbox->setModel(listmodel);
}
