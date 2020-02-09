/**********************************************************************
 * AUTHOR		: Kermite
 * Ass #4		: Movie List Intro to Link Lists
 * CLASS		: CS1B
 * SECTION		: TuTh 8:00a - 11:50a
 * DUE DATE		: 3/3/15
 *********************************************************************/

#include "HeaderFile.h"

/**********************************************************************
 * FUNCTION WordWrapPlot
 *___________________________________________________________________
 * This function receives a synopsis and an outfile variable (by reference),
 * and will word wrap the plot so that each synopsis for each movie will
 * be formated properly. -returns nothing
 *___________________________________________________________________
 * PRE-CONDITIONS
 * 		synopsis : the plot of the movie
 * 		outfile  : the output file variable
 * POST-CONDITIONS
 * 		This function will format the plot.
 * 		<Post-conditions are the changed outputs either passed
 * 		by value or by reference OR anything affected by the function>
 *********************************************************************/
void WordWrapPlot(string synopsis,	//PROC&OUT - the plot of movie
				  ofstream &outfile)//PROC	   - the outfile variable
{
	int index;			//PROC - the index number
	string plotWord;	//PROC - the word in the synopsis
	string plotLine;	//PROC - the line in the synopsis

	//Initialize - index to zero
	index = 0;

	//PROCESSING - loops so long as the index # did not reach the limit
	//for the total characters of the synopsis
	while(index <= synopsis.length())
	{
		//PROC - selection structure that adds characters to plotWord and
		//plotLine depending on if the character specified by the index #
		//is a space or not. It only outputs if the line & word length
		//exceed the maximum length
		if(synopsis[index] != ' ')
		{
			plotWord += synopsis[index];
		}
		else
		{
			if(plotLine.length() + plotWord.length() > MAX_LENGTH)
			{
				outfile << plotLine << endl;
				plotLine.clear();
			}

			plotLine += plotWord + SPACE;
			plotWord.clear();
		}
		//PROC - accounts for the left over words that didn't get outputed
		//because their combined lengths didn't not exceed the MAX_LENGTH
		if(index == synopsis.length())
		{
			if(plotLine.length() + plotWord.length() > MAX_LENGTH)
			{
				outfile << plotLine << endl << plotWord;
			}
			else
			{
				outfile << plotLine + plotWord;
			}
		}

		//Change - increment the index #
		index++;
	}
}
