/*************************************************************************
 * AUTHOR		: Kermite & ChickenLips
 * LAB #14      : Intro to OOP
 * CLASS		: CS1B
 * SECTION		: T/TH 8am
 * DUE DATE		: 3/19/15
 *************************************************************************/

#include "header.h"

/**************************************************************************
* FUNCTION SecondMenuOptions
*__________________________________________________________________________
* This function provides a menu of command choices that give you the options
* of initializing the animals, changing the ages or values, or displaying
* all the animals and their info. Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*	none
* POST-CONDITIONS
*  This displays another options menu
**************************************************************************/
void SecondMenuOptions()
{
	cout << "1 - Re-Initialize Sheep\n"
			"2 - Re-Initialize Pigs\n"
			"3 - Change Age\n"
			"4 - Display\n"
			"0 - Exit\n";
}
