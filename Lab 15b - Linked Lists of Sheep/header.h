/*************************************************************************
 * AUTHOR		: Kermite & Clover
 * LAB #15      : Arrays & Linked Lists for FarmList
 * CLASS		: CS1B
 * SECTION		: T/TH 8am
 * DUE DATE		: 4/9/15
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
#include "Sheep.h"
using namespace std;

enum SheepMenu
{
	EXIT,
	ADDSHEEP,
	OUTPUTFIRST,
	FINDSHEEP,
	LISTSIZE,
	OUTPUTLIST,
	CLEARLIST
};

// GLOBAL CONSTANTS
const string         PROGRAMMER	 = "Kermite & Clover";
const string         CLASS       = "CS1B";
const string         SECTION     = "T/Th 8am";
const string         AS_NAME     = "Arrays & Linked Lists of Sheep";
const char	         AS_TYPE     = 'L';
const unsigned short AS_NUM	     = 15;
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
* DisplayOneSheep
* This function will display all the info for a single sheep in table
* format. Returns -> nothing
**************************************************************************/
void DisplayOneSheep(Sheep oneSheep); // PROC&OUT - a specific sheep

/**************************************************************************
*ConvertIntToEnumType
* This function will receive and integer ad as a parameter and it will
* This convert those integers to Enumerated type. Then, these values will
* This  determine what search are we looking for and when to terminate
* This  the program
**************************************************************************/
SheepMenu ConvertIntToEnumType(int choiceF); // IN&OUT - the comm choice

#endif /* HEADER_H_ */
