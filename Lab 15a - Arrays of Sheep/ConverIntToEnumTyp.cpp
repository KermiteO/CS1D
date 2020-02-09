/*************************************************************************
 * AUTHOR		: Kermite & Clover
 * LAB #15      : Arrays & Linked Lists for FarmList
 * CLASS		: CS1B
 * SECTION		: T/TH 8am
 * DUE DATE		: 4/9/15
 *************************************************************************/

#include "header.h"

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
SheepMenu ConvertIntToEnumType(int choiceF) // IN & OUT - the comm choice
{

	SheepMenu listChoiceF; //PROC - the stack choice of enum type

	//PROCESSING - converts the integer command into a enum type.
	switch(choiceF)
	{
	case 0: listChoiceF = EXIT;
			 break;
	case 1: listChoiceF = ADDSHEEP;
			 break;
	case 2: listChoiceF = OUTPUTFIRST;
			 break;
	case 3: listChoiceF = FINDSHEEP;
			 break;
	case 4: listChoiceF = LISTSIZE;
			 break;
	case 5: listChoiceF = OUTPUTLIST;
			 break;
	case 6: listChoiceF = CLEARLIST;
			 break;
	default: cout << "INVALID choice!\n";
	}
	return listChoiceF;
}
