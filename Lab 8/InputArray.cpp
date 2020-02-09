/**********************************************************************
 * AUTHOR		: Kermite & DatOwl
 * Lab #8		: Structs
 * CLASS		: CS1B
 * SECTION		: TTH 8:00a - 11:50a
 * DUE DATE		: 2/12/15
 *********************************************************************/

#include "Headerfile.h"

/***********************************************************************
 * FUNCTION InputArray
 * This function receives a struct array, an array size, a infile
 * variable, and the variabla associated with infile.
 * RETURNS: nothng
 * -> will read in student info into the struct
 * _____________________________________________________________________
 * PRE-CONDITIONS
 * 		getStudent[]: the array of the struct StudentRec
 * 		AR_SIZE		: the constant that specifies the array size
 * 		getInfile	: input file name
 * 		infile		: the infile variable
 * POST-CONDITIONS
 * 		This function will read data from the input file into a struct.
 ***********************************************************************/
void InputArray(StudentRec getStudent[], //IN - the array of struct
				const int AR_SIZE,		 //IN - array size
				string getInfile,		 //IN - input file name
				ifstream &infile)	 	 //IN - the array size constant
{
	int index;		//PROC - the index number

	index = 0;

	infile.open(getInfile.c_str());

	//PROC - loops as long as not at end of infile and the index # is
	//		 less than the array size
	while(infile && index < AR_SIZE)
	{
		getline(infile, getStudent[index].getNameAr);
		infile >> getStudent[index].getIDAr;
		infile >> getStudent[index].getBalanceAr;
		infile.ignore(1000,'\n');
		index++;
	}

	infile.close();
}

