/**************************************************************************
 * AUTHOR		: Kermite & Fireduck
 * LAB #17		: Polymorphism
 * CLASS		: CS1B
 * SECTION		: TTh 0800
 * DUE DATE		: 22APR2015
 *************************************************************************/

#include "Sheep.h"

/**************************************************************************
 * Constructor Sheep : Class Sheep
 *_________________________________________________________________________
 *	This is the default constructor for Sheep, initializes type to LONG &
 *	BLACK.
 *_________________________________________________________________________
 * PRE-CONDITIONS
 *	none
 *
 * POST-CONDITIONS
 * 	initializes a Sheep
 *************************************************************************/
Sheep :: Sheep()
{
	type  = LONG;
	color = BLACK;
}

/**************************************************************************
 * Constructor Sheep : Class Sheep
 *_________________________________________________________________________
 *	This Constructor takes a sheepName, sheepAge, woolType, and woolColor as
 *	input and initializes the data for a Sheep
 *_________________________________________________________________________
 * PRE-CONDITIONS
 *	sheepName : The name for the new Sheep
 *	sheepAge  : The age for the new Sheep
 *	woolType  : The WoolType for the new Sheep
 *	woolColor : The color of the new Sheep
 *
 * POST-CONDITIONS
 * 	initialized Sheep
 *************************************************************************/
Sheep :: Sheep(string 		  sheepName,
			   unsigned short sheepAge,
			   WoolType       woolType,
			   ColorType 	  woolColor)
	   : Animal(sheepName, sheepAge)
{
	type  = woolType;
	color = woolColor;
}



/**************************************************************************
 * Destructor ~Sheep : Class Sheep
 *_________________________________________________________________________
 *	This destructor does nothing in particular
 *_________________________________________________________________________
 * PRE-CONDITIONS
 *	none
 *
 * POST-CONDITIONS
 * 	none
 *************************************************************************/
Sheep :: ~Sheep() {}
