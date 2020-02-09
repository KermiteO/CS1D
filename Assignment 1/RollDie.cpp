/**********************************************************************
 * AUTHOR		: Omar Kermiche
 * Assignment #1: Functions
 * CLASS		: CS1B
 * SECTION		: MW 8:00a - 11:50a
 * DUE DATE		: 2/3/15
 *********************************************************************/

#include "HeaderFile.h"

/**********************************************************************
 * FUNCTION RollDie
 * ___________________________________________________________________
 * This function uses a random number generator to pick a number between
 * one and six and returns that random value back to calling function.
 * return integer -> returns an integer value on a die
 * ___________________________________________________________________
 * PRE-CONDITIONS
 *		none
 * POST-CONDITIONS
 * 		This function will return a random integer value represented
 * 		by variable die.
 *********************************************************************/
int RollDie()
{
	int die;
	srand(time(NULL));
	die = rand()% 6 + 1;

	return die;
}
