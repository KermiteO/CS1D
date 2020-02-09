/**********************************************************************
 * AUTHOR		: Kermite & User
 * Lab #3		: Supplement: Coin Flip
 * CLASS		: CS1B
 * SECTION		: MW 8:00a - 11:50a
 * DUE DATE		: 2/3/15
 *********************************************************************/
#ifndef HEADERFILE_H_
#define HEADERFILE_H_

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
const int FORM_LINE = 75;
const int PROMPT_COL = 18;
const int PROMPT_COL2 = 25;
const int MAX_LENGTH = 74;
const int TITLE_SIZE = 49;
const char SPACE = ' ';
const string ELLIPSE = "... ";


//All the prototypes for the functions
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

/**********************************************************************
 * CreateLinkList
 *  This function receives an input file and uses all the information
 *  found in that file to create a link list of movies - returns the head
 *  of the link list by value.
 *********************************************************************/
DvdNode *CreateLinkList(string &getInputFile); // IN - the input file name

/**********************************************************************
 * OutputLinkList
 *  This function receives a link list and the name of an output file
 *  (by reference), and outputs all the movies to the output file
 *  from the link list;
 *********************************************************************/
void OutputLinkList(DvdNode *head,			// IN&OUT  - the link list
					string &getOutputFile);	// IN&PROC - the output file

/**********************************************************************
 * WordWrapPlot
 *  This function receives a synopsis and an outfile variable by reference,
 *  and will word wrap the plot so that each synopsis for each movie will
 *  be formated properly. -returns nothing
 *********************************************************************/
void WordWrapPlot(string synopsis,	 //PROC&OUT - the plot of movie
				  ofstream &outfile);//PROC	   - the outfile variable




#endif
