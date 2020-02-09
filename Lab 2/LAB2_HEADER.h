/***********************************************************************
 * AUTHOR		  : BEAK & Kermite
 * LAB #2 		  : Intro to Functions - GCD
 * CLASS		  : CS1B
 * SECTION		  : TTH 0800
 * DUE DATE		  : 3FEB2015
 ***********************************************************************/
#ifndef LAB2_HEADER_H_
#define LAB2_HEADER_H_

//Preprocessor directives go here
#include <iostream>		// cin, cout
#include <iomanip>		// setw() and right/left
#include <string>		// strings
#include <sstream>		// ostringstream
#include <fstream>		// file streams
using namespace std;

//Global Constants
//User Defined Types

//Function Prototypes
/*************************************************************************
 * PrintHeaderString
 * 		This function receives an assignment name, type, number, and
 * 		programmers name then stores the appropriate class header in a
 * 		string variable and returns that string to the calling function.
 * 		- returns string -> returns the class heading as a string
 ************************************************************************/
string PrintHeaderString(string assName,		// IN - Assignment Name
				   	     char   assType,		// IN - assignment Type
				   	     	 	 	 	 	 	//     (Lab or Assignment)
				   	     string assNum,			// IN - assignment number
				   	     string progName);		// IN - Programmers Name

/*************************************************************************
 * PrintHeaderOstream
 * 		This function receives an ostream variable, assignment name, type,
 * 		number, and programmers name. The function then returns the
 * 		appropriate header via reference through the ostream variable.
 * 		- returns nothing
 ************************************************************************/
void PrintHeaderOstream(ostream &output,	//OUT - output stream
					    string assName,		//IN  - Assignment Name
				   	    char   assType,		//IN  - assignment Type
				   	    	 	 	 	 	//     (Lab or Assignment)
				   	    string assNum,		//IN  - assignment number
				   	    string progName);	//IN  - Programmers Name

/*************************************************************************
 * FindGCD
 * 		This function receives two integers and finds the Greatest Common
 * 		Divisor. The function does this using the euclidean algorithm, or
 * 		by repeatedly modding whichever number is largest by the smaller
 * 		number.
 * 		- returns integer -> Returns GCD to the calling function
 *************************************************************************/
int FindGCD(int num1, 	//IN - integer number 1
			int num2);	//IN - integer number 2

#endif /* LAB2_HEADER_H_ */
