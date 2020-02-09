/**********************************************************************
 * AUTHOR(S)	: Kermite & Miss Lame
 * Lab #18		: Date Class
 * CLASS		: CS1B
 * SECTION		: TuTh 8:00a - 11:50a
 * DUE DATE		: 4/28/15
 *********************************************************************/

#include "HeaderFile.h"

/**************************************************************************
* FUNCTION GetLongestStringLength
*__________________________________________________________________________
* This function will determine which string length is the longest.
*__________________________________________________________________________
* PRE-CONDITIONS
* 	str1   : str1 has to be previously defined
* 	str2   : str2 has to be previously defined
* POST-CONDITIONS
* RETURNS: length of the longest string
**************************************************************************/
int GetLongestStringLength (string str1,  // IN - string one
			                string str2)  // IN - string two
{
	int longestString;
	int str1Length;
	int str2Length;

	str1Length = str1.length();
	str2Length = str2.length();

	if(str1Length > str2Length)
	{
		longestString = str1.length();
	}
	else if (str2Length > str1Length)
	{
		longestString = str2.length();
	}
	else
	{
		longestString = str1Length;
	}

	return longestString;

}
