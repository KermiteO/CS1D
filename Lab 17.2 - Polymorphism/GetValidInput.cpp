/**************************************************************************
 * AUTHOR		: Kermite & Fireduck
 * LAB #17		: Polymorphism
 * CLASS		: CS1B
 * SECTION		: TTh 0800
 * DUE DATE		: 22APR2015
 *************************************************************************/

#include "InputCheck.h"

/**************************************************************************
 * FUNCTION GetValidInput
 *_________________________________________________________________________
 * This function will output a preset prompt message which will be passed
 * into the function, it will also accept two integers representing
 * minimum and maximum values and will check to make sure that the user
 * entered an integer between the MIN & MAX, if it is not, the function
 * will output an error message and prompt the user to enter their integer
 * again. If the user inputs a char type value the Function will output a
 * error message and ask for the user to input a integer again.
 * - returns the accepted integer
 *_________________________________________________________________________
 * PRE-CONDITIONS the following must be previously defined.
 *
 *  PROMPT     - displayed message to enter a character
 *  PROMPT_W   - width of the prompt column
 *  MIN		   - one of two acceptable inputs, should be capital
 *  MAX		   - one of two acceptable inputs, should be capital
 *_________________________________________________________________________
 * POST-CONDITIONS
 * 	This function will return an integer
 * 		-returns valid integer response.
 *************************************************************************/
int GetValidInput(const string PROMPT,    // IN - Prompt to user
				  const short  PROMPT_W,  // IN - Prompt column width
				  const int    MIN,       // IN - Minimum accepted value
				  const int    MAX)       // IN - maximum accepted value
{
	int  colWidth;
	int  intInput;
	bool invalid;
	string stringOne;
	string stringTwo;
	ostringstream convert;

	cout << left;

	do
	{
		invalid = false;

		cout << setw(PROMPT_W) << PROMPT;
		if(!(cin >> intInput))
		{
			cout << "\n**** Please input a number between " << MIN << " and "
				 << MAX << " ****\n" << endl;

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			invalid = true;
		}
		else if(intInput < MIN || intInput > MAX)
		{
			convert << "The number " << intInput << " is an invalid "
					 << "entry";
			stringOne = convert.str();

			convert.str("");

			convert <<  "Please input a number between " << MIN
				     <<  " and " << MAX;
			stringTwo = convert.str();

			convert.str("");

			colWidth = GetSetw(stringOne, stringTwo);

			cout << "\n**** " << setw(colWidth) << stringOne << " ****\n";

			cout << "**** " << setw(colWidth) << stringTwo << " ****\n";
			invalid = true;
		}

	}while(invalid);
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << right;

	return intInput;
}


/**************************************************************************
 * FUNCTION GetValidInput
 *_________________________________________________________________________
 * This function will output a preset prompt message which will be passed
 * into the function, it will also accept two char responses and will check
 * to make sure that the user entered one of the accepted responses, if it
 * is not, the function will output an error message and prompt the user to
 * enter their response again.
 * - returns the accepted character.
 *_________________________________________________________________________
 * PRE-CONDITIONS the following must be previously defined.
 *
 *  prompt      - displayed message to enter a character
 *  promptWidth - width of the prompt column
 *  accepted1   - one of two acceptable inputs
 *  accepted2   - one of two acceptable inputs
 *_________________________________________________________________________
 * POST-CONDITIONS
 * 	This function will return a char
 * 		-returns valid char response.
 *************************************************************************/
char GetValidInput(string prompt,		// IN - displayed message
				   short  promptWidth,	// IN - message column width
				   char   accepted1,	// IN - one accepted char
				   char   accepted2)	// IN - one accepted char
{
	char userInput;

	cout << left;

	accepted1 = toupper(accepted1);
	accepted2 = toupper(accepted2);

	do //while(userInput != INPUT_OK_1 || userInput != INPUT_OK_2);
	{

		cout << setw(promptWidth) << prompt;
		cin.get(userInput);
		cin.ignore(numeric_limits<streamsize>::max(),'\n');

		userInput = toupper(userInput);

			if (userInput != accepted1 && userInput != accepted2)
			{
				cout << endl;
				cout << "** INVALID INPUT - Please enter \'" << accepted1
					 << "\' or \'" << accepted2 << "\' **\n\n";
			}
	}while(userInput != accepted1 && userInput != accepted2);

	cout << right;
	return userInput;
}


/**************************************************************************
 * FUNCTION GetValidInput
 *_________________________________________________________________________
 * This function will output a preset prompt message which will be passed
 * into the function, it will also accept four char responses and will
 * check to make sure that the user entered one of the accepted responses,
 * if it is not, the function will output an error message and prompt the
 * user to enter their response again.
 * - returns the accepted upper case character.
 *_________________________________________________________________________
 * PRE-CONDITIONS the following must be previously defined.
 *
 *  prompt      - displayed message to enter a character
 *  promptWidth - width of the prompt column
 *  accepted1   - one of four acceptable inputs
 *  accepted2   - one of four acceptable inputs
 *  accepted3   - one of four acceptable inputs
 *  accepted4   - one of four acceptable inputs
 *_________________________________________________________________________
 * POST-CONDITIONS
 * 	This function will return an upper case char
 * 		-returns valid char response.
 *************************************************************************/
