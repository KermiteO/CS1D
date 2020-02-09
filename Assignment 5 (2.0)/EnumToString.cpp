/**********************************************************************
 * AUTHOR		: Kermite
 * Ass #5		: Searching Link Lists
 * CLASS		: CS1B
 * SECTION		: TuTh 8:00a - 11:50a
 * DUE DATE		: 3/18/15
 *********************************************************************/

#include "HeaderFile.h"

/**************************************************************************
 * FUNCTION ConvertEnumToString
 *________________________________________________________________________
 * This function receives a command choice and will convert the enum
 * command to its corresponding string. Returns -> string
 *________________________________________________________________________
 * PRE-CONDITIONS
 * 		listChoiceF : specifies the command choice
 * POST-CONDITIONS
 * 		This function will convert an enum type into a string.
 *************************************************************************/
string ConvertEnumToString(CommandMenu listChoice) // PROC&OUT - a command choice
{
	string choiceString; // PROC - the corresponding string of an enum type

	// PROC - will assign choiceString to a string depending on what command it's
	switch (listChoice)
	{
	case TITLE : choiceString = "title";
				  break;
	case GENRE :  choiceString = "genre";
				  break;
	case ACTOR : choiceString = "actor";
				  break;
	case YEAR  : choiceString = "year";
				  break;
	case RATING: choiceString = "rating";
				  break;
	}

	return choiceString;
}
