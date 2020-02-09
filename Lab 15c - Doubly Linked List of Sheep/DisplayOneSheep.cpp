/*************************************************************************
 * AUTHOR		: Kermite & Clover
 * LAB #14      : Arrays & Linked Lists for FarmList
 * CLASS		: CS1B
 * SECTION		: T/TH 8am
 * DUE DATE		: 3/19/15
 *************************************************************************/

#include "header.h"
#include "FarmList.h"
#include "Sheep.h"

/**************************************************************************
* FUNCTION DisplayOneSheep
*__________________________________________________________________________
* This function will display all the info for a single sheep in table
* format. Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*  oneSheep : represents a single sheep found in list
* POST-CONDITIONS
*  Will display a single sheep's info in table format
**************************************************************************/
void DisplayOneSheep(Sheep oneSheep) // PROC&OUT - a specific sheep
{
	cout << left;
	cout << setw(NAME_SPACE + 1) << "NAME" << "AGE\n";
	cout << setfill('-') << setw(NAME_SPACE) << '-'<< " "
		 << setw(AGE_SPACE)  << '-' << setfill(' ')<< ' '
		 << endl;
	cout << setw(NAME_SPACE + 2) << oneSheep.GetName()
		 << oneSheep.GetAge() << endl;
}
