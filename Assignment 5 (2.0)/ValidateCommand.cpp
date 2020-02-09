/*************************************************************************
 * AUTHOR		    : Kermite
 * Ass #5           : Searching Link Lists
 * CLASS			: CS 1B
 * DUE DATE		    : 03/16/15
 *************************************************************************/

#include "HeaderFile.h"

/**************************************************************************
 * FUNCTION GetAndCheckIntResponse
 * _______________________________________________________________________
 * This function receives two boundary values and a string prompt and
 * uses them to error check the input that prompts the user to enter in an
 * integer. It then first checks to see if the value inputed is indeed
 * an integer or if the integer is a boundary value, if not, it outputs the
 * necessary statement, but if the command is valid, then invalid gets
 * set to false and the loop ends.
 * returns integer -> returns a number value between bound1 & bound2
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *		none
 * POST-CONDITIONS
 * 		This function return an input validation
 *************************************************************************/
int GetAndCheckIntResponse(int bound1F,	   		 // IN&PROC- 1st boundary value
						   int bound2F,	   		 // IN&PROC- 2nd boundary value
						   string promptF, 		 // IN&OUT - the input prompt
						   const int PROMPT_SIZE)//IN&PROC - the prompt size
{
	bool   invalid;	  // PROC - the boolean variable for do while
	int    inputValid;// IN   - the prompted integer input
	int    errSize;	  // PROC - the length of the first string used in the setw
	string errString1;// OUT  - the first error statement
	string errString2;// OUT  - the second error statement

	invalid = false;
	//PROC - Error checks the input and will keep looping so long as
	//there isn't a valid input
	do
	{
		cout << left;
		cout << setw(PROMPT_SIZE) << promptF;

		invalid = true;
		//Specifies which error statement to output only if the input value
		//is not a valid input, if not, then invalid gets set to false
		//and the loop ends
		if(!(cin >> inputValid))
		{
			cout << "\n**** Please input a NUMBER between " << bound1F
				 << " and " << bound2F << " ****\n\n\n";
			cin.clear();
		}
		else if(inputValid < bound1F || inputValid > bound2F)
		{
			//PROC - assign the two error statements to 2 string variables
			// 		 and in order to do this, ConvertIntToStr is needed
			errString1 = "**** The number " + ConvertIntToStr(inputValid)
					   + " is an invalid entry";
			errString2 = "**** Please input a number between "
					   + ConvertIntToStr(bound1F) + " and "
					   + ConvertIntToStr(bound2F);

			//OUT - find the length of the largest of the error strings
			//		to use it in setw to format the output, and output the errors
			errSize = StringLength(errString1, errString2);

			cout << endl;
			cout << setw(errSize) << errString1 << " ****\n";;
			cout << setw(errSize) << errString2 << " ****\n\n\n";
		}
		else
		{
			invalid = false;
		}//END IF

		//Clears the input buffer for the output statements and redisplays
		//the menu
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	} while(invalid);

	return inputValid;
}
