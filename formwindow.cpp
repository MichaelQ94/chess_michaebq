#include "formwindow.h"

/**Default Constructor.
 * Initializes each QLineEdit object to a new object, allowing the user to input the intial board size,
 * number of initial moves, and seed value.
 */
FormWindow::FormWindow()
{
	layout = new QFormLayout();
	setLayout(layout);
	whiteName = new QLineEdit();
	blackName = new QLineEdit();
	time = new QLineEdit();
	layout->addRow("White Player Name:", whiteName);
	layout->addRow("Black Player Name:", blackName);
	layout->addRow("Time Control (minutes):", time);
}

/**Destructor. Deletes all memory which was dynamically allocated with 'new.'
 */
FormWindow::~FormWindow()
{
	delete whiteName;
	delete blackName;
	delete time;
	delete layout;
}

QString FormWindow::getWhiteName()
{
	return whiteName->text();
}

QString FormWindow::getBlackName()
{
	return blackName->text();
}

int FormWindow::getTime()
{
	if(time->text() == "0" || time->text().isEmpty())
		return 0;
	else if(time->text().toInt() > 0)
		return time->text().toInt();
	else
		return -1;
}
