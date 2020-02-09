/**************************************************************************
 * AUTHOR		: Kermite & Fireduck
 * LAB #17		: Polymorphism
 * CLASS		: CS1B
 * SECTION		: TTh 0800
 * DUE DATE		: 22APR2015
 *************************************************************************/

#include "Animal.h"

/**************************************************************************
 * Method ChangeValues : Class Animal
 *_________________________________________________________________________
 *	This method Changes the data stored in name and age
 *_________________________________________________________________________
 * PRE-CONDITIONS
 *	newName: The new name for the animal
 *	newAge : The new Age for the animal
 *
 * POST-CONDITIONS
 * 	Changes the data stored in name and age
 *************************************************************************/
void Animal :: ChangeValues(string 		   newName,
							unsigned short newAge)
{
	name = newName;
	age  = newAge;
}

/**************************************************************************
 * Method ChangeValues : Class Animal
 *_________________________________________________________________________
 *	This method changes the value stored in the animals name
 *_________________________________________________________________________
 * PRE-CONDITIONS
 *	newName  : The new name for the animal
 *
 * POST-CONDITIONS
 * 	updates the data stored in name
 *************************************************************************/
void Animal :: ChangeValues(string newName)
{
	name = newName;
}

/**************************************************************************
 * Method ChangeValues : Class Animal
 *_________________________________________________________________________
 *	This method changes the data stored in the animals age
 *_________________________________________________________________________
 * PRE-CONDITIONS
 *	newAge : The new age for the animal
 *
 * POST-CONDITIONS
 * 	updates the data stored in age
 *************************************************************************/
void Animal :: ChangeValues(unsigned short newAge)
{
	age = newAge;
}
