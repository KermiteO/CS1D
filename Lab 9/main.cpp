/**********************************************************************
 * AUTHOR		: Kermite & Maclem
 * Lab #9		: Testing
 * CLASS		: CS1B
 * SECTION		: TTH 8:00a - 11:50a
 * DUE DATE		: 2/19/15
 *********************************************************************/

#include "HeaderFile.h"

int main()
{
	//Constant Declarations go here
	const char PROJECT_TYPE    = 'L';
	const char PROGRAMMER [35] = "Kermite & Maclem";
	const int  LAB_NUM         = 9;
	const char LAB_NAME   [30] = "Testing";

	//Variable Declarations go here
	int numSheep;
	int numChoc;
	int chocPerSheep;
	int chocLeft;

	//OUTPUT - the print header & output format
	cout << PrintHeader(PROJECT_TYPE, PROGRAMMER, LAB_NUM, LAB_NAME);

	cout << left;
	cout << "************************************************************\n"
		 << "Black Box Testing & White Box Testing\n"
		 << "************************************************************\n";

	//INPUT/PROCESSING - Prompt the user for the number of sheep and
	//the number of chocolate bars. Call GetInt to check for valid numbers
	cout << " Please enter the number of sheep: ";
	numSheep = GetInt();

	cout << " Please enter the number of chocolate: ";
	numChoc = GetInt();

	//CALCULATION - calls 3 functions that calculates the # of chocolate
	//bars left over, the # of bars per sheep, outputs a statement
	//specifying said values. Then the test drives test the functions.
	chocLeft = CalcMod(numSheep, numChoc);
	cout << "\nTesting CalcMod, numSheep, numChoc:  ";
	cout << chocLeft << endl;

	chocPerSheep = CalcTotal(numSheep, numChoc);
	cout << "\nTesting CalcTotal, numSheep, numChoc: ";
	cout << chocPerSheep << endl;

	GetOutput(chocLeft, chocPerSheep);
	cout << "\nTesting GetOutput: ";
	GetOutput(chocLeft, chocPerSheep);

	return 0;
}
