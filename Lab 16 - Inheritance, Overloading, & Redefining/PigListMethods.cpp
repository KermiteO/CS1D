/*************************************************************************
 * AUTHOR		: Kermite & Flash Gordon
 * LAB #16      : Inheritance, Overloading, Redefining
 * CLASS		: CS1B
 * SECTION		: T/TH 8am
 * DUE DATE		: 4/21/15
 *************************************************************************/

#include "Header.h"
#include "PigList.h"

/**************************************************************************
* Constructor PigList
*__________________________________________________________________________
* This function is a constructor that initializes value to PigList.
* Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*  none
* POST-CONDITIONS
*  only initialize values.
**************************************************************************/
PigList::PigList()
{
	head = NULL;
	tail = NULL;
	pigCounter = 0;
};

/**************************************************************************
* Deconstructor ~PigList
*__________________________________________________________________________
* This function is a deconstructor that terminates the PigList class.
* Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*  none
* POST-CONDITIONS
*  Terminates the PigList class
**************************************************************************/
PigList::~PigList()
{
	PigNode *aPtr; // PROC - a pointer

	aPtr = head;

	while(!IsEmpty())
	{
		head = aPtr -> next;
		delete aPtr;
		aPtr = head;
	}
};


/**************************************************************************
* Method AddPig: Class PigList
*__________________________________________________________________________
* This method will add a new pig object into a node and will add that node
* to a doubly link list (either to the front or the back), depending on if
* there is an empty list or not. Finally, it will delete the extra node
* and increment the pig counter.
* Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*  newPig : a new pig object
* POST-CONDITIONS
*  Will add a new pig to a link list
**************************************************************************/
void PigList::AddPig(Pig newPig) // PROC - a new pig object
{
	PigNode *pigPtr;   // IN&PROC - Pointer holding node info
	PigNode *searchPtr;// PROC    - points to current node in the link list
	bool    found;	   // PROC    - determines a found instance

	//ASSIGN - create an empty list and a new node and point the prev & next
	//		   to null
	pigPtr = new PigNode;
	pigPtr -> newPig = newPig;
	pigPtr -> prev = NULL;
	pigPtr -> next = NULL;

	if(IsEmpty()) //if the list is empty, add to the top
	{
		head = pigPtr;
		pigPtr = NULL;
	}
	else if(head -> newPig.GetName() > pigPtr -> newPig.GetName())
	{
		//if the name needs to go first, add to the top
		pigPtr -> next = head; //points next to head
		pigPtr -> prev = NULL; //points prev to null
		head -> prev   = pigPtr;
		head = pigPtr;
		pigPtr = NULL;
	}
	else
	{
		searchPtr = head;
		found = false;

		// PROC - will keep searching the list and rearranging nodes in
		//		  alphabetical order only if !found and searchPtr isn't at NULL
		while(searchPtr->next != NULL && !found)
		{
			if(searchPtr->next->newPig.GetName() > pigPtr->newPig.GetName())
			{
				found = true;
				pigPtr -> next = searchPtr -> next;
				pigPtr -> prev = searchPtr;
				searchPtr -> next -> prev = pigPtr;
				searchPtr -> next = pigPtr;
				pigPtr = NULL;
			}
			else
			{
				searchPtr = searchPtr->next;
			}
		}

		//If the loop exits w/out adding the node
		if(!found)
		{
			pigPtr -> next = NULL;
			pigPtr -> prev = searchPtr;
			searchPtr -> next = pigPtr;
			pigPtr = NULL;
		}
	}
	pigCounter++;
}

/**************************************************************************
* Method ClearList: Class PigList
*__________________________________________________________________________
* This method will go through the entire link list and delete every node.
* Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*  none
* POST-CONDITIONS
*  Will recreate an empty link list
**************************************************************************/
void PigList::ClearList()
{
	PigNode *delPtr;   // PROC - a pig node that has to be deleted

	delPtr = head;

	// PROC - will keep deleting nodes until head reaches NULL
	while(!IsEmpty())
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

	//Reinitialize the pig counter to 0
	pigCounter = 0;
}

/**************************************************************************
* Method GetFirstPig: Class PigList
*__________________________________________________________________________
* This method will find the front node of a link list.
* Returns -> a node
*__________________________________________________________________________
* PRE-CONDITIONS
*  none
* POST-CONDITIONS
*  Will return the node at the front of the list
**************************************************************************/
Pig PigList::GetFirstPig() const
{
	return head -> newPig;
}

/**************************************************************************
* Method FindPig: Class PigList
*__________________________________________________________________________
* This method will find the front node of a link list.
* Returns -> a node
*__________________________________________________________________________
* PRE-CONDITIONS
*  searchPig : the name of the pig that needs to be searched
* POST-CONDITIONS
*  Will return the node that has the pig that was searched for
**************************************************************************/
Pig *PigList::FindPig(string searchPig) const
{
	bool 	found;	   // PROC - condition of whether a pig was found
	PigNode *srchPtr;  // PROC - a node that contains info for a pig
	Pig     *foundPig; // PROC - a pig that was found in the list

	found = false;
	srchPtr = head;
	foundPig = NULL;

	// PROC - a sequential search that searches a link list for a certain pig
	while(!found && srchPtr != NULL)
	{
		if (srchPtr -> newPig.GetName() == searchPig)
		{
			found = true;
			foundPig = &srchPtr -> newPig;
		}
		else
		{
			srchPtr = srchPtr -> next;
		}
	}

	return foundPig;
}

