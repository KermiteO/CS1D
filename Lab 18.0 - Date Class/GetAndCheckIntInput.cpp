/**********************************************************************
 * AUTHOR(S)	: Kermite & Miss Lame
 * Lab #18		: Date Class
 * CLASS		: CS1B
 * SECTION		: TuTh 8:00a - 11:50a
 * DUE DATE		: 4/28/15
 *********************************************************************/

#include "HeaderFile.h"

/**************************************************************************
* FUNCTION GetAndCheckIntInp
*__________________________________________________________________________
*
 * This function prompts the user a prompt, minimum and maximum boundary.
 * It will error check the input and check if it is within boundaries.
 * It will return the valid integer input.
*
*__________________________________________________________________________
* PRE-CONDITIONS
* 	All of the following have to be previously defined:
* 		prompt,
* 		min,
* 		max
*
* POST-CONDITIONS
* RETURNS: returns the valid integer input
*
**************************************************************************/

int GetAndCheckIntInp (string prompt,      // IN  - prompt for user
				       int    min,         // IN  - minimum boundary
				       int    max)		   // IN  - maximum boundary

{
	int errorMsgCol;

	string errorMsg1;
	string errorMsg2;

	int  intInput;
	bool invalid;

	do
	{
		invalid = false;

		cout << prompt;

		// INPUT - Inputs a integer, error check for if user inputs character
		//		 - by mistake.
		if(!(cin >> intInput))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "\n**** Please input a NUMBER between " << min
				 << " and " <<	max << " ****\n\n\n";

			invalid = true;

		}
		else
		{
			invalid = intInput < min || intInput > max;

			if(invalid)
			{

				/**********************************************************
				 * PROCESSING - Program will determine the size of setw
				 * based off which error message length is longer.
				 *
				 *  The function IntegerToString will convert the input to
				 *  a string to be able to determine the length.
				 *
				 *********************************************************/

				errorMsg1 = "The number " + IntegerToString(intInput)
						    + " is an invalid entry";
				errorMsg2 = "Please input a number between "
						    + IntegerToString(min)
						    + " and " + IntegerToString(max);

				// GetLongestStringLength - This function will return the
				//						  - the length of the longest string.
				errorMsgCol = GetLongestStringLength(errorMsg1, errorMsg2);

				cout << left
				     << "\n**** " << setw(errorMsgCol)  << errorMsg1
					 << " ****\n"
				     << "**** " << setw(errorMsgCol) << errorMsg2
				     << " ****\n\n\n"
					 << right;
			}
		}

	}while(invalid);

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	return intInput;
}
