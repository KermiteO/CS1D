/**********************************************************************
 * AUTHOR		: Kermite & The Oz
 * Lab #10		: Intro to Pointers
 * CLASS		: CS1B
 * SECTION		: TuTh 8:00a - 11:50a
 * DUE DATE		: 2/26/15
 *********************************************************************/

#include "HeaderFile.h"

int main()
{
	//Constant Declarations go here
	const char PROJECT_TYPE    = 'L';
	const char PROGRAMMER [30] = "Kermite & The Oz";
	const int  LAB_NUM         = 10;
	const char LAB_NAME   [50] = "Intro to Pointers";

	const int PROMPT_COL = 43;
	const int PROMPT2_COL = 16;

	//Variable Declarations go here
	int staticInt;		//PROC 	  - the static integer variable
	int *dynPntr;		//IN&PROC - the dynamic pointer variable
	int *statPntr;		//IN&PROC - the pointer variable for the static integer


	//Initialize - dynamic pointer to null and assign the address of
	//the static integer variable to a pointer variable.
	dynPntr  = NULL;
	statPntr = &staticInt;

	//OUTPUT - the print header and the instructions for the game
	cout << PrintHeader(PROJECT_TYPE, PROGRAMMER, LAB_NUM, LAB_NAME);

	//Initialize - the condition for the while loop
	cout << left;
	cout << setw(PROMPT_COL) << "Enter the first value(enter -999 to exit)?";
	cin >> *statPntr;

	//Initialize - Dynamically allocates memory for another integer value
	dynPntr = new int;

	//Condition that checks to make sure if there isn't already a full
	//memory space. If there is, it outputs the necessary statement.
	if(dynPntr != NULL)
	{
/***********************************************************************
  PROCESSING - loops so long as the first integer typed in is
			   not -999. It then prompts the user for a second integer.
			   From there, it then takes the values it got from the two
			   pointer variable and calculates the sum and the product
			   and outputs them.
************************************************************************/
		while(*statPntr != -999)
		{
			cout << setw(PROMPT_COL) << "Input the second value?";
			cin >> *dynPntr;

			cout << endl << endl;

			//OUTPUT - the sum and the average of the two integers
			cout << setw(PROMPT2_COL) << "The sum is:" << staticInt + *dynPntr;

			cout << endl;
			cout << setw(PROMPT2_COL) << "The product is:"
				 << staticInt * *dynPntr;

			cout << endl << endl;

			//Change the LCV for the while loop
			cout << setw(PROMPT_COL)
				 << "Enter the first value(enter -999 to exit)?";
			cin >> *statPntr;
		}

		//Frees up the memory that was dynamically allocated for dynPntr
		delete dynPntr;
	}
	else
	{
		cout << "\n Out of memory!\n";
	}

	return 0;
}





