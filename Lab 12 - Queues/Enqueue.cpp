/*************************************************************************
 * AUTHOR		    : Deboogaloo & Kermite
 * LAB #11          : Implementing a Queue
 * CLASS			: CS 1B
 * DUE DATE		    : 03/10/15
 *************************************************************************/

#include "MyHeader.h"

/**************************************************************************
 * FUNCTION Enqueue
 *________________________________________________________________________
 * This function will receive two pointers; one representing the head
 * of the link list and another that represents the rear of the list. It
 * will take those two pointers and will create a new node and incorporate
 * a new person's info into that new node and then add that node to the
 * end of the link list. Returns -> nothing
 *________________________________________________________________________
 * PRE-CONDITIONS
 * 		headF : the pointer of the first node in the link list
 * 		tailF : the pointer of the last node in the link list
 * POST-CONDITIONS
 * 		This function will add a new node to the link list and return a head
 * 		and a tail by reference.
 *************************************************************************/
void Enqueue(personRec *&headF, // IN&PROC - pointer variable representing head
			 personRec *&tailF) // IN&PROC - pointer variable representing tail
{
	personRec *perPtr; // PROC - the pointer pointing to new node

	perPtr = new personRec;

	// PROC - call the function that gets the input
	GetInput(perPtr);

	//Assigns perPtr -> next to NULL
	perPtr -> next = NULL;

	//PROC - Condition that sets the head to the new node which is pointing to NULL
	//if the list is empty, but if it's not empty, then the tail gets moved
	//to the new node.
	if(IsEmpty(headF))
	{
		headF = perPtr;
	}
	else
	{
		tailF -> next = perPtr;
	}
	//PROC - once one of the conditions for the if statement is met, then
	//		 tail gets assigned to the new node and perPtr gets deallocated.
	tailF = perPtr;
	perPtr = NULL;
}
