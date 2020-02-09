/**********************************************************************
 * AUTHOR(S)	: Kermite & Miss Lame
 * Lab #18		: Date Class
 * CLASS		: CS1B
 * SECTION		: TuTh 8:00a - 11:50a
 * DUE DATE		: 4/28/15
 *********************************************************************/

#include "HeaderFile.h"

/*********************************************************************
 * Lab 18 Date Class
 *
 * ------------------------------------------------------------------
 * This program will implement the DATE CLASS
 *
 ********************************************************************/

int main()
{
	//Constant Declarations go here
	const char PROJECT_TYPE  = 'L';
	const string PROGRAMMER  = "Kermite & Miss Lame";
	const int  LAB_NUM       = 18;
	const string LAB_NAME    = "Date Class";

	const string MENU_PROMPT =  "Enter Selection: ";

	//Variable Declarations go here
	MenuOptions    menuChoice;    // IN & CALC - The user input for menu
	bool 		   valid;         // CALC      - bool for valid input
	unsigned short dateMonth;     // IN & CALC - The user input for month
	unsigned short dateYear;      // IN & CALC - The user input for year
	unsigned short dateDay;       // IN & CALC - The user input for day
	string 		   displayDateStr;			// PROC & OUT- the date as a string
	Date date(dateMonth, dateDay, dateYear);// PROC	   - object var. for class Date


	//OUTPUT - the print header and the instructions for the game
	cout << left;
	cout << PrintHeader(PROJECT_TYPE, PROGRAMMER, LAB_NUM, LAB_NAME);

	Menu();
	menuChoice = MenuOptions(GetAndCheckIntInp(MENU_PROMPT, 0, 2));

	while(menuChoice != EXIT)
	{
		switch(menuChoice)
		{
			case 1: do
					{
						cout << left;
						cout << "\nWhat would you like to change the date to?\n";

						cout << setw(12) << "Month(MM)" << ": ";
						cin >> dateMonth;
						cout << setw(12) << "Day(DD)" << ": ";
						cin >> dateDay;
						cout << setw(12) << "Year(YYYY)" << ": ";
						cin >> dateYear;
						valid = date.CheckDate(dateMonth, dateDay, dateYear);

						if(valid)
						{
							date.SetDate(dateMonth, dateDay, dateYear);
							displayDateStr = date.DisplayDate();
							cout << "\nThe date " << displayDateStr
								 <<  " you enter has been set!\n";

						}
						else
						{
							cout << "\nPlease re-enter a new date";
						}

					}while(!valid);
				break;

			case 2:
					displayDateStr =date.DisplayDate();
					cout << "\nThe current date is " << displayDateStr
						 << ".\n";
				break;
			default: cout << "\nA problem occurred, try again?\n";
		}

		Menu();
		menuChoice = MenuOptions(GetAndCheckIntInp(MENU_PROMPT, 0, 2));

	}

	cout << "\nThank you for using our program! :)\n";
	cout << right;

	return 0;
}
