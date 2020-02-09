/*************************************************************************
 * AUTHOR		: Kermite & Flash Gordon
 * LAB #16      : Inheritance, Overloading, Redefining
 * CLASS		: CS1B
 * SECTION		: T/TH 8am
 * DUE DATE		: 4/21/15
 *************************************************************************/
#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <string>
using namespace std;

class Animal
{
public:
	/*********************************
	 ** CONSTRUCTOR & DECONSTRUCTOR **
	 *********************************/
	 Animal();

	 Animal(string animalName,
	 		int	   animalAge);
	 ~Animal();

	/****************
	 **  MUTATORS  **
	 ****************/
	void SetInitialValues(string animalName,
						  int	 animalAge);
	void SetAge(int newAge);

	/*****************
	 **  ACCESSORS  **
	 *****************/
	void   GetValues(string &animalName,
					 int	&animalAge) const;

	string GetName() const;
	int	   GetAge () const;

private:
	string name; // IN&PROC - the name of an animal
	int	   age;  // IN&PROC - the age of an animal
};

/**************************************************************************
* Animal Class
*  This class represents an Animal object. It manages 2 attributes: a name
*  and age.
**************************************************************************/

/**********************************
 ** CONSTRUCTORS & DECONSTRUCTOR **
 **********************************/

/**************************************************************************
* Animal();
* 	Constructor: Initialize class attributes
* 	Parameters : none
* 	Returns	   : none
**************************************************************************/

/**************************************************************************
* Animal(string animalName,
	 	 int	animalAge);
* 	Non Default Constructor: Re-Initialize class attributes
* 	Parameters : animalName (string)
* 				 animalAge (int)
* 	Returns	   : none
**************************************************************************/

/**************************************************************************
* ~Animal();
* 	Deconstructor: This loops through and de-allocates all nodes in the list
* 	Parameters   : none
* 	Returns	     : none
**************************************************************************/


/****************
 **  MUTATORS  **
 ****************/

/**************************************************************************
* void SetInitalValues(string animalName,
					   int	  animalAge);
*
* 	Mutator; This method will assign a animal name and age to the name and
* 			 age of a animal object.
*--------------------------------------------------------------------------
*	Parameter: animalName (string) // PROC - a animal's name
*			   animalAge  (integer)// PROC - a animal's age
*--------------------------------------------------------------------------
*	Returns: none
***************************************************************************/

/**************************************************************************
* void SetAge(int newAge);
*
* 	Mutator; This method will assign new age to the age attribute for an
* 			 animal.
*--------------------------------------------------------------------------
*	Parameter: newAge (integer) // PROC - an animal's new age
*--------------------------------------------------------------------------
*	Returns: none
***************************************************************************/

/*****************
 **  ACCESSORS  **
 *****************/

/**************************************************************************
* void GetValue  (string   &animalName,
				  int	   &animalAge) const;
*
* 	Accessor; This method will return the value attribute
*--------------------------------------------------------------------------
*	Parameter: animalName (string) // PROC - a animal's name
*			   animalAge  (integer)// PROC - a animal's age
*--------------------------------------------------------------------------
*	Returns: none
***************************************************************************/

/**************************************************************************
* string GetName () const;
*
* 	Accessor; This method will return the name attribute
*--------------------------------------------------------------------------
*	Parameter: none
*--------------------------------------------------------------------------
*	Returns: name (string)
***************************************************************************/

/**************************************************************************
* int GetAge () const;
*
* 	Accessor; This method will return the age attribute
*--------------------------------------------------------------------------
*	Parameter: none
*--------------------------------------------------------------------------
*	Returns: age (integer)
***************************************************************************/
#endif /* ANIMAL_H_ */
