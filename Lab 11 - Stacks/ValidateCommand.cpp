/*************************************************************************
 * AUTHOR		    : Hamodi & Kermite
 * LAB #11          : Implementing a stack
 * CLASS			: CS 1B
 * DUE DATE		    : 03/10/15
 *************************************************************************/

#include "MyHeader.h"

/**************************************************************************
 * FUNCTION GetAndCheckCharResponse
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
	bool invalid;	// PROC - the boolean variable for do while
	int  inputValid;// IN   - the prompted integer input

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
			cout << "\n**** Please input a number between " << bound1F
				 << " and " << bound2F << "****\n\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			//Only applys for the command input
			if(bound2F == 6)
			{
				OutputMenu();
			}
		}
		else if(inputValid < bound1F || inputValid > bound2F)
		{
			cout << "\n**** The number " << inputValid
				 << " is an invalid entry";
			if(inputValid < 0)
			{
				cout << right << setw(9) << "****\n";
			}
			else
			{
				cout << right << setw(10) << "****\n";
			}
			cout << "**** Please input a number between " << bound1F
				 << " and " << bound2F << "****\n\n";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			//Only applys for the command input
			if(bound2F == 6)
			{
				OutputMenu();
			}
		}
		else
		{
			invalid = false;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}//END IF

	} while(invalid);

	return inputValid;
}
