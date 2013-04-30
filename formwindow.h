#ifndef FORMWINDOW_H
#define FORMWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QPushButton>
#include <QPixmap>
#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include <QToolBar>
#include <QLineEdit>
#include <QFormLayout>
#include <QString>

/**Class dedicated to displaying 3 input text boxes for extracting the player's names
 and the time control.*/
class FormWindow : public QWidget
{
	Q_OBJECT
	
	public:
		/**Default constructor. Initializes all text fields and add them to the layout.*/
		FormWindow();
		
		~FormWindow();
		
		/**Accessor used to retrieve the white player's name from the provided QLineEdit text box.*/
		QString getWhiteName();
		
		/**Accessor used to retrieve the black player's name from the provided QLineEdit text box.*/
		QString getBlackName();
		
		/**Accessor used to retrieve the time control from the provided QLineEdit text box.*/
		int getTime();
	private:
		/**Layout used to format the fields*/
		QFormLayout *layout;
		/**Used to retrieve the white player's name*/
		QLineEdit *whiteName;
		/**Used to retrieve the black player's name*/
		QLineEdit *blackName;
		/**Used to retrieve the time control*/
		QLineEdit *time;
};
#endif
