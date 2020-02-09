/*************************************************************************
 * AUTHOR		    : Deboogaloo & Kermite
 * LAB #11          : Implementing a Queue
 * CLASS			: CS 1B
 * DUE DATE		    : 03/10/15
 *************************************************************************/

#include "MyHeader.h"

/**************************************************************************
 * FUNCTION GetInput
 *________________________________________________________________________
 * This function read in three inputs that are name, age and gender of
 * types, string, int and a char. It will prompt the user to enter in a
 * name, and then it will call two functions that error checks the
 * character and integer value for gender and age, and then saves
 * all three into perPtr. Returns -> perPtr.
 *________________________________________________________________________
 * PRE-CONDITIONS
 * 		perPtrF - pointer holding the node that holds the info for a person
 * 				  of struct personRec
 * POST-CONDITIONS
 * 		This function will get the name, age and the gender of the person
 * 		being pushed into the list. Then these vales will be used for many
 * 		other searches.
 * 		<Post-conditions are the changed outputs either passed
 * 		by value or by reference OR anything affected by the function>
 *************************************************************************/
personRec *GetInput(personRec *perPtrF) // IN - Pointer holding node info
{

	// CONSTANT: PROMPT_SIZE -> Will be used to format the prompt length
	const int PROMPT_SIZE = 14;

	//Variable Declarations
	bool   invalidF;
	int    bound1;
	int    bound2;
	string prompt;

	invalidF = true;
	//Assigns the boundary values and prompt to be used in error check
	bound1 = 0;
	bound2 = 121;
	prompt = "Enter Age: ";

	cout << "\nWho would you like to add?\n";
	cout << setw(PROMPT_SIZE) << "Enter Name:";
	getline(cin, perPtrF -> name);

	//Calls the two error checking functions
	perPtrF -> gender = GetAndCheckCharResponse(invalidF, perPtrF -> gender);

	perPtrF -> age = GetAndCheckIntResponse(bound1, bound2, prompt, PROMPT_SIZE);
	cout << endl;

	return perPtrF;
}
