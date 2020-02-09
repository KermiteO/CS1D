/**********************************************************************
 * AUTHOR		: Omar Kermiche
 * Assignment #1: Functions
 * CLASS		: CS1B
 * SECTION		: MW 8:00a - 11:50a
 * DUE DATE		: 2/3/15
 *********************************************************************/
#include "HeaderFile.h"

/**********************************************************************
 * FUNCTION DisplayDie
 * ___________________________________________________________________
 * This function receives as input a value signified by variable die and
 * will determine which display of numbers on the die will be outputed
 * to the console.
 * returns nothing
 * ___________________________________________________________________
 * PRE-CONDITIONS
 *		die : the value rolled on the die
 * POST-CONDITIONS
 * 		This function will display a certain set of numbers on a die
 * 		depending on the value.
 *********************************************************************/
void DisplayDie(int die)	//PROC - the value of the die rolled
{
	const string DIE_ONE=	"-----------\n"
							"+         +\n"
							"+         +\n"
							"+    0    +\n"
							"+         +\n"
							"+         +\n"
							"-----------\n";
	const string DIE_TWO =  "-----------\n"
							"+         +\n"
							"+  0      +\n"
							"+         +\n"
							"+      0  +\n"
							"+         +\n"
							"-----------\n";

  const string DIE_THREE =  "-----------\n"
							"+ 0       +\n"
							"+         +\n"
							"+    0    +\n"
							"+         +\n"
							"+       0 +\n"
							"-----------\n";
	const string DIE_FOUR = "-----------\n"
							"+         +\n"
							"+  0   0  +\n"
							"+         +\n"
							"+  0   0  +\n"
							"+         +\n"
							"-----------\n";

	const string DIE_FIVE = "-----------\n"
							"+         +\n"
							"+  0   0  +\n"
							"+    0    +\n"
							"+  0   0  +\n"
							"+         +\n"
							"-----------\n";

	const string DIE_SIX  = "-----------\n"
							"+  0   0  +\n"
							"+         +\n"
							"+  0   0  +\n"
							"+         +\n"
							"+  0   0  +\n"
							"-----------\n";
	//PROC - determines which display to output only if the value generated
	//		 is between 1 and 6.
	switch (die)
		{
		case 1: cout << DIE_ONE;
					break;
		case 2: cout << DIE_TWO;
					break;
		case 3: cout << DIE_THREE;
					break;
		case 4: cout << DIE_FOUR;
					break;
		case 5: cout << DIE_FIVE;
					break;
		case 6: cout << DIE_SIX;
					break ;
		default: cout << "***** ERROR - INVALID DIE VALUE *****\n";
		}
}

