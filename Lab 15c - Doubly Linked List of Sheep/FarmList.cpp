/*************************************************************************
 * AUTHOR		: Kermite & Clover
 * LAB #15      : Arrays & Linked Lists for FarmList
 * CLASS		: CS1B
 * SECTION		: T/TH 8am
 * DUE DATE		: 4/9/15
 *************************************************************************/

#include "header.h"
#include "FarmList.h"
#include "Sheep.h"

/**************************************************************************
* Constructor FarmList
*__________________________________________________________________________
* This function is a constructor that initializes value to FarmList.
* Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*  none
* POST-CONDITIONS
*  only initialize values.
**************************************************************************/
FarmList::FarmList()
{
	head = NULL;
	tail = NULL;
	sheepCounter = 0;
};

/**************************************************************************
* Deconstructor ~FarmList
*__________________________________________________________________________
* This function is a deconstructor that terminates the FarmList class.
* Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*  none
* POST-CONDITIONS
*  Terminates the FarmList class
**************************************************************************/
FarmList::~FarmList()
{
	delete head;
	delete tail;
};

/**************************************************************************
* Method AddSheep: Class Sheep
*__________________________________________________________________________
* This method will add a new sheep object into a node and will add that node
* to a doubly link list (either to the front or the back), depending on if
* there is an empty list or not. Finally, it will delete the extra node
* and increment the sheep counter.
* Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*  newSheep : a new sheep object
* POST-CONDITIONS
*  Will add a new sheep to a link list
**************************************************************************/
void FarmList::AddSheep(Sheep newSheep) // PROC - a new sheep object
{
	AnimalNode *sheepPtr;   // IN&PROC - Pointer holding node info
	AnimalNode *searchPtrF; // PROC	   - points to current node in the link list

	//ASSIGN - create an empty list and a new node and point the prev & next
	//		   to null
	sheepPtr = new AnimalNode;
	sheepPtr -> newSheep = newSheep;
	sheepPtr -> prev = NULL;
	sheepPtr -> next = NULL;

	// PROC - accounts for whether to assign the node to an empty list,
	//		 or will place the node either in the front, middle, or tail.
	if(head == NULL)
	{
		// PROC - will add a node to an empty list and assign it to pointers
		head = sheepPtr;
		tail = head;
	}
	else if(sheepPtr -> newSheep.GetName() < head -> newSheep.GetName())
	{
		//Will add to the front
		sheepPtr -> next = head;
		head -> prev = sheepPtr;
		head = sheepPtr;
	}
	else
	{
		searchPtrF = head;
		// PROC - will search a link list for an instance where a node
		//		  is not pointing to NULL and the new node fits right after
		//		  the search pointer
		while(searchPtrF -> next != NULL && sheepPtr -> newSheep.GetName()
		    > searchPtrF -> next -> newSheep.GetName())
		{
			searchPtrF = searchPtrF -> next;
		}
		if(searchPtrF -> next != NULL)
		{
			// PROC - will add to the middle
			sheepPtr -> next = searchPtrF -> next;
			searchPtrF -> next -> prev = sheepPtr;
		}
		// PROC - used for when adding to both middle and tail
		sheepPtr -> prev = searchPtrF;
		searchPtrF -> next = sheepPtr;
		// PROC - will point tail to the last node in the list
		if(sheepPtr -> next == NULL)
		{
			tail = sheepPtr;
		}
	}
	//Creates a new node for a new person.
	sheepPtr = new AnimalNode;
	sheepPtr -> prev = NULL;
	sheepPtr -> next = NULL;

	//Deallocates excess memory stored for empty node
	delete sheepPtr;
	sheepPtr = NULL;
	searchPtrF = NULL;

	sheepCounter++;
}

/**************************************************************************
* Method ClearList: Class Sheep
*__________________________________________________________________________
* This method will go through the entire link list and delete every node.
* Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*  none
* POST-CONDITIONS
*  Will recreate an empty link list
**************************************************************************/
void FarmList::ClearList()
{
	AnimalNode *delPtr;   // PROC - a sheep node that has to be deleted

	delPtr = head;

	// PROC - will keep deleting nodes until head reaches NULL
	while(head != NULL)
	{
		head = head -> next;
		delete delPtr;
		delPtr = head;

		//Reassigns tail when the last node is deleted
		if(delPtr == NULL)
		{
			tail = head;
		}
	}
	delete delPtr;

	//Reinitialize the sheep counter to 0
	sheepCounter = 0;
}

/**************************************************************************
* Method GetFirstSheep: Class Sheep
*__________________________________________________________________________
* This method will find the front node of a link list.
* Returns -> a node
*__________________________________________________________________________
* PRE-CONDITIONS
*  none
* POST-CONDITIONS
*  Will return the node at the front of the list
**************************************************************************/
Sheep FarmList::GetFirstSheep() const
{
	return head -> newSheep;
}

