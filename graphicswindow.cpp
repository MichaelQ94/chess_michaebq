#include "graphicswindow.h"

GraphicsWindow::GraphicsWindow()
{
	timerCount_ = 0;
	selectedPiece_ = NULL;
	selectedSquare_ = NULL;
	slidingPiece_ = NULL;
	slidingPiece2_ = NULL;
	scene = new QGraphicsScene(this);
	view = new QGraphicsView(scene);
	timer = new QTimer();
	timer->setInterval(2);
	connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
	timer->start();
	
	view->setFixedSize(500, 500);
	
	int width = 60;
	//display the board
	for(int i = 0; i < 64; ++i)
	{
		guisquares_[i] = new GUISquare(this, board_.square(i),
			(width*(i % 8)), (width*(7 - i/8)), width);
			
		if((9 - (9 * i / 8)) % 2 == 0) //light square
		{
			guisquares_[i]->setColor(Qt::white);
		}
		else //dark square
		{
			guisquares_[i]->setColor(Qt::lightGray);
		}
		
		scene->addItem(guisquares_[i]);
	}
	//create the GUIPieces
	for(int i = 0; i < 16; ++i)
	{
		whiteguipieces_[i] = new GUIPiece(board_.whitePiece(i), this);
		scene->addItem(whiteguipieces_[i]);
		blackguipieces_[i] = new GUIPiece(board_.blackPiece(i), this);
		scene->addItem(blackguipieces_[i]);
	}
	//place the GUIPieces on the board
	
	whiteguipieces_[12]->cmove(guisquares_[0]); //white left rook
	whiteguipieces_[8]->cmove(guisquares_[1]); //white left knight
	whiteguipieces_[10]->cmove(guisquares_[2]); //white left bishop
	whiteguipieces_[14]->cmove(guisquares_[3]); //white queen
	whiteguipieces_[15]->cmove(guisquares_[4]); //white king
	whiteguipieces_[11]->cmove(guisquares_[5]); //white right bishop
	whiteguipieces_[9]->cmove(guisquares_[6]); //white right knight
	whiteguipieces_[13]->cmove(guisquares_[7]); //white right rook
	//white pawns
	whiteguipieces_[0]->cmove(guisquares_[8]);
	whiteguipieces_[1]->cmove(guisquares_[9]);
	whiteguipieces_[2]->cmove(guisquares_[10]);
	whiteguipieces_[3]->cmove(guisquares_[11]);
	whiteguipieces_[4]->cmove(guisquares_[12]);
	whiteguipieces_[5]->cmove(guisquares_[13]);
	whiteguipieces_[6]->cmove(guisquares_[14]);
	whiteguipieces_[7]->cmove(guisquares_[15]);
	
	//black pawns
	blackguipieces_[0]->cmove(guisquares_[48]);
	blackguipieces_[1]->cmove(guisquares_[49]);
	blackguipieces_[2]->cmove(guisquares_[50]);
	blackguipieces_[3]->cmove(guisquares_[51]);
	blackguipieces_[4]->cmove(guisquares_[52]);
	blackguipieces_[5]->cmove(guisquares_[53]);
	blackguipieces_[6]->cmove(guisquares_[54]);
	blackguipieces_[7]->cmove(guisquares_[55]);
	
	blackguipieces_[12]->cmove(guisquares_[56]); //black left rook
	blackguipieces_[8]->cmove(guisquares_[57]); //black left knight
	blackguipieces_[10]->cmove(guisquares_[58]); //black left bishop
	blackguipieces_[14]->cmove(guisquares_[59]); //black queen
	blackguipieces_[15]->cmove(guisquares_[60]); //black king
	blackguipieces_[11]->cmove(guisquares_[61]); //black right bishop
	blackguipieces_[9]->cmove(guisquares_[62]); //black right knight
	blackguipieces_[13]->cmove(guisquares_[63]); //black right rook
	
	//reset pieces which have conditions to detect if they have moved
	//since placement on the board requires moving the pieces
	//pawns
	for(int i = 0; i < 8; ++i)
	{
		whiteguipieces_[i]->reset();
		blackguipieces_[i]->reset();
	}
	
	//kings
	whiteguipieces_[15]->reset();
	blackguipieces_[15]->reset();
	
	//rooks
	whiteguipieces_[12]->reset();
	whiteguipieces_[13]->reset();
	blackguipieces_[12]->reset();
	blackguipieces_[13]->reset();
	
	
}

