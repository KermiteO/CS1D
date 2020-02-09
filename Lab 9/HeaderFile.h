/**********************************************************************
 * AUTHOR		: Kermite & Maclem
 * Lab #9		: Testing
 * CLASS		: CS1B
 * SECTION		: TTH 8:00a - 11:50a
 * DUE DATE		: 2/19/15
 *********************************************************************/
#ifndef HEADERFILE_H_
#define HEADERFILE_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <sstream>
using namespace std;

//GLOBAL CONSTANT

 const int MAX_CHOC = 4;


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

int GetInt();


int CalcMod(int num1, int num2);

int CalcTotal ( const int numSheep,
				const int numChoc);

void GetOutput(int rem, int total);

#endif