/**************************************************************************
* Method FindSheep: Class Sheep
*__________________________________________________________________________
* This method will find the front node of a link list.
* Returns -> a node
*__________________________________________________________________________
* PRE-CONDITIONS
*  searchSheep : the name of the sheep that needs to be searched
* POST-CONDITIONS
*  Will return the node that has the sheep that was searched for
**************************************************************************/
Sheep FarmList::FindSheep(string searchSheep) const
{
	bool 	    found;	    // PROC - condition of whether a sheep was found
	AnimalNode *srchPtr;    // PROC - a node that contains info for a sheep
	Sheep       foundSheep; // PROC - a sheep that was found in the list

	found = false;
	srchPtr = head;

	// PROC - a sequential search that searches a link list for a certain sheep
	while(!found && srchPtr != NULL)
	{
		if (srchPtr -> newSheep.GetName() == searchSheep)
		{
			found = true;
			foundSheep = srchPtr -> newSheep;
		}
		else
		{
			srchPtr = srchPtr -> next;
		}
	}

	return foundSheep;
}

/**************************************************************************
* Method FindSheep: Class Sheep
*__________________________________________________________________________
* This method will find the front node of a link list.
* Returns -> a node
*__________________________________________________________________________
* PRE-CONDITIONS
*  searchSheep : the name of the sheep that needs to be searched
* POST-CONDITIONS
*  Will return the node that has the sheep that was searched for
**************************************************************************/
int FarmList::TotalSheep() const
{
	return sheepCounter;
}

/**************************************************************************
* Method DisplaySheepTable: Class Sheep
*__________________________________________________________________________
* This method will display all of the sheep and their attributes to the
* console so long as the total number of sheep is not zero.
* Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*  none
* POST-CONDITIONS
*  Will display all the sheep
**************************************************************************/
void FarmList::DisplaySheepTable() const
{
	AnimalNode *srchPtr; // PROC&OUT - pointer that searches the list for a sheep

	// PROC - will display all the sheep so long as there are sheep to display
	if(TotalSheep() != 0)
	{
		cout << left << setw(NAME_SPACE + 1) << "NAME" << "AGE\n";
		cout << setfill('-') << setw(NAME_SPACE) << '-'   << " "
			 << setw(AGE_SPACE)  << '-' << setfill(' ') << ' ' << endl;

		srchPtr = head;

		// PROC - Will sweep the whole link list and output each sheep & info
		//		  in each node
		while(srchPtr != NULL)
		{
			cout << setw(NAME_SPACE + 2) << srchPtr -> newSheep.GetName()
				 << srchPtr -> newSheep.GetAge() << endl;

			srchPtr = srchPtr -> next;
		}

		// OUT - a certain statement based on the sheepCounter that clarifies
		//		 the # of sheep
		if(sheepCounter > 1)
		{
			cout << "\nThere are " << sheepCounter << " sheep in the list!\n";
		}
		else if (sheepCounter == 1)
		{
			cout << "\nThere is " << sheepCounter << " sheep in the list!\n";
		}
		else
		{
			cout << "\nThere are no sheep in the list!\n";
		}
	}
	else
	{
		cout << "The list is empty!\n";
	}
}

/**************************************************************************
* Method RemoveSheep: Class Sheep
*__________________________________________________________________________
* This method will take in the name of a sheep and then, first, will search
* the link list for the sheep that either exists or doesn't exist, and then,
* it will remove said sheep node from the link list.
* Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*  none
* POST-CONDITIONS
*  Will remove a node from a list
**************************************************************************/
void FarmList::RemoveSheep(string remSheep)
{
	AnimalNode *srchPtr;   // PROC - a pointer that points to sheep wanted
	bool		found;	   // PROC - whether a sheep was found or not

	found   = false;
	srchPtr = head;

	// PROC - performs a sequential search that searches for a sheep that
	//		  needs to be removed
	while(!found && srchPtr != NULL)
	{
		if (srchPtr -> newSheep.GetName() == remSheep)
		{
			found = true;
		}
		else
		{
			srchPtr = srchPtr -> next;
		}
	}
	// PROC - will remove a node from a list only if srchPtr isn't at NULL
	if(srchPtr != NULL)
	{
		if(srchPtr == head)
		{
			//Will remove from the front
			head = srchPtr -> next;
			srchPtr -> prev = NULL;
		}
		else if(srchPtr == tail)
		{
			//Will remove from the tail
			srchPtr -> prev -> next = NULL;
			tail = srchPtr -> prev;
		}
		else
		{
			//Will remove in the middle of two nodes
			srchPtr -> prev -> next = srchPtr -> next;
			srchPtr -> next -> prev = srchPtr ->prev;
		}
		delete srchPtr;
		sheepCounter--;
	}
}
