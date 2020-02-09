/*************************************************************************
 * AUTHOR		: Kermite & Clover
 * LAB #15      : Arrays & Linked Lists for FarmList
 * CLASS		: CS1B
 * SECTION		: T/TH 8am
 * DUE DATE		: 4/9/15
 *************************************************************************/

#include "header.h"

/**************************************************************************
* FUNCTION GetAndCheckIntInp
*__________________________________________________________________________
* This function prompts the user a prompt and receives integer input.
* It will error check the input and check if it is within boundaries.
* It will return the valid integer input. Returns -> an integer
*__________________________________________________________________________
* PRE-CONDITIONS
* 	prompt   : prompt has to be previously defined
* 	min      : minimum has to be previously defined
* 	max      : maximum has to be previously defined
* POST-CONDITIONS
* This function will return valid integer input
**************************************************************************/
int GetAndCheckIntInp(string prompt, // IN - prompt for user
					  int    min,    // IN - minimum boundary
				      int    max)    // IN - maximum boundary
{
	int            input;		 // IN&PROC- an integer input
	bool           invalid;		 // CALC   - checks if input is valid or not
	ostringstream  error1;		 // PROC   - oss variable used for output
	ostringstream  error2;		 // PROC   - other oss variable used for output
	unsigned short error1Length; // CALC   - the 1st length of an error statement
	unsigned short error2Length; // CALC   - the 2nd length of an error statement
	unsigned short newSetWLength;// CALC   - the size used for the setw in output
	do
	{
		invalid = false;

		cout << left;
		cout << prompt;

		// PROC - if the input is not a float or if the input is out of bounds,
		//		  the error messages will get formatted and outputed accordingly
		if(!(cin >> input))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			error1 << "**** Please input a number between "
				   << min << " and " << max << ' ';

			cout << endl << setw(newSetWLength) << error1.str() << "****"
				 << endl << endl;
			error1.str("");

			invalid = true;
		}
		else
		{
			invalid = input < min || input > max;

			if(invalid)
			{
				error1 << "**** The number " << input << " is an invalid entry ";
				error1Length = error1.str().length();

				error2 << "**** Please input a number between " << min << " and "
					   << max << ' ';
				error2Length = error2.str().length();

				if (error1Length > error2Length)
				{
					newSetWLength = error1Length;
				}
				else
				{
					newSetWLength = error2Length;
				}

				cout << endl  << setw(newSetWLength) << error1.str()  << "****\n";
				error1.str("");
				cout << setw(newSetWLength) << error2.str() << "****\n\n" ;
				error2.str("");
			}
		}
	}while(invalid);

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << right;

	return input;
}
