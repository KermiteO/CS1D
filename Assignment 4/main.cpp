/**********************************************************************
 * AUTHOR		: Kermite
 * Ass #4		: Movie List Intro to Link Lists
 * CLASS		: CS1B
 * SECTION		: TuTh 8:00a - 11:50a
 * DUE DATE		: 3/3/15
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
	 * ASRIX_COL : formats the line of asterix
	 * PROMT_COL : formats the title
	 * PROMT2_COL: also used to format title
	 * ******************************************************************/
	//Constant Declarations go here
	const char PROJECT_TYPE    = 'A';
	const char PROGRAMMER [30] = "Kermite";
	const int  LAB_NUM         = 04;
	const char LAB_NAME   [50] = "Movie List Intro to Link Lists";

	const int ASRIX_COL = 55;
	const int PROMPT_COL = 13;
	const int PROMPT2_COL = 16;

	//Variable Declarations go here
	string getInputFile;		// IN   - the name of the input file
	string getOutputFile;		// IN 	- the name of the output file
	ofstream outfile;			// PROC - the variable for the output file
	DvdNode *head;				// PROC - the pointer variable for the
								//		  of the link list
	ifstream infile;

	//OUTPUT - the print header and the instructions for the game
	cout << PrintHeader(PROJECT_TYPE, PROGRAMMER, LAB_NUM, LAB_NAME);

	cout << left;
	cout << setfill('*') << setw(ASRIX_COL) << '*' << endl << setfill(' ');
	cout <<  setw(PROMPT_COL) << '*' << "WELCOME TO THE MOVIE LIST!";
	cout << right << setw(PROMPT2_COL) << '*' << endl;
	cout << setfill('*') << setw(ASRIX_COL) << '*' << endl << setfill(' ');
	cout << right;

/*************************************************************************
 INPUT - the names of the input and output files that are going to be used
 	 	 in the functions used to create and output the link list
 *************************************************************************/
	cout << left << setw(37) << "Please enter the input file to use:";
	getline(cin, getInputFile);

	cout << "Please enter the output file to use: ";
	getline(cin, getOutputFile);

/*************************************************************************
 PROCESSING - calls the function that uses the data in the input file
 	 	 	  to create a link list of movies
 *************************************************************************/
	head = CreateLinkList(getInputFile);

/*************************************************************************
 OUTPUT - the link list of movies to the output file specified in the
 	 	  input
 *************************************************************************/
	OutputLinkList(head, getOutputFile);

	return 0;
}
