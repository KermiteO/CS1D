/**********************************************************************
 * AUTHOR		: Omar Kermiche
 * Assignment #1: Functions
 * CLASS		: CS1B
 * SECTION		: MW 8:00a - 11:50a
 * DUE DATE		: 2/3/15
 *********************************************************************/

#include "HeaderFile.h"

int main()
{
	//Variable declarations go here
	string name1;				//IN     - the first player's name
	string name2;				//IN     - the second player's name
	char playValid;				//PROC   - gives validation to play game or
								//		   not
	char highRollPlay;			//PROC   - calls on GetAndCheckCharResponse
								//		   function
	int die;					//PROC   - the value of the die rolled
	int roll1;					//OUTPUT - the number rolled by first player
	int roll2;					//OUTPUT - the number rolled by second
								//		   player
	bool invalid;				//PROC 	 - LCV for do while loop in the
								//		   GetAndCheckCharResponse function


	//OUTPUT - the print header and the instructions for the game
	PrintHeader("Functions", 'A', 1);
	cout << endl;

	OutputInstructions();

	//INPUT - calls on the function that receives two names as input and
	//		  sends them bssack by reference
	GetPlayersNames(name1, name2);


	/**********************************************************************
	 * PROCESSING - calls on the function that checks prompts if you want
	 *			   to play the game or not. It loops so long as the user
	 *			   wants to play and processes the rolls of the two users
	 *			   and who has the higher roll
	 *********************************************************************/

	//PROCESSING - initialize the get and check function (LCV)
	highRollPlay = GetAndCheckCharResponse(invalid, playValid);

	while(highRollPlay == 'Y' || highRollPlay == 'y')
	{
		roll1 = PlayOneTurn(name1, die);
		roll2 = PlayOneTurn(name2, die);

		//OUTPUT - displays who won the game
		DisplayWinner(roll1, roll2, name1, name2);

		//PROC - change the LCV
		highRollPlay = GetAndCheckCharResponse(invalid, playValid);
	}

	//OUTPUT - the game ends
	cout << "\nThank you for playing :-)";


	return 0;
}


