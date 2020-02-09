/**********************************************************************
 * AUTHOR		: Kermite
 * Assignment #3: Multi-Dimensional Arrays
 * CLASS		: CS1B
 * SECTION		: MW 8:00a - 11:50a
 * DUE DATE		: 2/19/15
 *********************************************************************/

#include "HeaderFile.h"

/**********************************************************************
 * FUNCTION CheckWin
 *___________________________________________________________________
 * This function checks to see if either player has won. Once it is
 *  possible for a win condition to exist, this should run after each
 *  player makes a play.
 *___________________________________________________________________
 * PRE-CONDITIONS
 * 		boardAr[] [NUM_COLS] : the tic tac toe board passed by constant
 * 							   reference
 *
 * POST-CONDITIONS
 * 		This function will return the character value of the player that
 * 		won or a value that indicates a tie.
 * 		<Post-conditions are the changed outputs either passed
 * 		by value or by reference OR anything affected by the function>
 *********************************************************************/
char CheckWin(const char boardAr[] [NUM_COLS]) // IN - tic tac toe board
{
	int row;			// PROC - the row number
	int col;			// PROC - the column number
	char searchTokenX;  // PROC - the token X
	char searchTokenO;  // PROC - the token O
	char whoWonF;		// CALC - which player won
	bool rowWin;		// PROC - condition to see if there are 3 tokens
						//		  in a row
	bool colWin;		// PROC - condition to see if there are 3 tokens
						//		  in a row vertically
	bool diagWin1;		// PROC - condition to see if there a 3 tokens
						//		  in a diagonal row
	bool diagWin2;		// PROC - condition to see if there a 3 tokens
						//		  in a diagonal row
	bool winTrue;		// PROC - lcv that checks to see which structure
						//		  to engage to determine win condition
	bool winX1;			// PROC - the condition if 'X' wins diagonally
	bool winX2;			// PROC - the 2nd condition if 'X' wins diagonally
	bool winO1;			// PROC - the condition if 'O' wins diagonally
	bool winO2;			// PROC - the 2nd condition if 'O' wins diagonally

	//Initialize - win true to false, the tokens being searched for to
	//respective token values, the value of whoWon to 'T' that may or
	//may not be changed in loop/selection structures, and the row #
	//to zero
	winTrue = false;

	searchTokenX = 'X';
	searchTokenO = 'O';
	whoWonF = 'T';

	row = 0;

	//Calculate - whether any row has the same token in each element
	//within that row and determines which player is the winner.
	//It loops so long as winTrue is false and row doesn't exceed the
	//# of rows within the board
	while(!winTrue && row < NUM_ROWS)
	{
		rowWin = (boardAr[row][0] == boardAr[row][1]
			   && boardAr[row][0] == boardAr[row][2]);

		//Condition that executes so long as rowWin is true and the given
		//element is not an empty space
		if(rowWin && boardAr[row][0] != ' ')
		{
			winTrue = true;

			if(boardAr[row][0] == searchTokenX)
			{
				whoWonF = 'X';
			}
			else if(boardAr[row][0] == searchTokenO)
			{
				whoWonF = 'O';
			}
		}

	//Update lcv
	row++;
	}
	//Initialize the column number to zero
	col = 0;

	//Calculate - whether any column has the same token in each element
	//within that vertical row and determines which player is the winner.
	//It loops so long as winTrue is false and col doesn't exceed the
	//# of columns within the board
	while(!winTrue && col < NUM_COLS)
	{
		colWin = (boardAr[0][col] == boardAr[1][col]
			   && boardAr[0][col] == boardAr[2][col]);

		//Condition that determines the winner so long as colWin holds true
		//and the element is not an empty space.
		if(colWin && boardAr[0][col] != ' ')
		{
			winTrue = true;

			if(boardAr[0][col] == searchTokenX)
			{
				whoWonF = 'X';
			}
			else if(boardAr[0][col] == searchTokenO)
			{
				whoWonF = 'O';
			}
		}
	//Update lcv
	col++;
	}

	//If winTrue is still false, then it calculates whether or not
	//there are 3 tokens in a diagonal row
	if(!winTrue)
	{
		//PROCESSING - the two boolean conditions that account for if there
		//are three of the same elements in a diagonal row
		diagWin1 = (boardAr[0][0] == boardAr[1][1]
				 && boardAr[0][0] == boardAr[2][2]);

		diagWin2 = (boardAr[0][2] == boardAr[1][1]
				 && boardAr[0][2] == boardAr[2][0]);
		//PROCESSING - boolean conditions that determine if there were three
		//of token X or token O in a diagonal row
		winX1 = (diagWin1 && boardAr[0][0] == searchTokenX);
		winX2 = (diagWin2 && boardAr[0][2] == searchTokenX);

		winO1= (diagWin1 && boardAr[0][0] == searchTokenO);
		winO2 = (diagWin2 && boardAr[0][2] == searchTokenO);
		//win condition that make or may not get reset back to false
		winTrue = true;

		//Determines if there is a player with a diagonal win
		if(boardAr[0][0] != ' ' || boardAr[0][2] != ' ')
		{
			if(winX1 || winX2)
			{
				whoWonF = 'X';
			}
			else if(winO1 || winO2)
			{
				whoWonF = 'O';
			}
		}
		else
		{
			winTrue = false;
		}
	}

	return whoWonF;
}
