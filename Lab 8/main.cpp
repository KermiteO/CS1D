/**********************************************************************
 * AUTHOR		: Kermite & DatOwl
 * Lab #8		: Structs
 * CLASS		: CS1B
 * SECTION		: TTH 8:00a - 11:50a
 * DUE DATE		: 2/12/15
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
	 * LAB_NUM    : Lab Number (specific to this lab)
	 * LAB_NAME   : Title of the Lab
	 * ------------------------------------------------------------------
	 * USED FOR PROCESSING
	 * ------------------------------------------------------------------
	 * OUTPUT_COL	  : the first number of spaces in the output column
	   OUTPUT_TWO_COL  : the second number of spaces in the output column
	   OUTPUT_THREE_COL: the third number of spaces in the output column
	   OUTPUT_FOUR_COL : the fourth number of spaces in the output column
	 * ******************************************************************/
	//Constant Declarations go here
	const char PROJECT_TYPE    = 'L';
	const char PROGRAMMER [32] = "Kermite & DatOwl";
	const int  LAB_NUM         = 8;
	const char LAB_NAME   [30] = "Structs";

	const int AR_SIZE = 10;
	const int OUTPUT_COL = 9;
	const int OUTPUT_TWO_COL = 25;
	const int OUTPUT_THREE_COL = 34;
	const int OUTPUT_FOUR_COL = 10;

	//Variable declarations go here
	StudentRec theStudent[AR_SIZE];	// IN   - the struct variable
	string     getInfile;  	 		// IN   - the name of the input file
	string     getOutfile;	 		// IN   - the name of the output file
	string     getName;				// IN   - the name of the person
	ifstream   infile;				// PROC - the input file variable
	ofstream   outfile;				// PROC - the output file variable
	int 	   index;		   	    // PROC - the index number
	float      sumBalance;			// CALC - total sum of the balances
	bool       searchFound;			// PROC - condition for found names


	//Initialize the sum of the balances
	sumBalance = 0;

/************************************************************************
	INPUT & OUTPUT - Prompt the user for an input file and an output file.
					 then once they're entered, call the print header
					 function to print to the output file
*************************************************************************/

		cout << PrintHeader(PROJECT_TYPE, PROGRAMMER, LAB_NUM, LAB_NAME);

		cout << "What input file would you like to use?  ";
		getline(cin, getInfile);

		cout << "What output file would you like to use? ";
		getline(cin, getOutfile);
		cout << endl;

		outfile.open(getOutfile.c_str());

		outfile << PrintHeader(PROJECT_TYPE, PROGRAMMER, LAB_NUM, LAB_NAME);

/***********************************************************************
	OUTPUT - Output the necessary statements that format the output file
			 tables
************************************************************************/
		outfile << left;
		outfile << setw(OUTPUT_COL) << "ID #"  << setw(OUTPUT_TWO_COL);
		outfile << "NAME" << "BALANCE DUE" << endl;
		outfile << setw(OUTPUT_COL) << "----"  << setw(OUTPUT_TWO_COL);
		outfile << "--------------------" << "-----------" << endl;

/***********************************************************************
PROCESSING - call the input array function and initialize the
			 statements that prompt the user for a name. Then set
			 the sum of the total balances to zero.
************************************************************************/

		InputArray(theStudent, AR_SIZE, getInfile, infile);

		cout << "Who do you want to search for (enter done to exit): ";
		getline(cin, getName);

/*********************************************************************
PROCESSING & OUTPUT - set the while loop to proceed so long as the
name entered is not "done". Call on the search string array and set
an if statement that reads into the output file date for the id#, name,
and balance of the index specified, and outputs a different statement
if the condition for the if statement is false. Once "done" is entered
exit the while loop and calculate the average balance due.
*********************************************************************/

		while(getName != "done")
		{

			searchFound = false;

			index = SearchStringArray(theStudent, getName, AR_SIZE);

			if(index != AR_SIZE)
			{
				cout << "Found." << endl << endl;
				searchFound = true;
			}
			else
			{
				cout << getName << " was not found.\n\n";
			}
//OUTPUT: uses a boolean variable to check if output is needed based on
//		  whether or not the input was found or not.
			if (searchFound == true)
			{
				outfile << fixed << setprecision(2)  << showpoint;
				outfile << setw(OUTPUT_COL) << theStudent[index].getIDAr;
				outfile << setw(OUTPUT_TWO_COL)
						<< theStudent[index].getNameAr;
				outfile << left << "$";
				outfile << right << setw(OUTPUT_FOUR_COL)
						<< theStudent[index].getBalanceAr ;
				outfile << endl;
				outfile << left;
				sumBalance = sumBalance + theStudent[index].getBalanceAr;
			}

		//PROCESSING: negates searchFound to false, increments index,
		//			  and changes the LCV
			index++;

			cout << "Who do you want to search for (enter done to exit): ";
			getline(cin, getName);
		}

		//The program ends
		cout << endl << "Thank you for using my program.";

/*********************************************************************
OUTPUTS: to the output file the average balance and the sum
		 balance due.
*********************************************************************/

		outfile << endl;
		outfile << fixed << setprecision(2)  << showpoint;
		outfile << right;
		outfile << setw(OUTPUT_THREE_COL) << "Average Balance Due: ";
		outfile << left << "$";
		outfile << right << setw(OUTPUT_FOUR_COL)
				<< sumBalance/(AR_SIZE - 6);

		//Close the output file
		outfile.close();

		return 0;
	}





