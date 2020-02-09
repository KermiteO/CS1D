/**********************************************************************
 * AUTHOR		: Kermite & DatOwl
 * Lab #8		: Structs
 * CLASS		: CS1B
 * SECTION		: TTH 8:00a - 11:50a
 * DUE DATE		: 2/12/15
 *********************************************************************/

#include "Headerfile.h"

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
int SearchStringArray(const StudentRec getStudent[], //IN - the struct
					  string& inputString,	         //IN - name of input
					  const int AR_SIZE)             //IN - the array size
{
	int index;	//PROC - the index number
	bool found; //PROC - the boolean evaluation of the found name



	index = 0;
	found = false;

	//PROC - loops as long found is false and the index is less than
	//		 array size
	while(!found && index < AR_SIZE)
	{
		if(getStudent[index].getNameAr == inputString)
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

