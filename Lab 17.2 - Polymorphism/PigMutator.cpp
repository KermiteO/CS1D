/**************************************************************************
 * AUTHOR		: Kermite & Fireduck
 * LAB #17		: Polymorphism
 * CLASS		: CS1B
 * SECTION		: TTh 0800
 * DUE DATE		: 22APR2015
 *************************************************************************/

#include "Pig.h"

/**************************************************************************
 * Method ChangeAge : Class Pig
 *_________________________________________________________________________
 *	This method Calls the animal Class ChangeValues and passes in the
 *	newPigAge to change the pigs age
 *_________________________________________________________________________
 * PRE-CONDITIONS
 *	newPigAge : the new Age for the Pig
 *
 * POST-CONDITIONS
 * 	updates the pigs Age
 *************************************************************************/
void Pig :: ChangeAge(unsigned short newPigAge)
{
	Animal :: ChangeValues(newPigAge);
}

/**************************************************************************
 * Method SetTail : Class Pig
 *_________________________________________________________________________
 *	This method updates the tail type for the pig
 *_________________________________________________________________________
 * PRE-CONDITIONS
 *	pigTail : The pigs new tail
 *
 * POST-CONDITIONS
 * 	updates the pigs tail
 *************************************************************************/
void Pig :: SetTail(TailType pigTail)
{
	tail = pigTail;
}
