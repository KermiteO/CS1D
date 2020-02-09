/**********************************************************************
 * AUTHOR		: Kermite
 * Assignment #3: Multi-Dimensional Arrays
 * CLASS		: CS1B
 * SECTION		: MW 8:00a - 11:50a
 * DUE DATE		: 2/23/15
 *********************************************************************/

#include "HeaderFile.h"

/**********************************************************************
 * FUNCTION GetAndCheckInp
 * ___________________________________________________________________
 * This function receives a two dimensional array (tic tac toe board), a
 * token character, and the name of a player, and prompts the user to enter
 * in a column & row number. The function error checks those two
 * numbers to make sure that the numbers inputed are within range of the
 * rows and columns of the array, as well as if the spot is taken or not.
 * If the two numbers are valid, then the spot gets assigned a token value.
 *  - returns nothing
 * ___________________________________________________________________
 * PRE-CONDITIONS
 * 		board [][NUM_COLS]: the tic tac toe board
 * 		token			  : the token character
 * 		playerX			  : player who has token X
 * 		playerO			  : player who has token O
 *
 * POST-CONDITIONS
 * 		This function will error check a move on a tic tac toe board and
 * 		make sure that it is within the boundaries of the array and if the
 * 		spot is already occupied by another token character or not.
 * 		<Post-conditions are the changed outputs either passed
 * 		by value or by reference OR anything affected by the function>
 *********************************************************************/

void GetAndCheckInp(char board [][NUM_COLS], //IN - the tic tac toe board
					char token,				 //IN - the token character
					string playerX, 		 //IN&OUT - player X's name
					string playerO)		  	 //IN&OUT - player O's name
{
	int intRow;		 // IN & PROC - the row #
	int intCol;		 // IN & PROC - the column #
	bool invalidRow; // PROC 	  - condition to see if the row # input is
					 //		   		out of bounds
	bool invalidCol; // PROC 	  - condition to see if the col # input is
	 	 	 	 	 //		   		out of bounds
	bool invalid;	 // PROC 	  - lcv for do while

	invalid = true;

	do
	{
		//Outputs - the name of the player depending on what the current
		//			token is.
		if (token == 'X')
		{
			cout << playerX;
		}
		else
		{
			cout << playerO;
		}

		cout << "\'s turn to play: ";
		cin >> intRow >> intCol;

		//These four statements are to account for the fact that arrays
		//are read from 0 to (AR_SIZE - 1), and the spaces on the board
		//are read from 1 to 3.
		invalidRow = intRow < 1 || intRow > NUM_ROWS;
		invalidCol = intCol < 1 || intCol > NUM_COLS;

		intRow--;
		intCol--;

		//Outputs - the necessary statement if one or both of the invalid
		//			input conditions hold true or if the space is taken.
		if (invalidRow && invalidCol)
		{
			cout << "*** INVALID row & column input!! ***\n\n";
		}
		else if (invalidCol)
		{
			cout << "*** INVALID column input! ***\n\n";
		}
		else if (invalidRow)
		{
			cout << "*** INVALID row input! ***\n\n";
		}
		else if (board [intRow][intCol] != ' ')
		{
			cout <<"*** INVALID move! This spot is taken! ***\n\n";
		}
		else
		{
			invalid = false;
		}

	}while(invalid);

	//Assign the element specified by the input to the necessary token
	//of the player who's turn it is
	board [intRow][intCol] = token;
	cin.ignore(10000, '\n');
}
