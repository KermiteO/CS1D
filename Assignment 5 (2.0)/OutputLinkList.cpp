/**********************************************************************
 * AUTHOR		: Kermite
 * Ass #5		: Searching Link Lists
 * CLASS		: CS1B
 * SECTION		: TuTh 8:00a - 11:50a
 * DUE DATE		: 3/3/15
 *********************************************************************/

#include "HeaderFile.h"

/**********************************************************************
 * FUNCTION OutputNode
 *___________________________________________________________________
 *  This function receives a node, an output file, (by reference), a command
 *  choice, a string search item, an int search item and a movie number,
 *  and outputs a specific movie to the output file from the link list.
 *  Returns -> nothing
 *___________________________________________________________________
 * PRE-CONDITIONS
 * 		perPtrF		  : the pointer that represents a node in the list
 * 		outfileF	  : the output file
 * 		listChoiceF	  : the command choice
 * 		stringItem	  : a string search item
 * 		numItem		  : an int search item
 * 		movieCountF   : the movie number
 * POST-CONDITIONS
 * 		This function will output a specific movie and it's info to
 * 		the output file.
 *********************************************************************/
void OutputNode(DvdNode *&perPtrF,		 // PROC   - represents a specific node
				ofstream &outfileF,  	 // IN&PROC- the output file
				CommandMenu &listChoiceF,// PROC   - the command choice
				string stringItem,		 // PROC   - a string search item
				int	numItem,		     // PROC   - an int search item
				int &movieCountF)		 // PROC   - the movie number
{
	string searchString; // PROC&OUT - the list choice converted to a string
	string outfileStr;   // PROC     - used to convert the num srched to a str

	// PROC - Call the function that converts the enum comm choice to string
	searchString = ConvertEnumToString(listChoiceF);

	outfileF << left;
	//PROC - accounts for if the user wants a title search or not 'cause
	//		 only the title search has a different output than the other searches
	if(listChoiceF == TITLE)
	{
		TitleOutput(perPtrF, outfileF);
	}
	else
	{
		//PROC - will only display the tables for movie info if it's the first movie
		if(movieCountF == 1)
		{
			//PROC - will convert the year or rating that's being searched
			//		 to a string to be used in the switch below
			if(listChoiceF == YEAR || listChoiceF == RATING)
			{
				outfileStr = ConvertIntToStr(numItem);
				stringItem = outfileStr;
			}
			//OUT - will output necessary table statement for outfile
			switch(listChoiceF)
			{
				case LIST  : outfileF << "COMPLETE MOVIE LISTING\n";
							  break;
				case GENRE :
				case ACTOR :
				case YEAR  :
				case RATING: outfileF << "\nSearch by " << searchString << " for "
									  << stringItem << " found:\n";
							  break;
				default    :  break;
			}
			// OUT - will output the table used for the searches
			SearchTableOutput(outfileF);
		}
		//OUT - will assign certain # of spaces depending on the movie count
		//so that the numbers and their corresponding lines allign properly
		if(movieCountF <= 9)
		{
			outfileF << setw(3) << ' ' << setfill(' ') << setw(6);
		}
		else
		{
			outfileF << setw(2) << ' ' << setfill(' ') << setw(7);
		}
		outfileF << movieCountF << setw(48);
		//OUT - Call the function that parses a string in a movie when needed
		StringParse(perPtrF -> title, perPtrF -> leadRole, perPtrF -> supRole,
				    outfileF);
		outfileF << perPtrF -> title << setw(8) << perPtrF -> year
				 << setw(5) << perPtrF -> rating << setw(PROMPT_COL)
				 << perPtrF -> genre << setw(20) << perPtrF -> altGenre
				 << setw(20) << perPtrF -> leadRole << setw(PROMPT_COL)
				 << perPtrF -> supRole << endl;
	}
}
