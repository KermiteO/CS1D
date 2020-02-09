/*************************************************************************
 * AUTHOR		    : Deboogaloo & Kermite
 * LAB #12          : Implementing a Queue
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
enum QueueMenu{ EXIT,
		   	    ENQUEUE,
		   	    DEQUEUE,
		   	    ISEMPTY,
		   	    FRONT,
		   	    SIZE,
		   	    DISPLAY,
		   	    CLEAR
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

/***************************************************************************
 * ConvertIntToStr
 *  This function receives a number value from the function call and will
 *  convert that number to a string using ostringstream. Returns -> a string
 ***************************************************************************/
string ConvertIntToStr(int numVal); // IN&PROC - the number value passed in

/**************************************************************************
ConvertIntToEnumType
	*This function will receive and integer ad as a parameter and it will
	*This convert those integers to Enumerated type. Then, these values will
	*This  determine what search are we looking for and when to terminate
	*This  the program
**************************************************************************/
QueueMenu ConvertIntToEnumType(int choiceF); // IN&OUT - the comm choice

/**************************************************************************
PeekUser
	* This function will be used to look for the last person in the list,
	* which is the last person was added and it will then output the name,
	* gender and age of that person in a formated table
**************************************************************************/
void FrontUser(personRec *headF); // IN & OUT - pointer of type personRec

/**************************************************************************
 GetInput
 	 * This function get three parameters that are name, age and gender of
 	 * types, string, in t and a char. These variables will be used to
 	 * input the data into the list and return them into the calling
 	 * function to be used thought out the program.
 *************************************************************************/
personRec *GetInput(personRec *perPtrF);   // IN - Pointer holding node info

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
 * DisplayQueue
 *  This function will receive a pointer variable representing the link list,
 *  and will output all of the people and their info to the console
 *  so long as there isn't an empty list. Returns -> nothing
 *************************************************************************/
void DisplayQueue(personRec *headF); // IN&OUT - pointer variable representing head

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

/**************************************************************************
 * Enqueue
 *  This function will receive two pointers; one representing the head
 *  of the link list and another that represents the rear of the list. It
 *  will take those two pointers and will create a new node and incorporate
 *  a new person's info into that new node and then add that node to the
 *  end of the link list. Returns -> nothing
 *************************************************************************/
void Enqueue(personRec *&headF, // IN&PROC - pointer variable representing head
			 personRec *&tailF);// IN&PROC - pointer variable representing tail

/**************************************************************************
 * Dequeue
 *  This function will receive two pointers; one representing the head
 *  of the link list and another that represents the rear of the list. It
 *  will take those two pointers and will remove the node found at the
 *  front of the link list. Returns -> nothing
 *************************************************************************/
void Dequeue(personRec *&headF, // IN&PROC - pointer variable representing head
		     personRec *&tailF);// IN&PROC - pointer variable representing tail

/**************************************************************************
 * ClearQueue
 *  This function will receive two pointers; one representing the head
 *  of the link list and another that represents the rear of the list. It
 *  will take those two pointers and will remove all the nodes found in
 *  the link list. Returns -> nothing
 *************************************************************************/
void ClearQueue(personRec *&headF, // IN&PROC - pointer variable representing head
		 	 	personRec *&tailF);// IN&PROC - pointer variable representing tail

#endif /* MYHEADER_H_ */
