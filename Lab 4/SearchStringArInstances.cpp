/**************************************************************************
 * AUTHOR     : Ikrit and Kermite
 * LAB #04    : Intro to arrays
 * CLASS      : CS1B
 * SECTION    : TuTh: 8am
 * DUE DATE   : 02/05/15
 * ***********************************************************************/

#include "Header.h"

/**************************************************************************
 * FUNCTION SearchStringArInstances
 *_________________________________________________________________________
 *	This function searches an array and returns the number of instances
 *_________________________________________________________________________
 *************************************************************************/
void SearchStringArInstances(string stringArF[],
		                     const int AR_SIZEF)
{
	string searchItem;
	int index;
	int instances;

	instances = 0;

	cout << "Who do you want to search for (enter done to exit)? ";
	getline(cin, searchItem);

	while (searchItem != "done")
	{
		for (index = 0; index < AR_SIZEF; index++)
		{
			if (stringArF[index] == searchItem)
			{
				instances++;
			}
		}
		cout << "There are " << instances <<
			    " instances of the name " << searchItem << ".\n\n";

		cout << "Who do you want to search for (enter done to exit)? ";
		getline(cin, searchItem);

		instances = 0;

	}

	cout << "\nThank you for using my program.";
}

