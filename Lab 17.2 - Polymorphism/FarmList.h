/**************************************************************************
 * AUTHOR		: Kermite & Fireduck
 * LAB #17		: Polymorphism
 * CLASS		: CS1B
 * SECTION		: TTh 0800
 * DUE DATE		: 22APR2015
 *************************************************************************/

#ifndef FARMLIST_H_
#define FARMLIST_H_

#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>
#include "Animal.h"
using namespace std;

class FarmList
{
public:
	/*******************************
	 ** CONSTRUCTOR & DESTRUCTORS **
	 *******************************/
	FarmList();

	~FarmList();

	/***************
	 ** MUTATORS  **
	 ***************/
	void AddAnimal(Animal *&newAnimal);

	bool RemoveAnimal(string searchAnimal);

	void ClearList();

	/***************
	 ** ACCESSORS **
	 ***************/
	void OutputHead()const;

	void ListSize()const;

	void DisplayTable()const;

	bool IsEmpty()const;

	void OutputInfo(string animalName) const;


private:

	struct AnimalNode
	{
		AnimalNode *prev;
		Animal     *myAnimal;
		AnimalNode *next;
	};

	AnimalNode *head;
	int animalCounter;
};

/***********************************************************************
 * FarmList Class : public Animal
 *   This class represents a FarmList object derived from an animal
 *   	It manages an node
 ***********************************************************************/

/*******************************
 ** CONSTRUCTOR & DESTRUCTORS **
 *******************************/

/***********************************************************************
 ** FarmList();
 **   Constructor; Initializes class attributes
 **   Parameter: None
 **   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 ** ~FarmList();
 **   Destructor; Does not perform any specific function except deleting
 **     all the nodes in the link list
 **   Parameter: None
 **   Returns: Nothing
 ***********************************************************************/

/**************
 ** MUTATORS **
 **************/

/***********************************************************************
 ** AddAnimal
 **
 **   Mutator; Adds an animal to the list of animal
 **---------------------------------------------------------------------
 **   Parameter: newName (string)
 **---------------------------------------------------------------------
 **   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 ** RemoveAnimal
 **
 **   Mutator; Removes an animal to the list of animals
 **---------------------------------------------------------------------
 **   Parameter: searchAnimal (string)
 **---------------------------------------------------------------------
 **   Returns: a boolean
 ***********************************************************************/

/***********************************************************************
 ** ClearList
 **
 **   Accessor; This will loop through the list and delete every node
 **     until it's empty.
 **---------------------------------------------------------------------
 **   Parameter: none
 **---------------------------------------------------------------------
 **   Returns: none
 ***********************************************************************/

/***************
 ** ACCESSORS **
 ***************/

/***********************************************************************
 ** OutputHead
 **
 **   Accessor; This method will output the info of the animal who
 *		currently resides at the front of the list.
 **---------------------------------------------------------------------
 **   Parameter: none
 **---------------------------------------------------------------------
 **   Returns: none
 ***********************************************************************/

/***********************************************************************
 ** ListSize
 **
 **   Accessor; This method will output a statement that tells how many
 *		total number of animals are in the list.
 **---------------------------------------------------------------------
 **   Parameter: none
 **---------------------------------------------------------------------
 **   Returns: none
 ***********************************************************************/

/***********************************************************************
 ** DisplayTable
 **
 **   Accessor; This method will display all of the animals and their
 *		corresponding info in table format. Returns -> nothing.
 **---------------------------------------------------------------------
 **   Parameter: none
 **---------------------------------------------------------------------
 **   Returns: none
 ***********************************************************************/

/***********************************************************************
 ** IsEmpty
 **
 **   Accessor; Checks to see if the link list is empty. It returns a
 *   	 boolean condition
 **---------------------------------------------------------------------
 **   Parameter: none
 **---------------------------------------------------------------------
 **   Returns: a boolean condition that head == NULL
 ***********************************************************************/

/***********************************************************************
 ** OutputInfo
 **
 **   Accessor; This method gets and processes three lines of text used
 *		for the personal info for an animal and outputs those three lines
 *		as one string.
 **---------------------------------------------------------------------
 **   Parameter: none
 **---------------------------------------------------------------------
 **   Returns: none
 ***********************************************************************/


#endif /* FARMLIST_H_ */
