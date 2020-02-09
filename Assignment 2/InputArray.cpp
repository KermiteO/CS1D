/**********************************************************************
 * AUTHOR		: Kermite
 * Assignment #2: Parallel Arrays
 * CLASS		: CS1B
 * SECTION		: MW 8:00a - 11:50a
 * DUE DATE		: 2/9/15
 *********************************************************************/

#include "headerfile.h"

/***********************************************************************
 * FUNCTION InputArray
 * This function receives 3 parallel arrays, an array size, and returns
 * nothing -> This will read in data from the input file
 * heading to the output file.
 * _____________________________________________________________________
 * PRE-CONDITIONS
 * 		nameArrayF[] : the array for the names
 * 		getIDF[]	 : the array for the id#'s
 * 		balanceDueF[]: the array for the balances that are due
 * 		AR_SIZE		 : the constant that specifies the array size
 * POST-CONDITIONS
 * 		This function will read data from the input file into the three
 * 		arrays.
 ***********************************************************************/
void InputArray(string nameArrayF[], //IN - the array for the names
			    int getIDF[],		 //IN - the array for the id#'s
			    float balanceDueF[], //IN - the array for the balances due
			    const int AR_SIZE)	 //IN - the array size constant
{
	int index;		//PROC - the index number
	string getName;	//PROC - the name found in an index of a string array
	ifstream infile;//PROC - the I/O variable that reads from the arrays

	index = 0;

	infile.open("InFile.txt");

	while(index < AR_SIZE)
	{
		getline(infile, nameArrayF[index]);
		infile >> getIDF[index];
		infile >> balanceDueF[index];
		infile.ignore(1000,'\n');
		index++;
	}

	infile.close();
}

