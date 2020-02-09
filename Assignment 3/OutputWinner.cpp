/**********************************************************************
 * AUTHOR		: Kermite
 * Assignment #3: Multi-Dimensional Arrays
 * CLASS		: CS1B
 * SECTION		: MW 8:00a - 11:50a
 * DUE DATE		: 2/19/15
 *********************************************************************/

#include "HeaderFile.h"

/**********************************************************************
 * FUNCTION OutputWinner
 *___________________________________________________________________
 *  This function receives as input a character indicating which player
 *  won or if the game was a tie and outputs an appropriate message.
 *  This function does not return anything as it simply outputs the
 *  appropriate message to the screen.
 *___________________________________________________________________
 * PRE-CONDITIONS
 * 		whoWon  : the character value of the player that won passed by
 * 		  		  reference
 * 		playerX : the name of the player who holds the token X
 * 		playerO : the name of the player who holds the token O
 *
 * POST-CONDITIONS
 * 		This function will display the winner's name or a message that
 * 		shows if it's a tie game.
 * 		<Post-conditions are the changed outputs either passed
 * 		by value or by reference OR anything affected by the function>
 *********************************************************************/
void OutputWinner(char whoWon,	  // IN - represents the winner or a value
								  // 	  indicating a tied game.
				  string playerX, // OUT - player X's name
				  string playerO) // OUT - player O's name
{
	switch(whoWon)
	{
	case 'X': cout << playerX << " is the WINNER!\n";
			  break;
	case 'O': cout << playerO << " is the WINNER!\n";
			  break;
	case 'T': cout << "Cats Game! Both players have tied!\n";
			  break;
	default : cout << "INVALID winner!\n";
	}
}
