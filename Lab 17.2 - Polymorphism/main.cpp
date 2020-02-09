/**************************************************************************
 * AUTHOR		: Kermite & Fireduck
 * LAB #17		: Polymorphism
 * CLASS		: CS1B
 * SECTION		: TTh 0800
 * DUE DATE		: 22APR2015
 *************************************************************************/

#include "Header.h"

/*************************************************************************
 * 	LAB 17 - Polymorphism
 * -----------------------------------------------------------------------
 * This program will utilize 4 different classes to store various sheep
 * and pigs into a doubly linked lists. It utitilizes one base class
 * (Animal), two derived classes (Sheep & Pig), and one FarmList that
 * manages the actual list of animals. The user will be given a menu
 * to either add or remove an animal, output the first animal in the list,
 * find a specific animal in the list, display the animals in the list,
 * clear the list, list the # of animals currently in the list, or exit
 * the program. From there, the user will be prompted to enter in info
 * for either a new sheep or pig to be added to the list and depending
 * on the command, a text blurb and image of the certain animal in question
 * will be displayed. This program utitilizes concepts of polymorphism,
 * virtual functions, inheritance, overloading, and redefining.
 * -----------------------------------------------------------------------
 * INPUT:
 * mainMenuOption : option from 1st menu regarding the list of animals
 * animalType	  : the option from menu that regards the animal type
 * deleteAnimal	  : the name of an animal you want deleted
 * animalName	  : the name of an animal you want searched for
 *
 * OUTPUT:
 * an individual pig or sheep with it's life story and picture image.
 *************************************************************************/
int main()
{
	//Constant Declarations go here
	const string WELCOME = "**************************************\n"
						   "* WELCOME TO THE ANIMAL LIST MANAGER *\n"
						   "**************************************\n";

	const string MAIN_MENU = "1 - Add Animal\n"
							 "2 - Remove Animal\n"
							 "3 - Output 1st Animal\n"
							 "4 - Find Animal\n"
						     "5 - List Size\n"
							 "6 - Display Table\n"
							 "7 - Clear List\n"
							 "0 - Exit\n"
							 "Enter a command: ";

	const string TYPE_MENU = "ANIMAL TYPE:\n"
							 "(P) - Pig\n"
							 "(S) - Sheep\n"
							 "Selection (P/S): ";

	const string COLOR_MENU = "Sheep Color:\n"
							  "(B) - Black\n"
							  "(W) - White\n"
							  "Enter Choice (B/W): ";

	const string WOOL_MENU =  "Sheep Wool Type:\n"
							  "(L) - Long\n"
							  "(M) - Medium\n"
							  "(F) - Fine\n"
							  "(C) - Carpet\n"
							  "Enter Choice (L/M/F/C): ";

	const string TAIL_MENU = "Pig Tail Type:\n"
							 "(C) - Corkscrew\n"
							 "(U) - Curls Up\n"
							 "(R) - Curls Right\n"
							 "(L) - Curls Left\n"
							 "(S) - Straight\n"
							 "Enter Choice (C/U/R/L/S): ";

	//Variable Declarations go here
	FarmList 	myFarm;           // PROC 	    - used to access meths in FarmList
	MenuOptions mainMenuOption;   // IN & PROC  - a command from 1st menu
	char		animalType;       // IN & PROC  - an animal type
	string		lifeStory;        // PROC & OUT - the text & image of animal
	string		animalName;       // IN & PROC  - an animal's name
	string		deleteAnimal;     // IN & PROC  -  name of an animal want delete


	PrintHeaderOstream(cout, "Polymorphism", 'L', "17", "Kermite & Fireduck");

/*************************************************************************
 * INPUT - Will give a menu of 7 command choices regarding a list of
 * 		   animals and which action on said list the user wishes to
 * 		   perform.
 *************************************************************************/

	cout << WELCOME;

	mainMenuOption = MenuOptions(GetValidInput(MAIN_MENU, 0, EXIT, CLEAR));

/*****************************************************************************
 * PROCESSING & -  Program will enter a while loop based on the user input.
 * OUTPUT		   If the user entered a 0, the program will fail to enter the
 * 		 		   while loop and exit the program. In the while loop the
 * 		  		   program will perform a certain action on the link list
 * 		  		   of animals to either add a new animal, remove an animal,
 * 		  		   output the first animal in the list, find a certain animal,
 * 		  		   output the # of total animals in the list, display all the
 * 		  		   animals in the list, or clear the entire list.
 *****************************************************************************/
	while(mainMenuOption != EXIT)
	{
		switch(mainMenuOption)
		{
		case ADD: cout << endl;
				  animalType = GetValidInput(TYPE_MENU, 0, 'S', 'P');
				  cout << endl;
				  // PROC - will either add a sheep if animalType is 'S' or add
				  //		a pig.
				  if(animalType == 'S')
				  {
					  AddSheep(myFarm);
				  }
				  else
				  {
					  AddPig(myFarm);
				  }
			break;
		case REMOVE: // PROC - will only prompt and remove if the list isn't empty
					 if(!(myFarm.IsEmpty()))
					 {
			 	 	 	 cout << "\nWho would you like to remove? ";
						 getline(cin, deleteAnimal);

						 myFarm.RemoveAnimal(deleteAnimal);
					 }
					 else
					 {
						cout << "\nCan't remove from an empty list!\n";
					 }
			break;
		case OUTPUT: // OUT - will output the head only if the list isn't empty
					 if(!(myFarm.IsEmpty()))
					 {
						 myFarm.OutputHead();
					 }
					 else
					 {
						 cout << "\nThere is nobody in the front to output!\n";
					 }
			break;
		case FIND:  // PROC & OUT - will only prompt & find if the list isn't empty
					if(!(myFarm.IsEmpty()))
					{
						cout << "\nWho are you looking for? ";
					    getline(cin, animalName);

						myFarm.OutputInfo(animalName);
					}
					else
					{
						cout << "\nCannot Search an Empty List.\n";
					}
			break;
		case SIZE:  // OUT - will only list the size if the list isn't empty
						if(!(myFarm.IsEmpty()))
						{
							myFarm.ListSize();
						}
						else
						{
							cout << "\nThere are no animals on the Farm!\n";
						}
				break;
		case DISPLAY: // OUT - will only display if the list isn't empty
					  if(!(myFarm.IsEmpty()))
					  {
					  	  myFarm.DisplayTable();

					  	  cout << endl;

						  myFarm.ListSize();
					  }
					  else
					  {
						  cout << "\nThere is nothing to display!\n";
					  }
			break;
		case CLEAR: myFarm.ClearList();
			break;
		}

		cout << endl;

		//Update the LCV for while loop
		mainMenuOption = MenuOptions(GetValidInput(MAIN_MENU,
												   0, EXIT, CLEAR));
	}

	return 0;
}
