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
* FUNCTION InitializeAnimals
*__________________________________________________________________________
* This function initalizes name, age, value, and type to the animals.
* Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
* 	none
* POST-CONDITIONS
*  This function will initialize all the animals and all their corresponding
*  information and attributes.
**************************************************************************/
void InitializeAnimals(Animals &fluffy, // IN&PROC - the sheep fluffy
					   Animals &maa,	// IN&PROC - the sheep maa
					   Animals &babe)	// IN&PROC - the pig babe
{
	//INITIALIZE - all three class objects
	fluffy.SetName("Fluffy");
	fluffy.SetAge(1);
	fluffy.SetValue(15000.00);
	fluffy.SetType("Sheep");

	maa.SetName("Maa");
	maa.SetAge(3);
	maa.SetValue(16520.35);
	maa.SetType("Sheep");

	babe.SetName("Babe");
	babe.SetAge(2);
	babe.SetValue(10240.67);
	babe.SetType("Pig");
}
