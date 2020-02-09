/**************************************************************************
 * AUTHOR		: Kermite & Fireduck
 * LAB #17		: Polymorphism
 * CLASS		: CS1B
 * SECTION		: TTh 0800
 * DUE DATE		: 22APR2015
 *************************************************************************/

#include "Header.h"

/**************************************************************************
 * FUNCTION AddSheep
 *_________________________________________________________________________
 *	This function will perform certain actions that will add a sheep to the
 *	link list of farm animals and then return the new list by reference.
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	currentFarm : the current list of farm animals
 *
 * POST-CONDITIONS
 * 	returns a list (by reference) containing the new list of animals
 *************************************************************************/
 void AddSheep(FarmList &currentFarm)
{
	const string WOOL_MENU =  "Sheep Wool Type:\n"
							  "(L) - Long\n"
							  "(M) - Medium\n"
							  "(F) - Fine\n"
							  "(C) - Carpet\n"
							  "Enter Choice (L/M/F/C): ";

	const string COLOR_MENU = "Sheep Color:\n"
							  "(B) - Black\n"
							  "(W) - White\n"
							  "Enter Choice (B/W): ";

	Sheep		  *newSheep;
	Animal		  *newAnimal;
	string 		   sheepName;
	unsigned short sheepAge;
	char		   woolMenuChoice;
	char		   colorMenuChoice;
	WoolType       newSheepWool;
	ColorType	   newSheepColor;

	newAnimal = NULL;
	newSheep  = NULL;

	cout << "Sheep\'s Name: ";
	getline(cin, sheepName);

	sheepAge = GetValidInput("Sheep\'s Age:", 14, 0, 9);

	cout << endl;

	woolMenuChoice = GetValidInput(WOOL_MENU, 0, 'L', 'M', 'F', 'C');

	switch(woolMenuChoice)
	{
	case 'L': newSheepWool = LONG;
		break;
	case 'M': newSheepWool = MEDIUM;
		break;
	case 'F': newSheepWool = FINE;
		break;
	case 'C': newSheepWool = CARPET;
		break;
	}

	cout << endl;

	colorMenuChoice = GetValidInput(COLOR_MENU, 0, 'B', 'W');

	if(colorMenuChoice == 'B')
	{
		newSheepColor = BLACK;
	}
	else
	{
		newSheepColor = WHITE;
	}

	newSheep = new Sheep(sheepName, sheepAge, newSheepWool, newSheepColor);

	newAnimal = newSheep;

	currentFarm.AddAnimal(newAnimal);

	cout << "\nThe animal:\n";
	currentFarm.OutputInfo(sheepName);

	newSheep  = NULL;
	newAnimal = NULL;
}
