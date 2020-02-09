/**************************************************************************
 * AUTHOR     : Ikrit and Kermite
 * LAB #04    : Intro to arrays
 * CLASS      : CS1B
 * SECTION    : TuTh: 8am
 * DUE DATE   : 02/05/15
 * ***********************************************************************/
#include "header.h"

/**************************************************************************
 * Intro to Functions
 *________________________________________________________________________
 *
 * This program will read in two values from a user and output the
 *  greatest common divisor.
 *________________________________________________________________________
 *************************************************************************/

int main()
{
	 /*********************************************************************
	  * -------------------------------------------------------------------
	  * USED FOR CLASS HEADING - USED TO DETERMINE HEADER
	  * -------------------------------------------------------------------
	  * PROJECT TYPE : Lab or Assignment
	  * PROGRAMMER   : Programmer's name
	  * LAB_NUM      : Lab Number
	  * LAB_NAME     : Lab Title
	  *
	  * -------------------------------------------------------------------
	  * USED FOR PROCESSING
	  * -------------------------------------------------------------------
	  * PROMPT_COL : Size of the prompt column spacing.
	  *
	  ********************************************************************/
	 const char PROJECT_TYPE    = 'L';
	 const char PROGRAMMER [30] = "Ikrit & Kermite";
	 const int  LAB_NUM         = 04;
	 const char LAB_NAME   [30] = "Intro to Arrays";

	 const int AR_SIZE          = 10;
	 const string LIST_TYPE     = "name";

	 string nameAr[AR_SIZE];    // IN - Array list of names


	 // Header Output to Console (ostringstream)
	 cout << PrintHeader(PROJECT_TYPE, PROGRAMMER, LAB_NUM, LAB_NAME);

	 // Gets 10 names and stores in an array
	 GetStringAr(nameAr, AR_SIZE, LIST_TYPE);
	 cout << endl;

	 // Search array for instances
	 SearchStringArInstances(nameAr, AR_SIZE);




   return 0;
}
