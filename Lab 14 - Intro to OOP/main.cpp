/*************************************************************************
 * AUTHOR		: Kermite & ChickenLips
 * LAB #14      : Intro to OOP
 * CLASS		: CS1B
 * SECTION		: T/TH 8am
 * DUE DATE		: 3/19/15
 *************************************************************************/

#include "header.h"
#include "Animals.h"

/*************************************************************************
 * 	LAB - Intro to OOP
 * -----------------------------------------------------------------------
 *	This program implements a doubly linked list which is created
 *	alphabetically. The user may then search for a particular name.
 *	The program also outputs the list, outputs the list in reverse order,
 *	checks if the list is empty, removes a node, or clears the list.
 * -----------------------------------------------------------------------
 * INPUT:
 * 	menuChoice
 * 	inFileName
 * 	searchKey
 * OUTPUT:
 * This program outputs the entire list or a particular node.
 *************************************************************************/
int main()
{
	// VARIABLE DECLARATIONS
	int 	userInput;	     // IN&PROC - a command # choice from the first menu
	int 	secUserInput;	 // IN&PROC - a command # choice from the second menu
	Animals fluffy;			 // PROC&OUT- the sheep called Fluffy
	Animals maa;			 // PROC&OUT- the sheep called Maa
	Animals babe;			 // PROC&OUT- the pig called Babe
	char    userCharInput;   // IN&PROC	- a Y/N validation

	// OUTPUTS CLASS HEADING TO CONSOLE
	cout << PrintHeaderStream(PROGRAMMER,CLASS,SECTION,AS_NAME, AS_TYPE,AS_NUM);

/****************************************************************************
 * INPUT - Will enter a do while loop who's sole purpose is to initialize
 * 		   all the animals to their corresponding attribute information
 ****************************************************************************/
	do
	{
		MenuOptions();
		userInput = GetAndCheckIntInp("Enter selection: ", 0, 1);
		cout << endl;

		switch (userInput)
		{
			case EXIT		:  break;
			case INITANIMALS: InitializeAnimals(fluffy, maa, babe);
							  cout << "Initializing " << fluffy.GetName()
								   << ", " << maa.GetName() << ", & "
								   << babe.GetName() << "...\n\n";
							   break;
		};

	} while(userInput != 1 && userInput != 0);

/****************************************************************************
 * PROCESSING - If the animals have all been initialized, then the code will
 * 				enter an if statement that displays a second menu and prompts
 * 				the user to choose one of the commands. Once a command is
 * 				chosen, then it will enter a while loop that will keep
 * 				prompting the user for commands until the user enters 0 to
 * 				exit. It will then take the # command and execute one of
 * 				the cases in the switch statement that will call specific
 * 				functions to either re-initialize, change the age, value, or
 * 				display the animal info.
 ****************************************************************************/
	if(userInput == 1)
	{
		SecondMenuOptions();
		secUserInput = GetAndCheckIntInp("Enter selection: ", 0, 4);
		cout << endl;

		while(secUserInput != 0)
		{
			switch(secUserInput)
			{
			case SECONDEXIT		:  break;
			case SECINITANIMALS : userCharInput = GetAndCheckCharInput("Are you "
						   	      "sure you want to reinitialize (Y/N)? ", 'Y',
						   	      'N');
								 if (userCharInput == 'Y')
								 {
									 InitializeAnimals(fluffy, maa, babe);
									 cout << "Initializing " << fluffy.GetName()
									      << ", " << maa.GetName() << ", & "
									      << babe.GetName() << "...\n\n";
								 }
								 else
								 {
									 cout << "Animals have not been "
											 "re-initialized!\n\n";
								 }
								   break;
			case CHANGEAGE		: ChangeAge(fluffy, maa, babe);
								   break;
			case CHANGEVALUES   : ChangeValue(fluffy, maa, babe);
								   break;
			case DISPLAY		: cout << DisplayList(fluffy, maa, babe);
								   break;
			}
			// PROC - update the lcv
			SecondMenuOptions();
			secUserInput = GetAndCheckIntInp("Enter selection: ", 0, 4);
			cout << endl;
		}
	}

	return 0;
}
