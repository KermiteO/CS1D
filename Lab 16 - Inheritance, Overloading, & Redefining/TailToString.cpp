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
 * FUNCTION TailToString
 *________________________________________________________________________
 * This function receives a TailType and will convert the enum
 * to its corresponding string. Returns -> string representing TailType
 *________________________________________________________________________
 * PRE-CONDITIONS
 * 		currentWool : the current tail type as an enum
 * POST-CONDITIONS
 * 		This function will convert a TailType to a string
 *************************************************************************/
string TailToString(TailType tailType) // IN - TailType to convert
{
	string tailString; // PROC - the corresponding enum type of a string

	// PROC - will assign currentWool to an enum depending on what the string is
	switch(tailType)
	{
	case STRAIGHT  : tailString = "Straight";
					 break;
	case CORKSCREW : tailString = "CorkScrew";
				  	 break;
	case CURL_UP   : tailString = "Curls Up";
					 break;
	case CURL_RIGHT: tailString = "Curls Right";
				  	 break;
	case CURL_LEFT : tailString = "Curls Left";
				  	 break;
	default : tailString = "Invalid Tail Type!";
	}

	return tailString;
}
