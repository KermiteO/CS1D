/*************************************************************************
 * AUTHOR		    : Kermite & Blue
 * LAB #13          : Creating an Ordered List
 * CLASS			: CS 1B
 * DUE DATE		    : 03/24/15
 *************************************************************************/

#include "MyHeader.h"

/**************************************************************************
 * FUNCTION OutputMenu
 * _______________________________________________________________________
 * This function will only be specified to only output the menu to the user
 * so the user can select the desired command. Return -> nothing
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *		none
 * POST-CONDITIONS
 * 		This function output the menu of command choice tasks.
 *************************************************************************/
void OutputMenu()
{
	cout << left;
	cout << "LIST MENU:\n";
	cout << "1- Create List\n"
			"2- Display List\n"
			"3- Display List in Reverse Order\n"
			"4- Is the list empty?\n"
			"5- Search by name\n"
			"6- Remove Node\n"
			"7- Clear List\n"
			"0- to Exit\n";
	cout << right;
}
