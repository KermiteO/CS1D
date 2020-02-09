/**********************************************************************
 * AUTHOR		: Kermite & Maclem
 * Lab #9		: Testing
 * CLASS		: CS1B
 * SECTION		: TTH 8:00a - 11:50a
 * DUE DATE		: 2/19/15
 *********************************************************************/

#include "HeaderFile.h"

void GetOutput(int rem, int total)
{
	if(total > MAX_CHOC)
	{
		cout << "\nINVALID - Each sheep can't have more than 4 chocolate bars.\n";
	}
	else
	{
		cout << "\nEach sheep will get "  << total << " chocolate bars and "
			 << "there will be " << rem << " left over.\n";
	}
}
