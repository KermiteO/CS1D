/**********************************************************************
 * AUTHOR		: Kermite
 * Lab #6		: As #3 - Supplement Tic Tac Toe
 * CLASS		: CS1B
 * SECTION		: MW 8:00a - 11:50a
 * DUE DATE		: 2/9/15
 *********************************************************************/

#include "HeaderFile.h"

/**********************************************************************
 * FUNCTION GetPlayers
 * ___________________________________________________________________
 * This function prompts the user to enter two names and passes those two
 * names back to main by reference.
 *  - returns nothing
 * ___________________________________________________________________
 * PRE-CONDITIONS
 * 		playerX : the name of the first player previously defined
 * 		playerO : the name of the second player previously defined
 *
 * POST-CONDITIONS
 * 		This function will output a prompt that asks the user to enter in
 * 		two players' names.
 * 		<Post-conditions are the changed outputs either passed
 * 		by value or by reference OR anything affected by the function>
 *********************************************************************/

void GetPlayers(string& playerX,	//IN - first player
				string& playerO)	//IN - second player
{
	cout << "Enter the first player's name: ";
	getline(cin, playerX);
	cout << "Enter the second player's name: ";
	getline(cin, playerO);
	cout << endl;
}
