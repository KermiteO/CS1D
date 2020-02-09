/*************************************************************************
 * AUTHOR		    : Kermite
 * Ass #5           : Searching Link Lists
 * CLASS			: CS 1B
 * DUE DATE		    : 03/16/15
 *************************************************************************/

#include "HeaderFile.h"

/**************************************************************************
 * FUNCTION ConvertIntToStr
 *________________________________________________________________________
 * This function receives a number value from the function call and will
 * convert that number to a string using ostringstream. Returns -> a string
 *________________________________________________________________________
 * PRE-CONDITIONS
 * 		numVal : the integer value that needs to be converted
 * POST-CONDITIONS
 * 		This function will convert an integer value into a string and
 * 		return that string.
 *************************************************************************/
string ConvertIntToStr(int numVal) // IN&PROC - the number value passed in
{
	string stringToInt;
	ostringstream convert;

	//PROC - Stores numVal into ostringstream variable and then uses that variable
	//       to convert numVal into a string(convertInt)
	convert << numVal;

	stringToInt = convert.str();

	return stringToInt;
}



