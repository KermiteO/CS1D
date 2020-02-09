/**********************************************************************
 * AUTHOR		: Kermite
 * Assignment #3: Multi-Dimensional Arrays
 * CLASS		: CS1B
 * SECTION		: MW 8:00a - 11:50a
 * DUE DATE		: 2/19/15
 *********************************************************************/
#ifndef TICTACHEADER_H_
#define TICTACHEADER_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <limits>
#include <ios>
using namespace std;

/***********************************************************************
 * As #3 - Supplement Tic Tac Toe
 * _____________________________________________________________________
 * This program plays a game of tic tac toe. First, it receives as input
 * two names and assigns the token variables 'X' or 'O' to each name
 * accordingly. From there, a function initializes all the elements in the
 * two dimensional board created by another function (DisplayBoard) to a
 * space. Then, a function that gets and checks the input of the user that
 * makes a move on the tic tac toe board (i.e. the column & the row number)
 * to see if the row and column are within range of the maximum amount of
 * rows and columns of the board.
 * _____________________________________________________________________
 * INPUTS:
 *	 playerX: The first player that will always receive the token X.
 *   playerO: The second player that will always receive the token O.
 ***********************************************************************/

//Global constants go here
const int NUM_ROWS = 3;
const int NUM_COLS = 3;

//All the prototypes for the functions
/*************************************************************************
 * PrintHeader
 *  This function receives an assignment name, type, and number the
 *  outputs the appropriate header - returns nothing
 *  by value or by reference OR anything affected by the function>
 *
 * RETURNS: nothing
 * -> Displays the header
 *************************************************************************/
string PrintHeader(char   prType,     // IN - Project Type
                                      //    - (LAB or ASSIGNMENT)
                   string programmer, // IN - Programmer(s)
                   int    prNum,      // IN - Project Number
                   string prName);	  // IN - Project Name


/**************************************************************************
 * OutputInstructions
 *  This function outputs instructions to the users. There are no input
 *  or output parameters for this function as it only displays text to
 *  the screen.
 *
 *  RETURNS: nothing
 *  -> Displays the instructions to the user
 *************************************************************************/
void OutputInstructions();


/**********************************************************************
 * InitBoard
 * 	  This function initializes each sopt in the board to a space ' '.
 *
 * RETURNS: Board initialized with all spaces
 *********************************************************************/
void InitBoard(char boardAr[][NUM_COLS]); // OUT - tic tac toe board


/**********************************************************************
 * DisplayBoard
 *  This function outputs the tic tac toe board including the tokens
 *  played in the proper format (as described below).
 *
 *       1       2       3
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
 *
 * RETURNS: nothing
 * -> outputs the current state of the board
 *********************************************************************/
void DisplayBoard(const char boardAr [][NUM_COLS]); // IN - the board


/**********************************************************************
 * GetPlayers
 *  This function prompts the user to enter two names and passes those two
 *  names back to main by reference.
 *
 * RETURNS: the players names through the variables playerX and playerO
 *********************************************************************/
void GetPlayers(string& playerX,	// IN - first player
				string& playerO);	// IN - second player


/**********************************************************************
 * GetAndCheckInp
 *  This function receives a two dimensional array (tic tac toe board), a
 *  token character, and the name of a player, and prompts the user to enter
 *  in a column & row number. The function error checks those two
 *  numbers to make sure that the numbers inputed are within range of the
 *  rows and columns of the array, as well as if the spot is taken or not.
 *  If the two numbers are valid, then the spot gets assigned a token value.
 *
 * RETURNS: the validation of the input.
 *********************************************************************/
void GetAndCheckInp(char board [][NUM_COLS], // IN - the tic tac toe board
					char token,				 // IN - the token character
					string playerX, 		 // IN - player X's name
					string playerO);	  	 // IN - player O's name


/**********************************************************************
 * SwitchToken
 *  This function switches the active player.
 *  It takes in a parameter representing the current player's token
 *  as a character value (either an X or an O) and returns the opposite.
 *  For example, if this function receives an X it returns an O. If it
 *  receives an O it returns an X.
 *
 * RETURNS: the token opposite of the one in which it receives.
 *********************************************************************/
char SwitchToken(char token);	// IN - current player's tkoen ('X' or 'O')


/**********************************************************************
 * CheckWin
 *  This function checks to see if either player has won. Once it is
 *  possible for a win condition to exist, this should run after each
 *  player makes a play.
 *
 * RETURNS: the character value of the player that won or a value that
 * 	 indicates a tie.
 *********************************************************************/
char CheckWin(const char boardAr[] [NUM_COLS]); // IN - tic tac toe board


/**********************************************************************
 * OutputWinner
 *  This function receives as input a character indicating which player
 *  won or if the game was a tie and outputs an appropriate message.
 *  This function does not return anything as it simply outputs the
 *  appropriate message to the screen.
 *
 * RETURNS: nothing
 * -> Displays the winner's name
 *********************************************************************/
void OutputWinner(char whoWon,	  // IN - represents the winner or a value
								  // 	  indicating a tied game.
				  string playerX, // OUT - player X's name
				  string playerO);// OUT - player O's name

#endif
