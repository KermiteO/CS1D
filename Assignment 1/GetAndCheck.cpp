/**********************************************************************
 * AUTHOR		: Omar Kermiche
 * Assignment #1: Functions
 * CLASS		: CS1B
 * SECTION		: MW 8:00a - 11:50a
 * DUE DATE		: 2/3/15
 *********************************************************************/

#include "HeaderFile.h"

/**********************************************************************
 * FUNCTION GetAndCheckCharResponse
 * ___________________________________________________________________
 * This function receives a boolean variable and a character variable and
 * uses them to error check the input that prompts the user to play the
 * game or not. It makes sure that the character entered was either yes or
 * no, and it accepts upper and lower case characters.
 * returns character -> returns a character value.
 * ___________________________________________________________________
 * PRE-CONDITIONS
 *		invalid   : boolean validation used to error check the input
 *		playValid : represents the character M/F.
 *
 * POST-CONDITIONS
 * 		This function return a character validation
 *********************************************************************/
char GetAndCheckCharResponse(bool invalid,	 //PROC - condition for loop
							 char playValid) //IN 	- game validation
{
	do
	{
		cout << "Would you like to play High Roller (y/n)? ";
		cin.get(playValid);
		playValid = toupper(playValid);
		cin.ignore(1000, '\n');
		invalid = true;

		if(playValid == 'M' || playValid == 'F')
		{
			invalid = false;
		}
		else
		{
			cout << "** INVALID INPUT - Please enter a valid character! **\n\n";
		}
	} while(invalid);

	return playValid;
}
