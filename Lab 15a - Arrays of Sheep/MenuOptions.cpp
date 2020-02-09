/*************************************************************************
 * AUTHOR		: Kermite & Clover
 * LAB #15      : Arrays & Linked Lists for FarmList
 * CLASS		: CS1B
 * SECTION		: T/TH 8am
 * DUE DATE		: 4/9/15
 *************************************************************************/

#include "header.h"

/**************************************************************************
* FUNCTION MenuOptions
*__________________________________________________________________________
* This function displays the menu of options that give you options to
* modify the list of sheep in different ways.
* Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*	none
* POST-CONDITIONS
*  This function displays the  menu for the sheep list manager
**************************************************************************/
void MenuOptions()
{
	cout << "\nSHEEP LIST MANAGER\n"
			"1 - Add Sheep\n"
			"2 - Output 1st Sheep\n"
			"3 - Find Sheep\n"
			"4 - List Size\n"
			"5 - Output List\n"
			"6 - Clear List\n"
			"0 - Exit\n";
}
