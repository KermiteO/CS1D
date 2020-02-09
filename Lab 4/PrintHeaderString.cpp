/**************************************************************************
 * AUTHOR     : Ikrit and Kermite
 * LAB #04    : Intro to arrays
 * CLASS      : CS1B
 * SECTION    : TuTh: 8am
 * DUE DATE   : 02/05/15
 * ***********************************************************************/

#include "Header.h"

/**************************************************************************
 * FUNCTION PrintHeader
 *_________________________________________________________________________
 *	This function receives lab or assignment information and
 *	outputs the appropriate header as a string.
 *_________________________________________________________________________
 *************************************************************************/
string PrintHeader(char   prType,     // IN - Project Type
                                      //    - (LAB or ASSIGNMENT)
                   string programmer, // IN - Programmer(s)
                   int    prNum,      // IN - Project Number
                   string prName)     // IN - Project Name

{
	ostringstream output;             // OUT - String variable

	output << left;
	output << "*************************************************\n";
	output << "* PROGRAMMED BY : " << programmer;
	output << "\n*" << setw(15) << " CLASS"   << ": CS1B";
	output << "\n*" << setw(15) << " SECTION" << ": TuTh 8am";
	output << "\n*";
	if (toupper(prType) == 'L')
	{
		output << " Lab #" << setw(9);
	}
	else
	{
		output << " ASSIGNMENT #" << setw(2);
	}
	output << prNum << ": " << prName;
	output << "\n*************************************************\n\n";
	output << right;

	return output.str();
}

