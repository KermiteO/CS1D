/*************************************************************************
 * AUTHOR		    : Deboogaloo & Kermite
 * LAB #11          : Implementing a Queue
 * CLASS			: CS 1B
 * DUE DATE		    : 03/10/15
 *************************************************************************/

#include "MyHeader.h"

/**************************************************************************
 * FUNCTION ClearQueue
 *________________________________________________________________________
 * This function will receive two pointers; one representing the head
 * of the link list and another that represents the rear of the list. It
 * will take those two pointers and will remove all the nodes found in
 * the link list. Returns -> nothing
 *________________________________________________________________________
 * PRE-CONDITIONS
 * 		headF : the pointer of the first node in the link list
 * 		tailF : the pointer of the last node in the link list
 * POST-CONDITIONS
 * 		This function will remove all the nodes in the link list and return
 * 		the head and tail back to calling function by reference.
 *************************************************************************/
void ClearQueue(personRec *&headF, // IN&PROC - pointer variable representing head
		 	 	personRec *&tailF) // IN&PROC - pointer variable representing tail
{
	personRec *perPtr; // PROC - the pointer pointing to new node

	if(SizeUser(headF) == 0)
	{
		cout << "\nThe QUEUE is ALREADY clear!\n\n\n";
	}
	else
	{
		//Initialize - the tail of link list to NULL and perPtr to headF
		tailF = NULL;
		perPtr = headF;
		//PROC - as long as not at the end of the link list, keep deleting nodes.
		while(perPtr != NULL)
		{
			cout << perPtr -> name << endl;
			headF = perPtr -> next;
			delete perPtr;
			perPtr = headF;
		}

		cout << "\nThe queue has been CLEARED!\n\n\n";
	}
}
