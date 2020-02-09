/*************************************************************************
 * AUTHOR		    : Kermite & Blue
 * LAB #13          : Creating an Ordered List
 * CLASS			: CS 1B
 * DUE DATE		    : 03/24/15
 *************************************************************************/

#include "MyHeader.h"

/**************************************************************************
 * FUNCTION ConvertIntToEnumType
 *________________________________________________________________________
 * This function receives a pointer from a command choice from main and
 * will convert it into an enum type. Return -> enum type
 *________________________________________________________________________
 * PRE-CONDITIONS
 * 		choiceF : integer variable that specifies command choice
 * POST-CONDITIONS
 * 		This function will convert an command choice into one of the
 * 		six choices in the enum data type.
 *************************************************************************/
ListMenu ConvertIntToEnumType(int choiceF) // IN & OUT - the comm choice
{

	ListMenu listChoiceF; //PROC - the stack choice of enum type

	//PROCESSING - converts the integer command into a enum type.
	switch(choiceF)
	{
	case 0: listChoiceF = EXIT;
			 break;
	case 1: listChoiceF = CREATE;
			 break;
	case 2: listChoiceF = DISPLAY;
			 break;
	case 3: listChoiceF = DISPLAYREV;
			 break;
	case 4: listChoiceF = ISEMPTY;
			 break;
	case 5: listChoiceF = SEARCH;
			 break;
	case 6: listChoiceF = REMOVE;
			 break;
	case 7: listChoiceF = CLEAR;
			 break;
	default: cout << "INVALID choice!\n";
	}

	return listChoiceF;
}
