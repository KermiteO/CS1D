/*************************************************************************
 * AUTHOR		    : Hamodi & Kermite
 * LAB #11          : Implementing a stack
 * CLASS			: CS 1B
 * DUE DATE		    : 03/10/15
 *************************************************************************/

#include "MyHeader.h"

/**************************************************************************
 * FUNCTION PopUser
 *________________________________________________________________________
 * This function receives a pointer from main as a parameter. Then,
 * it will find the last input data into the stack/list and it will remove
 * it from the list, but in order for that to happen the list must not be
 * empty. Returns -> a link list of people and their info
 *________________________________________________________________________
 * PRE-CONDITIONS
 * 		headF : pointer of type personRec is passed in as a parameter
 * POST-CONDITIONS
 * 		This function will create a link list of person record that will
 * 		search for different things and will return based on the input
 * 		command.
 * 		<Post-conditions are the changed outputs either passed
 * 		by value or by reference OR anything affected by the function>
 *************************************************************************/
personRec *PopUser(personRec *headF) // IN & OUT - pointer of type personRec
{
	personRec *perPtr; // IN, CALC & OUT - declaring a new pointer

	// Initializing a new pointer to headF.
	perPtr = headF;

	PeekUser(headF);

	// Checks if headF is not at the NULL position
	if(headF != NULL)
	{
		headF = perPtr -> next;
	}
	// END IF - STATEMENT

	// Deallocating the memory of the pointer perPtr.
	delete perPtr;

	return headF;
}
