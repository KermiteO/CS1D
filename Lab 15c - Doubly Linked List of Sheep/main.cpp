/*************************************************************************
 * AUTHOR		: Kermite & Clover
 * LAB #15      : Arrays & Linked Lists for FarmList
 * CLASS		: CS1B
 * SECTION		: T/TH 8am
 * DUE DATE		: 4/9/15
 *************************************************************************/

#include "header.h"
#include "Sheep.h"
#include "FarmList.h"

/*************************************************************************
 * 	LAB 15c - Doubly Linked Lists of Sheep
 * -----------------------------------------------------------------------
 * This program will implement a sheep class and let the user choose what
 * to do with that information. The program will prompt the user to choose
 * an option of 0-6 and accordingly perform certain actions on the link list
 * the user has created. The user may enter 0 to exit and the program will
 * repeat this process until the user enters 0. The information will be kept
 * in the form of a doubly linked list.
 * -----------------------------------------------------------------------
 * INPUT:
 * userInput  : a command # choice from the first menu
 * sheepAge   : a sheep's age
 * sheepName  : a sheep's name
 * searchSheep: name of a sheep user wants searched
 * OUTPUT:
 * sheepAge   : a sheep's age
 * sheepName  : a sheep's name
 *************************************************************************/
int main()
{
	// VARIABLE DECLARATIONS
	int 	  userInput;	// IN&PROC 	  - a command # choice from the first menu
	int       sheepAge;	    // IN/PROC/OUT- a sheep's age
	int		  totalSheep;   // PROC&OUT	  - the total number of sheep
	string    sheepName;	// IN/PROC/OUT- a sheep's name
	string    searchSheep;  // IN&PROC 	  - name of a sheep you want searched
	string	  remSheep;		// IN&PROC    - sheep you'd like to remove
	Sheep	  newSheep;	    // PROC		  - a specific sheep in the list
	Sheep	  firstSheep;   // PROC&OUT   - the sheep found at the front of array
	FarmList  sheepList;	// PROC		  - used to reference the farm list
	SheepMenu menuChoice;   // PROC       - the users menuChoice as an enum

	// OUTPUTS CLASS HEADING TO CONSOLE
	cout << PrintHeaderStream(PROGRAMMER,CLASS,SECTION,AS_NAME, AS_TYPE,AS_NUM);

/**************************************************************************
 * OUTPUT - Outputs the Welcome message to the screen
 **************************************************************************/
	cout << endl;
	cout << setw(37) << setfill('*') << '*' << setfill(' ') << endl;
	cout << "* WELCOME TO THE SHEEP LIST MANAGER *\n";
	cout << setw(37) << setfill('*') << '*' << setfill(' ') << endl;

/**************************************************************************
 * INPUT - Will prompt and get the user's menu choice option. The
 *         Program will then continue to check the userInput and
 *         perhaps repeat this process until a correct userInput has
 *         been entered
 **************************************************************************/
	MenuOptions();
	userInput = GetAndCheckIntInp("Enter selection: ", 0, 7);
	cout << endl;

	menuChoice = ConvertIntToEnumType(userInput);

/***************************************************************************
 * PROCCESSING - Program will enter a while loop based on the user input.
 * 		  		 If the user entered a 0, the program will fail to enter the
 * 		 		 while loop and exit the program. In the while loop the
 * 		  		 program will perform a certain action on the sheep array
 * 		  		 based on the userInput. It will repeat doing so until the
 * 		  		 user enters a 0.
 ***************************************************************************/
	while(menuChoice != EXIT)
	{
		//PROC - Switches the user's menu choice to determine what
		//        action needs to be done
		switch (menuChoice)
		{
			case ADDSHEEP:
				    cout << "Sheep Name: ";
					getline(cin, sheepName);
					cout << left << setw(12);
					sheepAge = GetAndCheckIntInp("Sheep Age: ", 0, 9);

					//Initializes the new sheep
					newSheep.SetInitalValues(sheepName, sheepAge);
					//Adds the new sheep to the array
					sheepList.AddSheep(newSheep);

					//Gets and outputs the name and age of the new sheep
					cout << "\nThe sheep...\n" << "Sheep Name: "
						 << newSheep.GetName() << endl;
					cout << left << setw(12) << "Sheep Age:"
						 << newSheep.GetAge()<< "\nHas been added!\n";
					 break;
			case OUTPUTFIRST: //Displays info of 1 sheep if the total # of sheep isn't 0
					if(sheepList.TotalSheep() != 0)
					{
						firstSheep = sheepList.GetFirstSheep();
						DisplayOneSheep(firstSheep);
						cout << "\nIs at the front of the list.\n";
					}
					else
					{
						cout << "Nobody is in front - the list is empty!\n";
					}
					 break;
			case FINDSHEEP:
				    if(sheepList.TotalSheep() != 0)
					{
						cout << "Who are you looking for? ";
						getline(cin, searchSheep);
						cout << endl;

						//Finds the sheep to be searched and displays its
						// info if it is found
						newSheep = sheepList.FindSheep(searchSheep);

						if(!(newSheep.GetName().empty()))
						{
							DisplayOneSheep(newSheep);
							cout << "\nHas been found.\n";
						}
						else
						{
							cout << searchSheep << " has not been found.\n";
						}
					}
					else
					{
						cout << "There are no sheep to be found!\n";
					}
					 break;
			case LISTSIZE: totalSheep = sheepList.TotalSheep();

					//Displays how many sheep there are in the array,
					// checking first if there is any to begin with
					if(totalSheep != 0)
					{
						cout << "There are " << totalSheep
							 << " sheep in the list!\n";
					}
					else
					{
						cout << "The list is empty!\n";
					}
					 break;
			case OUTPUTLIST: sheepList.DisplaySheepTable();
					 break;
			case CLEARLIST:
				    if(sheepList.TotalSheep() != 0) //Clears the array
					{
						sheepList.ClearList();
						cout << "The list has been cleared!\n";
					}
					else
					{
						cout << "The list is empty!\n";
					}
					 break;
			case REMOVE:
					if(sheepList.TotalSheep() != 0)
					{
						 cout << "Which sheep would you like to remove? ";
						 getline(cin, remSheep);
						 sheepList.RemoveSheep(remSheep);
					}
					else
					{
						cout << "The list is empty!\n";
					}
				     break;
			case EXIT:  break;
		}//END SWITCH

		//Updates the loop control variable with the users new menu choice
		MenuOptions();
		userInput = GetAndCheckIntInp("Enter selection: ", 0, 7);
		cout << endl;
		menuChoice = ConvertIntToEnumType(userInput);
	}//END WHILE

	return 0;
}
