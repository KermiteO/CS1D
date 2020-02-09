/*************************************************************************
 * AUTHOR		    : Hamodi & Kermite
 * LAB #11          : Implementing a stack
 * CLASS			: CS 1B
 * DUE DATE		    : 03/10/15
 *************************************************************************/

#include "MyHeader.h"

/**************************************************************************
 * FUNCTION PushUser
 *________________________________________________________________________
 * This function receives a link list from main as a parameter. Then,
 * this function will declare another pointer of type personRec. Finally,
 * we will be calling another function that will return the name, age and
 * gender of the person and link that to the node of our list.
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
personRec *PushUser(personRec *headF) // IN & OUT - the stack of persons
{
	// VARIABLES DECLARATION:
	personRec *perPtr;	   // IN, CALC & OUT - declaring a new pointer
	string     personName; // IN & OUT       - will read in name of person
	char       gender;	   // IN & OUT       - will read in gender of person
	int        age;		   // IN & OUT       - will read in age of person

	// INITIALIZATION: Here pointer headF is initialized to 0 and we are
	// also declaring a new dynamic pointer
	perPtr = new personRec;

	// Calling the GetInput function to return the name, age and gender of
	// the person
	GetInput(personName, gender, age);

	perPtr -> name   = personName;
	perPtr -> gender = gender;
	perPtr -> age    = age;

	perPtr -> next = headF;
	headF = perPtr;
	// INITIALIZING pointer is initialized back to 0
	perPtr = NULL;

	return headF;
}
