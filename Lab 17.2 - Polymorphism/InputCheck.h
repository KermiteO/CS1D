/**************************************************************************
 * AUTHOR		: Kermite & Fireduck
 * LAB #17		: Polymorphism
 * CLASS		: CS1B
 * SECTION		: TTh 0800
 * DUE DATE		: 22APR2015
 *************************************************************************/

#ifndef INPUTCHECK_H_
#define INPUTCHECK_H_

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>
#include <ios>
using namespace std;

/**************************************************************************
 * FUNCTION GetValidInput
 *_________________________________________________________________________
 * This function will output a preset prompt message which will be passed
 * into the function, it will also accept two integers representing
 * minimum and maximum values and will check to make sure that the user
 * entered an integer between the MIN & MAX, if it is not, the function
 * will output an error message and prompt the user to enter their integer
 * again. If the user inputs a char type value the Function will output a
 * error message and ask for the user to input a integer again.
 * - returns the accepted integer
 *************************************************************************/
int GetValidInput(const string PROMPT,    // IN - Prompt to user
				  const short  PROMPT_W,  // IN - Prompt column width
				  const int    MIN,       // IN - Minimum accepted value
				  const int    MAX);      // IN - maximum accepted value


/**************************************************************************
 * FUNCTION GetValidInput
 *_________________________________________________________________________
 * This function will output a preset prompt message which will be passed
 * into the function, it will also accept two char responses and will check
 * to make sure that the user entered one of the accepted responses, if it
 * is not, the function will output an error message and prompt the user to
 * enter their response again.
 * - returns the accepted character.
 *************************************************************************/
char GetValidInput(string prompt,		// IN - displayed message
				   short  promptWidth,	// IN - message column width
				   char   accepted1,	// IN - one accepted char
				   char   accepted2);	// IN - one accepted char


/**************************************************************************
 * FUNCTION GetValidInput
 *_________________________________________________________________________
 * This function will output a preset prompt message which will be passed
 * into the function, it will also accept four char responses and will
 * check to make sure that the user entered one of the accepted responses,
 * if it is not, the function will output an error message and prompt the
 * user to enter their response again.
 * - returns the accepted upper case character.
 *************************************************************************/
char GetValidInput(string prompt,		// IN - displayed message
				   short  promptWidth,	// IN - message column width
				   char   accepted1,	// IN - One accepted char
				   char   accepted2,	// IN - Second accepted char
				   char   accepted3,	// IN - Third accepted char
				   char   accepted4);	// IN - Fourth accepted char


/**************************************************************************
 * FUNCTION GetValidInput
 *_________________________________________________________________________
 * This function will output a preset prompt message which will be passed
 * into the function, it will also accept five char responses and will
 * check to make sure that the user entered one of the accepted responses,
 * if it is not, the function will output an error message and prompt the
 * user to enter their response again.
 * - returns the accepted upper case character.
 *************************************************************************/
char GetValidInput(string prompt,		// IN - displayed message
				   short  promptWidth,	// IN - message column width
				   char   accepted1,	// IN - One accepted char
				   char   accepted2,	// IN - Second accepted char
				   char   accepted3,	// IN - Third accepted char
				   char   accepted4,	// IN - Fourth accepted char
				   char   accepted5);	// IN - Fifth accepted char


/**************************************************************************
 * FUNCTION GetSetw
 *_________________________________________________________________________
 * This function will compare two strings and find the length of them both
 * and returns the larger length.
 * - returns the larger length
 *************************************************************************/
int GetSetw(string stringOne,  // IN - one string message
			string stringTwo); // IN - one string message

#endif /* INPUTCHECK_H_ */
