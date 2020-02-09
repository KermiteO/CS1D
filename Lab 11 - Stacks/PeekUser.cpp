/*************************************************************************
 * AUTHOR		    : Hamodi & Kermite
 * LAB #11          : Implementing a stack
 * CLASS			: CS 1B
 * DUE DATE		    : 03/10/15
 *************************************************************************/

#include "MyHeader.h"

/**************************************************************************
 * FUNCTION PeekUser
 * _______________________________________________________________________
 * This function receives a pointer called HeadF as a parameter. Which will
 * be initially pointing to the person at the beginning of the list. It
 * will then take the info from that and output the name, gender, and age
 * of the person found in that node.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *		headF: the variable representing the link list
 *
 * POST-CONDITIONS
 * 		This function return name, gender and age.
 *************************************************************************/
void PeekUser(personRec *headF) //IN & PROC - the link list of persons
{
	personRec *perPtr; // IN, CALC & OUT - declaring a new pointer

	// INITIALIZATION: Initializing pointer to headF
	perPtr = headF;

	if(headF != NULL)
	{
		cout << setw(COL_SIZE) <<  "Name:"   << perPtr -> name   << endl;
		cout << setw(COL_SIZE) <<  "Gender:" << perPtr -> gender << endl;
		cout << setw(COL_SIZE) <<  "Age:"    << perPtr -> age    << endl << endl;
	}
	// END IF STATEMENT
}
