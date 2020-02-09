/**************************************************************************
 * AUTHOR		: Kermite & Fireduck
 * LAB #17		: Polymorphism
 * CLASS		: CS1B
 * SECTION		: TTh 0800
 * DUE DATE		: 22APR2015
 *************************************************************************/

#include "FarmList.h"

/**************************************************************************
 * Constructor FarmList() : Class FarmList
 *_________________________________________________________________________
 *	This is the default FarmList constructor, initializes FarmListCounter to 0
 *	and head to NULL.
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	none
 * POST-CONDITIONS
 * 	Initializes the data items for an FarmList variable
 *************************************************************************/
FarmList::FarmList()
{
	animalCounter = 0;
	head = NULL;
}

/**************************************************************************
 * Destructor ~FarmList() : Class FarmList
 *_________________________________________________________________________
 *	This is the default FarmList Destructor, and will recreate
 *	an empty link list.
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	none
 * POST-CONDITIONS
 * 	will delete all the nodes in the list until empty.
 *************************************************************************/
FarmList::~FarmList()
{
	AnimalNode *deletePointer;

	while(head != NULL)
	{
		deletePointer = head;
		head = head->next;
		delete deletePointer;
	}

	deletePointer = NULL;
}
