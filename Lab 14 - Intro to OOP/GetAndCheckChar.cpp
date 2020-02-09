/*************************************************************************
 * AUTHOR		: Kermite & ChickenLips
 * LAB #13      : Creating an Ordered List
 * CLASS		: CS1B
 * SECTION		: T/TH 8am
 * DUE DATE		: 3/19/15
 *************************************************************************/

#include "header.h"

/*************************************************************************
 * 	FUNCTION GetAndCheckCharInput
 *_______________________________________________________________________
 * 	This function will accept a single character as input and error
 * 	check it to ensure is is a valid gender response. Returns -> a char
 *_______________________________________________________________________
 * PRE-CONDITIONS:
 *	  PROMPT : prompt for getting character response.
 * POST-CONDITIONS:
 *	  This function returns a single character returned to main after it is
 *	  error checked.
 *************************************************************************/
char GetAndCheckCharInput (const string PROMPT,// IN - response prompt
						   char validChar1,	   // IN - valid char response
						   char validChar2)    // IN - valid char response
{
	bool invalidInput; 			 // CALC   - checks if input is valid or not
	char charCheck;		         // IN&OUT - play again? y/n
	ostringstream  error1;		 // PROC   - oss variable used for output
	ostringstream  error2;		 // PROC   - other oss variable used for output
	unsigned short error1Length; // CALC   - the 1st length of an error statement
	unsigned short error2Length; // CALC   - the 2nd length of an error statement
	unsigned short newSetWLength;// CALC   - the size used for the setw in output

	cout << left;

	// ERROR CHECKS CHARACTER RESPONSE
	do // while (invalidInput)
	{
		// PROMPTS USER FOR A YES OR NO RESPONSE
		cout  << setw(PROMPT_COL) << PROMPT;
		cin.get(charCheck);
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		charCheck = toupper(charCheck);

		invalidInput = (charCheck != validChar1 && charCheck != validChar2);

		if (invalidInput)
		{
			error1 << "**** " << charCheck << " is an invalid entry ";
			error1Length = error1.str().length();

			error2 << "**** Please input  " << validChar1 << " and " << validChar2
				   << ' ';
			error2Length = error2.str().length();

			if (error1Length > error2Length)
			{
				newSetWLength = error1Length;
			}
			else
			{
				newSetWLength = error2Length;
			}

			cout << endl << setw(newSetWLength) << error1.str()  << "****\n";
			error1.str("");

			cout << setw(newSetWLength) << error2.str() << "****" << endl << endl;
			error2.str("");
		}
	}while(invalidInput);

	cout << right;

	return charCheck;
}
