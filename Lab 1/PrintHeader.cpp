#include "HeaderFile.h"

/***********************************************************************
 * FUNCTION printHeader
 * This function receives nothing for input returns nothing.
 * _____________________________________________________________________
 * PRE-CONDITIONS
 * 		There as no variable getting passed through
 * POST-CONDITIONS
 * 		This function will output to main the class heading.
 ***********************************************************************/

void PrintHeader()
{
	cout << left;
	cout << "******************************************************\n";
	cout << "* Programmed by" << ": Omar Kermiche\n";
	cout << setw(15) <<"* Student ID" << ": 271406\n";
	cout << setw(15) << "* CS1B" << ": TTH - 8a-10:50a\n";
	cout << setw(15) << "* Lab #1"
		 << ": CS1A Review - Theme Park Day- Planner\n";
	cout << "******************************************************\n";
	cout << right;
}
