#ifndef GRAPHICSWINDOW_H
#define GRAPHICSWINDOW_H

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

class GUISquare;

class GraphicsWindow : public QWidget
{
	Q_OBJECT
	
	private:
		GUISquare* squares_[64];
	public:
};
#endif
