/*************************************************************************
 * AUTHOR		: Kermite & Flash Gordon
 * LAB #16      : Inheritance, Overloading, Redefining
 * CLASS		: CS1B
 * SECTION		: T/TH 8am
 * DUE DATE		: 4/21/15
 *************************************************************************/

#include "Sheep.h"
#include "header.h"

/**************************************************************************
 * FUNCTION WoolToString
 *________________________________________________________________________
 * This function receives a WoolType and will convert the enum
 * to its corresponding string. Returns -> string representing WoolType
 *________________________________________________________________________
 * PRE-CONDITIONS
 * 		currentWool : the current wool type as an enum
 * POST-CONDITIONS
 * 		This function will convert a WoolType to a string
 *************************************************************************/
string WoolToString(WoolType currentWool) // IN - WoolType to convert
{
	string woolType; // PROC - the corresponding enum type of a string

	// PROC - will assign currentWool to an enum depending on what the string is

	switch(currentWool)
	{
	case LONG : woolType = "Long";
				 break;
	case MEDIUM : woolType = "Medium";
				 break;
	case FINE : woolType = "Fine";
				 break;
	case CARPET : woolType = "Carpet";
				 break;

	default : woolType = "Invalid Wool Type!";
	}

	return woolType;
}
