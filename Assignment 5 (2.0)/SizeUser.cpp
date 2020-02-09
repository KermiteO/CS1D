/*************************************************************************
 * AUTHOR		    : Hamodi & Kermite
 * LAB #11          : Implementing a stack
 * CLASS			: CS 1B
 * DUE DATE		    : 03/10/15
 *************************************************************************/

#include "HeaderFile.h"

/**************************************************************************
 * FUNCTION SizeUser
 * _______________________________________________________________________
 *  This function receives a pointer from main as a parameter and it
 *  will then calculate the size of the stack by counting the number of
 *  times a person was added or removed from the list. Return -> integer
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *		headF: the variable representing the link list
 *
 * POST-CONDITIONS
 * 		This function will return the number of people in the link list
 *************************************************************************/
int SizeUser(DvdNode *headF)
{
	int        count;  // CALC & OUT - variable is used to count the number
					   //			   of people in the stack.
	DvdNode *perPtr; // CALC & OUT - pointer of type DvdNode.

	// INITIALIZATION: count and the pointer perPtr will be initialized to 0.
	count  = 0;
	perPtr = headF;

	// This while loop will check whether the pointer is at location NULL
	while(perPtr != NULL)
	{
		count++;
		perPtr = perPtr -> next;
	}// END WHILE

	// Deallocating the memory of the pointer
	perPtr = NULL;

	return count;
}
