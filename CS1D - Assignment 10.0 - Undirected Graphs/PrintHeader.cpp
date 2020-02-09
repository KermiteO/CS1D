/*************************************************************************
 * AUTHOR		: Halley Bradt & Omar Kermiche
 * ASSIGNMENT#10: Graphs
 * CLASS		: CS1D
 * SECTION 		: M/W 3pm
 * DUE DATE		: 4/12/17
 ************************************************************************/


#include "header.h"

/**************************************************************************
* FUNCTION PrintHeader
*__________________________________________________________________________
* This function gets information from the main to output the author
*     box in the output file or main.
* _________________________________________________________________________
* PRE-CONDITIONS
* 	asType			: the type must be declared
* 	outLoc			: the ostream file name must be declared
*
* POST-CONDITIONS
* 	This function will only output the author's information to an
* 	output file
* 	outLoc			: the ostream file must be returned
**************************************************************************/

void PrintHeader(const string PROGRAMMER,  // IN - programmers names
				 const string CLASS,	   // IN - class
				 const string SECTION,     // IN - section of day/time
				 const int    LAB_NUM,     // IN - lab number
				 const string LAB_NAME,    // IN - lab name
				 char         asType,	   // IN - type of task
				 ostream& outLoc)	   	   // IN & OUT - the ostream variable

{
	outLoc << left;
	outLoc << "******************************************************";
	outLoc << "\n*  PROGRAMMED BY : " << PROGRAMMER;
	outLoc << "\n*  " << setw(14) << "CLASS" << ": " << CLASS;
	outLoc << "\n*  " << setw(14) << "SECTION" << ": " << SECTION;
	outLoc << endl;
	if(toupper(asType) == 'L')
	{
		outLoc << "*  LAB #" << setw(9);
	}
	else
	{
		outLoc << "*  ASSIGNMENT #" << setw(2);
	}
	outLoc << LAB_NUM << ": " << LAB_NAME;
	outLoc << "\n******************************************************\n\n";
	outLoc << right;
}



