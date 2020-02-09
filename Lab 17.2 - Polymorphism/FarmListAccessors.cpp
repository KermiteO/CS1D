/**************************************************************************
 * AUTHOR		: Kermite & Fireduck
 * LAB #17		: Polymorphism
 * CLASS		: CS1B
 * SECTION		: TTh 0800
 * DUE DATE		: 22APR2015
 *************************************************************************/

#include "FarmList.h"

/*************************************************************************
 * Method IsEmpty: Class FarmList
 *------------------------------------------------------------------------
 *   Checks to see if the link list is empty. It returns a boolean
 *   condition
 *------------------------------------------------------------------------
 *  PRE-CONDITIONS:
 *    None
 *
 *  POST-CONDITIONS:
 *    The list is cleared
 *************************************************************************/
bool FarmList::IsEmpty() const
{
	return head == NULL;
}

/**************************************************************************
 * Method OutputInfo : Class FarmList
 *_________________________________________________________________________
 *	This method gets and processes three lines of text used for the personal
 *	info for an animal and outputs those three lines as one string.
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	animalName : the name of an animal
 *
 * POST-CONDITIONS
 * 	lifeStory : the personal info for an individual animal
 *
 *  returns the lifeStory as a string
 *************************************************************************/
void FarmList::OutputInfo(string animalName) const
{
	AnimalNode   *thisAnimal;
	ostringstream lifeStory;
	ostringstream storage;
	bool   		  found;
	string 		  line1;
	string 		  line2;
	string 		  line3;
	int    		  longestString;

	thisAnimal = NULL;
	found      = false;

	lifeStory << endl << animalName << " was Not found\n";

	if(!(IsEmpty()))
	{
		thisAnimal = head;

		while(thisAnimal != NULL && !found)
		{
			if(thisAnimal->myAnimal->GetName() == animalName)
			{

				found = true;
			}
			else
			{
				thisAnimal = thisAnimal->next;
			}
		}

		if(found)
		{
			lifeStory.str("");
			storage << "My name is "     << thisAnimal->myAnimal->GetName()
					<< " and I like to " << thisAnimal->myAnimal->Speak()
					<< '!';

			line1 = storage.str();

			storage.str("");

			storage << "I have been " << thisAnimal->myAnimal->Speak()
					<< "ing for "     << thisAnimal->myAnimal->GetAge()
					<< " Year(s)!";

			line2 = storage.str();

			storage.str("");

			if (head->myAnimal->GetName()
				 == thisAnimal->myAnimal->GetName()
				 && thisAnimal->next == NULL)
			{
				storage << "I am the first in line...";
			}
			else if(thisAnimal->next == NULL)
			{
				storage << "I am last in line...";
			}
			else
			{
				storage << thisAnimal->next->myAnimal->GetName()
						<< " is following me!";
			}

			line3 = storage.str();

			if(line1.length() >= line2.length()
			  && line1.length() >= line3.length())
			{
				longestString = line1.length();
			}
			else if(line2.length() >= line3.length())
			{
				longestString = line2.length();
			}
			else
			{
				longestString = line3.length();
			}

			lifeStory << left;
			lifeStory << setfill('-') << ','
					  << setw(longestString+2) << '-' << ".\n" << setfill(' ');

			lifeStory << "( " << setw(longestString) << line1 << " )\n";
			lifeStory << "( " << setw(longestString) << line2 << " )\n";
			lifeStory << "( " << setw(longestString) << line3 << " )\n";

			lifeStory << setfill('-') << '`'
					  << setw(longestString+2) << '-' << "\'\n" << setfill(' ');
			lifeStory << "   \\\\\n"
					  << "    \\\\\n";
			lifeStory << thisAnimal->myAnimal->Selfie();

			lifeStory << endl << endl << thisAnimal->myAnimal->JibberJabber()
					  << endl;
		}
	}

	cout << lifeStory.str();
}

/**************************************************************************
 * Method DisplayTable : Class FarmList
 *_________________________________________________________________________
 *	This method will display all of the animals and their corresponding info
 *	in table format. Returns -> nothing.
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	none
 *
 * POST-CONDITIONS
 * 	will display a table of animal and their info.
 *************************************************************************/
void FarmList :: DisplayTable() const
{
	ostringstream  table;
	AnimalNode    *locationPointer;

	locationPointer = NULL;

	if(!(IsEmpty()))
	{
		locationPointer = head;

		table << left;

		table << "ANIMAL  " << setw(14) << "NAME"  << "AGE  "
			  << "WOOL/TAIL TYPE  " << " FOLLOWED BY\n";

		table << "------  ------------  ---  --------------- "
			  << " -------------\n";

		while(locationPointer != NULL)
		{
			table << locationPointer-> myAnimal-> DisplayTable();

			if(locationPointer -> next != NULL)
			{
				table << locationPointer-> next->myAnimal->GetName();
			}
			else
			{
				table << "Nobody";
			}
			locationPointer = locationPointer->next;

			table << endl;
		}
		table << right;
	}
	cout << table.str();
}

/**************************************************************************
 * Method OutputHead : Class FarmList
 *_________________________________________________________________________
 *	This method will output the info of the animal who currently resides
 *	at the front of the list.
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	none
 *
 * POST-CONDITIONS
 * 	will display the animal at the front of a list.
 *************************************************************************/
void FarmList :: OutputHead()const
{
	OutputInfo(head->myAnimal->GetName());

	cout << "I am at the front of the list.\n";
}

/**************************************************************************
 * Method ListSize : Class FarmList
 *_________________________________________________________________________
 *	This method will output a statement that tells how many total number
 *	of animals are in the list.
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	none
 *
 * POST-CONDITIONS
 * 	will output a statement specifying the total # of animals in the list
 *************************************************************************/
void FarmList :: ListSize() const
{
	cout << "\nThere are " << animalCounter << " animal(s) on the Farm!\n";
}
