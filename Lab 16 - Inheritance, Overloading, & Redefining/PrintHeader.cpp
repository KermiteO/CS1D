/*************************************************************************
 * AUTHOR		: Kermite & Flash Gordon
 * LAB #16      : Inheritance, Overloading, Redefining
 * CLASS		: CS1B
 * SECTION		: T/TH 8am
 * DUE DATE		: 4/21/15
 *************************************************************************/

#include "header.h"

/*************************************************************************
 * FUNCTION PrintHeaderStream
 *_______________________________________________________________________
 * This function will output the header, including the names of the
 * programmers, class and assignment information. Returns -> a string stream
 * _______________________________________________________________________
 * PRE-CONDITIONS:
 * 		PROGRAMMER  : predefined in main
 * 		CLASS		: predefined in main
 * 		SETION		: predefined in main
 * 		ASSIGN_NUM  : predefined in main
 * 		ASSIGN_TYPE : predefined in main
 * 		ASSIGN_NAME : predefined in main
 * POST-CONDITIONS:
 * 		This function will return the class heading as a string
 ************************************************************************/
string PrintHeaderStream(const string PROGRAMMER,// IN - name of programmer
					     const string CLASS,	 // IN - class abbreviation
					     const string SECTION,	 // IN - class day/time
					     const string AS_NAME,   // IN - name of assign
					     const char   AS_TYPE,   // IN - assign or lab
					     const int    AS_NUM)	 // IN - assign or lab #
{
	ostringstream output;

	output << left;
	output << "*********************************************************";
	output << "\n*  PROGRAMMED BY : " << PROGRAMMER;
	output << "\n*  " << setw(14) << "CLASS"  << ": " << CLASS;
	output << "\n*  " << setw(14) << "SECTION"  << ": " << SECTION;
	if (toupper(AS_TYPE) == 'L')
	{
		output << "\n*  LAB #" << setw(9);
	}
	else
	{
	output << "\n*  ASSIGNMENT #" << setw(2);
	}
	output << AS_NUM << ": " << AS_NAME;
	output << "\n*********************************************************\n";
	output << right;

	return output.str();
}
