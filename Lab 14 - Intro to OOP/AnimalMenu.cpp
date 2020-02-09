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
* FUNCTION AnimalMenu
*__________________________________________________________________________
* This function provides an animal menu that specifies a different animal.
* Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*	fluffy : represents the sheep Fluffy
*	maa	   : represents the second sheep Maa
*	babe   : represents the pig Babe
* POST-CONDITIONS
*  This function displays the options menu
**************************************************************************/
void AnimalMenu (Animals &fluffy, // IN&PROC - the animal Fluffy
				 Animals &maa,	  // IN&PROC - the animal Maa
				 Animals &babe)   // IN&PROC - the animal Babe
{
	cout << "1 - " << fluffy.GetName() << endl
		 << "2 - " << maa.GetName()    << endl
		 << "3 - " << babe.GetName()   << endl;
}
