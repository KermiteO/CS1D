/*************************************************************************
 * AUTHOR		    : Deboogaloo & Kermite
 * LAB #11          : Implementing a Queue
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
QueueMenu ConvertIntToEnumType(int choiceF) // IN & OUT - the comm choice
{

	QueueMenu queueChoiceF; //PROC - the stack choice of enum type

	//PROCESSING - converts the integer command into a enum type.
	switch(choiceF)
	{
	case 0: queueChoiceF = EXIT;
			 break;
	case 1: queueChoiceF = ENQUEUE;
			 break;
	case 2: queueChoiceF = DEQUEUE;
			 break;
	case 3: queueChoiceF = ISEMPTY;
			 break;
	case 4: queueChoiceF = FRONT;
			 break;
	case 5: queueChoiceF = SIZE;
			 break;
	case 6: queueChoiceF = DISPLAY;
			 break;
	case 7: queueChoiceF = CLEAR;
			 break;
	default: cout << "INVALID choice!\n";
	}

	return queueChoiceF;
}
