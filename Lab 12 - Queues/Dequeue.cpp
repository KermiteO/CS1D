/*************************************************************************
 * AUTHOR		    : Deboogaloo & Kermite
 * LAB #11          : Implementing a Queue
 * CLASS			: CS 1B
 * DUE DATE		    : 03/10/15
 *************************************************************************/

#include "MyHeader.h"

/**************************************************************************
 * FUNCTION Dequeue
 *________________________________________________________________________
 * This function will receive two pointers; one representing the head
 * of the link list and another that represents the rear of the list. It
 * will take those two pointers and will remove the node found at the
 * front of the link list. Returns -> nothing
 *________________________________________________________________________
 * PRE-CONDITIONS
 * 		headF : the pointer of the first node in the link list
 * 		tailF : the pointer of the last node in the link list
 * POST-CONDITIONS
 * 		This function will remove a node at the front of the link list and
 * 		return a head and a tail by reference.
 * 		<Post-conditions are the changed outputs either passed
 * 		by value or by reference OR anything affected by the function>
 *************************************************************************/
void Dequeue(personRec *&headF, // IN&PROC - pointer variable representing head
		     personRec *&tailF) // IN&PROC - pointer variable representing tail
{
	personRec *perPtr; // PROC - the pointer pointing to new node

	if(IsEmpty(headF))
	{
		cout << "\nCan't DEQUEUE from an empty list!\n\n\n";
	}
	else
	{
		//PROC - makes sure that if there is only one node, tail doesn't
		//		 point past NULL.
		if(SizeUser(headF) == 1)
		{
			tailF = NULL;
		}
		//PROC - assigns perPtr to head, moves head to the next node in
		//		 the list, and deallocate the dangling pointer
		perPtr = headF;

		headF = perPtr -> next;

		delete perPtr;
	}
}
