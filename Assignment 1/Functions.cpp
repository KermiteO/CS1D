/**********************************************************************
 * AUTHOR		: Omar Kermiche
 * Assignment #1: Functions
 * CLASS		: CS1B
 * SECTION		: MW 8:00a - 11:50a
 * DUE DATE		: 2/3/15
 *********************************************************************/
#include "HeaderFile.h"
/**********************************************************************
 * FUNCTION OutputInstructions
 * ___________________________________________________________________
 * This function is called back to main and outputs to the console
 * the instructions for the game High Roller
 * returns nothing
 * ___________________________________________________________________
 * PRE-CONDITIONS
 *		Must be called on by function call in main and must have a
 *		prototype in the header file
 * POST-CONDITIONS
 * 		This function will output the game instructions.
 *********************************************************************/

void OutputInstructions()
{
	cout << "***********************************************************\n";
	cout << left << setw(PROMPT2_COL) << "*" << "WELCOME TO HIGH ROLLER";
	cout <<	right << setw(PROMPT3_COL) << " *\n";
	cout << "*-------------------------------------------------------- *\n";
	cout << left << setw(PROMPT_COL)
		 << "* This is a two-player game that allows each player to"
		 << "*\n";
	cout << left << setw(PROMPT_COL)
		 << "* roll a die. The player with the highest roll wins." << "*\n";
	cout << "*-------------------------------------------------------- *\n";
	cout << "* Each player will first be prompted to enter their name. *\n";
	cout << left << setw(PROMPT_COL)
		 << "* Then each player will roll in turn (the first name" << right
		 << "*\n";
	cout << left << setw(PROMPT_COL) << "* entered will go first)."
		 << "*\n";
	cout << "***********************************************************\n";
}
