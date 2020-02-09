/**********************************************************************
 * AUTHOR(S)	: Kermite & Miss Lame
 * Lab #18		: Date Class
 * CLASS		: CS1B
 * SECTION		: TuTh 8:00a - 11:50a
 * DUE DATE		: 4/28/15
 *********************************************************************/

#include "HeaderFile.h"

/**************************************************************************
* FUNCTION IntegerToString
*__________________________________________________________________________
*
* This function converts an integer to string. Returns a string number.
*__________________________________________________________________________
* PRE-CONDITIONS
* 	num   : num has to be previously defined
*
* POST-CONDITIONS
* RETURNS: string number
*
**************************************************************************/
string IntegerToString(int num) // IN - a number
{
	ostringstream intToStr;
	intToStr << num;

	return intToStr.str();
}
