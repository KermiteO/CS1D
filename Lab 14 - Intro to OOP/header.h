/*************************************************************************
 * AUTHOR		: Kermite & ChickenLips
 * LAB #14      : Intro to OOP
 * CLASS		: CS1B
 * SECTION		: T/TH 8am
 * DUE DATE		: 3/19/15
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
#include "Animals.h"
using namespace std;

// GLOBAL CONSTANTS
const string         PROGRAMMER	 = "Kermite & ChickenLips";
const string         CLASS       = "CS1B";
const string         SECTION     = "T/Th 8am";
const string         AS_NAME     = "Intro to OOP";
const char	         AS_TYPE     = 'L';
const unsigned short AS_NUM	     = 14;
const unsigned short PROMPT_COL  = 14;
const unsigned short DISPLAY_COL = 8;
const short 		 NAME_COL    = 14;
const short 		 GEN_COL     = 11;
const short 		 AGE_COL	 = 3;
const short 		 NUM_COL 	 = 10;

// ENUM DECLARATIONS: for the two different command menus
enum FirstMenu
{
	EXIT,
	INITANIMALS
};

enum SecondMenu
{
	SECONDEXIT,
	SECINITANIMALS,
	CHANGEAGE,
	CHANGEVALUES,
	DISPLAY
};


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
* AnimalMenu
*  This function provides an animal menu that specifies a different animal.
*  Returns -> nothing
**************************************************************************/
void AnimalMenu (Animals &fluffy, // IN&PROC - the animal Fluffy
				 Animals &maa,	  // IN&PROC - the animal Maa
				 Animals &babe);  // IN&PROC - the animal Babe

/**************************************************************************
* MenuOptions
*  This function displays the menu of options that give you the choice of
*  either exiting the program or initializing the animals.
*  Returns -> nothing
**************************************************************************/
void MenuOptions();

/**************************************************************************
* SecondMenuOptions
*  This function provides a menu of command choices that give you the options
*  of initializing the animals, changing the ages or values, or displaying
*  all the animals and their info. Returns -> nothing
**************************************************************************/
void SecondMenuOptions();

/**************************************************************************
* InitializeAnimals
*  This function initalizes name, age, value, and type to the animals
**************************************************************************/
void InitializeAnimals(Animals &fluffy, // IN&PROC - the sheep fluffy
					   Animals &maa,	// IN&PROC - the sheep maa
					   Animals &babe);	// IN&PROC - the pig babe

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
* GetAndCheckFloatInput
*  This function prompts the user a prompt and receives a float number.
*  It will error check the input and check if it is within boundaries.
*  It will return the valid float input. Returns -> a float
**************************************************************************/
float GetAndCheckFloatInput(string prompt, // IN - prompt for user
						    int    min,    // IN - minimum boundary
						    int    max);   // IN - maximum boundary

/*************************************************************************
 * 	GetAndCheckCharInput
 * 	 This function will accept a single character as input and error
 * 	 check it to ensure is is a valid gender response. Returns -> a char
 *************************************************************************/
char GetAndCheckCharInput(const string PROMPT,// IN - response prompt
						  char  validChar1,	  // IN - valid char response
						  char  validChar2);  // IN - valid char response

/**************************************************************************
* ChangeAge
*  This function changes the age of a particular animal. Returns -> nothing
**************************************************************************/
void ChangeAge(Animals &fluffy,   // OUT - new age of animal fluffy
			   Animals &maa,	  // OUT - new age of animal maa
			   Animals &babe);	  // OUT - new age of animal babe

/**************************************************************************
* ChangeValue
*  This function changes the value of a particular animal. Returns -> nothing
**************************************************************************/
void ChangeValue(Animals &fluffy,   // OUT - new value of animal fluffy
				 Animals &maa,		// OUT - new value of animal maa
				 Animals &babe);	// OUT - new value of animal babe

/**************************************************************************
* DisplayList
*  This function displays all the animals and their corresponding attributes.
**************************************************************************/
string DisplayList(Animals &fluffy, // OUT - current info for animal fluffy
				   Animals &maa,	// OUT - current info for animal maa
				   Animals &babe);	// OUT - current info for animal babe

#endif /* HEADER_H_ */
