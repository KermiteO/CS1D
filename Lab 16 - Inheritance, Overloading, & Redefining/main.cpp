/*************************************************************************
 * AUTHOR		: Kermite & Flash Gordon
 * LAB #16      : Inheritance, Overloading, Redefining
 * CLASS		: CS1B
 * SECTION		: T/TH 8am
 * DUE DATE		: 4/21/15
 *************************************************************************/

#include "header.h"
#include "Sheep.h"
#include "SheepList.h"
#include "Pig.h"
#include "PigList.h"

/*************************************************************************
 * 	LAB 16 - Inheritance, Overloading, & Redefining
 * -----------------------------------------------------------------------
 * This program will use 5 different classes to create two different
 * lists of farm animals. One list will have all the sheep and the other
 * will have all the pigs. As far as user input is concerned, they will
 * first be prompted with a menu to either exit the program or initialize
 * all the animals. From there, they will then get a second menu that
 * prompts the user to either reinitialize the sheep list or the pig list,
 * change the age of a sheep or a pig, display both lists, or exit the
 * program. The program ends when the user enters 0.
 * -----------------------------------------------------------------------
 * INPUT:
 * userInput  : a command # choice from the second menu
 * firstUserIn: a command # choice from the first menu
 * animalType : an animal type
 * animalName : an animal's name
 * OUTPUT:
 * listOfSheep: a list of sheep
 * listOfPigs : a list of pigs
 *************************************************************************/
int main()
{
	//CONSTANT DECLARATIONS GO HERE
	const string         PROGRAMMER	 = "Kermite & Flash Gordon";
	const string         CLASS       = "CS1B";
	const string         SECTION     = "T/Th 8am";
	const string         AS_NAME     = "Inheritance, Overloading, & Redefining";
	const char	         AS_TYPE     = 'L';
	const unsigned short AS_NUM	     = 16;

	const string MENU1 = "1 - Initialize Animals\n"
			             "0 - Exit\n"
						 "Enter selection: ";

	const string MENU2 = "1 - Re-Initialize Sheep\n"
				         "2 - Re-Initialize Pigs\n"
						 "3 - Change Age\n"
						 "4 - Display\n"
						 "0 - Exit\n"
						 "Enter selection: ";

	// VARIABLE DECLARATIONS GO HERE
	MenuOption userInput;	// IN&PROC - a command # choice from the second menu
	MenuOption2 firstUserIn;// IN&PROC - command # choice from the first menu
	SheepList  listOfSheep;	// PROC&OUT- used to reference the farm list
	PigList	   listOfPigs;  // PROC&OUT- accesses methods in PigList
	string 	   animalType;  // IN&PROC - the animal type

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
 * INPUT - Will first prompt user to initialize animals or exit program.
 * 		   Then, it will create two doubly linked lists of sheep and pigs
 * 		   only if the user entered 1. Finally, it will output a second
 * 		   menu of command choices and prompt the user to do their thing.
 **************************************************************************/
	firstUserIn = MenuOption2(GetAndCheckIntInp(MENU1, 0, 1));
	cout << endl;

	if(firstUserIn == INIT_ANIMALS)
	{
		listOfSheep.CreateListFromFile();
		listOfPigs.CreateListFromFile();

		cout << "Both animals have been initialized!\n\n";
	}

	userInput = MenuOption(GetAndCheckIntInp(MENU2, 0, 4));
/*****************************************************************************
 * PROCCESSING & - Program will enter a while loop based on the user input.
 * OUTPUT		   If the user entered a 0, the program will fail to enter the
 * 		 		   while loop and exit the program. In the while loop the
 * 		  		   program will perform a certain action on the two link lists
 * 		  		   of animals to either reinitialize, change the ages of
 * 		  		   individual animals, display the lists, or exit the program.
 *****************************************************************************/
	while(userInput != EXIT)
	{
		//PROC - Switches the user's menu choice to determine what
		//        action needs to be done
		switch (userInput)
		{
			case INIT_SHEEP : listOfSheep.ClearList();
							  listOfSheep.CreateListFromFile();
							  cout << endl;
							  cout << "The sheep have been re-initialized!\n\n";
							  break;

			case INIT_PIGS :  listOfPigs.ClearList();
							  listOfPigs.CreateListFromFile();
							  cout << "\nThe pigs have been re-initialized!\n\n";
							  break;

			case CHANGE_AGE : cout << "\nEnter animal type: ";
							  getline(cin, animalType);
							  // PROC - will change an age only if animalType
							  //		is a sheep or pig
							  if(animalType == "sheep" || animalType == "Sheep")
							  {
								  listOfSheep.ChangeAge();
							  }
							  else if(animalType == "pig" || animalType == "Pig")
							  {
								  listOfPigs.ChangeAge();
							  }
							  else
							  {
								  cout << "\nInvalid animal type!\n\n";
							  }//END IF STATEMENT
							  break;

			case DISPLAY :// PROC - will display the animal lists if the total
						  //		# of sheep and pigs aren't zero
							if(listOfSheep.TotalSheep() != 0
						    || listOfPigs.TotalPigs() != 0)
						    {
									cout << endl;
									listOfSheep.DisplaySheepTable();
									cout << endl;
									listOfPigs.DisplayPigTable();
									cout << endl << endl;
							}
						    else
						    {
						    	cout << "\nThere is nothing to display!\n";
						    }//END IF STATEMENT
						      break;
		}//END SWITCH

		//Updates the loop control variable with the users new menu choice
		userInput = MenuOption(GetAndCheckIntInp(MENU2, 0, 4));
	}//END WHILE

	return 0;
}
