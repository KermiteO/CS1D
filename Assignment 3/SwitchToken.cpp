/**********************************************************************
 * AUTHOR		: Kermite
 * Assignment #3: Multi-Dimensional Arrays
 * CLASS		: CS1B
 * SECTION		: MW 8:00a - 11:50a
 * DUE DATE		: 2/19/15
 *********************************************************************/

#include "HeaderFile.h"

/**********************************************************************
 * FUNCTION SwitchToken
 *___________________________________________________________________
 * This function switches the active player.
 * It takes in a parameter representing the current player's token
 * as a character value (either an X or an O) and returns the opposite.
 * For example, if this function receives an X it returns an O. If it
 * receives an O it returns an X.
 *___________________________________________________________________
 * PRE-CONDITIONS
 * 		token 	: the token symbol previously defined
 *
 * POST-CONDITIONS
 * 		This function will return the token of the player that's
 * 		currently playing.
 * 		<Post-conditions are the changed outputs either passed
 * 		by value or by reference OR anything affected by the function>
 *********************************************************************/
char SwitchToken(char token) // IN - current player's token ('X' or 'O')
{
	char newToken;

	switch(token)
	{
	case 'X': newToken = 'O';
			  break;
	case 'O': newToken = 'X';
			  break;
	default : cout << "ERROR - INVALID token!\n";
	}

	return newToken;
}
