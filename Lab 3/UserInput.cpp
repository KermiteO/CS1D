/**********************************************************************
 * AUTHOR		: Kermite & User
 * Lab #3		: Supplement: Coin Flip
 * CLASS		: CS1B
 * SECTION		: MW 8:00a - 11:50a
 * DUE DATE		: 2/3/15
 *********************************************************************/
#include "HeaderFile.h"
/**********************************************************************
 * FUNCTION UserInput
 * ___________________________________________________________________
 * This function receives user's name and their gender - returns both.
 * ___________________________________________________________________
 * PRE-CONDITIONS
 * 		name  : the name of the user
 * 		gender: the gender of the user
 *
 * POST-CONDITIONS
 * 		This function outputs to the console a prompt that asks the
 * 		user for their name and gender
 *********************************************************************/
void UserInput(string &name,	//IN - the name
			   char &gender)	//IN - the gender
{
	const int PROMPT2_COL = 27;

	cout << left << setw(PROMPT2_COL) << "What is your name?";
	getline(cin, name);

	cout << setw(PROMPT2_COL) << "What is your gender(m/f)?";
	cin.get(gender);
	cin.ignore(1000, '\n');

	cout << endl;
}
