/*************************************************************************
 * AUTHOR		: Kermite & Clover
 * LAB #15      : Arrays & Linked Lists for FarmList
 * CLASS		: CS1B
 * SECTION		: T/TH 8am
 * DUE DATE		: 4/9/15
 *************************************************************************/
#ifndef ANIMALS_H_
#define ANIMALS_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <ios>
#include <sstream>
#include <cstdlib>
#include <fstream>
using namespace std;

class Sheep
{
	public:
		/*********************************
		 ** CONSTRUCTOR & DECONSTRUCTOR **
		 *********************************/
		Sheep();		// Constructor
		~Sheep(); 		// Deconstructor

		/****************
		 **  MUTATORS  **
		 ****************/
		void  SetInitalValues(string sheepName,
							  int	 sheepAge);

		/*****************
		 **  ACCESSORS  **
		 *****************/
		void   GetValues(string &sheepName,
					     int	&sheepAge) const;

		string GetName() const;
		int	   GetAge () const;

	private:
		string   name;  // IN&OUT  - the name of an animal
		int      age;	// IN&PROC - the animal age
};


/**************************************************************************
* Sheep Class
*  This class represents a sheep object. It manages 4 attributes: a name,
*  age, value, and animal type.
**************************************************************************/


/*********************************
 ** CONSTRUCTOR & DECONSTRUCTOR **
 *********************************/

/**************************************************************************
* Sheep ();
* 	Constructor: Initialize class attributes
* 	Parameters : none
* 	Returns	   : none
**************************************************************************/

/**************************************************************************
* ~Sheep();
* 	Deconstructor: This doesn't perform any specific function
* 	Parameters   : none
* 	Returns	     : none
**************************************************************************/


/****************
 **  MUTATORS  **
 ****************/

/**************************************************************************
* void SetInitalValues(string sheepName,
					   int	  sheepAge);
*
* 	Mutator; This method will assign a sheep name and age to the name and
* 			 age of a sheep object.
*--------------------------------------------------------------------------
*	Parameter: sheepName (string) // PROC - a sheep's name
*			   sheepAge	 (integer)// PROC - a sheep's age
*--------------------------------------------------------------------------
*	Returns: none
***************************************************************************/


/*****************
 **  ACCESSORS  **
 *****************/

/**************************************************************************
* int GetAge () const;
*
* 	Accessor; This method will return the age attribute
*--------------------------------------------------------------------------
*	Parameter: none
*--------------------------------------------------------------------------
*	Returns: age (integer)
***************************************************************************/

/**************************************************************************
* float GetValue () const;
*
* 	Accessor; This method will return the value attribute
*--------------------------------------------------------------------------
*	Parameter: none
*--------------------------------------------------------------------------
*	Returns: value (float)
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

#endif /* ANIMALS_H_ */
