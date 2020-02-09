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
 * This function receives an ostream variable, assignment name, type,
 * number, and programmers name. The function then returns the
 * appropriate header via reference through the ostream variable.
 * Returns -> nothing
 *________________________________________________________________________
 * PRE-CONDITIONS
 * 		output	 : An ostream variable such as cout or ofstream
 * 		assName  : Assignment Name has to be previously defined
 * 		assType  : Assignment Type has to be previously defined
 * 		assNum   : Assignment Number has to be previously defined
 * 		progName : Programmer Name has to be previously defined
 * POST-CONDITIONS
 * 		This function will return the heading to the calling function
 * 		via reference through the ostream variable
 *************************************************************************/
void PrintHeaderOstream(ostream &output,	// OUT - output stream
						string  assName,	// IN - Assignment Name
						char    assType,	// IN - assignment Type
				 	 	 	 	 	 	 	//     (Lab or Assignment)
						string  assNum,		// IN - assignment number
						string  progName)	// IN - Programmers Name
{
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
}
