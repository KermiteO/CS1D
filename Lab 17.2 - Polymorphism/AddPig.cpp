/**************************************************************************
 * AUTHOR		: Kermite & Fireduck
 * LAB #17		: Polymorphism
 * CLASS		: CS1B
 * SECTION		: TTh 0800
 * DUE DATE		: 22APR2015
 *************************************************************************/

#include "Header.h"

/**************************************************************************
 * FUNCTION AddPig
 *_________________________________________________________________________
 *	This function will perform certain actions that will add a pig to the
 *	link list of farm animals and then return the new list by reference.
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	currentFarm : the current list of farm animals
 *
 * POST-CONDITIONS
 * 	returns a list (by reference) containing the new list of animals
 *************************************************************************/
void AddPig(FarmList &currentFarm)
{
	const string TAIL_MENU = "Pig Tail Type:\n"
							 "(C) - Corkscrew\n"
							 "(U) - Curls Up\n"
							 "(R) - Curls Right\n"
							 "(L) - Curls Left\n"
							 "(S) - Straight\n"
							 "Enter Choice (C/U/R/L/S): ";
	Pig			  *newPig;
	Animal		  *newAnimal;
	string 		   pigName;
	unsigned short pigAge;
	char		   tailMenuChoice;
	TailType       newPigTail;

	newAnimal = NULL;
	newPig    = NULL;

	cout << "Pig\'s Name: ";
	getline(cin, pigName);

	pigAge = GetValidInput("Pig\'s Age:", 12, 0, 20);

	cout << endl;

	tailMenuChoice = GetValidInput(TAIL_MENU, 0, 'C', 'U', 'R', 'L', 'S');

	switch(tailMenuChoice)
	{
	case 'C': newPigTail = CORKSCREW;
		break;
	case 'U': newPigTail = CURL_UP;
		break;
	case 'R': newPigTail = CURL_RIGHT;
		break;
	case 'L': newPigTail = CURL_LEFT;
		break;
	case 'S': newPigTail = STRAIGHT;
		break;
	}

	newPig = new Pig(pigAge, pigName, newPigTail);

	newAnimal = newPig;

	currentFarm.AddAnimal(newAnimal);

	cout << "\nThe animal:\n";

	currentFarm.OutputInfo(pigName);

	newPig 	  = NULL;
	newAnimal = NULL;
}
