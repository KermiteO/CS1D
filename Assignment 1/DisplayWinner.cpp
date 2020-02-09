/**********************************************************************
 * AUTHOR		: Omar Kermiche
 * Assignment #1: Functions
 * CLASS		: CS1B
 * SECTION		: MW 8:00a - 11:50a
 * DUE DATE		: 2/3/15
 *********************************************************************/
#include "HeaderFile.h"
/**********************************************************************
 * FUNCTION DisplayWinner
 * ___________________________________________________________________
 * This function receives two function calls and two variables representing
 * two names (by reference) and will determine using a selection statement
 * who rolled the higher number; whether the first player won, the second
 * player won, or if they both tied with the same number.
 * returns nothing
 * ___________________________________________________________________
 * PRE-CONDITIONS
 *		roll1 : the number of the first roll of the die
 *		roll2 : the number of the second roll of the die
 *		name1 : the first player's name
 *		name2 : the second player's name
 * POST-CONDITIONS
 * 		This function will output the game instructions.
 *********************************************************************/
void DisplayWinner(int roll1,	  //PROC - the number of the first roll
				   int roll2,	  //PROC - the # of the second roll
				   string &name1, //OUT  - the first player's name
				   string &name2) //OUT  - the second player's name
{
	if(roll1 > roll2)
	{
		cout << endl << name1 << " is the WINNER!!!\n\n";
	}
	else if(roll1 < roll2)
	{
		cout << endl << name2 << " is the WINNER!!!\n\n";
	}
	else
	{
		cout << endl << name1 << " & " << name2 << " have tied!\n\n";
	}
}
