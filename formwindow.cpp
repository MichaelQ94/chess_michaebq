#include "formwindow.h"

/**Default Constructor.
 * Initializes each QLineEdit object to a new object, allowing the user input their names and the time
 * control.
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

/**Extracts the white player's name from the QLineEdit
 * @return The white player's name
 */
QString FormWindow::getWhiteName()
{
	return whiteName->text();
}

/**Extracts the black player's name from the QLineEdit
 * @return The black player's name
 */
QString FormWindow::getBlackName()
{
	return blackName->text();
}

/**Extracts the time control from the QLineEdit
 * @return Returns the number if a proper, positive value was entered, returns -1 if not
 */
int FormWindow::getTime()
{
	if(time->text() == "0" || time->text().isEmpty())
		return 0;
	else if(time->text().toInt() > 0)
		return time->text().toInt();
	else
		return -1;
}
