/**********************************************************************
 * AUTHOR		: Kermite
 * Assignment #3: Multi-Dimensional Arrays
 * CLASS		: CS1B
 * SECTION		: MW 8:00a - 11:50a
 * DUE DATE		: 2/23/15
 *********************************************************************/

#include "HeaderFile.h"

/**********************************************************************
 * FUNCTION DisplayBoard
 * ___________________________________________________________________
 * This function outputs the tic tac toe board including the tokens
 * played in the proper format (as described below).
 *
 *          1       2       3
      [1][1] | [1][2] | [1][3]
             |        |
1            |        |
             |        |
     --------------------------
      [2][1] | [2][2] | [2][3]
             |        |
2            |        |
             |        |
     --------------------------
      [3][1] | [3][2] | [3][3]
             |        |
3            |        |
             |        |
 *___________________________________________________________________
 * PRE-CONDITIONS
 * 		boardAr [][NUM_COLS]: the 2 dimensional array (tic tac toe board)
 * 							  previously defined
 * POST-CONDITIONS
 * 		This function will display the tic tac toe board.
 * 		<Post-conditions are the changed outputs either passed
 * 		by value or by reference OR anything affected by the function>.
 *********************************************************************/

void DisplayBoard(const char boardAr [][NUM_COLS]) //IN - tic tac toe board
{
	int row;
	int col;

	//Clears the board
	system("cls");

	cout << endl;
	cout << setw(10) << "1" << setw(8) << "2" << setw(9) << "3\n";

	for(row = 0; row < 3; row++)
	{
		//Outputs the row and column number for each element in a row
		cout << setw(7) << "[" << row+1 << "][1] | " << "[" << row+1;
		cout << "][2] | " << "[" << row+1 << "][3]" << endl;
		cout << setw(14) << "|" << setw(9) << "|" << endl;

		for (col = 0; col < 3; col++)
		{
			//Displays the lines that separate each element into its own
			//square that make up the 9 spaces of the tic tac toe board
			switch(col)
			{
				case 0: cout << row + 1 << setw(9) << boardAr[row][col];
						cout << setw(4) << "|";
						break;

				case 1: cout << setw(4) << boardAr[row][col];
						cout << setw(5) << "|";
						break;

				case 2: cout << setw(4) << boardAr[row][col] << endl;
						break;

				default: cout << "ERROR!\n\n";
			}
		}

		//Displays the line the separates each individual column
		cout << setw(14) << "|" << setw(10) << "|\n";

		//Displays the line that separates each individual row
		if (row != 2)
		{
			cout << setw(32) << "--------------------------\n";
		}
	}
	cout << endl << endl;
}