QWidget* GraphicsWindow::getViewPort()
{
	return view->viewport();
}

void GraphicsWindow::highlightSquares(vector<int> squares)
{
	for(unsigned int i = 0; i < squares.size(); ++i)
	{
		guisquares_[squares[i]]->highlight();
	}
}

void GraphicsWindow::dehighlight()
{
	for(int i = 0; i < 64; ++i)
	{
		if(guisquares_[i]->highlighted())
		{
			guisquares_[i]->resetColor();
		}
	}
}

void GraphicsWindow::setSelectedPiece(GUIPiece *gpiece)
{
	selectedPiece_ = gpiece;
}

void GraphicsWindow::setSelectedSquare(GUISquare *gsquare)
{
	selectedSquare_ = gsquare;
}

GUIPiece* GraphicsWindow::selectedPiece()
{
	return selectedPiece_;
}

GUISquare* GraphicsWindow::selectedSquare()
{
	return selectedSquare_;
}

void GraphicsWindow::deselectPiece()
{
	selectedPiece_ = NULL;
}

void GraphicsWindow::deselectSquare()
{
	selectedSquare_ = NULL;
}

void GraphicsWindow::changeTurn()
{
	board_.changeTurn();
}

void GraphicsWindow::capturePiece(GUIPiece *piece)
{
	scene->removeItem(piece);
}

bool GraphicsWindow::whiteToMove()
{
	return board_.whiteToMove();
}

void GraphicsWindow::castleKingSide()
{
	selectedPiece_->move(guisquares_[selectedSquare_->index() + 2]);
	guisquares_[selectedSquare_->index() + 3]->guiPiece()->move(guisquares_[selectedSquare_->index() + 1]);
	selectedPiece_ = NULL;
	selectedSquare_->resetColor();
	selectedSquare_ = NULL;
	changeTurn();
	dehighlight();
}

void GraphicsWindow::castleQueenSide()
{
	selectedPiece_->move(guisquares_[selectedSquare_->index() - 2]);
	guisquares_[selectedSquare_->index() - 4]->guiPiece()->move(guisquares_[selectedSquare_->index() - 1]);
	selectedPiece_ = NULL;
	selectedSquare_->resetColor();
	selectedSquare_ = NULL;
	changeTurn();
	dehighlight();
}

void GraphicsWindow::enPassantCapture(GUISquare* gsquare)
{
	if(selectedPiece_->color() == 'W' && 
		guisquares_[gsquare->index() - 8]->guiPiece() != NULL &&
		guisquares_[gsquare->index() - 8]->guiPiece()->enPassant())
	{
		capturePiece(guisquares_[gsquare->index() - 8]->guiPiece());
		guisquares_[gsquare->index() - 8]->setPiece(NULL);
	}
	else if(selectedPiece_->color() == 'B' &&
		guisquares_[gsquare->index() + 8]->guiPiece() != NULL && 
		guisquares_[gsquare->index() + 8]->guiPiece()->enPassant())
	{
		capturePiece(guisquares_[gsquare->index() + 8]->guiPiece());
		guisquares_[gsquare->index() + 8]->setPiece(NULL);
	}
}

void GraphicsWindow::promote(GUIPiece *gpiece)
{
	gpiece->promote('Q');
}

GUIPiece* GraphicsWindow::slidingPiece()
{
	return slidingPiece_;
}

GUIPiece* GraphicsWindow::slidingPiece2()
{
	return slidingPiece2_;
}

void GraphicsWindow::slidePiece(GUIPiece *piece)
{
	slidingPiece_ = piece;
}

void GraphicsWindow::slidePiece2(GUIPiece *piece)
{
	slidingPiece2_ = piece;
}

void GraphicsWindow::stopSliding()
{
	slidingPiece_ = NULL;
}

void GraphicsWindow::stopSliding2()
{
	slidingPiece2_ = NULL;
}

void GraphicsWindow::handleTimer()
{
	++timerCount_;
	if(slidingPiece_ != NULL)
		slidingPiece_->slide();
	if(slidingPiece2_ != NULL)
		slidingPiece2_->slide();
}

GraphicsWindow::~GraphicsWindow()
{
	for(int i = 0; i < 64; ++i)
	{
		delete guisquares_[i];
	}
	for(int i = 0; i < 16; ++i)
	{
		delete whiteguipieces_[i];
		delete blackguipieces_[i];
	}
	
	delete scene;
	delete view;
}
