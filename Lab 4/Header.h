/**************************************************************************
 * AUTHOR     : Ikrit and Kermite
 * LAB #04    : Intro to arrays
 * CLASS      : CS1B
 * SECTION    : TuTh: 8am
 * DUE DATE   : 02/05/15
 * ***********************************************************************/
#ifndef HEADER_H_
#define HEADER_H_


#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;


// Prints Project Header (ostringstream)
string PrintHeader(char   prType,     // IN - Project Type
                                      //    - (LAB or ASSIGNMENT)
                   string programmer, // IN - Programmer(s)
                   int    prNum,      // IN - Project Number
                   string prName);    // IN - Project Name

// Gets strings and stores into array
void GetStringAr(string stringArF[],
				 const int AR_SIZEF,
				 string stringType);

// Searches a string array for the number of instances
void SearchStringArInstances(string stringArF[],
		                     const int AR_SIZEF);


#endif /* HEADER_H_ */
