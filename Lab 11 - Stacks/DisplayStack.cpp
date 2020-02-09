/*************************************************************************
 * AUTHOR		    : Hamodi & Kermite
 * LAB #11          : Implementing a stack
 * CLASS			: CS 1B
 * DUE DATE		    : 03/10/15
 *************************************************************************/

#include "MyHeader.h"

/**************************************************************************
 * FUNCTION DisplayStack
 * _______________________________________________________________________
 * This function receives a pointer called HeadF as a parameter that
 * represents the link list of people. It then takes each node and outputs
 * to the console each person's individual information. Returns -> nothing
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *		headF: the variable representing the link list
 *
 * POST-CONDITIONS
 * 		This function will display the persons found in the link list
 *************************************************************************/
void DisplayStack(personRec *headF) // IN & OUT - the stack of persons
{

	personRec *perPtr; // IN, CALC & OUT - declaring a new pointer

	// INITALIZATION: Initializing pointer to headF
	perPtr  = headF;

	//PROC - will keep displaying person info so long as the end of the
	//link list hasn't been reached.
	while(perPtr != NULL)
	{
		cout << endl;
		cout << setw(LENGTH_SIZE) << setfill('*') << '*' << setfill(' ');
		cout << endl
			 << setw(COL_SIZE2) << "Name:"    << setw(COL_SIZE2)
			 	 	 	 	 	 	 	 	 << perPtr -> name
	         << setw(COL_SIZE2) << "Gender: " << setw(COL_SIZE2)
	         	 	 	 	 	 	 	 	 << perPtr -> gender
			 << setw(COL_SIZE2) << "Age: "    << setw(COL_SIZE2)
			 	 	 	 	 	 	         << perPtr -> age;
		cout << endl;
		cout << setw(LENGTH_SIZE) << setfill('_') << '_' << setfill(' ');
		cout << endl << endl;

		perPtr = perPtr -> next;
	}// END WHILE LOOP
}
