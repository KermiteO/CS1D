/**********************************************************************
 * AUTHOR(S)	: Kermite & Miss Lame
 * Lab #18		: Date Class
 * CLASS		: CS1B
 * SECTION		: TuTh 8:00a - 11:50a
 * DUE DATE		: 4/28/15
 *********************************************************************/
#ifndef HEADERFILE_H_
#define HEADERFILE_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <ios>
#include <sstream>
#include "Date.h"

using namespace std;

enum MenuOptions
{
	EXIT,
	SETDATE,
	DISPLAYDATE,
	RESET
};

//All the prototypes for the functions

/*********************************************************************
 * menu
 *  Displays the menu for the user to select a choice from.
 *  returns nothing
 ********************************************************************/
void Menu();

/**********************************************************************
 * PrintHeader
 *  This function receives an assignment name, type, and number the
 *  outputs the appropriate header - returns nothing
 *  by value or by reference OR anything affected by the function>
 *********************************************************************/
string PrintHeader(char   prType,     // IN - Project Type
                                      //    - (LAB or ASSIGNMENT)
                   string programmer, // IN - Programmer(s)
                   int    prNum,      // IN - Project Number
                   string prName);	  // IN - Project Name

/**************************************************************************
* GetAndCheckIntInp
*  This function prompts the user a prompt, minimum and maximum boundary.
*  It will error check the input and check if it is within boundaries.
*  It will return the valid integer input.
*  RETURNS: returns the valid integer input
**************************************************************************/
int GetAndCheckIntInp (string prompt,      // IN  - prompt for user
				       int    min,         // IN  - minimum boundary
				       int    max);		   // IN  - maximum boundary


/**************************************************************************
* GetLongestStringLength
*  This function will determine which string length is the longest.
**************************************************************************/
int GetLongestStringLength (string str1,  // IN - string one
			                string str2); // IN - string two

/**************************************************************************
* IntegerToString
*  This function converts an integer to string. Returns a string number.
**************************************************************************/
string IntegerToString(int num); // IN - a number

#endif
