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
* to a link list (either to the front or the back), depending on if there
* is an empty list or not. Finally, it will increment the sheep counter.
* Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*  newSheep : a new sheep object
* POST-CONDITIONS
*  Will add a new sheep to a link list
**************************************************************************/
void FarmList::AddSheep(Sheep newSheep) // PROC - a new sheep object
{
	AnimalNode *newPtr;	 // PROC - the pointer that represents a new animal

	newPtr = new AnimalNode;
	newPtr -> newSheep = newSheep;

	// PROC - will add the new node to the list to the front or the back
	//		  depending on if there is an empty list and increment the sheepCount
	if(head == NULL)
	{
		newPtr -> next = head;
		head = newPtr;
	}
	else
	{
		newPtr -> next = NULL;
		tail   -> next = newPtr;
	}

	tail = newPtr;
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
