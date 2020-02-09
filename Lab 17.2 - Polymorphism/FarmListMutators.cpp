/**************************************************************************
 * AUTHOR		: Kermite & Fireduck
 * LAB #17		: Polymorphism
 * CLASS		: CS1B
 * SECTION		: TTh 0800
 * DUE DATE		: 22APR2015
 *************************************************************************/

#include "FarmList.h"

/*************************************************************************
 * Method AddAnimal: Class FarmList
 *------------------------------------------------------------------------
 *   Adds an animal to the list of animal
 *------------------------------------------------------------------------
 *  PRE-CONDITIONS:
 *    The following need previously defined values:
 *	    newAnimal:  	 new animal object to add to list
 *
 *  POST-CONDITIONS:
 *    Adds an animal to the list
 *************************************************************************/
void FarmList::AddAnimal(Animal *&newAnimal)
{
	bool    	found;		  //PROC - true if the item is found
	AnimalNode *searchPtr;	  //PROC - Pointer to move through the list
	AnimalNode *newAnimalNode;//PROC - The pointer to add to the list

	found         = false;
	searchPtr     = head;
	newAnimalNode = new AnimalNode;

	if(newAnimalNode != NULL)
	{
		//PROC - Assign the new sheep object to the sheep node pointer to add
		newAnimalNode -> myAnimal = newAnimal;
		//PROC - Case if list is empty or new node needs to be in the front
		if(IsEmpty() ||
		   head->myAnimal->GetName() > newAnimalNode->myAnimal->GetName())
		{
			newAnimalNode -> prev = NULL;
			newAnimalNode -> next = head;
			if(!IsEmpty())
			{
				head -> prev = newAnimalNode;
			}
			head = newAnimalNode;
		}
		//PROC - Find the proper location
		else
		{
			while(searchPtr->next != NULL && !found)
			{
				if(searchPtr->next->myAnimal->GetName() >
				   newAnimalNode->myAnimal->GetName())
				{
					found = true;
				}
				else
				{
					searchPtr = searchPtr->next;
				}
			}
			//PROC - Insert the new node in the found location
			newAnimalNode -> prev = searchPtr;
			newAnimalNode -> next = searchPtr -> next;
			searchPtr -> next = newAnimalNode;
			//PROC - Link in the node to the tail end of list unless at end
			if(newAnimalNode -> next != NULL)
			{
				newAnimalNode -> next -> prev = newAnimalNode;
			}
		}
		animalCounter++;
		newAnimalNode = NULL;
	}
	else
	{
		cout << "**** OUT OF MEMORY!! :\'( ****";
	}

	newAnimalNode = NULL;
}

/*************************************************************************
 * Method RemoveAnimal: Class FarmList
 *------------------------------------------------------------------------
 *   Removes an animal to the list of animals
 *------------------------------------------------------------------------
 *  PRE-CONDITIONS:
 *    The following need previously defined values:
 *	    searchAnimal:  	 new animal object to remove from list
 *
 *  POST-CONDITIONS:
 *    removes an animal from the list
 *************************************************************************/
bool FarmList::RemoveAnimal(string searchAnimal)
{
	bool        found;
	AnimalNode *currentNode;

	found       = false;
	currentNode = head;

	if(!IsEmpty())
	{
		//PROC - Find the node to delete
		while(currentNode != NULL && !found)
		{
			if(searchAnimal != currentNode -> myAnimal->GetName())
			{
				currentNode = currentNode->next;
			}
			else
			{
				found = true;
			}
		}
		if(found)
		{
			OutputInfo(searchAnimal);
			//PROC - Case if not the first in the list
			if(head != currentNode)
			{
				currentNode -> prev -> next = currentNode -> next;
				//PROC - Case if the node is not the last in the list
				if(currentNode -> next != NULL)
				{
					currentNode -> next -> prev = currentNode -> prev;
				}
			}
			//PROC - Case if the node is the first in the list
			else
			{
				if(currentNode -> next != NULL)
				{
					currentNode -> next -> prev = NULL;
				}
				head = currentNode -> next;
			}
			//PROC - Get rid of the node

			cout << "<POOF> " << searchAnimal << " is no longer "
					<< currentNode->myAnimal->Speak() << "ing on this farm!\n";

			delete currentNode;
			currentNode = NULL;
			animalCounter--;
		}
		else
		{
			cout << endl << searchAnimal << " was not found!\n";
		}
	}

	return found;
}

/*************************************************************************
 * Method ClearList: Class FarmList
 *------------------------------------------------------------------------
 *   Clears the list by re-initializing to a clear string and -1 for age
 *------------------------------------------------------------------------
 *  PRE-CONDITIONS:
 *    None
 *
 *  POST-CONDITIONS:
 *    The list is cleared
 *************************************************************************/
void FarmList::ClearList()
{
	AnimalNode *delPointer;

	delPointer = head;

	if(!(IsEmpty()))
	{
		cout << "\nClearing the Farm:\n";
		while(head != NULL)
		{
			cout << "removing " << delPointer->myAnimal->GetName() << "...\n";
			head = head->next;
			delete delPointer;
			delPointer = head;
		}
		cout << "The list has been cleared!";
		animalCounter = 0;
	}
	else
	{
		cout << "\nThe list is already Clear!";
	}

	cout << endl;
	delPointer = NULL;
}
