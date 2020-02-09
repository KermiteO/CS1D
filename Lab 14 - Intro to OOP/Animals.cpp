/*************************************************************************
 * AUTHOR		: Kermite & ChickenLips
 * LAB #14      : Intro to OOP
 * CLASS		: CS1B
 * SECTION		: T/TH 8am
 * DUE DATE		: 3/19/15
 *************************************************************************/

#include "header.h"
#include "Animals.h"

/**************************************************************************
* Constructor Animals
*__________________________________________________________________________
* This function is a constructor that initializes value to animals.
* Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*  none
* POST-CONDITIONS
*  only initialize values.
**************************************************************************/
Animals::Animals()
{
	age   = 0;
	value = 0.0;
	name  = " ";
	type  = " ";
};

/**************************************************************************
* Deconstructor ~Animals
*__________________________________________________________________________
* This function is a deconstructor that terminates the Animals class.
* Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*  none
* POST-CONDITIONS
*  Terminates the Animals class
**************************************************************************/
Animals::~Animals() {};

/**************************************************************************
* Method SetAge: Class Animals
*__________________________________________________________________________
* This method sets age to what user inputs. Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*  animalAge : the age of a specific animal found within the class Animals
* POST-CONDITIONS
*  Will set the age of an animal
**************************************************************************/
void Animals::SetAge(int animalAge) // IN&PROC - the age of an animal
{
	age = animalAge;
}

/**************************************************************************
* Method SetValue: Class Animals
*__________________________________________________________________________
* This method sets value to what user inputs. Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*  animalValue : the value of a specific animal found within the class Animals
* POST-CONDITIONS
*  Will set the value of an animal
**************************************************************************/
void Animals::SetValue(float animalValue) // IN&PROC - the value of an animal
{
	value = animalValue;
}

/**************************************************************************
* Method SetName: Class Animals
*__________________________________________________________________________
* This method sets the name of an animal to what user inputs. Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*  animalName : the name of a specific animal found within the class Animals
* POST-CONDITIONS
*  Will set the name of an animal
**************************************************************************/
void Animals::SetName(string animalName) // IN&PROC - the name of an animal
{
	name = animalName;
}

/**************************************************************************
* Method SetType: Class Animals
*__________________________________________________________________________
* This method sets the type to what user inputs. Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*  animalType : the type of a specific animal found within the class Animals
* POST-CONDITIONS
*  Will set the type of an animal
**************************************************************************/
void Animals::SetType(string animalType) // IN&PROC - the type of an animal
{
	type = animalType;
}

/**************************************************************************
* Method GetAge: Class Animals
*__________________________________________________________________________
* This method gets the age of an animal. Returns -> the animal's age
*__________________________________________________________________________
* PRE-CONDITIONS
*  none
* POST-CONDITIONS
*  returns the age of the animal
**************************************************************************/
int Animals::GetAge() const
{
	return age;
}

/**************************************************************************
* Method GetName: Class Animals
*__________________________________________________________________________
* This method gets the name of an animal. Returns -> the animal's name
*__________________________________________________________________________
* PRE-CONDITIONS
*  none
* POST-CONDITIONS
*  returns the name of the animal
**************************************************************************/
string Animals::GetName() const
{
	return name;
}

/**************************************************************************
* Method GetType: Class Animals
*__________________________________________________________________________
* This method gets the type of an animal. Returns -> the animal's type
*__________________________________________________________________________
* PRE-CONDITIONS
*  none
* POST-CONDITIONS
*  returns the type of the animal
**************************************************************************/
string Animals::GetType() const
{
	return type;
}

/**************************************************************************
* Method GetValue: Class Animals
*__________________________________________________________________________
* This method gets the value of an animal. Returns -> the animal's value
*__________________________________________________________________________
* PRE-CONDITIONS
*  none
* POST-CONDITIONS
*  returns the value of the animal
**************************************************************************/
float Animals::GetValue() const
{
	return value;
}

