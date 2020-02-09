/**********************************************************************
 * AUTHOR		: Kermite
 * Ass #5		: Searching Link Lists
 * CLASS		: CS1B
 * SECTION		: TuTh 8:00a - 11:50a
 * DUE DATE		: 3/24/15
 *********************************************************************/

#include "HeaderFile.h"

/**************************************************************************
 * FUNCTION OutputMenu
 * _______________________________________________________________________
 * This function will only be specified to only output the menu to the console
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
	cout << "DVD MENU OPTIONS\n\n";
	cout << "1- Output Entire List\n"
			"2- Title Search\n"
			"3- Genre Search\n"
			"4- Actor Search\n"
			"5- Year Search\n"
			"6- Rating Search (0-9)\n"
			"0- EXIT\n";
	cout << right;
}
