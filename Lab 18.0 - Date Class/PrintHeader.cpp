/**********************************************************************
 * AUTHOR(S)	: Kermite & Miss Lame
 * Lab #18		: Date Class
 * CLASS		: CS1B
 * SECTION		: TuTh 8:00a - 11:50a
 * DUE DATE		: 4/28/15
 *********************************************************************/

#include "HeaderFile.h"

/**********************************************************************
 * FUNCTION PrintHeader
 * ___________________________________________________________________
 * This function receives an assignment name, type, and number the
 * outputs the appropriate header - returns nothing
 * ___________________________________________________________________
 * PRE-CONDITIONS
 * 		asName: assignment name has to be previously defined
 * 		asType: assignment type has to be previously defined
 * 		asNum : assignment number has to be previously defined
 *
 * POST-CONDITIONS
 * 		This function will output the class heading.
 * 		<Post-conditions are the changed outputs either passed
 * 		by value or by reference OR anything affected by the function>
 *********************************************************************/
string PrintHeader(char   prType,     // IN - Project Type(Lab or Ass.)
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
