/***********************************************************************
 * AUTHOR		  : BEAK & Kermite
 * LAB #2 		  : Intro to Functions - GCD
 * CLASS		  : CS1B
 * SECTION		  : TTH 0800
 * DUE DATE		  : 3FEB2015
 ***********************************************************************/
#include "LAB2_HEADER.h"
/***********************************************************************
 * Intro to Functions - GCD
 * _____________________________________________________________________
 * This program will accept as input from the user two integers and then
 * 		calculate the Greatest Common Divisor using the FindGCD function.
 * 		The program will then output the GCD for the two numbers to the
 * 		output file in pretty formatting.
 * 		The program will do this a specific number of times (four), before
 * 		exiting.
 * _____________________________________________________________________
 * INPUT:
 * 		num1		: The first of two integers for finding the GCD
 * 		num2		: The second of two integers for finding the GCD
 *
 * OUTPUT:
 *		oFile		: Output file stream variable
 *
 ***********************************************************************/
int main()
{
	/*******************************************************************
	 * CONSTANTS
	 * -----------------------------------------------------------------
	 * USED FOR CLASS HEADING - ALL WILL BE OUTPUT
	 * -----------------------------------------------------------------
	 * PROGRAMMER	: Programmers Name
	 * CLASS		: Student's Course
	 * SECTION		: Class Days and Times
	 * LAB_NUM		: Lab Number (specific to this lab)
	 * LAB_NAME		: Title of the Lab
	 *
	 * -----------------------------------------------------------------
	 * USED FOR CALCULATION & FORMATTING
	 * -----------------------------------------------------------------
	 * RUNS			: How many pairs of numbers to analyze
	 * OUT_WIDTH	: Width of the input prompts for formatting
	 *******************************************************************/
	const string ASS_NAME	= "Intro to Functions - GCD";
	const char   ASS_TYPE	= 'l';
	const string ASS_NUM	= "1";
	const string PROG_NAME  = "BEAK & KERMITE";

	//Constant declaration go here
	const int	 RUNS		= 4;
	const int	 OUT_WIDTH	= 26;

	//Variable declarations go here
	int num1;		//IN - the first integer value
	int num2;		//IN - the second integer value
	ofstream oFile;	//OUT - the output file variable

	oFile.open("Outfile.txt");

	//OUTPUT - Class Heading to the console
	cout << PrintHeaderString(ASS_NAME, ASS_TYPE, ASS_NUM, PROG_NAME);
	PrintHeaderOstream(cout, ASS_NAME, ASS_TYPE, ASS_NUM, PROG_NAME);

	//OUTPUT - Class Heading to the output file
	oFile << PrintHeaderString(ASS_NAME, ASS_TYPE, ASS_NUM, PROG_NAME);
	PrintHeaderOstream(oFile, ASS_NAME, ASS_TYPE, ASS_NUM, PROG_NAME);

	for(int runCount = 1; runCount <= RUNS; runCount++)
	{
/*************************************************************************
 * INPUT - The program will collect two integers from the user to calculate
 * 		   a Greatest Common Divisor.
 ************************************************************************/
		cout << left << setw(OUT_WIDTH) << "Enter the first integer:";
		cin  >> num1;
		cout << setw(OUT_WIDTH) << "Enter the second integer:";
		cin  >> num2;
		cout << endl;

/*************************************************************************
 * CALC & OUTPUT - Output the GCD to the output file, calling the FindGCD
 * 				   function in line to calculate the GCD using the two
 * 				   integers entered by the user.
 ************************************************************************/
		oFile << "The GCD for " << num1 << " & " << num2 << " = "
			  << FindGCD(num1, num2) << endl << endl;
	}
}
