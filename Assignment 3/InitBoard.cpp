/**********************************************************************
 * AUTHOR		: Kermite
 * Lab #6		: As #3 - Supplement Tic Tac Toe
 * CLASS		: CS1B
 * SECTION		: MW 8:00a - 11:50a
 * DUE DATE		: 2/9/15
 *********************************************************************/

#include "HeaderFile.h"

/**********************************************************************
 * FUNCTION InitBoard
 *___________________________________________________________________
 * 	  This function initializes each spot in the board to a space ' '.
 *___________________________________________________________________
 * PRE-CONDITIONS
 * 		boardAr[][NUM_COLS]: the tic tac toe board as a multi-dimensional
 * 							 array previously defined
 *
 * POST-CONDITIONS
 * 		This function will initialize all the elements in the array
 * 		to a space.
 * 		<Post-conditions are the changed outputs either passed
 * 		by value or by reference OR anything affected by the function>
 *********************************************************************/
void InitBoard(char boardAr[][NUM_COLS]) //OUT - tic tac toe board
{
	int rowCnt;		//IN - the row count
	int colCnt;		//IN - the column count

	for (rowCnt = 0; rowCnt < NUM_COLS; rowCnt++)
	{
		for (colCnt = 0; colCnt < NUM_COLS; colCnt++)
		{
			boardAr[rowCnt][colCnt] = ' ';
		}
	}
}
