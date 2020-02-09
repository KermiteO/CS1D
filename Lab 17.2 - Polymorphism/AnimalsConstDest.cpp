/***********************************************************************
 * AUTHOR		: The Oz & Fireduck
 * LAB #16		: Inheritance, Overloading, & Redefining
 * CLASS		: CS1B
 * SECTION		: TTh 0800
 * DUE DATE		: 22APR2015
 ***********************************************************************/

#include "Animal.h"

/**************************************************************************
 * Constructor Animal() : Class Animal
 *_________________________________________________________________________
 *	This is the default Animal constructor, initializes age to 0
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	none
 * POST-CONDITIONS
 * 	Initializes the data items for an animal variable
 *************************************************************************/
Animal :: Animal()
{
	age = 0;
}

/**************************************************************************
 * Constructor Animal() : Class Animal
 *_________________________________________________________________________
 *	This is a non-default Animal constructor, initializes age to animalAge
 *  and name to animalName
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	animalName : The name of the new animal
 * 	animalAge  : The age of the new animal
 *
 * POST-CONDITIONS
 * 	Initializes the data items for an animal variable
 *************************************************************************/
Animal :: Animal(string         animalName,
				 unsigned short animalAge)
{
	name = animalName;
	age  = animalAge;
}

/**************************************************************************
 * Destructor ~Animal() : Class Animal
 *_________________________________________________________________________
 *	This is the default Animal Destructor, does nothing special
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	none
 * POST-CONDITIONS
 * 	none
 *************************************************************************/
Animal :: ~Animal() {}
