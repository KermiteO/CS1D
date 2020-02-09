/*************************************************************************
 * AUTHOR		    : Hamodi & Kermite
 * LAB #11          : Implementing a stack
 * CLASS			: CS 1B
 * DUE DATE		    : 03/10/15
 *************************************************************************/
#ifndef MYHEADER_H_
#define MYHEADER_H_

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <fstream>
#include <limits>
#include <ios>
using namespace std;

/**************************************************************************
GLOBAL CONSTANTS:
	COL_SIZE   : Will be used to format the output from the function
	PROMPT_SIZE: Will be used to format the prompt questions
**************************************************************************/
const int COL_SIZE = 8;
const int PROMPT_SIZE = 14;
const int COL_SIZE2 = 7;
const int LENGTH_SIZE = 75;

/**************************************************************************
This is a structs that contains the data types of string, int, and float
**************************************************************************/
struct personRec
{
	string     name;   // IN & OUT - name of people
	char       gender; // IN & OUT - gender of person
	int        age;	   // IN & OUT - age of person
	personRec *next;   // IN OUT   - pointer of type MovieList
};

/**************************************************************************
StackMenu
	*This is an Enumerated type, we defined our own user defined variables.
	*we will use these variables to make our code easier to follow. These
	*we variables will be used as input commands that will be converted to
	*we integers
**************************************************************************/
enum StackMenu{ EXIT,
		   	    PUSH,
		   	    POP,
		   	    ISEMPTY,
		   	    PEEK,
		   	    SIZE,
		   	    DISPLAY
		  	   };

/**********************************************************************
 PrintHeader
  	  * This function receives an assignment name, type, and number the
  	  * outputs the appropriate header - returns nothing
 *********************************************************************/
string PrintHeader(char   prType,     // IN - Project Type(Lab or Ass.)
                   string programmer, // IN - Programmer(s)
                   int    prNum,      // IN - Project Number
                   string prName);     // IN - Project Name

/**************************************************************************
OutputMenu
	*This function will only be specified to only output the menu to the user
	*so the user can select the desired command
**************************************************************************/
void OutputMenu();

/**************************************************************************
 * GetAndCheckCharResponse
 * 	This function receives two boundary values and a string prompt and
 * 	uses them to error check the input that prompts the user to enter in an
 * 	integer. It then first checks to see if the value inputed is indeed
 * 	an integer or if the integer is a boundary value, if not, it outputs the
 * 	necessary statement, but if the command is valid, then invalid gets
 * 	set to false and the loop ends.
 * 	returns integer -> returns a number value between bound1 & bound2
 *************************************************************************/
int GetAndCheckIntResponse(int bound1F,	   		  // IN&PROC- 1st boundary value
						   int bound2F,	   		  // IN&PROC- 2nd boundary value
						   string promptF, 		  // IN&OUT - the input prompt
						   const int PROMPT_SIZE);//IN&PROC - the prompt size

/**************************************************************************
ConvertIntToEnumType
	*This function will receive and integer ad as a parameter and it will
	*This convert those integers to Enumerated type. Then, these values will
	*This  determine what search are we looking for and when to terminate
	*This  the program
**************************************************************************/
StackMenu ConvertIntToEnumType(int choiceF); // IN&OUT - the comm choice

/**************************************************************************
PushUser
	*In this function, the program will add a new member into the list that
	*contains a name, gender and an age of a person.
**************************************************************************/
personRec *PushUser(personRec *headF); // IN & OUT - pointer of type personRec

/**************************************************************************
PopUser
	* This function will handle the removal of a person information from
	* the list. The person being removed will be the last person added to
	* the list
**************************************************************************/
personRec *PopUser(personRec *headF); // IN & OUT - pointer of type personRec

/**************************************************************************
PeekUser
	* This function will be used to look for the last person in the list,
	* which is the last person was added and it will then output the name,
	* gender and age of that person in a formated table
**************************************************************************/
void PeekUser(personRec *headF); // IN & OUT - pointer of type personRec

/**************************************************************************
 GetInput
 	 * This function get three parameters that are name, age and gender of
 	 * types, string, in t and a char. These variables will be used to
 	 * input the data into the list and return them into the calling
 	 * function to be used thought out the program.
 *************************************************************************/
void GetInput(string &name,   // IN & OUT - name of the person
			  char   &gender, // IN & OUT - gender of the person
			  int    &age);   // IN & OUT - age of the person

/**************************************************************************
 * GetAndCheckCharResponse
 	 * This function receives a boolean variable and a character variable
 	 * and uses them to error check the input that prompts the user to play
 	 * the game or not. It makes sure that the character entered was either
 	 * yes or no, and it accepts upper and lower case characters.
 	 * returns character -> returns a character value.
 **************************************************************************/
char GetAndCheckCharResponse(bool invalid,	 //PROC - condition for loop
							 char playValid);//IN 	- game validation

/**************************************************************************
 DisplayStack
 	 * This function receives a pointer called HeadF as a parameter that
 	 * represents the link list of people. It then takes each node and
 	 * outputs to the console each person's individual information.
 	 * Returns -> nothing
 *************************************************************************/
void DisplayStack(personRec *headF); // IN & OUT - the link list of persons

/**************************************************************************
 IsEmpty
 	 * This function receives a pointer from main as a parameter that
 	 * represents the link list of people. Returns -> a boolean that
 	 * evaluates to true if head is equal to NULL.
 *************************************************************************/
bool IsEmpty(personRec *headF); //IN & PROC - the link list of persons

/**************************************************************************
 SizeUser
 	 * This function receives a pointer from main as a parameter and it
 	 * will then calculate the size of the stack by counting the number of
 	 * times a person was added or removed from the list
 *************************************************************************/
int SizeUser(personRec *headF); //IN & PROC - the link list of persons

#endif /* MYHEADER_H_ */
