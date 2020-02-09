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
* FUNCTION ChangeValue
*__________________________________________________________________________
* This function changes the value of a particular animal. Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*	fluffy		   : name of first animal
*	maa			   : name of second animal
*	babe		   : name of third animal
* POST-CONDITIONS
*  This function will modify the value of the chosen animal.
**************************************************************************/
void ChangeValue(Animals &fluffy,   // OUT - new value of animal fluffy
				 Animals &maa,		// OUT - new value of animal maa
				 Animals &babe)		// OUT - new value of animal babe
{
	float newVal; 	 	// PROC - Variable for new age
	int  changeValInput;// PROC - represents the value that was error checked

	AnimalMenu(fluffy, maa, babe);
	changeValInput = GetAndCheckIntInp("Select the animal you'd like to change: ",
									 1, 3);
	cout << endl;
	newVal = GetAndCheckFloatInput("NEW VALUE: ", 0, 400000);

	if (changeValInput == 1)
	{
		cout << "\nChanging Fluffy's value to " << newVal << "...\n\n";
		fluffy.SetValue(newVal);
	}
	else if (changeValInput == 2)
	{
		cout << "\nChanging Maa's value to " << newVal << "...\n\n";
		maa.SetValue(newVal);
	}
	else
	{
		cout << "\nChanging Babe's value to " << newVal << "...\n\n";
		babe.SetValue(newVal);
	}
}
