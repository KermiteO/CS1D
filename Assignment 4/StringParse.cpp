/**********************************************************************
 * AUTHOR		: Kermite
 * Ass #4		: Movie List Intro to Link Lists
 * CLASS		: CS1B
 * SECTION		: TuTh 8:00a - 11:50a
 * DUE DATE		: 3/3/15
 *********************************************************************/

#include "HeaderFile.h"

/**********************************************************************
 * FUNCTION StringParse
 *___________________________________________________________________
 * This function receives a title and an outfile variable, and
 * will determine whether the title should be parsed or not so that
 * it fits within the column - returns nothing
 *___________________________________________________________________
 * PRE-CONDITIONS
 * 		title	 : the title of the movie
 * 		outfile  : the output file variable
 * POST-CONDITIONS
 * 		This function will parse the title.
 * 		<Post-conditions are the changed outputs either passed
 * 		by value or by reference OR anything affected by the function>
 *********************************************************************/
void StringParse(string title,		//PROC&OUT - the title of the movie
				 ofstream &outfile) //PROC	   - the output file variable
{
	int strLength;	//PROC - the string length

	strLength = title.length();

	//Outputs to a substring only if the string length exceeds the limit
	if(strLength > TITLE_SIZE)
	{
		outfile << right << setw(15) << "Title: "
				<< title.substr(0, 45) + ELLIPSE << endl;
	}
	else
	{
		outfile << right << setw(15) << "Title: " << title << endl;
	}
}
