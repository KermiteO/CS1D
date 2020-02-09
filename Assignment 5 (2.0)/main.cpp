/**********************************************************************
 * AUTHOR		: Kermite
 * Ass #5		: Searching Link Lists
 * CLASS		: CS1B
 * SECTION		: TuTh 8:00a - 11:50a
 * DUE DATE		: 3/18/15
 *********************************************************************/

#include "HeaderFile.h"

int main()
{
    /*********************************************************************
	 * CONSTANTS
	 * -------------------------------------------------------------------
	 * USED FOR OUTPUT FILE - ALL WILL BE OUTPUT
	 * -------------------------------------------------------------------
	 * PROGRAMMER : Programmer's Name
	 * CLASS      : Student's Course
	 * SECTION    : Class Days and Times
	 * LAB_NUM    : Lab/Assignment Number (specific to this lab)
	 * LAB_NAME   : Title of the Lab/Assignment
	 * ------------------------------------------------------------------
	 * USED FOR PROCESSING
	 * ------------------------------------------------------------------
	 * PROJECT_TYPE: the project type
	 * PROGRAMMER  : the name(s) of the programer(s)
	 * LAB_NUM	   : the lab number
	 * LAB_NAME	   : the lab name
	 * PROMPT_SIZE : the prompt size usded for formatting
	 * ******************************************************************/
	//Constant declarations go here
	const char PROJECT_TYPE = 'A';
	const string PROGRAMMER = "Kermite";
	const int  LAB_NUM      = 05;
	const string LAB_NAME   = "Searching Link Lists";

	const int PROMPT_SIZE = 17;

	//Variable Declarations go here
	CommandMenu listChoice;  // IN&PROC    - com. choice passed back as an enum
	DvdNode *head;			 // PROC       - the variable that represents the l.l
	DvdNode *perPtr;		 // PROC&OUT   - points to a specific dvd node
	string   getInputFile;	 // IN         - the name of the input file
	string   getOutputFile;	 // IN 	       - the name of the output file
	string   defaultFile;	 // IN         - the default file name
	string	 prompt;		 // PROC&OUT   - the input prompt
	string   enterTitle;	 // IN&PROC	   - a title of a movie
	string	 defaultStr;	 // IN		   - string needed for int searches
	ifstream infile;		 // IN&PROC    - the infile variable
	ofstream outfile;		 // PROC       - the variable for the output file
	int		 movieCount;     // PROC&OUT   - the current movie number
	int		 bound1;		 // PROC	   - the 1st boundary value
	int		 bound2;		 // PROC       - the 2nd boundary value
	int      commandInput;   // IN/CALC/OUT- used to determine the search
	int 	 numInstances;   // PROC       - # of inst. of movie
	int		 defaultInt;	 // IN		   - int variable needed for string srches
	bool 	 found;			 // PROC       - represents a found movie

	// INITIALIZATION: variables that will be used for code (in functions & main)
	movieCount = 1;
	numInstances = 0;
	bound1 = 0;
	bound2 = 6;
	prompt = "Enter an option (0 to exit): ";
	defaultFile = 'd';
	defaultStr = "Nothing";
	defaultInt = 999;
	found = false;

	//OUTPUT - the print header and the instructions for the game
	cout << left;
	cout << PrintHeader(PROJECT_TYPE, PROGRAMMER, LAB_NUM, LAB_NAME);

/*************************************************************************
 INPUT - the names of the input and output files that are going to be used
		 in the functions used to create and output the link list, and
		 prompt the user to enter in a dvd menu option. Then it converts
		 that command choice to an enum type and creates a link list from
		 the list of movie found in the input file
 *************************************************************************/
	cout << "Which input file would you like to use(type d for default file)? ";
	getline(cin, getInputFile);

	cout << "Which output file would you like to use(type d for default file)? ";
	getline(cin, getOutputFile);
	cout << endl << endl;

	//PROC - if the names entered were 'd', then the file names get assigned
	if(getInputFile == defaultFile || getOutputFile == defaultFile)
	{
		getInputFile = "InFile.txt";
		getOutputFile = "OFile.txt";
	}
	//INITALIZE - the lcv and create a link list
	OutputMenu();
	commandInput = GetAndCheckIntResponse(bound1, bound2, prompt, PROMPT_SIZE);
	listChoice = ConvertIntToEnumType(commandInput);

	head = CreateLinkList(getInputFile);
	perPtr = head;
/*************************************************************************
 PROCESSING - depending on what command choice was inputed, this piece
 	 	 	  of code will call different functions that will prompt
 	 	 	  the user to enter in a dvd info search and will search a
 	 	 	  link list of movies for either the 1st instance or the #
 	 	 	  of times that dvd info search appears in the link list.
 *************************************************************************/
	//Open the output file
	outfile.open(getOutputFile.c_str());

	//Outputs the print header to the output file
	outfile << PrintHeader(PROJECT_TYPE, PROGRAMMER, LAB_NUM, LAB_NAME);

	while(listChoice != EXIT)
	{
		switch(listChoice)
		{
		case EXIT : listChoice = EXIT;
				     break;
		case LIST : cout << "\nListing all movies!\n\n\n";
				    //PROC - Will output all the movies in the link list to the
					//		 ofile
				    while(perPtr != NULL)
				    {
				    	OutputNode(perPtr, outfile, listChoice, defaultStr,
				    			   defaultInt, movieCount);
					    //PROC - moves perPtr to the next node in the list
					    perPtr = perPtr -> next;
					    movieCount++;
				    }
				    perPtr = NULL;
				     break;
		case TITLE: cout << endl << "Which title are you looking for? ";
					getline(cin, enterTitle);
					cout << endl;
					cout << "Searching for the title " << enterTitle << endl;

					SearchNodeInstance(head, listChoice, enterTitle,
									   outfile, defaultInt, numInstances, found);
					//PROC - output necessary statement to console & ofile based
					//		 on the boolean value
					if(found)
					{
						cout << "Found the movie " << enterTitle << "!\n\n\n";
					}
					else
					{
						cout << "Sorry, the movie \"" << enterTitle
							 << "\" was not found.\n\n\n";
					}
					 break;
		case GENRE :
		case ACTOR :
		case YEAR  :
		case RATING: ListOutputSearch(head, listChoice, outfile);
		}
		// PROC - will change the lcv to keep looping
		OutputMenu();
		commandInput = GetAndCheckIntResponse(bound1, bound2, prompt, PROMPT_SIZE);
		listChoice = ConvertIntToEnumType(commandInput);

		// PROC - movieCnt,numInstances, found, and perPtr get reset back to
		//		  original state
		found  = false;
		perPtr = head;
		movieCount   = 1;
		numInstances = 0;
	}
	//Close the output file
	outfile.close();

	return 0;
}
