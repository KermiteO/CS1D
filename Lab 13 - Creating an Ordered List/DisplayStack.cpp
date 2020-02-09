/*************************************************************************
 * AUTHOR		    : Kermite & Blue
 * LAB #13          : Creating an Ordered List
 * CLASS			: CS 1B
 * DUE DATE		    : 03/24/15
 *************************************************************************/

#include "MyHeader.h"

/**************************************************************************
 * FUNCTION DisplayList
 *________________________________________________________________________
 * This function will receive a pointer variable representing the link list,
 * and will output all of the people and their info to the console
 * so long as there isn't an empty list. Returns -> nothing
 *________________________________________________________________________
 * PRE-CONDITIONS
 * 		headF : a link list
 * POST-CONDITIONS
 * 		This function will display all the information for each person in
 * 		each node.
 *************************************************************************/
void DisplayList(personRec *&headF) // IN&OUT - pointer variable representing head
{
	//Constant declarations go here
	const int GENDER_W = 30;
	const int NAME_W = 8;
	const int NUM_W = 5;
	const int AGE_W = 6;

	//Variable declarations go here
	personRec *perPtr; // PROC&OUT - the pointer pointing to new node
	int nodeNum;	   // PROC&OUT - the number of a node within a list

    // ASSIGNS - the first # of node and the pointer variable to the link list
	nodeNum = 1;
	perPtr = headF;

	//PROC - will output a statement if there is nobody in the list or will
	//		 output all the people in the link list depending on the # of
	//		 people calculated in SizeUser
	if(IsEmpty(headF))
	{
		cout << "\nCan't display from an empty list\n";
	}
	else
	{
/*************************************************************************
 OUTPUT - will output to the console all the names of the people stored
 	 	  in the link list in alphabetical order
**************************************************************************/
		cout << right << endl;
		cout << setw(4) << "#" << setw(NAME_W) << "NAME" << setw(29)
			 << "GENDER" << setw(AGE_W) << "AGE" << endl;
		cout << left;
		cout << setw(7) << setfill('-') << '-' << setfill(' ') << " " << setw(25)
			 << setfill('-') << '-' << setfill(' ') << " " << setw(NAME_W)
			 << setfill('-') << '-' << setfill(' ') << " " << setw(NUM_W)
			 << setfill('-') << '-' << setfill(' ') << endl;
		//PROC - will keep displaying person info so long as the end of the
		//		 link list isn't reached
		while(perPtr != NULL)
		{
			// PROC - assigns 2 or three spaces before nodeNum depending on digits
			if(nodeNum < 10)
			{
				cout << setw(3) << setfill(' ')  << ' ' << setw(5);
			}
			else
			{
				cout << setw(2)<< setfill(' ')  << ' ' << setw(AGE_W);
			}
			cout << nodeNum
				 << setw(GENDER_W)<< perPtr -> name << setw(7) << perPtr -> gender
				 << perPtr -> age << endl;

			//Update the lcv & increment the node number
			perPtr = perPtr -> next;
			nodeNum++;
		}
	}
}
