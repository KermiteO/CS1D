/**************************************************************************
 * AUTHOR		: Kermite & Fireduck
 * LAB #17		: Polymorphism
 * CLASS		: CS1B
 * SECTION		: TTh 0800
 * DUE DATE		: 22APR2015
 *************************************************************************/

#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>
using namespace std;

class Animal
{
public:

	/*******************************
	 ** CONSTRUCTOR & DESTRUCTORS **
	 *******************************/

	 Animal();									//default constructor
	 Animal(string         animalName,
			unsigned short animalAge);          //non-default constructor
	 virtual ~Animal();                         //destructor


	/***************
	 ** MUTATORS  **
	 ***************/

	void ChangeValues(string         newName,  //changes the animal's age
					  unsigned short newAge);

	void ChangeValues(string newName);         //changes the animal name

	void ChangeValues(unsigned short newAge);  //changes the animal age

	/****************
	 ** ACCESSORS  **
	 ****************/

	void GetValues(string 		  &animalName, //changes the animal age and name
				   unsigned short &animalAge)const;

	string GetName()const;                     //gets the animal's name

	unsigned short GetAge()const;			   //gets the animal's age

	virtual string DisplayTable()const;        //displays the table contents

	virtual string Speak()const;			   //gets a string of animal speaking

	virtual string Selfie()const;			   //gets the default image

	virtual string JibberJabber()const;		   //gets the default jibber jabber


private:

	string 		   name; //IN - animal name
	unsigned short age;  //IN - animal age
};

/***********************************************************************
 * Animal Class
 *   This class represents a animal object
 *   It manages 2 attributes: The name and age of the animal
 ***********************************************************************/

/*******************************
 ** CONSTRUCTOR & DESTRUCTORS **
 *******************************/

/***********************************************************************
 ** Animal();
 **   Default Constructor; Initializes class attributes
 **   Parameter: None
 **   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 ** Animal();
 **   Constructor; Initializes class attributes to the specified values
 **   Parameter: animalName, animalAge
 **   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 ** ~Animal();
 **   Destructor; Does not perform any specific function
 **   Parameter: None
 **   Returns: Nothing
 ***********************************************************************/

/***************
 ** MUTATORS  **
 ***************/

/***********************************************************************
 ** ChangeValues
 **
 **   Mutator; This function changes the name and age of the animal object
 **---------------------------------------------------------------------
 **   Parameter: newName and newAge
 **---------------------------------------------------------------------
 **   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 ** ChangeValues
 **
 **   Mutator; This function changes the name of the animal object
 **---------------------------------------------------------------------
 **   Parameter: newName
 **---------------------------------------------------------------------
 **   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 ** ChangeValues
 **
 **   Mutator; This function changes the age of the animal object
 **---------------------------------------------------------------------
 **   Parameter: newAge
 **---------------------------------------------------------------------
 **   Returns: Nothing
 ***********************************************************************/

/****************
 ** ACCESSORS  **
 ****************/

/***********************************************************************
 ** GetValues
 **
 **   Accessor; This gets the attributes of the animal object (name and age)
 **---------------------------------------------------------------------
 **   Parameter: animalName and animalAge
 **---------------------------------------------------------------------
 **   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 ** GetName
 **
 **   Accessor; This returns the name of the animal
 **---------------------------------------------------------------------
 **   Parameter: none
 **---------------------------------------------------------------------
 **   Returns: the name of the animal
 ***********************************************************************/

/***********************************************************************
 ** GetAge
 **
 **   Accessor; This returns the age of the animal
 **---------------------------------------------------------------------
 **   Parameter: none
 **---------------------------------------------------------------------
 **   Returns: the animals age
 ***********************************************************************/

/***********************************************************************
 ** DisplayTableHeading
 **
 **   Accessor; This method returns a formated line of the table
 **   	containing the NAME and AGE title
 **---------------------------------------------------------------------
 **   Parameter: none
 **---------------------------------------------------------------------
 **   Returns: a string containing NAME and AGE
 ***********************************************************************/

/***********************************************************************
 ** Selfie
 **
 **   Accessor; This method returns a string that represents the default
 **     image of an animal
 **
 **---------------------------------------------------------------------
 **   Parameter: none
 **---------------------------------------------------------------------
 **   Returns: a string containing "No selfie available!"
 ***********************************************************************/

/***********************************************************************
 ** JibberJabber
 **
 **   Accessor; This method returns a string that represents the default
 **     jibber jabber of an animal
 **
 **---------------------------------------------------------------------
 **   Parameter: none
 **---------------------------------------------------------------------
 **   Returns: a string containing "I know not my details!!!"
 ***********************************************************************/

#endif /* ANIMAL_H_ */
