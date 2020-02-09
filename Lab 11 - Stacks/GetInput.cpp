/*************************************************************************
 * AUTHOR		    : Hamodi & Kermite
 * LAB #11          : Implementing a stack
 * CLASS			: CS 1B
 * DUE DATE		    : 03/10/15
 *************************************************************************/

#include "MyHeader.h"

/**************************************************************************
 * FUNCTION GetInput
 *________________________________________________________________________
 * This function get three parameters that are name, age and gender of
 * types, string, int and a char. It will prompt the user to enter in a
 * name, and then it will call two functions that error checks the
 * character and integer value for gender and age. Returns -> nothing.
 *________________________________________________________________________
 * PRE-CONDITIONS
 * 		name    : name of the person added to the list
 * 		gender  : gender of the person added to the list (male or female)
 * 		age     : age of the person added to the list
 * POST-CONDITIONS
 * 		This function will get the name, age and the gender of the person
 * 		being pushed into the list. Then these vales will be used for many
 * 		other searches.
 * 		<Post-conditions are the changed outputs either passed
 * 		by value or by reference OR anything affected by the function>
 *************************************************************************/
void GetInput(string &name,   // IN & OUT - name of the person
			  char   &gender, // IN & OUT - gender of the person
			  int    &age)    // IN & OUT - age of the person
{

	// CONSTANT: PROMPT_SIZE -> Will be used to format the prompt length
	const int PROMPT_SIZE = 14;

	//Variable Declarations
	bool   invalidF;
	int    bound1;
	int    bound2;
	string prompt;

	//Assigns the boundary values and prompt to be used in error check
	bound1 = 0;
	bound2 = 121;
	prompt = "Enter Age: ";

	invalidF = true;

	cout << "\nWho would you like to add?\n";
	cout << setw(PROMPT_SIZE) << "Enter Name:";
	getline(cin, name);

	//Calls the two error checking functions
	gender = GetAndCheckCharResponse(invalidF, gender);

	age = GetAndCheckIntResponse(bound1, bound2, prompt, PROMPT_SIZE);
	cout << endl;
}
