/**********************************************************************
 * AUTHOR		: Kermite
 * Ass #5		: Searching Link Lists
 * CLASS		: CS1B
 * SECTION		: TuTh 8:00a - 11:50a
 * DUE DATE		: 3/18/15
 *********************************************************************/

#include "HeaderFile.h"

/**************************************************************************
 * FUNCTION ConvertIntToEnum
 *________________________________________________________________________
 * This function receives a pointer from a command choice from main and
 * will convert it into an enum type. Return -> enum type
 *________________________________________________________________________
 * PRE-CONDITIONS
 * 		choiceF : integer variable that specifies command choice
 * POST-CONDITIONS
 * 		This function will convert an command choice into one of the
 * 		six choices in the enum data type.
 * 		<Post-conditions are the changed outputs either passed
 * 		by value or by reference OR anything affected by the function>
 *************************************************************************/
 CommandMenu ConvertIntToEnumType(int choiceF) // IN & OUT - the comm choice
{

	 CommandMenu menuChoiceF; //PROC - the stack choice of enum type

	//PROCESSING - converts the integer command into a enum type.
	switch(choiceF)
	{
	case 0: menuChoiceF = EXIT;
			 break;
	case 1: menuChoiceF = LIST;
			 break;
	case 2: menuChoiceF = TITLE;
			 break;
	case 3: menuChoiceF = GENRE;
			 break;
	case 4: menuChoiceF = ACTOR;
			 break;
	case 5: menuChoiceF = YEAR;
			 break;
	case 6: menuChoiceF = RATING;
			 break;
	default: cout << "INVALID choice!\n";
	}

	return menuChoiceF;
}
