/**********************************************************************
 * AUTHOR		: Kermite
 * Ass #4		: Movie List Intro to Link Lists
 * CLASS		: CS1B
 * SECTION		: TuTh 8:00a - 11:50a
 * DUE DATE		: 3/3/15
 *********************************************************************/

#include "HeaderFile.h"

/**********************************************************************
 * FUNCTION OutputLinkList
 *___________________________________________________________________
 * This function receives a link list and the name of an output file
 * (by reference), and outputs all the movies to the output file
 * from the link list;
 *___________________________________________________________________
 * PRE-CONDITIONS
 * 		head		  : the pointer variable that represents the link
 * 						list
 * 		getOutputFile : the name of the output file
 * POST-CONDITIONS
 * 		This function will output all the movies stored in the link list
 * 		<Post-conditions are the changed outputs either passed
 * 		by value or by reference OR anything affected by the function>
 *********************************************************************/
void OutputLinkList(DvdNode *head,			// IN&OUT  - the link list
					string &getOutputFile)	// IN&PROC - the output file
{
	int movieIndex;		// IN&OUT - the movie index number
	ofstream outfile;	// PROC   - the outfile variable
	DvdNode *perPtr;	// PROC   - the pointer variable that points to
						//			each node in the link list

	//Open the output file
	outfile.open(getOutputFile.c_str());

	//Initialize - the movie index # to zero and assign perPtr to the head
	movieIndex = 0;
	perPtr = head;

	//PROC&OUT - outputs all the data in a node so long as perPtr doesn't
	//			 reach the tail of the link list
	while(perPtr != NULL)
	{
		outfile << setfill('*') << setw(FORM_LINE) << '*' << endl;
		outfile << setfill(' ');
		outfile << left << "MOVIE #: " << movieIndex + 1;

		//Call the function that determines whether to output a sub-string
		//for the title
		StringParse(perPtr -> title, outfile);

		outfile << setfill('-') << setw(FORM_LINE) << '-' << endl;
		outfile	<< setfill(' ');
		outfile << left << "Year: " << perPtr -> year;
		outfile << right << setw(16) << "Rating: " << perPtr -> rating << endl;
		outfile << setfill('-') << setw(FORM_LINE) << '-' << endl;
		outfile << setfill(' ');
		outfile << left << setw(PROMPT_COL) << "Leading Actor: "
				<< setw(PROMPT_COL2) << perPtr -> leadRole;
		outfile << "Genre 1: " << perPtr -> genre << endl;
		outfile << left << setw(PROMPT_COL) << "Supporting Actor: "
				<< setw(PROMPT_COL2) << perPtr -> supRole;
		outfile << "Genre 2: " << perPtr -> altGenre << endl;
		outfile << setfill('-') << setw(FORM_LINE) << '-' << endl;
		outfile << setfill(' ');
		outfile << left << "PLOT:\n";

		//Calls the function that word wraps the plot
		WordWrapPlot(perPtr -> synopsis, outfile);

		outfile << endl;
		outfile << setfill('*') << setw(FORM_LINE) << '*' << endl << endl;
		outfile << setfill(' ');
		outfile << right;

		//PROC - head points to the next node and gets assigned back to
		//		 perPtr; Increment - the movie index #
		head = perPtr -> next;
		perPtr = head;

		movieIndex++;
	}

	//Close the output file
	outfile.close();
}

