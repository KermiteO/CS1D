/**********************************************************************
 * AUTHOR		: Kermite
 * Assignment #2: Parallel Arrays
 * CLASS		: CS1B
 * SECTION		: MW 8:00a - 11:50a
 * DUE DATE		: 2/9/15
 *********************************************************************/

#include "headerfile.h"

/***********************************************************************
 * FUNCTION SearchStringArray
 * This function receives a name, a string array, and an array size, and
 * returns an index number.
 * _____________________________________________________________________
 * PRE-CONDITIONS
 * 		getName    : the name of the person entered
 * 		STRING_AR[]: the array that specifies a particular name
 * 		AR_SIZE    : the array size constant
 * POST-CONDITIONS
 * 		This function will return an index number
 ***********************************************************************/
int SearchStringArray(string getName,	       //IN - the name of the being
					  const string STRING_AR[],//IN - array for the names
					  const int AR_SIZE)       //IN - the array size
{
	int index;	//PROC - the index number
	bool found; //PROC - the boolean evaluation of the found name

	index = 0;
	found = false;

	while(!found && index < AR_SIZE)
	{
		if(getName == STRING_AR[index])
		{
			found = true;
		}
		else
		{
			index++;
		}
	}
	return index;
}

