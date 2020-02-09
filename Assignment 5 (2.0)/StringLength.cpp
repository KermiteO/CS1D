/*************************************************************************
 * AUTHOR		    : Kermite
 * Ass #5           : Searching Link Lists
 * CLASS			: CS 1B
 * DUE DATE		    : 03/16/15
 *************************************************************************/

#include "HeaderFile.h"

/**************************************************************************
 * FUNCTION StringLength
 * _______________________________________________________________________
 * This function receives two strings and returns the necessary length
 * length of the string that will be used to format the error statements so
 * their asterix' line up when displayed on the console, depending on which
 * string is bigger. Returns integer -> returns an integer value
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *		str1 : the first string
 *		str2 : the second string
 * POST-CONDITIONS
 * 		This function return an error size
 *************************************************************************/
int StringLength(string str1, // IN & PROC - the first string
				 string str2) // IN & PROC - the second string
{
	int errSize; // PROC - the size of the error statement

	if(str1.length() <= str2.length())
	{
		errSize = str2.length();
	}
	else
	{
		errSize = str1.length();
	}

	return errSize;
}
