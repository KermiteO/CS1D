/*************************************************************************
 * AUTHOR		: Omar Kermiche
 * ASSIGNMENT#11: Directed Graphs
 * CLASS		: CS1D
 * SECTION 		: M/W 3pm
 * DUE DATE		: 4/12/17
 ************************************************************************/

#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
#include <functional>
#include "graphs.h"
using namespace std;


//The header of the assignment
void PrintHeader(const string PROGRAMMER,  // IN - programmers names
				 const string CLASS,	   // IN - class
				 const string SECTION,     // IN - section of day/time
				 const int    LAB_NUM,     // IN - lab number
				 const string LAB_NAME,    // IN - lab name
				 char         asType,	   // IN - type of task
				 ostream& outLoc);	   	   // IN & OUT - the ostream var.




#endif /* HEADER_H_ */
