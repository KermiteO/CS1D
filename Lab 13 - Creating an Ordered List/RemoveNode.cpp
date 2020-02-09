/*************************************************************************
 * AUTHOR		    : Kermite & Blue
 * LAB #13          : Creating an Ordered List
 * CLASS			: CS 1B
 * DUE DATE		    : 03/24/15
 *************************************************************************/

#include "MyHeader.h"

/**************************************************************************
 * FUNCTION RemoveNode
 *________________________________________________________________________
 * This function will receive a doubly linked list, two variables pointing
 * to the front and the end of the list, and a string that was prompted in
 * main as input. It will then take that string name and search the link
 * list for the node in the list that contains that person and its info.
 * Then, it will remove that person's node from the link list.
 * Returns -> a new doubly linked list
 *________________________________________________________________________
 * PRE-CONDITIONS
 * 		headF   : the front of the link list/whole list
 * 		tailF   : the end of the link list/whole list
 * 		inString: an input name
 * POST-CONDITIONS
 * 		This function will search for and remove a node from a link list.
 *************************************************************************/
personRec *RemoveNode(personRec *headF,   // PROC - front of list/whole list
					  personRec *tailF,   // PROC - end of list/ whole list
					  string	 inString)// IN&PROC - a name
{
	personRec *searchPtrF;// PROC	 - points to current node in the link list
	bool	   foundNode; // PROC    - var. that tells whether a node was found

	cout << "\nSearching for " << inString << "...\n";

	//INITIALIZE - the bool variable to false and assign the pointer to the list
	foundNode = false;
	searchPtrF = headF;

	//PROC - will search the link list for the node that contains the name
	while(!foundNode && searchPtrF != NULL)
	{
		if(searchPtrF -> name == inString)
		{
			foundNode = true;
		}
		else
		{
			searchPtrF = searchPtrF -> next;
		}
	}
	//OUTPUT - will remove the node that was found if the person was found
	if(foundNode)
	{
		cout << "Removing " << inString << "!\n";
		if(searchPtrF == headF)
		{
			//Removes a node from the front
			headF = searchPtrF -> next;
			searchPtrF -> next -> prev = NULL;
		}
		else if(searchPtrF == tailF)
		{
			//Removes a node from the end
			searchPtrF -> prev -> next = NULL;
			tailF = searchPtrF -> prev;
		}
		else
		{
			//Removes a node that is the middle
			searchPtrF -> next -> prev = searchPtrF -> prev;
			searchPtrF -> prev -> next = searchPtrF -> next;
		}
		//deletes the node and sets it to NULL
		delete searchPtrF;
		searchPtrF = NULL;
	}
	else
	{
		cout << "I'm sorry, " << "\"" << inString << "\" was NOT found!\n";
	}

	return headF;
}
