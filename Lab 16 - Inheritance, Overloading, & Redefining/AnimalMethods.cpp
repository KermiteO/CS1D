/*************************************************************************
 * AUTHOR		: Kermite & Flash Gordon
 * LAB #16      : Inheritance, Overloading, Redefining
 * CLASS		: CS1B
 * SECTION		: T/TH 8am
 * DUE DATE		: 4/21/15
 *************************************************************************/

#include "Animal.h"
#include "header.h"

/**************************************************************************
* Constructor Animal
*__________________________________________________________________________
* This function is a constructor that initializes value to Animal.
* Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*  none
* POST-CONDITIONS
*  only initialize values.
**************************************************************************/
Animal::Animal()
{
	age = -1;
}

/**************************************************************************
* Non-Default Constructor Animal
*__________________________________________________________________________
* This function is a non default constructor that initializes an age and
* a name.
* Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*  animalName : an animal name
*  animalAge  : an animal age
* POST-CONDITIONS
*  only initialize values.
**************************************************************************/
Animal::Animal(string animalName,
			   int	  animalAge)
{
	age  = animalAge;
	name = animalName;
}


/**************************************************************************
* Deconstructor ~Animal
*__________________________________________________________________________
* This function is a deconstructor that terminates the animal class.
* Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*  none
* POST-CONDITIONS
*  Terminates the Animal class
**************************************************************************/
Animal::~Animal() {}

/**************************************************************************
* Method SetInitialValues: Class Animal
*__________________________________________________________________________
* This method will receive an animal's name and age from main and assign
* them to the name and age of an animal object accordingly. Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*  AnimalName : the name of a Animal
*  AnimalAge	 : the age of a Animal
* POST-CONDITIONS
*  Will assign the name and age of a Animal object.
**************************************************************************/
void Animal::SetInitialValues(string animalName, // PROC - an animal's name
		  	  	  	          int    animalAge)  // PROC - an animal's age
{
	name = animalName;
	age  = animalAge;
}

/**************************************************************************
* Method SetAge: Class Animal
*__________________________________________________________________________
* This method will receive an animal's age and assign it to the age
* attribute. Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*  newAge : Age of the animal
* POST-CONDITIONS
*  Will assign the age of a Animal object.
**************************************************************************/
void Animal::SetAge(int newAge)
{
	age = newAge;
}

/**************************************************************************
* Method GetValues: Class Animal
*__________________________________________________________________________
* This method gets the value of an animal. Returns -> the animal's value
*__________________________________________________________________________
* PRE-CONDITIONS
*  none
* POST-CONDITIONS
*  returns the value of the animal
**************************************************************************/
void Animal::GetValues(string &animalName,
		   	   	   	   int	  &animalAge) const
{
	animalName = name;
	animalAge  = age;
}


/**************************************************************************
* Method GetName: Class Animal
*__________________________________________________________________________
* This method gets the name of an animal. Returns -> the animal's name
*__________________________________________________________________________
* PRE-CONDITIONS
*  none
* POST-CONDITIONS
*  returns the name of the animal
**************************************************************************/
string Animal::GetName() const
{
	return name;
}

/**************************************************************************
* Method GetAge: Class Animal
*__________________________________________________________________________
* This method gets the age of an animal. Returns -> the animal's age
*__________________________________________________________________________
* PRE-CONDITIONS
*  none
* POST-CONDITIONS
*  returns the age of the animal
**************************************************************************/
int Animal::GetAge() const
{
	return age;
}



