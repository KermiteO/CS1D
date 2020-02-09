/**********************************************************************
 * AUTHOR		: Omar Kermiche
 * Assignment #1: Functions
 * CLASS		: CS1B
 * SECTION		: MW 8:00a - 11:50a
 * DUE DATE		: 2/3/15
 *********************************************************************/
#include "HeaderFile.h"
/**********************************************************************
 * FUNCTION PrintHeader
 * ___________________________________________________________________
 * This function receives an assignment name, type, and number the
 * outputs the appropriate header - returns nothing
 * ___________________________________________________________________
 * PRE-CONDITIONS
 * 		asName: assignment name has to be previously defined
 * 		asType: assignment type has to be previously defined
 * 		asNum : assignment number has to be previously defined
 *
 * POST-CONDITIONS
 * 		This function will output the class heading.
 * 		<Post-conditions are the changed outputs either passed
 * 		by value or by reference OR anything affected by the function>
 *********************************************************************/

void PrintHeader(string asName, //IN - assignment name
				 char asType,	//IN - assignment type(lab or assignment)
				 int asNum)		//IN - assignment number
{
	//output the class heading to the screen
	cout << left;
	cout << "******************************************************\n";
	cout << "* PROGRAMMED BY" << ": Omar Kermiche\n";
	cout << setw(15) <<"* CLASS" << ": CS1B\n";
	cout << setw(15) <<"* SECTION" << ": TTH 8:00a - 11:50a\n";

	//PROC - This will output "LAB #" or "ASSIGNMENT #" based on the
	//		 asType and adjust the setw accordingly

	if(toupper(asType) == 'L')
	{
		cout << setw(9) << "* LAB #";
	}
	else
	{
		cout << setw(2) << "* ASSIGNMENT #";
	}
	cout << asNum << ": " << asName << endl;
	cout << "******************************************************\n";
	cout << right;
}
