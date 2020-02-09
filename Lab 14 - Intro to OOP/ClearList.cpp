/*************************************************************************
 * AUTHOR		    : Kermite & Blue
 * LAB #13          : Creating an Ordered List
 * CLASS			: CS 1B
 * DUE DATE		    : 03/24/15
 *************************************************************************/

#include "MyHeader.h"

/**************************************************************************
 * FUNCTION ClearList
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
void ClearList(personRec *&headF, // IN&PROC - the link list of persons
		  	   personRec *&tailF) // IN&PROC - points to last node
{
	personRec *perPtr; // PROC - the pointer pointing to new node

	if(!(IsEmpty(headF)))
	{
		//Initialize - the tail of link list to NULL and perPtr to headF
		tailF = NULL;
		perPtr = headF;
		//OUT - will output the list of names that are being cleared
		cout << "\nCLEARING LIST:";

		//PROC - as long as not at the end of the link list, keep deleting nodes.
		while(perPtr != NULL)
		{
			cout << "\nRemoving " << perPtr -> name << "!";
			headF = perPtr -> next;
			delete perPtr;
			perPtr = headF;
		}
		cout << endl;
	}
	//OUT - a statement that shows that the list has been cleared
	cout << "\nThe list has been cleared!\n";
}
