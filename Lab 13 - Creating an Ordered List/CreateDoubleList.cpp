/*************************************************************************
 * AUTHOR		    : Kermite & Blue
 * LAB #13          : Creating an Ordered List
 * CLASS			: CS 1B
 * DUE DATE		    : 03/24/15
 *************************************************************************/

#include "MyHeader.h"

/**************************************************************************
 * FUNCTION CreateDoubleList
 *________________________________________________________________________
 * This function will create a doubly linked list from an input file that
 * includes a list of people and each person's corresponding info.
 * Returns -> a link list
 *________________________________________________________________________
 * PRE-CONDITIONS
 *    headF : points to the front of the list and represents the list as a whole
 *    tailF : points to the end of the list and represents the whole list
 * POST-CONDITIONS
 * 	  This function will return a link list of people by means of a pointer
 * 	  headF and tailF.
 *************************************************************************/
void CreateDoubleList(personRec *&headF, // IN&PROC - the link list of persons
					  personRec *&tailF) // IN&PROC - points to last node
{
	personRec *perPtrF;   // IN&PROC - Pointer holding node info
	personRec *searchPtrF;// PROC	 - points to current node in the link list
	ifstream   infileF;   // IN&PROC - the infile variable

	//ASSIGN - create an empty list and a new node and point the prev & next
	//		   to null
	headF = NULL;
	tailF = headF;
	perPtrF = new personRec;
	perPtrF -> prev = NULL;
	perPtrF -> next = NULL;

	infileF.open("InFile.txt");
	cout << endl;
	// PROC - will keep retrieving input from a file and storing it in a node
	//		  as well as placing said node in its right place alphabetically
	//		  in the link list.
	while(infileF)
	{
		getline(infileF, perPtrF -> name);
		infileF.get(perPtrF -> gender);
		infileF >> perPtrF -> age;
		infileF.ignore(numeric_limits<streamsize>::max(), '\n');
		infileF.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Adding : " << perPtrF -> name << endl;
		// PROC - accounts for whether to assign the node to an empty list,
		//		 or will place the node either in the front, middle, or tail.
		if(IsEmpty(headF))
		{
			// PROC - will add a node to an empty list and assign it to pointers
			headF = perPtrF;
			tailF = headF;
		}
		else if(perPtrF -> name < headF -> name)
		{
			//Will add to the front
			perPtrF -> next = headF;
			headF -> prev = perPtrF;
			headF = perPtrF;
		}
		else
		{
			searchPtrF = headF;
			// PROC - will search a link list for an instance where a node
			//		  is not pointing to NULL and the new node fits right after
			//		  the search pointer
			while(searchPtrF -> next != NULL
			   && perPtrF -> name > searchPtrF -> next -> name )
			{
				searchPtrF = searchPtrF -> next;
			}
			if(searchPtrF -> next != NULL)
			{
				// PROC - will add to the middle
				perPtrF -> next = searchPtrF -> next;
				searchPtrF -> next -> prev = perPtrF;
			}
			// PROC - used for when adding to both middle and tail
			perPtrF -> prev = searchPtrF;
			searchPtrF -> next = perPtrF;
			// PROC - will point tail to the last node in the list
			if(perPtrF -> next == NULL)
			{
				tailF = perPtrF;
			}
		}
		//Creates a new node for a new person.
		perPtrF = new personRec;
		perPtrF -> prev = NULL;
		perPtrF -> next = NULL;
	}
	//Deallocates excess memory stored for empty node
	delete perPtrF;
	perPtrF = NULL;
	searchPtrF = NULL;

	//Closes the input file
	infileF.close();
}
