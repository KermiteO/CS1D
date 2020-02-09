/**********************************************************************
 * AUTHOR		: Kermite
 * Assignment #3: Multi-Dimensional Arrays
 * CLASS		: CS1B
 * SECTION		: MW 8:00a - 11:50a
 * DUE DATE		: 2/19/15
 *********************************************************************/

#include "HeaderFile.h"

int main()
{
	/*********************************************************************
	 * CONSTANTS
	 * -------------------------------------------------------------------
	 * USED FOR OUTPUT FILE - ALL WILL BE OUTPUT
	 * -------------------------------------------------------------------
	 * PROGRAMMER : Programmer's Name
	 * CLASS      : Student's Course
	 * SECTION    : Class Days and Times
	 * LAB_NUM    : Lab/Assignment Number (specific to this lab)
	 * LAB_NAME   : Title of the Lab/Assignment
	 * ------------------------------------------------------------------
	 * USED FOR PROCESSING
	 * ------------------------------------------------------------------
	 *
	 * ******************************************************************/
	//Constant Declarations go here
	const char PROJECT_TYPE    = 'A';
	const char PROGRAMMER [31] = "Kermite";
	const int  LAB_NUM         = 03;
	const char LAB_NAME   [31] = "Mulit-Dimensional Arrays";

	const int NUM_TURNS = 9;

	//Variable declarations go here
	char boardAr [NUM_ROWS][NUM_COLS];	// IN 	   - the tic tac toe board
	char currentToken;					// IN&PROC - the token symbol
	char playResponse;					// IN 	   - LCV
	char winner;						// PROC&OUT- the winner of the game
	int turnCount;						// PROC	   - how many total turns
	string playerX;						// IN&OUT  - name of player with
										//			 token X
	string playerO;						// IN&OUT  - name of player with
										//			 token O
	bool gameEnd;						// PROC    - whether the game
										//			 should end or not

	//Initialize game end to false and set playResponse to accept upper
	//and lower case characters as input

	gameEnd = false;
	playResponse = toupper(playResponse);

	//Calls and outputs PrintHeader to console
	cout << PrintHeader(PROJECT_TYPE, PROGRAMMER, LAB_NUM, LAB_NAME);

	//Calls function that displays the instructions on how to play
	OutputInstructions();

/*********************************************************************
 * INPUT - the response of whether players want to play tic tac toe/
 * 		   Initialization of lcv.
 *********************************************************************/
	cout << "Would you like to play? (y/n): ";
	cin.get(playResponse);

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << endl;

/*********************************************************************
 * PROCESSING - the data required to play the game, which includes
 * 				prompting the players for their names, clearing the
 * 				board each time a player moves, and a loop that
 * 				accounts for the actual game itself(i.e. moves, winner).
 * 				Each player keeps playing as long as the total turns
 * 				is less than 9 or gameEnd is false.
 *********************************************************************/
	while (playResponse != 'n')
	{
		GetPlayers(playerX, playerO);

		InitBoard(boardAr);

		DisplayBoard(boardAr);

		//Initialize token symbol to X and turnCount to 1
		currentToken = 'X';

		turnCount = 1;

		//The loop that accounts for whose turn it is and what their move is
		//on the board.
		while (!gameEnd && turnCount <= NUM_TURNS)
		{
			GetAndCheckInp(boardAr, currentToken, playerX, playerO);

			DisplayBoard(boardAr);

			currentToken = SwitchToken(currentToken);

			//The win condition that makes sure enough turns were played
			//so that a winner can be calculated.
			if(turnCount >= 5)
			{
				winner = CheckWin(boardAr);

				//This statement checks to make sure that if there are
				//still more moves on the board, or if a player has indeed
				//won or not.
				if(winner == 'T' && turnCount == NUM_TURNS)
				{
					gameEnd = true;
				}
				else if(winner == 'X' || winner == 'O')
				{
					turnCount = NUM_TURNS + 1;
				}
			}

			//update and or change lcv
			turnCount++;

		}

/*********************************************************************
 * OUTPUT - the winner of the game or if there was a tie, update
 * 			the lcv in the first while loop, and second lcv gets
 * 			reinitialized to false.
 *********************************************************************/
		OutputWinner(winner, playerX, playerO);

		cout << "\nWould you like to play again? (y/n): ";
		cin.get(playResponse);

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << endl;

		gameEnd = false;
	}

	//The program ends
	cout << "Thank you for playing!!";

	return 0;
}