char GetValidInput(string prompt,		// IN - displayed message
				   short  promptWidth,	// IN - message column width
				   char   accepted1,	// IN - One accepted char
				   char   accepted2,	// IN - Second accepted char
				   char   accepted3,	// IN - Third accepted char
				   char   accepted4)	// IN - Fourth accepted char
{
	char userInput;

	cout << left;

	accepted1 = toupper(accepted1);
	accepted2 = toupper(accepted2);
	accepted3 = toupper(accepted3);
	accepted4 = toupper(accepted4);

	do //while(userInput != INPUT_OK_1 || userInput != INPUT_OK_2);
	{

		cout << setw(promptWidth) << prompt;
		cin.get(userInput);
		cin.ignore(numeric_limits<streamsize>::max(),'\n');

		userInput = toupper(userInput);

			if (userInput != accepted1 && userInput != accepted2
			 && userInput != accepted3 && userInput != accepted4)
			{
				cout << "\n**** INVALID INPUT - Please enter ("
					 << accepted1 << ',' << accepted2 << ','
					 << accepted3 << ',' << accepted4 << ") ****\n\n";
			}
	}while(userInput != accepted1 && userInput != accepted2
		&& userInput != accepted3 && userInput != accepted4);
	cout << right;

	return userInput;
}

/**************************************************************************
 * FUNCTION GetValidInput
 *_________________________________________________________________________
 * This function will output a preset prompt message which will be passed
 * into the function, it will also accept five char responses and will
 * check to make sure that the user entered one of the accepted responses,
 * if it is not, the function will output an error message and prompt the
 * user to enter their response again.
 * - returns the accepted upper case character.
 *_________________________________________________________________________
 * PRE-CONDITIONS the following must be previously defined.
 *
 *  prompt      - displayed message to enter a character
 *  promptWidth - width of the prompt column
 *  accepted1   - one of five acceptable inputs
 *  accepted2   - one of five acceptable inputs
 *  accepted3   - one of five acceptable inputs
 *  accepted4   - one of five acceptable inputs
 *  accepted5   - one of five acceptable inputs
 *_________________________________________________________________________
 * POST-CONDITIONS
 * 	This function will return an upper case char
 * 		-returns valid char response.
 *************************************************************************/
char GetValidInput(string prompt,		// IN - displayed message
				   short  promptWidth,	// IN - message column width
				   char   accepted1,	// IN - One accepted char
				   char   accepted2,	// IN - Second accepted char
				   char   accepted3,	// IN - Third accepted char
				   char   accepted4,	// IN - Fourth accepted char
				   char   accepted5)	// IN - Fifth accepted char
{
	char userInput;

	cout << left;

	accepted1 = toupper(accepted1);
	accepted2 = toupper(accepted2);
	accepted3 = toupper(accepted3);
	accepted4 = toupper(accepted4);
	accepted5 = toupper(accepted5);

	do //while(userInput != INPUT_OK_1 || userInput != INPUT_OK_2);
	{

		cout << setw(promptWidth) << prompt;
		cin.get(userInput);
		cin.ignore(numeric_limits<streamsize>::max(),'\n');

		userInput = toupper(userInput);

			if (userInput != accepted1 && userInput != accepted2
			 && userInput != accepted3 && userInput != accepted4
			 && userInput != accepted5)
			{
				cout << "\n**** INVALID INPUT - Please enter ("
					 << accepted1 << ',' << accepted2 << ','
					 << accepted3 << ',' << accepted4 << ',' << accepted5
					 << ") ****\n\n";
			}
	}while(userInput != accepted1 && userInput != accepted2
		&& userInput != accepted3 && userInput != accepted4
		&& userInput != accepted5);
	cout << right;

	return userInput;
}


/**************************************************************************
 * FUNCTION GetSetw
 *_________________________________________________________________________
 * This function will compare two strings and find the length of them both
 * and returns the larger length.
 * - returns the larger length
 *_________________________________________________________________________
 * PRE-CONDITIONS the following must be previously defined.
 *
 *  stringOne - one string message
 *  stringTwo - another string message
 *
 *_________________________________________________________________________
 * POST-CONDITIONS
 * 	This function will return length
 * 		-returns larger length
 *************************************************************************/
int GetSetw(string stringOne,  // IN - one string message
			string stringTwo)  // IN - one string message
{
	int size1;
	int size2;
	int largest;

	size1 = stringOne.length();
	size2 = stringTwo.length();

	if(size1 > size2)
	{
		largest = size1;
	}
	else
	{
		largest = size2;
	}

	return largest;
}
