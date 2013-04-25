#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow mainwindow(&a);
	
	mainwindow.show();
	
	return a.exec();
}
