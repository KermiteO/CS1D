/**********************************************************************
 * AUTHOR		: Omar Kermiche
 * Assignment #1: Functions
 * CLASS		: CS1B
 * SECTION		: MW 8:00a - 11:50a
 * DUE DATE		: 2/3/15
 *********************************************************************/

#include "HeaderFile.h"

/**********************************************************************
 * FUNCTION PlayOneTurn
 * ___________________________________________________________________
 * This function is responsible for receiving a player's name and
 * processing the roll of the die the player executes. It receives the
 * variable inputName by reference and the variable die.
 * returns integer -> returns the value of the die back into main
 * __________________________________________________________________
 * PRE-CONDITIONS
 *		inputName : pass by reference alias used for both names inputed
 *		die		  : the integer value of the number rolled on the die
 * POST-CONDITIONS
 * 		This function will return the integer value of the die roll
 * 		back into main
 *********************************************************************/
int PlayOneTurn(string &inputName,	//OUT  - one of the names prompted by
									//		 user
				int die)			//PROC - the value of the die rolled
{
	cout << endl << inputName << "'s turn\n";
	PressEnterToRoll();

	cout << inputName << " rolls:\n";

	//PROC - the function calls for functions that roll & display the die
	die = RollDie();
	cout << left;
	DisplayDie(die);


	return die;
}
