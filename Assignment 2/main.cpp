/**********************************************************************
 * AUTHOR		: Kermite
 * Assignment #2: Parallel Arrays
 * CLASS		: CS1B
 * SECTION		: MW 8:00a - 11:50a
 * DUE DATE		: 2/9/15
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
	 *
	 * ******************************************************************/
	//Constant Declarations go here
	const char PROJECT_TYPE    = 'A';
	const char PROGRAMMER [30] = "Kermite";
	const int  LAB_NUM         = 02;
	const char LAB_NAME   [30] = "Parallel Arrays";


	const int AR_SIZE = 10;
	const int OUTPUT_COL = 9;
	const int OUTPUT_TWO_COL = 25;
	const int OUTPUT_THREE_COL = 34;
	const int OUTPUT_FOUR_COL = 4;

	//Variable declarations go here
	string getInfile;				  	 //IN      - the name of the input
										 //		     file
	string getOutfile;	 				 //IN      - the name of the output
										 //		     file
	string getName;						 //IN      - the name of the person
	string nameArray[AR_SIZE];			 //IN&OUT  - the array that
										 //			 specifies names
	int getID[AR_SIZE];					 //IN&OUT  - the array the
										 //			 specifies id
	float balanceDue[AR_SIZE];			 //IN&OUT  - the array that
										 //			 specifies the bal. due
	ifstream infile;					 //PROC    - the input file
										 //			 variable
	ofstream outfile;					 //PROC     - the output file
										 //			  variable
	int index;							 //PROC     - the index number
	float sumBalance;					 //CALC     - the total sum of the
										 //			  balances


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

		InputArray(nameArray, getID, balanceDue, AR_SIZE);

		cout << "Who do you want to search for (enter done to exit): ";
		getline(cin, getName);

		sumBalance = 0;

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
			index = SearchStringArray(getName, nameArray, AR_SIZE);

			if(index != AR_SIZE)
			{
				cout << "Found." << endl << endl;

//OUTPUT: if the condition for the if statement is true, it proceeds
//		  with the nested if statement that outputs the required data but
//		  only for the indexes that had names that were found, and outputs
//		  a statement that specifies when the names weren't found.


				if(index == 7 )
				{
					outfile << fixed << setprecision(3)  << showpoint;
					outfile << setw(OUTPUT_COL) << getID[index];
					outfile << setw(OUTPUT_TWO_COL) << nameArray[index];
					outfile << setw(OUTPUT_FOUR_COL) << "$";
					outfile << balanceDue[index];
					outfile << endl;
					sumBalance = sumBalance + balanceDue[index];
				}
				else if(index == 0 || index == 1 || index == 3)
				{
					outfile << fixed << setprecision(2)  << showpoint;
					outfile << setw(OUTPUT_COL) << getID[index];
					outfile << setw(OUTPUT_TWO_COL) << nameArray[index];
					outfile << setw(OUTPUT_FOUR_COL) << "$";
					outfile << balanceDue[index];
					outfile << endl;
					sumBalance = sumBalance + balanceDue[index];
				}
					index++;
				}
				else
				{
					cout << getName << " was not found." << endl << endl;
				}

		//PROCESSING: Change the LCV

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
		outfile << left << setw(OUTPUT_FOUR_COL) << "$";
		outfile << sumBalance/(AR_SIZE - 6);

		//Close the output file
		outfile.close();

		return 0;
	}





