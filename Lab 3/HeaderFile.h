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
#include <time.h>
#include <sstream>
using namespace std;

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

/**********************************************************************
 * FUNCTION FlipCoin
 * ___________________________________________________________________
 * This function generates coin flip and displays results of coin
 * the toss.
 *********************************************************************/
int FlipCoin(int flip,			//CALC		 - used for random number
								//			   generator
			bool result,		//OUT 		 - a bool value of true or
								//			   false
			int &headCount,		//CALC & OUT - the # of instances of heads
			int &sumCount);		//CALC & OUT - the total number of flips

/**********************************************************************
 * FUNCTION UserInput
 * ___________________________________________________________________
 * This function receives user's name and their gender - returns both.
 **********************************************************************/
void UserInput(string &name, char &gender);

/**********************************************************************
 * FUNCTION AverageCalc
 * ___________________________________________________________________
 * This function calculates the average time the coin flipped heads.
 *********************************************************************/
int AvgCalc(int &sumCount, float averageHead, int &headCount);

/**********************************************************************
 * FUNCTION OutputResults
 * ___________________________________________________________________
 * This function outputs the results of the game/program.
 *********************************************************************/
void OuputResults(int &sumCount, int &averageHead, int &headCount,
				  int averageTotal);
#endif