/**************************************************************************
* Method FindPig: Class PigList
*__________________________________________________________________________
* This method will find the front node of a link list.
* Returns -> a node
*__________________________________________________________________________
* PRE-CONDITIONS
*  searchPig : the name of the pig that needs to be searched
* POST-CONDITIONS
*  Will return the node that has the pig that was searched for
**************************************************************************/
int PigList::TotalPigs() const
{
	return pigCounter;
}

/**************************************************************************
* Method DisplayPigTable: Class PigList
*__________________________________________________________________________
* This method will display all of the pig and their attributes to the
* console so long as the total number of pig is not zero.
* Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*  none
* POST-CONDITIONS
*  Will display all the pig
**************************************************************************/
void PigList::DisplayPigTable() const
{
	PigNode *sPtr; // PROC&OUT - pointer that searches the list for a pig

	// PROC - will display all the pig so long as there are pig to display
	if(pigCounter != 0)
	{
		DisplayHeader();

		for(sPtr = head; sPtr != NULL; sPtr = sPtr -> next)
		{
			sPtr -> newPig.Display();
		}
	}
	else
	{
		cout << "The list is empty!\n";
	}
}

/**************************************************************************
* Method OutputListSize: Class PigList
*__________________________________________________________________________
* This method will display the size of the list in an output statement
* Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*  none
* POST-CONDITIONS
*  Will display the size of the list
**************************************************************************/
void PigList::OutputListSize() const
{
	if(pigCounter > 1)
	{
		cout << "\nThere are " << pigCounter << " pigs in the list!\n";
	}
	else if (pigCounter == 1)
	{
		cout << "\nThere is " << pigCounter << " pig in the list!\n";
	}
	else
	{
		cout << "\nThere are no pigs in the list!\n";
	}
}

/**************************************************************************
* Method RemovePig: Class PigList
*__________________________________________________________________________
* This method will take in the name of a pig and then, first, will search
* the link list for the pig that either exists or doesn't exist, and then,
* it will remove said pig node from the link list.
* Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*  none
* POST-CONDITIONS
*  Will remove a node from a list
**************************************************************************/
void PigList::RemovePig(string remPig)
{
	PigNode *srchPtr;   // PROC - a pointer that points to pig wanted
	bool    found;	    // PROC - whether a pig was found or not

	found   = false;
	srchPtr = head;

	// PROC - performs a sequential search that searches for a pig that
	//		  needs to be removed
	while(!found && srchPtr != NULL)
	{
		if (srchPtr -> newPig.GetName() == remPig)
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
		pigCounter--;
	}
}

/**************************************************************************
* Method AddPig: Class PigList
*__________________________________________________________________________
* This method will add a new pig object into a node and will add that node
* to a doubly link list (either to the front or the back), depending on if
* there is an empty list or not. Finally, it will delete the extra node
* and increment the pig counter.
* Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*  newPig : a new pig object
* POST-CONDITIONS
*  Will add a new pig to a link list
**************************************************************************/
void PigList::CreateListFromFile()
{
	ifstream inFile;    // PROC    - the input file variable
	Pig 	 newPig;	// PROC    - the new pig
	string   stringType;// IN&PROC - a tail type by string
	string   pigName;   // IN&PROC - a pig's name
	TailType pigTail;   // PROC    - a tail type by enum
	int 	 pigAge;	// IN&PROC - a pig's age

	inFile.open("Pigs.txt");

	while(inFile)
	{
		getline(inFile, pigName);
		inFile >> pigAge;
		inFile.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(inFile, stringType);

		//string to enum woolType
		pigTail = StringToTail(stringType);

		inFile.ignore(numeric_limits<streamsize>::max(), '\n');

		newPig.SetInitialValues(pigTail, pigName, pigAge);

		AddPig(newPig);
	}

	inFile.close();
}

/**************************************************************************
* Method DisplayHeader: Class PigList
*__________________________________________________________________________
* This method will display the header for the display methods
* Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*  none
* POST-CONDITIONS
*  Will display the header for the output table
**************************************************************************/
void PigList::DisplayHeader() const
{
	cout << left;
	cout << "\nTHE PIG(S):\n\n";
	cout << setw(11) << "NAME" << setw(5) << "AGE" << "TAILTYPE" << endl;
	cout << OutputLine('-', 9) << "  "
		 << OutputLine('-', 3) << "  "
		 << OutputLine('-', 11) << "  " << endl;
}

/**************************************************************************
* Method ChangeAge: Class PigList
*__________________________________________________________________________
* This method will change the age of one of the pig
* Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*  none
* POST-CONDITIONS
*  Will display the header for the output table
**************************************************************************/
void PigList::ChangeAge()
{
	string animalName; // IN&PROC - an animal name
	int    newAge;	   // IN&PROC - a pig's new age
	Pig  *pigToChange; // PROC	 - a pig node

	DisplayPigTable();

	cout << "\nWhich pig would you like to modify? ";
	getline(cin, animalName);

	pigToChange = FindPig(animalName);

	//Checks to see if it found a pig
	if(pigToChange != NULL)
	{
		cout << endl;
		newAge = GetAndCheckIntInp("What would you like the new age to be? ",
								   0, 9);
		cout << endl;
		pigToChange -> SetAge(newAge);

		cout << animalName << "\'s age has been changed!\n\n";
	}
	else
	{
		cout << "\nSorry, there were no pigs found with that name.\n\n";
	}
}

/**************************************************************************
* Method IsEmtpy: Class PigList
*__________________________________________________________________________
* This method will return a bool determining if the list is empty
* Returns -> a bool determining if the list is empty
*__________________________________________________________________________
* PRE-CONDITIONS
*  none
* POST-CONDITIONS
*  Will return a bool determining if the list is empty
**************************************************************************/
bool PigList::IsEmpty() const
{
	return head == NULL;
}
