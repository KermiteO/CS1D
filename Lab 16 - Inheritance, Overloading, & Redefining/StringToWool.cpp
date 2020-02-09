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
 * FUNCTION StringToWool
 *________________________________________________________________________
 * This function receives a wool type and will convert the string
 * to its corresponding enum type. Returns -> enum type
 *________________________________________________________________________
 * PRE-CONDITIONS
 * 		currentWool : the current wool type as a string
 * POST-CONDITIONS
 * 		This function will convert a string to an enum type.
 *************************************************************************/
WoolType StringToWool(string currentWool) // PROC&OUT - a command choice
{
	WoolType wool; // PROC - the corresponding enum type of a string

	// PROC - will assign currentWool to an enum depending on what the string is
	if(currentWool == "Long")
	{
		wool = LONG;
	}
	else if(currentWool == "Medium")
	{
		wool = MEDIUM;
	}
	else if(currentWool == "Fine")
	{
		wool = FINE;
	}
	else if(currentWool == "Carpet")
	{
		wool = CARPET;
	}


	return wool;
}
