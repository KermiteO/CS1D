/**********************************************************************
 * AUTHOR		: Kermite
 * Assignment #3: Multi-Dimensional Arrays
 * CLASS		: CS1B
 * SECTION		: MW 8:00a - 11:50a
 * DUE DATE		: 2/23/15
 *********************************************************************/

#include "HeaderFile.h"

/**********************************************************************
 * FUNCTION OutputInstructions
 *___________________________________________________________________
 * This function outputs instructions to the users. There are no input
 * or output parameters for this function as it only displays text to
 * the screen.
 *___________________________________________________________________
 * PRE-CONDITIONS
 * 		none
 *
 * POST-CONDITIONS
 * 		This function will output the instructions on how to play
 * 		tic tac toe.
 * 		<Post-conditions are the changed outputs either passed
 * 		by value or by reference OR anything affected by the function>
 *********************************************************************/
void OutputInstructions()
{
	cout << "*****************************************************\n";
	cout << left << setw(15) << "*" << "WELCOME TO TIC-TAC-TOE!"
		 << right << setw(16) << "*\n";
	cout << "* Tic tac toe is a two player game that incorporates*\n";
	cout << "* a 3 by 3 board of 9 spaces and uses the symbols X *\n";
	cout << "* and O. Each player is assigned one of these tokens*\n";
	cout << "* and the 2 players take turns filling in the empty *\n";
	cout << "* spaces. The goal for the player is to fill 3 X's  *\n";
	cout << "* or 3 O's in a row on the grid either diagonally,  *\n";
	cout << "* vertically, or horizontally. The game will end in *\n";
	cout << "* a tie if both players failed to fill in a row of  *\n";
	cout << left << setw(52) << "* their token." << "*\n";
	cout << "*___________________________________________________*\n";
	cout << "* For this version of tic tac toe, each player will *\n";
	cout << "* be asked to enter their name. The first name will *\n";
	cout << "* get assigned the token X and the 2nd gets token O.*\n";
	cout << "* From there, when it's their turn, each player will*\n";
	cout << "* be asked to enter the space on the board that they*\n";
	cout << "* wish their token to be filled in by specifying the*\n";
	cout << "* row # & column # using a space in between the #'s.*\n";
	cout << "* The game ends when a player gets 3 of their token *\n";
	cout << setw(52) << "* in a row or if both players have tied." << "*\n";
	cout << "*****************************************************\n\n";
	cout << right;
}
