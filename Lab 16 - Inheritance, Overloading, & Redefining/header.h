/*************************************************************************
 * AUTHOR		: Kermite & Flash Gordon
 * LAB #16      : Inheritance, Overloading, Redefining
 * CLASS		: CS1B
 * SECTION		: T/TH 8am
 * DUE DATE		: 4/21/15
 *************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <ios>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include "SheepList.h"
#include "PigList.h"
using namespace std;

enum MenuOption
{
	EXIT,
	INIT_SHEEP,
	INIT_PIGS,
	CHANGE_AGE,
	DISPLAY
};

enum MenuOption2
{
	EXIT_TWO,
	INIT_ANIMALS,
};

const unsigned short PROMPT_COL  = 14;
const unsigned short DISPLAY_COL = 8;
const short 		 NAME_COL    = 14;
const short 		 GEN_COL     = 11;
const short 		 AGE_COL	 = 3;
const short 		 NUM_COL 	 = 10;


// FUNCTION DECLARATIONS
/*************************************************************************
 * PrintHeaderStream
 *  This function will output the header, including the names of the
 *  programmers, class and assignment information.
 *  - returns: the class header as a string stream
 ************************************************************************/
string PrintHeaderStream(const string PROGRAMMER,// IN - name of programmer
					     const string CLASS,	 // IN - class abbreviation
					     const string SECTION,	 // IN - class day/time
					     const string AS_NAME,   // IN - name of assign
					     const char   AS_TYPE,   // IN - assign or lab
					     const int    AS_NUM);	 // IN - assign or lab #

/**************************************************************************
* MenuOptions
*  This function displays the menu of options that give you the choice of
*  either exiting the program or initializing the animals.
*  Returns -> nothing
**************************************************************************/
void MenuOptions();

/**************************************************************************
* GetAndCheckIntInp
*  This function prompts the user a prompt and receives integer input.
*  It will error check the input and check if it is within boundaries.
*  It will return the valid integer input.
**************************************************************************/
int GetAndCheckIntInp(string prompt,// IN - prompt for user
					  int    min,   // IN - minimum boundary
				      int    max);  // IN - maximum boundary

/**************************************************************************
 * StringToWool
 *  This function receives a wool type and will convert the string
 *  to its corresponding enum type. Returns -> enum type
 *************************************************************************/
WoolType StringToWool(string currentWool); // IN - string to convert

/**************************************************************************
 * WoolToString
 *  This function receives a WoolType and will convert the enum
 *  to its corresponding string. Returns -> string representing WoolType
 *************************************************************************/
string WoolToString(WoolType currentWool); // IN - WoolType to convert

/**************************************************************************
 * WoolToString
 *  This function receives a TailType and will convert the enum
 *  to its corresponding string. Returns -> string representing TailType
 *************************************************************************/
string TailToString(TailType tailType); // IN - TailType to convert

/**************************************************************************
 * StringToTail
 *  This function receives a tail type and will convert the string
 *  to its corresponding enum type. Returns -> enum type
 *************************************************************************/
TailType StringToTail(string tailString); // IN - string to convert

/**************************************************************************
 * OuputLine
 *    This function receives the type of line to output and the size of the
 * 	  line and returns a line of that type.
 * 	  -Returns -> A string of the given character and length
 *************************************************************************/
string OutputLine(char lineType, //IN - Character to fill the line with
				  int lineSize); //IN - Size of the line


#endif /* HEADER_H_ */
