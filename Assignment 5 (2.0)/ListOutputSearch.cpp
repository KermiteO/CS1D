/**********************************************************************
 * AUTHOR		: Kermite
 * Ass #5		: Searching Link Lists
 * CLASS		: CS1B
 * SECTION		: TuTh 8:00a - 11:50a
 * DUE DATE		: 3/3/15
 *********************************************************************/

#include "HeaderFile.h"

/**********************************************************************
 * FUNCTION ListOutputSearch
 *___________________________________________________________________
 *  This function will prompt user to enter in specific dvd info to be
 *  searched & will search a link list for all the occurrences & output
 *  corresponding statements specifying whether that movie was found.
 *  Returns -> nothing
 *___________________________________________________________________
 * PRE-CONDITIONS
 * 		headF		  : a link list
 * 		listChoiceF	  : the command choice
 * 		outfileF	  : the output file
 * POST-CONDITIONS
 * 		none
 *********************************************************************/
void ListOutputSearch(DvdNode *headF,	         // IN     - original link list
					  CommandMenu &searchChoiceF,// IN&PROC- command choice
					  ofstream &outfileF)	     // PROC   - the outfile variable
{
	//Constant declarations go here
	const int PROMPT_SIZEF = 17;
	//Variable declarations go here
	int    defaultIntF;  // PROC    - the default int if a string is searched
	int    numInstancesF;// PROC    - # of instances of a movie that was found
	int    bound1;	   	 // PROC    - 1st boundary value
    int    bound2;	   	 // PROC    - 2nd boundary value
    int    dvdSrchInt;	 // PROC    - specific dvd string that you want searched
	bool   foundF;		 // PROC    - represents a found movie
	string defaultStrF;  // PROC    - default str if an int is searched
	string movieInfoType;// PROC    - the menu (enum) choice converted to string
	string consoleInput; // IN&PROC - a specific dvd info srch inputed in console
	string prompt; 	 	 // PROC&OUT- the input prompt
	string dvdSrchStr;   // PROC    - dvd str want srched

	//INITIALIZE - the two default variables to corresponding values
	defaultIntF = 999;
	defaultStrF = "Nothing";
	foundF = false;
	numInstancesF = 0;

	// PROC - converts enum type to string and uses that to assign to prompt
	movieInfoType = ConvertEnumToString(searchChoiceF);
	prompt = "Which " + movieInfoType + " are you looking for? ";

	// PROC - whether 2 boundaries should be assigned or prompt for a str input
	if(movieInfoType == "year")
	{
		bound1 = 1878;
		bound2 = 3000;
	}
	else if(movieInfoType == "rating")
	{
		bound1 = 0;
		bound2 = 9;
	}
	else
	{
		cout << "\nWhich " << movieInfoType << " are you looking for? ";
		getline(cin, dvdSrchStr);
		consoleInput = dvdSrchStr;
	}

	// PROC - asks user for # if not prompted for string already & performs search
	if(movieInfoType != "actor" && movieInfoType != "genre")
	{
		cout << endl;
		dvdSrchInt = GetAndCheckIntResponse(bound1, bound2, prompt, PROMPT_SIZEF);
		consoleInput = ConvertIntToStr(dvdSrchInt);

		cout << "\nSearching for the " << movieInfoType << endl;
		SearchNodeInstance(headF, searchChoiceF, defaultStrF, outfileF,
						   dvdSrchInt, numInstancesF, foundF);
	}
	else
	{
		cout << "\nSearching for the " << movieInfoType << " " << consoleInput
			 << endl;
		SearchNodeInstance(headF, searchChoiceF, dvdSrchStr, outfileF,
						   defaultIntF, numInstancesF, foundF);
	}

	// PROC - will output list the movie & # of instances based on boolean var.
	if(foundF)
	{
		cout << "Found " << numInstancesF
		     << " movies for the " << movieInfoType << " " << consoleInput
			 << "!\n\n\n";
	}
	else
	{
		cout << "Sorry, no movies for the " << movieInfoType << ", "
			 << consoleInput << " were found.\n\n\n";
	}
}
