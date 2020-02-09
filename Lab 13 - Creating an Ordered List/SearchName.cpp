/*************************************************************************
 * AUTHOR		    : Kermite & Blue
 * LAB #13          : Creating an Ordered List
 * CLASS			: CS 1B
 * DUE DATE		    : 03/24/15
 *************************************************************************/

#include "MyHeader.h"

/**************************************************************************
 * FUNCTION SearchName
 *________________________________________________________________________
 * This function will use a doubly linked list. It will prompt the user to
 * enter in a name and then search the link list for the first occurrence of
 * that name and will output info according to whether the name was found.
 * Returns -> nothing
 *________________________________________________________________________
 * PRE-CONDITIONS
 * 		headF  : a link list
 * 		getName: an input name
 * POST-CONDITIONS
 * 		This function will search a link list for a specific node
 *************************************************************************/
void SearchName(personRec *headF, // IN&PROC - ptr var. representing head
				string	   getName)   // IN&PROC - a name of a person
{
	personRec *searchPtrF;// PROC	 - points to current node in the link list
	bool	   foundNode; // PROC    - var. that tells whether a node was found
	//INITIALIZE - the bool variable to false and assign the pointer to the list
	foundNode = false;
	searchPtrF = headF;
	//PROC - will search the link list for the node that contains the name
	while(!foundNode && searchPtrF != NULL)
	{
		if(searchPtrF -> name == getName)
		{
			foundNode = true;
		}
		else
		{
			searchPtrF = searchPtrF -> next;
		}
	}
	//OUTPUT - will output the node that was found if the name was found
	if(foundNode)
	{
		cout << left << setw(9) << "\nName:" << searchPtrF -> name;
		cout << setw(9) << "\nGender:" << searchPtrF -> gender;
		cout << setw(9) << "\nAge:" << searchPtrF -> age << endl;
	}
	else
	{
		cout << "I'm sorry, " << "\"" << getName << "\" was NOT found!\n";
	}
}
