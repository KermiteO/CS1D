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
	for(int index = 0; index < AR_SIZE; index++)
	{
		sheepListAr[index].SetInitalValues(" ", 0);
	}
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
FarmList::~FarmList() {};

/**************************************************************************
* Method AddSheep: Class Sheep
*__________________________________________________________________________
* This method will add a new sheep object into an element in an array
* called sheepListAr and increment the sheep counter so long as the
* value of the sheepCounter is less then the AR_SIZE.
* Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*  newSheep : a new sheep object
* POST-CONDITIONS
*  Will add a new sheep to an array
**************************************************************************/
void FarmList::AddSheep(Sheep newSheep) // PROC - a new sheep object
{
	if(sheepCounter < AR_SIZE)
	{
		sheepListAr[sheepCounter] = newSheep;
		sheepCounter++;
	}
	else
	{
		cout << "\nCound not add to class!\n";
	}
}

/**************************************************************************
* Method ClearList: Class Sheep
*__________________________________________________________________________
* This method will add a new sheep object into an element in an array
* called sheepListAr and increment the sheep counter so long as the
* value of the sheepCounter is less then the AR_SIZE.
* Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*  newSheep : a new sheep object
* POST-CONDITIONS
*  Will add a new sheep to an array
**************************************************************************/
void FarmList::ClearList()
{
	for(int index = 0; index <= sheepCounter; index++)
	{
		sheepListAr[index].SetInitalValues(" ", 0);
	}
	sheepCounter = 0;
}

Sheep FarmList::GetFirstSheep() const
{
	return sheepListAr[0];
}

Sheep FarmList::FindSheep(string searchSheep) const
{
	bool found;
	int index;

	found = false;
	index = 0;

	while(!found && index < AR_SIZE)
	{
		if (sheepListAr[index].GetName() == searchSheep)
		{
			found = true;
		}
		else
		{
			index++;
		}
	}

	return sheepListAr[index];
}

int FarmList::TotalSheep() const
{
	return sheepCounter;
}


void FarmList::DisplaySheepTable() const
{
	int index;

	if(TotalSheep() != 0)
	{
		cout << left << setw(NAME_SPACE + 1) << "NAME" << "AGE\n";
		cout << setfill('-') << setw(NAME_SPACE) << '-'   << " "
			 << setw(AGE_SPACE)  << '-' << setfill(' ') << ' ' << endl;

		for(index = 0; index < sheepCounter; index++)
		{
			cout << setw(NAME_SPACE + 2) << sheepListAr[index].GetName()
				 << sheepListAr[index].GetAge() << endl;
		}
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
