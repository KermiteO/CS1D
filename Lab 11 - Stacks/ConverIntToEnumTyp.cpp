/*************************************************************************
 * AUTHOR		    : Hamodi & Kermite
 * LAB #11          : Implementing a stack
 * CLASS			: CS 1B
 * DUE DATE		    : 03/10/15
 *************************************************************************/

#include "MyHeader.h"

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
StackMenu ConvertIntToEnumType(int choiceF) // IN & OUT - the comm choice
{

	StackMenu stackChoiceF; //PROC - the stack choice of enum type

	//PROCESSING - converts the integer command into a enum type.
	switch(choiceF)
	{
	case 0: stackChoiceF = EXIT;
			 break;
	case 1: stackChoiceF = PUSH;
			 break;
	case 2: stackChoiceF = POP;
			 break;
	case 3: stackChoiceF = ISEMPTY;
			 break;
	case 4: stackChoiceF = PEEK;
			 break;
	case 5: stackChoiceF = SIZE;
			 break;
	case 6: stackChoiceF = DISPLAY;
			 break;
	default: cout << "INVALID choice!\n";
	}

	return stackChoiceF;
}
