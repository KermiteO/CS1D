/**********************************************************************
 * AUTHOR		: Kermite
 * Assignment #2: Parallel Arrays
 * CLASS		: CS1B
 * SECTION		: MW 8:00a - 11:50a
 * DUE DATE		: 2/9/15
 *********************************************************************/
#ifndef HEADERFILE_H_
#define HEADERFILE_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <fstream>
using namespace std;

/***********************************************************************
 * Parallel Arrays
 * _____________________________________________________________________
 * This program first receives as input the name of an input file and an
 * output file. It will then read in a list of names, id #'s, and balances
 * from an input file. The program will then prompt the user for a name
 * to search for, and when it's found, it outputs to an output file the
 * person's id#, name, and balance. The program keeps prompting for a name
 * until the word done is entered. Then it ends.
 * _____________________________________________________________________
 * INPUTS:
 *	getInfile   : the variable that specifies the input file received as
 *				  input
 *  getOutfile  : the variable that specifies the output file received as
 *  			  input
 *  getName	    : the name
 * OUTPUTS:
 * 	sumBalance  : the total sum of the balances
 *  nameArray[] : the array that specifies the name to be outputed based
 *  			  on the index number
 *  getID[]     : the array that specifies the id# to be outputed based
 *  			  on the index
 *  balanceDue[]: the array that specifies a balance  to be outputed based
 *  			  on the index
 ***********************************************************************/

//All the prototypes for the functions
/**********************************************************************
 * FUNCTION PrintHeader
 * ___________________________________________________________________
 * This function receives an assignment name, type, and number the
 * outputs the appropriate header - returns nothing
 * by value or by reference OR anything affected by the function>
 *********************************************************************/
string PrintHeader(char   prType,     // IN - Project Type
                                      //    - (LAB or ASSIGNMENT)
                   string programmer, // IN - Programmer(s)
                   int    prNum,      // IN - Project Number
                   string prName);	  // IN - Project Name


/***********************************************************************
 * FUNCTION InputArray
 * ___________________________________________________________________
 * This function receives 3 parallel arrays, an array size, and returns
 * nothing -> This will read in data from the input file
 * heading to the output file.
 ***********************************************************************/
void InputArray(string nameArrayF[], //IN - the array for the names
			    int getIDF[],		 //IN - the array for the id#'s
			    float balanceDueF[], //IN - the array for the balances due
			    const int AR_SIZE);	 //IN - the array size constant

/***********************************************************************
 * FUNCTION SearchStringArray
 * ___________________________________________________________________
 * This function receives a name, a string array, and an array size, and
 * returns an index number.
 ***********************************************************************/
int SearchStringArray(string getName,	       //IN - the name of the being
					  const string STRING_AR[],//IN - array for the names
					  const int AR_SIZE);      //IN - the array size

#endif
