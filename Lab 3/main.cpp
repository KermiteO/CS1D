/**********************************************************************
 * AUTHOR		: Kermite & User
 * Lab #3		: Supplement: Coin Flip
 * CLASS		: CS1B
 * SECTION		: MW 8:00a - 11:50a
 * DUE DATE		: 2/3/15
 *********************************************************************/
#include "HeaderFile.h"
int main()
{
	//Constant Declarations go here
	const char PROJECT_TYPE    = 'L';
	const char PROGRAMMER [30] = "Kermite & User";
	const int  LAB_NUM         = 03;
	const char LAB_NAME   [30] = "Supplement: Coin Flip";

	//Variable declarations go here
	string name;		//INPUT - the name of the user
	char gender;		//INPUT - the gender of the user
	int flip;			//PROC  - used to store a random value (t/f)
	bool result;		//PROC  - the boolean value being returned to main
	int headCount;		//PROC  - the # of times heads was flipped
	int sumCount;		//PROC  - the total times the coin was flipped
	int loopCount;		//PROC  - the lcv for the loop in main that decides
						//		  whether to keep flipping the coin
	int flipResult;		//PROC  - used to store the return value of
						//		  FlipCoin function
	int averageHead;	//OUTPUT - the average # of times heads was flipped
	int averageTotal;	//OUTPUT - used to call function that calc's the
						// 		   averageHead


	srand(time(NULL));

	//OUTPUT - the print header and the instructions for the game
	cout << PrintHeader(PROJECT_TYPE, PROGRAMMER, LAB_NUM, LAB_NAME);

	cout << endl;

	cout << "Welcome to coin toss! Get 3 heads in a row to win!\n\n";

	//Calling function UserInput
	UserInput(name, gender);

	cout << "Try to get 3 heads in a row. ";

	//PROCESSING - determines which to output based on the gender inputed
	switch(gender)
	{
	case 'm':
	case 'M': cout << "Good luck Mr. " << name << "!";
				break;
	case 'f':
	case 'F': cout << "Good luck Ms. " << name << "!";
				break;
	default : cout << "Error.";
	}
	cout << endl;

	//Initialize - loop counters
	loopCount = 0;
	sumCount = 0;
	headCount = 0;

	cout << endl;

	//PROCESSING - loops until three consecutive heads are flipped
	while(loopCount < 3)
	{
		cout << "Press <enter> to flip";
		cin.ignore(10000, '\n');

		flipResult = FlipCoin(flip, result, headCount, sumCount);

		sumCount += 1;

		if(flipResult == true)
		{
			loopCount += 1;
			headCount += 1;
		}
		else
		{
			loopCount = 0;
		}
	}

	//Calling function OuputResults
	OuputResults(sumCount, averageHead, headCount, averageTotal);

	return 0;
}





