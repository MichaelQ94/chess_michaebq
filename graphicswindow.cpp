#include "graphicswindow.h"

GraphicsWindow::GraphicsWindow()
{
	selectedPiece_ = NULL;
	selectedSquare_ = NULL;
	scene = new QGraphicsScene(this);
	view = new QGraphicsView(scene);
	
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
	
	whiteguipieces_[12]->move(guisquares_[0]); //white left rook
	whiteguipieces_[8]->move(guisquares_[1]); //white left knight
	whiteguipieces_[10]->move(guisquares_[2]); //white left bishop
	whiteguipieces_[14]->move(guisquares_[3]); //white queen
	whiteguipieces_[15]->move(guisquares_[4]); //white king
	whiteguipieces_[11]->move(guisquares_[5]); //white right bishop
	whiteguipieces_[9]->move(guisquares_[6]); //white right knight
	whiteguipieces_[13]->move(guisquares_[7]); //white right rook
	//white pawns
	whiteguipieces_[0]->move(guisquares_[8]);
	whiteguipieces_[1]->move(guisquares_[9]);
	whiteguipieces_[2]->move(guisquares_[10]);
	whiteguipieces_[3]->move(guisquares_[11]);
	whiteguipieces_[4]->move(guisquares_[12]);
	whiteguipieces_[5]->move(guisquares_[13]);
	whiteguipieces_[6]->move(guisquares_[14]);
	whiteguipieces_[7]->move(guisquares_[15]);
	
	//black pawns
	blackguipieces_[0]->move(guisquares_[48]);
	blackguipieces_[1]->move(guisquares_[49]);
	blackguipieces_[2]->move(guisquares_[50]);
	blackguipieces_[3]->move(guisquares_[51]);
	blackguipieces_[4]->move(guisquares_[52]);
	blackguipieces_[5]->move(guisquares_[53]);
	blackguipieces_[6]->move(guisquares_[54]);
	blackguipieces_[7]->move(guisquares_[55]);
	
	blackguipieces_[12]->move(guisquares_[56]); //black left rook
	blackguipieces_[8]->move(guisquares_[57]); //black left knight
	blackguipieces_[10]->move(guisquares_[58]); //black left bishop
	blackguipieces_[14]->move(guisquares_[59]); //black queen
	blackguipieces_[15]->move(guisquares_[60]); //black king
	blackguipieces_[11]->move(guisquares_[61]); //black right bishop
	blackguipieces_[9]->move(guisquares_[62]); //black right knight
	blackguipieces_[13]->move(guisquares_[63]); //black right rook
	
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
