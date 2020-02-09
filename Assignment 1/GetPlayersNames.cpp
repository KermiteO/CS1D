/**********************************************************************
 * AUTHOR		: Omar Kermiche
 * Assignment #1: Functions
 * CLASS		: CS1B
 * SECTION		: MW 8:00a - 11:50a
 * DUE DATE		: 2/3/15
 *********************************************************************/
#include "HeaderFile.h"
/**********************************************************************
 * FUNCTION GetPlayersNames
 * ___________________________________________________________________
 * This function prompts the user to enter in two names that are
 * passed by reference back into main to be used for other functions.
 * returns nothing
 * _________________________________________________________________
 * PRE-CONDITIONS
 *		input1 : represents the first name
 *		input2 : represents the second name
 * POST-CONDITIONS
 * 		This function will output the game instructions.
 *********************************************************************/
void GetPlayersNames(string &input1,  //IN - the first name
					 string &input2)  //IN - the second name
{
	cout << "First player, please enter your name  : ";
	getline(cin, input1);
	cout << "Second player, please enter your name : ";
	getline(cin, input2);
	cout << endl;
}
