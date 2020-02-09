/**********************************************************************
 * AUTHOR		: Kermite
 * Ass #5		: Searching Link Lists
 * CLASS		: CS1B
 * SECTION		: TuTh 8:00a - 11:50a
 * DUE DATE		: 3/24/15
 *********************************************************************/
#ifndef HEADERFILE_H_
#define HEADERFILE_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include <limits>
#include <ios>

using namespace std;

/***************************************************************************
 * Searching Linked Lists
 * _____________________________________________________________________
 * This program will utilize a link list in which each node contains a
 * movie and its corresponding information, obtained from an input file.
 * The user will then be prompted to choose a menu option (numbers 0-6) that
 * specifies whether they want to output the entire link list to the output
 * file, or they would like to search the link list for a specific instance
 * of certain movie info. The program will then ask the user what type of
 * movie information they would like to search for (title, genre, year, or
 * rating), and then perform the search. If the specified movie or
 * occurrences of that movie is found, then the program will tell you so and
 * tell you the # of times that movie appeared in the link list. It ends once
 * the user presses 0.
 * _____________________________________________________________________
 * INPUT:
 *		getInputFile : the name of the input file
 *		getOutputFile: the name of an output file
 *		commandInput : a command choice from the list of menu options
 *		enterTitle   : the name of a title
 *		dvdSrchStr   : the name of an actor or genre that you want to search
 *		dvdSrchInt	 : the number year or rating you want searched
 * OUTPUT:
 *		perPtrF		 : a node that has all the info for a specific movie
 ***************************************************************************/
//enum Declaration for the menu choice
enum CommandMenu{ EXIT,
				  LIST,
		   	      TITLE,
				  GENRE,
				  ACTOR,
				  YEAR,
				  RATING
		  	    };

//Struct declaration for dvd records
struct DvdNode
{
	string   title;
	string   leadRole;
	string   supRole;
	string   genre;
	string   altGenre;
	int      year;
	int	     rating;
	string   synopsis;
	DvdNode *next;
};

//Global Constants go here
const int FORM_LINE   = 75;
const int PROMPT_COL  = 18;
const int PROMPT_COL2 = 25;
const int MAX_LENGTH  = 74;
const int TITLE_SIZE  = 49;
const int GEN_COL     = 19;
const char SPACE	  = ' ';
const string ELLIPSE = "... ";

//All the prototypes for the functions
/****************************************************************************
 * PrintHeader
 *  This function receives an assignment name, type, and number the
 *  outputs the appropriate header - returns nothing
 *  by value or by reference OR anything affected by the function>
  ****************************************************************************/
string PrintHeader(char   prType,     // IN - Project Type
                                      //    - (LAB or ASSIGNMENT)
                   string programmer, // IN - Programmer(s)
                   int    prNum,      // IN - Project Number
                   string prName);	  // IN - Project Name

/****************************************************************************
 * OutputMenu
 *  This function will only be specified to only output the menu to the user
 *  so the user can select the desired command
 ****************************************************************************/
void OutputMenu();

/****************************************************************************
 * GetAndCheckCharResponse
 * 	This function receives two boundary values and a string prompt and
 * 	uses them to error check the input that prompts the user to enter in an
 * 	integer. It then first checks to see if the value inputed is indeed
 * 	an integer or if the integer is a boundary value, if not, it outputs the
 * 	necessary statement, but if the command is valid, then invalid gets
 * 	set to false and the loop ends.
 * 	returns integer -> returns a number value between bound1 & bound2
 ****************************************************************************/
int GetAndCheckIntResponse(int bound1F,	   		  // IN&PROC- 1st boundary value
						   int bound2F,	   		  // IN&PROC- 2nd boundary value
						   string promptF, 		  // IN&OUT - the input prompt
						   const int PROMPT_SIZE);//IN&PROC - the prompt size

/****************************************************************************
 * ConvertIntToStr
 *  This function receives a number value from the function call and will
 *  convert that number to a string using ostringstream. Returns -> a string
 ****************************************************************************/
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

/****************************************************************************
ConvertIntToEnumType
	*This function will receive and integer ad as a parameter and it will
	*This convert those integers to Enumerated type. Then, these values will
	*This  determine what search are we looking for and when to terminate
	*This  the program
 ****************************************************************************/
