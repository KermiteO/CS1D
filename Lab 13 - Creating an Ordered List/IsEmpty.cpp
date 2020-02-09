/*************************************************************************
 * AUTHOR		    : Kermite & Blue
 * LAB #13          : Creating an Ordered List
 * CLASS			: CS 1B
 * DUE DATE		    : 03/24/15
 *************************************************************************/

#include "MyHeader.h"

/**************************************************************************
 * FUNCTION IsEmpty
 *________________________________________________________________________
 * This function receives a pointer from main as a parameter that represents
 * the link list of people. Returns -> a boolean that evaluates to true
 * if head is equal to NULL
 *________________________________________________________________________
 * PRE-CONDITIONS
 * 		headF : pointer of type personRec is passed in as a parameter
 * POST-CONDITIONS
 * 		This function will return a boolean that evaluates to true
 * 		if head is equal to NULL.
 * 		<Post-conditions are the changed outputs either passed
 * 		by value or by reference OR anything affected by the function>
 *************************************************************************/
bool IsEmpty(personRec *headF) //IN & PROC - the stack of persons
{
	return headF == NULL;
}
