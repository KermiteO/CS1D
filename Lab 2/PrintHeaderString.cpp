/***********************************************************************
 * AUTHOR		  : BEAK & Kermite
 * LAB #2 		  : Intro to Functions - GCD
 * CLASS		  : CS1B
 * SECTION		  : TTH 0800
 * DUE DATE		  : 3FEB2015
 ***********************************************************************/
#include "LAB2_HEADER.h"
/*************************************************************************
 * FUNCTION PrintHeaderString
 *________________________________________________________________________
 * This function receives an assignment name, type, number, and programmer
 * 		name(s) then returns the appropriate class header as a string
 * 		- returns string -> returns the class heading as a string
 *________________________________________________________________________
 * PRE-CONDITIONS
 * 		assName  : Assignment Name has to be previously defined
 * 		assType  : Assignment Type has to be previously defined
 * 		assNum   : Assignment Number has to be previously defined
 * 		progName : Programmer Name has to be previously defined
 * POST-CONDITIONS
 * 		This function will output the class heading
 *************************************************************************/
string PrintHeaderString(string assName,		// IN - Assignment Name
				 	 	 char   assType,		// IN - Assignment/Lab type
				 	 	 string assNum,			// IN - assignment number
				 	 	 string progName)		// IN - Programmers Name
{
	ostringstream output;

	output << left;
	output << "*****************************************************";
	output << "\n*  PROGRAMMED BY  : " << progName;
	output << "\n*  " << setw(15) << "CLASS" << ": CS1B";
	output << "\n*  " << setw(15) << "SECTION" << ": TTh: 0800 - 1150";
	output << "\n*  ";

	//OUTPUT - If assignment type is 'L', output LAB #. if the assignment
	//		   type is anything else output "ASSIGNMENT #".
	//		   toupper() function makes this case-insensitive.
	if (toupper(assType) == 'L')
	{
		output << "LAB #" << setw(10);
	}
	else
	{
		output << "ASSIGNMENT #" << setw(3);
	}
	output << assNum << ": " << assName;
	output << "\n*****************************************************\n\n";
	output << right;

	return output.str();
}
