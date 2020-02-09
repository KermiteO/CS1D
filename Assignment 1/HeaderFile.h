/**********************************************************************
 * AUTHOR		: Omar Kermiche
 * Assignment #1: Functions
 * CLASS		: CS1B
 * SECTION		: MW 8:00a - 11:50a
 * DUE DATE		: 2/3/15
 *********************************************************************/
#ifndef ASSIGNMENT_1_HEADERFILE_H_
#define ASSIGNMENT_1_HEADERFILE_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

//Global constants go here
const int PROMPT_COL = 58;
const int PROMPT2_COL = 16;
const int PROMPT3_COL = 22;

//All the prototypes for the functions
/**********************************************************************
 * FUNCTION PrintHeader
 * ___________________________________________________________________
 * This function receives an assignment name, type, and number the
 * outputs the appropriate header - returns nothing
 * by value or by reference OR anything affected by the function>
 *********************************************************************/
void PrintHeader(string asName, char asType, int asNum);

/**********************************************************************
 * FUNCTION OutputInstructions
 * ___________________________________________________________________
 * This function is called back to main and outputs to the console
 * the instructions for the game High Roller
 *********************************************************************/
void OutputInstructions();

/**********************************************************************
 * FUNCTION GetPlayersNames
 * ___________________________________________________________________
 * This function prompts the user to enter in two names that are
 * passed by reference back into main to be used for other functions
 *********************************************************************/
void GetPlayersNames(string &name1, string &name2);

/**********************************************************************
 * FUNCTION GetAndCheckCharResponse
 * ___________________________________________________________________
 * This function receives a boolean variable and a character variable and
 * uses them to error check the input that prompts the user to play the
 * game or not. It makes sure that the character entered was either yes or
 * no, and it accepts upper and lower case characters.
 *********************************************************************/
char GetAndCheckCharResponse(bool invalid, char playValid);

/**********************************************************************
 * FUNCTION PlayOneTurn
 * ___________________________________________________________________
 * This function is responsible for receiving a player's name and
 * processing the roll of the die the player executes. It receives the
 * variable inputName by reference and the variable die.
 *********************************************************************/
int PlayOneTurn(string &inputName, int die);

/**********************************************************************
 * FUNCTION RollDie
 * ___________________________________________________________________
 * This function uses a random number generator to pick a number between
 * one and six and returns that random value back to calling function.
 * return integer -> returns an integer value on a die
 *********************************************************************/
int RollDie();

/**********************************************************************
 * FUNCTION DisplayWinner
 * ___________________________________________________________________
 * This function receives two function calls and two variables representing
 * two names (by reference) and will determine using a selection statement
 * who rolled the higher number; whether the first player won, the second
 * player won, or if they both tied with the same number.
 * returns nothing
 *********************************************************************/
void DisplayWinner(int roll1, int roll2, string &name1, string &name2);

/**********************************************************************
 * FUNCTION PressEnterToRoll
 * ___________________________________________________________________
 * This function prompts the user to press enter. The game will commence
 * once the user presses <enter>.
 * returns nothing
 *********************************************************************/
void PressEnterToRoll();

/**********************************************************************
 * FUNCTION DisplayDie
 * ___________________________________________________________________
 * This function receives as input a value signified by variable die and
 * will determine which display of numbers on the die will be outputed
 * to the console.
 *********************************************************************/
void DisplayDie(int die);

#endif
