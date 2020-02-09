/*************************************************************************
 * AUTHOR		: Kermite & ChickenLips
 * LAB #14      : Intro to OOP
 * CLASS		: CS1B
 * SECTION		: T/TH 8am
 * DUE DATE		: 3/19/15
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

class Animals
{
	public:
	/*********************************
	 ** CONSTRUCTOR & DECONSTRUCTOR **
	 *********************************/

	Animals();		// Constructor
	~Animals(); 	// Deconstructor

	/****************
	 **  MUTATORS  **
	 ****************/
	void SetAge(int age);
	void SetValue(float value);
	void SetName(string name);
	void SetType(string type);

	/*****************
	 **  ACCESSORS  **
	 *****************/
	int GetAge() const;
	float GetValue() const;
	string GetName() const;
	string GetType() const;

	private:
	int      age;	// IN&PROC - the animal age
	float    value; // IN&PROC - the value of an animal
	string   type;  // IN&OUT  - the animal type
	string   name;  // IN&OUT  - the name of an animal
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
* void SetAge (int age);
*
* 	Mutator; This method will update the age attribute to the parameter
* 			  age value
*--------------------------------------------------------------------------
*	Parameter: age (integer) // IN - the age for the new attribute
*--------------------------------------------------------------------------
*	Returns: none
***************************************************************************/

/**************************************************************************
* void SetValue (float value);
*
* 	Mutator; This method will update the value attribute to the parameter
* 			  (value) value
*--------------------------------------------------------------------------
*	Parameter: value (float) // IN - the value for the new attribute
*--------------------------------------------------------------------------
*	Returns: none
***************************************************************************/

/**************************************************************************
* void SetName (string name);
*
* 	Mutator; This method will update the name attribute to the parameter
* 			  name string
*--------------------------------------------------------------------------
*	Parameter: name (string) // IN - the name for the new attribute
*--------------------------------------------------------------------------
*	Returns: none
***************************************************************************/

/**************************************************************************
* void SetType (string type);
*
* 	Mutator; This method will update the type attribute to the parameter
* 			  type value
*--------------------------------------------------------------------------
*	Parameter: type (string) // IN - the type for the new attribute
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

/**************************************************************************
* string GetType () const;
*
* 	Accessor; This method will return the type attribute
*--------------------------------------------------------------------------
*	Parameter: none
*--------------------------------------------------------------------------
*	Returns: type (string)
***************************************************************************/

#endif /* ANIMALS_H_ */
