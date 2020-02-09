/*************************************************************************
 * AUTHOR		: Kermite & Flash Gordon
 * LAB #16      : Inheritance, Overloading, Redefining
 * CLASS		: CS1B
 * SECTION		: T/TH 8am
 * DUE DATE		: 4/21/15
 *************************************************************************/

#include "header.h"

/**************************************************************************
 * FUNCTION OuputLine
 *________________________________________________________________________
 *  This function receives the type of line to output and the size of the
 *  line and returns a line of that type.
 * 	-Returns -> A string of the given character and length
 *________________________________________________________________________
 * PRE-CONDITIONS
 * 		lineType : Character or symbol of the line to be printed
 * 		lineSize : Size of the line
 *
 * POST-CONDITIONS
 * 		This function will return a string of the given character and size
 *************************************************************************/
string OutputLine(char lineType, //IN - Character to fill the line with
				  int  lineSize) //IN - Size of the line

{
	ostringstream ss;

	ss << setfill(lineType) << setw(lineSize) << lineType;

	return ss.str();
}
