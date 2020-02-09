/**********************************************************************
 * AUTHOR		: Kermite
 * Ass #5		: Searching Link Lists
 * CLASS		: CS1B
 * SECTION		: TuTh 8:00a - 11:50a
 * DUE DATE		: 3/3/15
 *********************************************************************/

#include "HeaderFile.h"

/**********************************************************************
 * FUNCTION TitleOutput
 *___________________________________________________________________
 * This function receives a node, and an output file, (by reference),
 * and will output all the necessary info based on the title command.
 * This function is to shorten OutputNode. Returns -> nothing
 *___________________________________________________________________
 * PRE-CONDITIONS
 * 		perPtrF		  : the pointer that represents a node in the list
 * 		outfileF	  : the output file
 * POST-CONDITIONS
 * 		This function will output a specific movie, including its
 * 		synopsis, to the output file.
 *********************************************************************/
void TitleOutput(DvdNode *&perPtr, // PROC   - represents a specific node
				 ofstream &outfile)// IN&PROC- the output file
{
	// PROC - output the info for title search to output file
	outfile << endl << setfill('*') << setw(FORM_LINE) << '*' << endl;
	outfile << setfill(' ');
	outfile << "Title: " << perPtr -> title << endl;
	outfile << setfill('-') << setw(FORM_LINE) << '-' << endl;
	outfile << setfill(' ');
	outfile << "Year: " << perPtr -> year;
	outfile << right << setw(16) << "Rating: "
			 << perPtr -> rating << endl;
	outfile << setfill('-') << setw(FORM_LINE) << '-' << endl;
	outfile << setfill(' ');
	outfile << left << setw(PROMPT_COL) << "Leading Actor: "
			 << setw(PROMPT_COL2) << perPtr -> leadRole;
	outfile << "Genre 1: " << perPtr -> genre << endl;
	outfile << setw(PROMPT_COL) << "Supporting Actor: "
			 << setw(PROMPT_COL2) << perPtr -> supRole;
	outfile << "Genre 2: " << perPtr -> altGenre << endl;
	outfile << setfill('-') << setw(FORM_LINE) << '-' << endl;
	outfile << setfill(' ');
	outfile << "PLOT:\n";
	//Calls the function that word wraps the plot
	WordWrapPlot(perPtr -> synopsis, outfile);

	outfile << endl;
	outfile << setfill('*') << setw(FORM_LINE) << '*' << endl
			 << endl << setfill(' ');
}
