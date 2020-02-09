/*************************************************************************
 * AUTHOR		    : Deboogaloo & Kermite
 * LAB #11          : Implementing a Queue
 * CLASS			: CS 1B
 * DUE DATE		    : 03/10/15
 *************************************************************************/

#include "MyHeader.h"

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
	string convertInt;	  // PROC - a string var that the integer gets con. to
	ostringstream output; // PROC - the ostringstream variable used to convert
						  //		the integer value

	//PROC - Stores numVal into ostringstream variable and then uses that variable
	//       to convert numVal into a string(convertInt)
	output << numVal;

	convertInt = output.str();

	return convertInt;
}