CommandMenu ConvertIntToEnumType(int choiceF); // IN&OUT - the comm choice

/****************************************************************************
 * CreateLinkList
 *  This function receives an input file and uses all the information
 *  found in that file to create a link list of movies - returns the head
 *  of the link list by value.
 ****************************************************************************/
DvdNode *CreateLinkList(string &getInputFile); // IN - the input file name

/****************************************************************************
 * ConvertEnumToString
 *  This function receives a command choice and will convert the enum
 *  command to its corresponding string. Returns -> string
 ****************************************************************************/
string ConvertEnumToString(CommandMenu listChoice); // PROC&OUT - command choice

/****************************************************************************
 * SearchNodeInstance
 *  This function receives a link list, a command choice, a search item of
 *  type string, an output file variable, a search item of type int,
 *  a variable representing the # of movie occurrences, and a boolean
 *  variable. It will take all of those arguments and search a link list
 *  for the # of times that specified command choice appears for each movie
 *  in the list. Everytime a movie is found, it gets outputed to the file.
 *  Returns -> variables of type (ofstream, int & bool)
 ****************************************************************************/
void SearchNodeInstance(DvdNode *headF,	         // IN      - original link list
						CommandMenu searchChoice,// IN&PROC - command choice
						string strSrchItem,		 // PROC	- string search item
						ofstream &outfileF,		 // PROC	- the outfile var
						int intSrchItem,		 // PROC    - int search item
						int &numInstancesF,  	 // PROC    - # of inst. of movie
						bool &foundF);			 // PROC    - a found movie

/**********************************************************************
 * ListOutputSearch
 *  This function will prompt user to enter in specific dvd info to be
 *  searched & will search a link list for all the occurrences & output
 *  corresponding statements specifying whether that movie was found.
 *  Returns -> nothing
 *********************************************************************/
void ListOutputSearch(DvdNode *headF,	         // IN     - original link list
					  CommandMenu &searchChoiceF,// IN&PROC- command choice
					  ofstream &outfileF);	     // PROC   - the outfile variable

/****************************************************************************
 * OutputNode
 *  This function receives a node, an output file, (by reference), a command
 *  choice, a string search item, an int search item and a movie number,
 *  and outputs a specific movie to the output file from the link list.
 *  Returns -> nothing
 ****************************************************************************/
void OutputNode(DvdNode *&perPtrF,		 // PROC   - represents a specific node
				ofstream &outfileF,  	 // IN&PROC- the output file
				CommandMenu &listChoiceF,// PROC   - the command choice
				string stringItem,		 // PROC   - a string search item
				int	numItem,		     // PROC   - an int search item
				int &movieCountF);		 // PROC   - the movie number

/****************************************************************************
 * TitleOutput
 *  This function receives a node, and an output file, (by reference),
 *  and will output all the necessary info based on the title command.
 *  This function is to shorten OutputNode. Returns -> nothing
 ****************************************************************************/
void TitleOutput(DvdNode *&perPtr,  // PROC   - represents a specific node
				 ofstream &outfile);// IN&PROC- the output file

/****************************************************************************
 * WordWrapPlot
 *  This function receives a synopsis and an outfile variable by reference,
 *  and will word wrap the plot so that each synopsis for each movie will
 *  be formated properly. -returns nothing
 ****************************************************************************/
void WordWrapPlot(string synopsis,	 //PROC&OUT - the plot of movie
				  ofstream &outfile);//PROC	   - the outfile variable

/****************************************************************************
 * FUNCTION SearchTableOutput
 * This function receives an output file, (by reference), and will
 * output a table used w.r.t. the specified search command. This
 * function is also to shorten OutputNode. Returns -> nothing
 ****************************************************************************/
void SearchTableOutput(ofstream &outfile); // IN&PROC- the output file

/****************************************************************************
 * StringParse
 *  This function receives a title, an actor, a supActor, and an outfile
 *  variable, and will determine whether the title should be parsed or
 *  not so that it fits within the column - returns nothing
 ****************************************************************************/
void StringParse(string &title,		//PROC&OUT - the title of the movie
				 string &actor,		//PROC&OUT - the lead actor
				 string &supActor,  //PROC&OUT - the supporting actor
				 ofstream &outfile);//PROC	   - the output file variable

#endif
