/*************************************************************************
 * AUTHOR		    : Deboogaloo & Kermite
 * LAB #11          : Implementing a Queue
 * CLASS			: CS 1B
 * DUE DATE		    : 03/10/15
 *************************************************************************/

#include "MyHeader.h"

/**************************************************************************
 * FUNCTION DisplayQueue
 *________________________________________________________________________
 * This function will receive a pointer variable representing the link list,
 * and will output all of the people and their info to the console
 * so long as there isn't an empty list. Returns -> nothing
 *________________________________________________________________________
 * PRE-CONDITIONS
 * 		headF : the pointer of the first node in the link list
 * POST-CONDITIONS
 * 		This function will display all the information for each person in
 * 		each node.
 *************************************************************************/
void DisplayQueue(personRec *headF) // IN&OUT - pointer variable representing head
{
	//Constant declarations go here
	const int NAME_W = 30;
	const int GENDER_W = 8;

	personRec *perPtr; // PROC - the pointer pointing to new node
	perPtr = headF;

	//PROC - will output a statement if there is nobody in the list or will
	//		 output all the people in the link list depending on the # of
	//		 people calculated in SizeUser
	if(SizeUser(headF) == 0)
	{
		cout << "\nThere is NOBODY to DISPLAY!\n\n\n";
	}
	else
	{
		cout << left;
		cout << setw(NAME_W) << "NAME" << setw(GENDER_W) << "GENDER" << "AGE"
			 << endl;
		cout << setw(NAME_W) << "----" << setw(GENDER_W) << "------" << "---"
			 << endl;
		//PROC - will keep displaying person info so long as the end of the
		//		 link list isn't reached
		while(perPtr != NULL)
		{
			cout << setw(NAME_W) << perPtr -> name << setw(GENDER_W)
				 << perPtr -> gender << perPtr -> age  << endl;

			perPtr = perPtr -> next;
		}
		cout << endl << endl;
	}
}
