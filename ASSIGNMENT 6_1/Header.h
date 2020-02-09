/**************************************************************************
 * AUTHOR		: Kermite & Fireduck
 * LAB #17		: Polymorphism
 * CLASS		: CS1B
 * SECTION		: TTh 0800
 * DUE DATE		: 22APR2015
 *************************************************************************/
#ifndef ASSIGNMENT_6_HEADER_H_
#define ASSIGNMENT_6_HEADER_H_

//Preprocessor directives go here
#include <iostream>		//for cin/cout
#include <iomanip>		//for IO manipulators
#include <string>		//for strings
#include <limits>		//limits
#include <ios>			//streamsize
#include <fstream>		//for file stream
#include "BankList.h"
#include "Account.h"
#include "Savings.h"
#include "Checking.h"
#include "MoneyMarket.h"

using namespace std;

//Global Constants go here
const int MAX_ACCS = 3;


/*************************************************************************
 * PrintHeaderString
 *  This function receives an ostream variable, assignment name, type,
 * 	number, and programmers name. The function then returns the
 * 	appropriate header via reference through the ostream variable.
 * 	- returns nothing
 *************************************************************************/
void PrintHeaderOstream(ostream &output,	// OUT - output stream
						string  assName,	// IN - Assignment Name
						char    assType,	// IN - assignment Type
			 	 	 						//     (Lab or Assignment)
						string  assNum,		// IN - assignment number
						string  progName);	// IN - Programmers Name



#endif /* ASSIGNMENT_6_HEADER_H_ */
