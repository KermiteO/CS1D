/*************************************************************************
 * AUTHOR		: Kermite & ChickenLips
 * LAB #14      : Intro to OOP
 * CLASS		: CS1B
 * SECTION		: T/TH 8am
 * DUE DATE		: 3/19/15
 *************************************************************************/
#include "header.h"
#include "Animals.h"

/**************************************************************************
* FUNCTION ChangeAge
*__________________________________________________________________________
* This function changes the age of a particular animal. Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*	fluffy		   : name of first animal
*	maa			   : name of second animal
*	babe		   : name of third animal
* POST-CONDITIONS
*  This function will modify the age of the chosen animal.
**************************************************************************/
void ChangeAge (Animals &fluffy,    // OUT - new age of animal fluffy
				Animals &maa,		// OUT - new age of animal maa
				Animals &babe)		// OUT - new age of animal babe
{
	int newAge; 	 	// PROC&OUT - Variable for new age
	int  changeAgeInput;// PROC 	- represents the value that was error checked

	AnimalMenu(fluffy, maa, babe);
    changeAgeInput = GetAndCheckIntInp("Select the animal you'd like to change: ",
    							     1, 3);
	cout << endl;
	newAge = GetAndCheckIntInp("NEW AGE: ", 0, 10);

	if (changeAgeInput == 1)
	{
		cout << "\nChanging Fluffy's age to " << newAge << "...\n\n";
		fluffy.SetAge(newAge);
	}
	else if (changeAgeInput == 2)
	{
		cout << "\nChanging Maa's age to " << newAge << "...\n\n";
		maa.SetAge(newAge);
	}
	else
	{
		cout << "\nChanging Babe's age to " << newAge << "...\n\n";
		babe.SetAge(newAge);
	}
}
