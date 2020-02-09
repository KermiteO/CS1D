/**************************************************************************
 * AUTHOR     : Ikrit and Kermite
 * LAB #04    : Intro to arrays
 * CLASS      : CS1B
 * SECTION    : TuTh: 8am
 * DUE DATE   : 02/05/15
 * ***********************************************************************/

#include "Header.h"

/**************************************************************************
 * FUNCTION GetStringAr
 *_________________________________________________________________________
 *	This function receives string input from the user
 *	and stores them into an array
 *_________________________________________________________________________
 *************************************************************************/
void GetStringAr(string stringArF[], const int AR_SIZEF, string stringType)
{
	int index;

	for (index = 0; index < AR_SIZEF; index++)
	{
		cout << "Enter " << stringType << " #" << index + 1 << ": ";
		getline(cin, stringArF[index]);
	}

}

