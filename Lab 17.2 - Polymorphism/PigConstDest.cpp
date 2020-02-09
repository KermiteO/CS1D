/***********************************************************************
 * AUTHOR		: The Oz & Fireduck
 * LAB #16		: Inheritance, Overloading, & Redefining
 * CLASS		: CS1B
 * SECTION		: TTh 0800
 * DUE DATE		: 22APR2015
 ***********************************************************************/

#include "Pig.h"

/**************************************************************************
 * Constructor Pig : Class Pig
 *_________________________________________________________________________
 *	This Constructor is the default constructor for the pig class,
 *	initializes the pigs tail to STRAIGHT
 *_________________________________________________________________________
 * PRE-CONDITIONS
 *	none
 *
 * POST-CONDITIONS
 * 	initializes the new Pig
 *************************************************************************/
Pig :: Pig()
{
	tail = STRAIGHT;
}

/**************************************************************************
 * Constructor Pig : Class Pig
 *_________________________________________________________________________
 *	This Constructor initializes the animals age name and tail to the
 *	values passed into it
 *_________________________________________________________________________
 * PRE-CONDITIONS
 *	animalAge  : The age of the new pig
 *	animalName : The name of the new Pig
 *	animalTail : The tail type of the new pig
 *
 * POST-CONDITIONS
 * 	Initializes the new Pig
 *************************************************************************/
Pig :: Pig (unsigned short animalAge,
		    string animalName,
		    TailType animalTail)
            : Animal(animalName, animalAge)
{

	tail = animalTail;
}

/**************************************************************************
 * Destructor ~Pig : Class Pig
 *_________________________________________________________________________
 *	This Destructor does nothing in particular
 *_________________________________________________________________________
 * PRE-CONDITIONS
 *	none
 *
 * POST-CONDITIONS
 * 	none
 *************************************************************************/
Pig :: ~Pig () {}
