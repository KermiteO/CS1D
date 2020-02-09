/*************************************************************************
 * AUTHOR		    : Kermite & Blue
 * LAB #13          : Creating an Ordered List
 * CLASS			: CS 1B
 * DUE DATE		    : 03/24/15
 *************************************************************************/
#ifndef MYHEADER_H_
#define MYHEADER_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
#include <sstream>
#include <fstream>
#include <cmath>
#include <limits>
#include <ios>
using namespace std;

//Global constants go here
const int COL_SIZE = 8;
const int PROMPT_SIZE = 14;
const int COL_SIZE2 = 7;
const int LENGTH_SIZE = 75;

/**************************************************************************
This is a structs that contains the data types of string, int, and float
**************************************************************************/
struct personRec
{
	personRec *prev;   // IN & OUT - points to the previous node
	string     name;   // IN & OUT - name of people
	char       gender; // IN & OUT - gender of person
	int        age;	   // IN & OUT - age of person
	personRec *next;   // IN OUT   - pointer the next node in the list
};

/**************************************************************************
 *ListMenu
 * This is an Enumerated type, we defined our own user defined variables.
 * we will use these variables to make our code easier to follow. These
 * we variables will be used as input commands that will be converted to
 * we integers
**************************************************************************/
enum ListMenu{ EXIT,
		   	   CREATE,
		   	   DISPLAY,
		   	   DISPLAYREV,
		   	   ISEMPTY,
		   	   SEARCH,
		   	   REMOVE,
		   	   CLEAR,
		  	   };

/**********************************************************************
 *PrintHeader
 * This function receives an assignment name, type, and number the
 * outputs the appropriate header - returns nothing
 *********************************************************************/
string PrintHeader(char   prType,     // IN - Project Type(Lab or Ass.)
                   string programmer, // IN - Programmer(s)
                   int    prNum,      // IN - Project Number
                   string prName);     // IN - Project Name

/**************************************************************************
 *OutputMenu
 * This function will only be specified to only output the menu to the user
 * so the user can select the desired command
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
						   const int PROMPT_SIZE);// IN&PROC- the prompt size

/***************************************************************************
 * ConvertIntToStr
 *  This function receives a number value from the function call and will
 *  convert that number to a string using ostringstream. Returns -> a string
 ***************************************************************************/
string ConvertIntToStr(int numVal); // IN&PROC - the number value passed in

/****************************************************************************
 * StringLength
 *  This function receives two strings and returns the necessary length
 *  length of the string that will be used to format the error statements so
 *  their asterix' line up when displayed on the console, depending on which
 *  string is bigger. Returns integer -> returns an integer value
 ****************************************************************************/
int StringLength(string str1, // IN & PROC - the first string
				 string str2);// IN & PROC - the second string

/**************************************************************************
ConvertIntToEnumType
	*This function will receive and integer ad as a parameter and it will
	*This convert those integers to Enumerated type. Then, these values will
	*This  determine what search are we looking for and when to terminate
	*This  the program
**************************************************************************/
ListMenu ConvertIntToEnumType(int choiceF); // IN&OUT - the comm choice

/**************************************************************************
 * CreateDoubleList
 *  This function will create a doubly linked list from an input file that
 *  includes a list of people and each person's corresponding info.
 *  Returns -> a link list
 *************************************************************************/
void CreateDoubleList(personRec *&headF, // IN&PROC - the link list of persons
					  personRec *&tailF);// IN&PROC - points to last node

/**************************************************************************
 * DisplayList
 *  This function will receive a pointer variable representing the link list,
 *  and will output all of the people and their info to the console
 *  so long as there isn't an empty list. Returns -> nothing
 *************************************************************************/
void DisplayList(personRec *&headF); // IN&OUT - pointer variable representing head

/**************************************************************************
 * DisplayReverseList
 *  This function will receive a pointer variable representing the link list,
 *  and will output all of the people and their info to the console
 *  in reverse alphabetical order so long as there isn't an empty list.
 *  Returns -> nothing
 *************************************************************************/
void DisplayReverseList(personRec *tailF);// IN&PROC- points to last node

/**************************************************************************
 IsEmpty
 	 * This function receives a pointer from main as a parameter that
 	 * represents the link list of people. Returns -> a boolean that
 	 * evaluates to true if head is equal to NULL.
 *************************************************************************/
bool IsEmpty(personRec *headF); //IN & PROC - the link list of persons

/**************************************************************************
 * SearchName
 *  This function will use a doubly linked list. It will prompt the user to
 *  enter in a name and then search the link list for the first occurrence of
 *  that name and will output info according to whether the name was found.
 *  Returns -> nothing
 *************************************************************************/
void SearchName(personRec *headF,   // IN&PROC - ptr var. representing head
				string	   getName);// IN&PROC - a name of a person

/**************************************************************************
 * RemoveNode
 *  This function will receive a doubly linked list, two variables pointing
 *  to the front and the end of the list, and a string that was prompted in
 *  main as input. It will then take that string name and search the link
 *  list for the node in the list that contains that person and its info.
 *  Then, it will remove that person's node from the link list.
 *  Returns -> a new doubly linked list
 *************************************************************************/
personRec *RemoveNode(personRec *headF,    // PROC    - front of list/whole list
					  personRec *tailF,    // PROC    - end of list/ whole list
					  string	 inString);// IN&PROC - a name

/**************************************************************************
 * ClearList
 *  This function will receive two pointers; one representing the head
 *  of the link list and another that represents the rear of the list. It
 *  will take those two pointers and will remove all the nodes found in
 *  the link list. Returns -> nothing
 *************************************************************************/
void ClearList(personRec *&headF, // IN&PROC - the link list of persons
		  	   personRec *&tailF);// IN&PROC - points to last node

#endif /* MYHEADER_H_ */
