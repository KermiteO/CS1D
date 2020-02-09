/*************************************************************************
 * AUTHOR		: Kermite & Flash Gordon
 * LAB #16      : Inheritance, Overloading, Redefining
 * CLASS		: CS1B
 * SECTION		: T/TH 8am
 * DUE DATE		: 4/21/15
 *************************************************************************/
#ifndef Pig_H_
#define Pig_H_

#include "Animal.h"
using namespace std;

enum TailType
{
	STRAIGHT,
	CORKSCREW,
	CURL_UP,
	CURL_RIGHT,
	CURL_LEFT
};

class Pig: protected Animal
{
public:
	/*********************************
	 ** CONSTRUCTOR & DECONSTRUCTOR **
	 *********************************/
	Pig();				  // Default Constructor
	Pig(string   pigName,
		int	     pigAge,
		TailType newTail); // Non-default Constructor
	~Pig(); 			   // Deconstructor

	/****************
	 **  MUTATORS  **
	 ****************/
	void  SetInitialValues(TailType newTail, // PROC - the tail type
						  string   pigName,  // PROC - a Pig's name
						  int      pigAge);  // PROC - a Pig's age
	void ChangeAge(Pig *pigToChange);
	void SetAge(int newAge);

	/*****************
	 **  ACCESSORS  **
	 *****************/
	void GetValues(string   &pigName,
			   	   int	    &pigAge,
			   	   TailType &currentTail) const;

	string   GetName 	 () const;
	int	     GetAge  	 () const;
	TailType GetTailType () const;
	void 	 Display	 () const;

private:
	TailType pigTail;
};

/**************************************************************************
* Pig Class
*  This class represents a Pig object. It manages 3 attributes: a name,
*  age, and tailType.
**************************************************************************/


/**********************************
 ** CONSTRUCTORS & DECONSTRUCTOR **
 **********************************/

/**************************************************************************
* Pig ();
* 	Constructor: Initialize class attributes
* 	Parameters : none
* 	Returns	   : none
**************************************************************************/

/**************************************************************************
* Pig ();
* 	Non-default Constructor: Initialize class attributes
* 	Parameters 			   : pigName (string)
		  	  	  	  	     pigAge (int)
		  	  	  	  	     newTail (TailType)
* 	Returns	   			   : none
**************************************************************************/

/**************************************************************************
* ~Pig();
* 	Deconstructor: This doesn't perform any specific function
* 	Parameters   : none
* 	Returns	     : none
**************************************************************************/


/****************
 **  MUTATORS  **
 ****************/

/**************************************************************************
* void SetInitalValues(TailType newTail,
* 					   string PigName,
					   int	  PigAge);
*
* 	Mutator; This method will assign a Pig name, age, and tail type to the
* 			 name and age of a Pig object.
*--------------------------------------------------------------------------
*	Parameter: newTail (TailType)// PROC - a pig's tail type
*			   PigName (string)  // PROC - a Pig's name
*			   PigAge  (integer) // PROC - a Pig's age
*--------------------------------------------------------------------------
*	Returns: none
***************************************************************************/

/**************************************************************************
* void ChangeAge (Pig *pigToChange)
*
* 	Accessor; This method will change the age of a pig
*--------------------------------------------------------------------------
*	Parameter: pigToChange (Pig) // PROC - the pig who's info needs changing
*--------------------------------------------------------------------------
*	Returns: none
***************************************************************************/

/*****************
 **  ACCESSORS  **
 *****************/

/**************************************************************************
* void GetValue  (string   &pigName,
				  int	   &pigAge,
				  TailType &currentTail) const;
*
* 	Accessor; This method will return the value attribute
*--------------------------------------------------------------------------
*	Parameter: pigName (string)      // PROC - a Pig's name
*			   pigAge (integer)      // PROC - a Pig's age
*			   currentTail (TailType)// PROC - a pig's tail type
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

/**************************************************************************
* TailType GetTailType () const;
*
* 	Accessor; This method will return the name attribute
*--------------------------------------------------------------------------
*	Parameter: none
*--------------------------------------------------------------------------
*	Returns: pigTail (TailType)
***************************************************************************/

/**************************************************************************
* void Display () const;
*
* 	Accessor; This method will display the Pig contents
*--------------------------------------------------------------------------
*	Parameter: none
*--------------------------------------------------------------------------
*	Returns: none
***************************************************************************/
#endif /* Pig_H_ */
