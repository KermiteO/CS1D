/**************************************************************************
 * AUTHOR		: Kermite & Fireduck
 * LAB #17		: Polymorphism
 * CLASS		: CS1B
 * SECTION		: TTh 0800
 * DUE DATE		: 22APR2015
 *************************************************************************/

#ifndef PIG_H_
#define PIG_H_

#include "Animal.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

enum TailType
{
	STRAIGHT,
	CORKSCREW,
	CURL_UP,
	CURL_RIGHT,
	CURL_LEFT
};

class Pig : public Animal

{
public:

	/******************************
	 ** CONSTRUCTOR & DESTRUCTOR **
	 ******************************/

	Pig();							// Default constructor
	Pig (unsigned short animalAge,  // Non-default constructor
		 string 		animalName,
		 TailType 		animalTail);
	virtual	~Pig();					// Default destructor

	 /**************
	  ** MUTATORS **
	  **************/

	void ChangeAge(unsigned short newAge);

	void SetTail(TailType pigTail);

	/***************
	 ** ACCESSORS **
	 ***************/

	TailType GetTailType()const;

	virtual string DisplayTable()const;

	string GetName()const;

	virtual string Selfie()const;

	virtual string Speak()const;

	virtual string JibberJabber()const;

private:
	TailType tail;

	string TailToString(TailType pigTail) const;
};

/***********************************************************************
 * Pig Class : public Animal
 *   This class represents a pig object derived from an animal
 *   	It manages 1 attribute: tailType
 ***********************************************************************/

/*******************************
 ** CONSTRUCTOR & DESTRUCTORS **
 *******************************/

/***********************************************************************
 ** Pig();
 **   Constructor; Initializes class attributes
 **   Parameter: None
 **   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 ** Pig();
 **   Constructor; Initializes class attributes to the specified values,
 **   	calls the animal non-default constructor
 **
 **   Parameter: animalName, animalAge, animalTail
 **   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 ** ~Pig();
 **   Destructor; Does not perform any specific function
 **   Parameter: None
 **   Returns: Nothing
 ***********************************************************************/

/**************
 ** MUTATORS **
 **************/

/***********************************************************************
 ** ChangeAge
 **
 **   Mutator; This function changes the age of the pig by calling the
 **   	Animal :: ChangeAge method
 **---------------------------------------------------------------------
 **   Parameter: newName
 **---------------------------------------------------------------------
 **   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 ** SetTail
 **
 **   Mutator; This function changes the tail type of the pig
 **---------------------------------------------------------------------
 **   Parameter: pigTail
 **---------------------------------------------------------------------
 **   Returns: Nothing
 ***********************************************************************/

/***************
 ** ACCESSORS **
 ***************/

/***********************************************************************
 ** GetTailType
 **
 **   Accessor; This gets the tail type of the pig and returns it
 **---------------------------------------------------------------------
 **   Parameter: none
 **---------------------------------------------------------------------
 **   Returns: tail type of the pig
 ***********************************************************************/

/***********************************************************************
 ** DisplayTable
 **
 **   Accessor; This method returns a formated line of the table
 **   	containing the name age and tailType of the pig
 **---------------------------------------------------------------------
 **   Parameter: none
 **---------------------------------------------------------------------
 **   Returns: a string the name age and tailType
 ***********************************************************************/

/***********************************************************************
 ** GetName
 **
 **   Accessor; This method returns the name of the pig
 **---------------------------------------------------------------------
 **   Parameter: none
 **---------------------------------------------------------------------
 **   Returns: the name of the pig as a string
 ***********************************************************************/

/***********************************************************************
 ** Selfie
 **
 **   Accessor; This method returns the image of a pig to the calling
 **     function as a string.
 **---------------------------------------------------------------------
 **   Parameter: none
 **---------------------------------------------------------------------
 **   Returns: the image of a pig as a string
 ***********************************************************************/

/***********************************************************************
 ** Speak
 **
 **   Accessor; This method returns the sound a pig makes as a string.
 **---------------------------------------------------------------------
 **   Parameter: none
 **---------------------------------------------------------------------
 **   Returns: a string containing the sound of a pig
 ***********************************************************************/

/***********************************************************************
 ** JibberJabber
 **
 **   Accessor; This method returns a string that got converted from an
 **     ostringstream variable that specifies that the pig has a tail
 **     and a certain tail type.
 **---------------------------------------------------------------------
 **   Parameter: none
 **---------------------------------------------------------------------
 **   Returns: a string containing the tail specifications of a pig
 ***********************************************************************/

/***********************************************************************
 ** TailToString
 **
 **   Accessor; This method converts the enumerated type tail to a string
 **   	and returns it through the return line
 **---------------------------------------------------------------------
 **   Parameter: none
 **---------------------------------------------------------------------
 **   Returns: the tail type of the pig as a string
 ***********************************************************************/


#endif /* PIG_H_ */
