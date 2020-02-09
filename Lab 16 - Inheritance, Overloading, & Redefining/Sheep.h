/*************************************************************************
 * AUTHOR		: Kermite & Flash Gordon
 * LAB #16      : Inheritance, Overloading, Redefining
 * CLASS		: CS1B
 * SECTION		: T/TH 8am
 * DUE DATE		: 4/21/15
 *************************************************************************/
#ifndef ANIMALS_H_
#define ANIMALS_H_

#include "Animal.h"
using namespace std;

enum WoolType
{
	LONG,
	MEDIUM,
	FINE,
	CARPET
};

class Sheep: public Animal
{
public:
	/*********************************
	 ** CONSTRUCTOR & DECONSTRUCTOR **
	 *********************************/
	Sheep();				  // Default Constructor
	Sheep(string   sheepName,
		  int	   sheepAge,
		  string   sheepColor,
		  WoolType sheepWool);// Non-default Constructor
	~Sheep(); 				  // Deconstructor

	/****************
	 **  MUTATORS  **
	 ****************/
	void  SetInitialValues(string   sheepColor, // PROC - a sheep's color
						   WoolType sheepWool,  // PROC - a sheep's wool type
						   string   sheepName,  // PROC - a sheep's name
						   int      sheepAge);  // PROC - a sheep's age

	/*****************
	 **  ACCESSORS  **
	 *****************/
	void GetValues(string   &sheepName,
				   int	    &sheepAge,
				   string   &sheepColor,
				   WoolType &sheepWool) const;

	string   GetName () const;
	int	     GetAge  () const;
	string   GetColor() const;
	WoolType GetWool () const;
	void 	 Display () const;

private:
	string	 color; // PROC&OUT - the color of the sheep
	WoolType wool;  // PROC&OUT - the wool type of the sheep
};


/**************************************************************************
* Sheep Class
*  This class represents a sheep object. It manages 4 attributes: a name,
*  age, color, and wool type.
**************************************************************************/


/**********************************
 ** CONSTRUCTORS & DECONSTRUCTOR **
 **********************************/

/**************************************************************************
* Sheep ();
* 	Constructor: Initialize class attributes
* 	Parameters : none
* 	Returns	   : none
**************************************************************************/

/**************************************************************************
* Sheep ();
* 	Non-default Constructor: Initialize class attributes
* 	Parameters 			   : sheepName (string)
		  	  	  	  	     sheepAge (int)
		  	  	  	  	     sheepColor (string)
		  	  	  	  	  	 sheepWool (WoolType)
* 	Returns	   			   : none
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
* void GetValue  (string   &sheepName,
				  int	   &sheepAge,
				  string   &sheepColor,
				  WoolType &sheepWool) const;
*
* 	Accessor; This method will return the value attribute
*--------------------------------------------------------------------------
*	Parameter: sheepName (string) // PROC - a sheep's name
*			   sheepAge	 (integer)// PROC - a sheep's age
*			   sheepColor(string) // PROC - a sheep's color
*			   sheepWool(WoolType)// PROC - a sheep's wool type
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
* string GetColor () const;
*
* 	Accessor; This method will return the color attribute
*--------------------------------------------------------------------------
*	Parameter: none
*--------------------------------------------------------------------------
*	Returns: color (string)
***************************************************************************/

/**************************************************************************
WoolType GetWool () const;
*
* 	Accessor; This method will return the wool type attribute
*--------------------------------------------------------------------------
*	Parameter: none
*--------------------------------------------------------------------------
*	Returns: wool (WoolType)
***************************************************************************/

/**************************************************************************
* void Display () const;
*
* 	Accessor; This method will display the sheep contents
*--------------------------------------------------------------------------
*	Parameter: none
*--------------------------------------------------------------------------
*	Returns: none
***************************************************************************/


#endif /* ANIMALS_H_ */
