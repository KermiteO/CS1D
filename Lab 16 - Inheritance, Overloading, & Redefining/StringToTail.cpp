/*************************************************************************
 * AUTHOR		: Kermite & Flash Gordon
 * LAB #16      : Inheritance, Overloading, Redefining
 * CLASS		: CS1B
 * SECTION		: T/TH 8am
 * DUE DATE		: 4/21/15
 *************************************************************************/

#include "Pig.h"
#include "header.h"

/**************************************************************************
 * FUNCTION StringToTail
 *________________________________________________________________________
 * This function receives a tail type and will convert the string
 * to its corresponding enum type. Returns -> enum type
 *________________________________________________________________________
 * PRE-CONDITIONS
 * 		currentWool : the current wool type as a string
 * POST-CONDITIONS
 * 		This function will convert a string to an enum type.
 *************************************************************************/
TailType StringToTail(string tailString) // IN - string to convert
{
	TailType newTail; // PROC - the corresponding enum type of a string

	// PROC - will assign currentWool to an enum depending on what the string is
	if(tailString == "Straight")
	{
		newTail = STRAIGHT;
	}
	else if(tailString == "CorkScrew")
	{
		newTail = CORKSCREW;
	}
	else if(tailString == "Curls Up")
	{
		newTail = CURL_UP;
	}
	else if(tailString == "Curls Right")
	{
		newTail = CURL_RIGHT;
	}
	else if(tailString == "Curls Left")
	{
		newTail = CURL_LEFT;
	}

	return newTail;
}
