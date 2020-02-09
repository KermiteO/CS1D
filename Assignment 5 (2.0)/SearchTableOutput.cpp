/**********************************************************************
 * AUTHOR		: Kermite
 * Ass #5		: Searching Link Lists
 * CLASS		: CS1B
 * SECTION		: TuTh 8:00a - 11:50a
 * DUE DATE		: 3/3/15
 *********************************************************************/

#include "HeaderFile.h"

/**********************************************************************
 * FUNCTION SearchTableOutput
 *___________________________________________________________________
 * This function receives an output file, (by reference), and will
 * output a table used w.r.t. the specified search command. This
 * function is also to shorten OutputNode. Returns -> nothing
 *___________________________________________________________________
 * PRE-CONDITIONS
 * 		perPtrF		  : the pointer that represents a node in the list
 * 		outfileF	  : the output file
 * POST-CONDITIONS
 * 		This function will output the table for the movie searches
 * 		output to the file.
 *********************************************************************/
void SearchTableOutput(ofstream &outfile) // IN&PROC- the output file
{
	outfile << setw(9) << "MOVIE #" << setw(48) << "TITLE" << "YEAR "
			<< setw(8) << "RATING" << setw(18) << "GENRE" << setw(20)
			<< "ALT GENRE" << setw(20) << "LEAD ACTOR" << setw(18)
			<<"SUPPORTING ACTOR" << endl;
	outfile << setfill('-') << setw(7) << '-' << setfill(' ') << " "
			<< setfill('-') << setw(48) << '-' << setfill(' ') << " "
			<< setfill('-') << setw(4) << '-' << setfill(' ') << " "
			<< setfill('-') << setw(6) << '-' << setfill(' ') << " "
			<< setfill('-') << setw(17) << '-' << setfill(' ') << " "
			<< setfill('-') << setw(GEN_COL) << '-' << setfill(' ')
			<< " " << setfill('-') << setw(GEN_COL) << '-'
		    << setfill(' ') << " " << setfill('-') << setw(GEN_COL)
			<< '-' << setfill(' ') << " " << setfill(' ') << endl;
}
