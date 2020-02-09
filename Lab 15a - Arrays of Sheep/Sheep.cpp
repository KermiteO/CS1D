/*************************************************************************
 * AUTHOR		: Kermite & Clover
 * LAB #15      : Arrays & Linked Lists for FarmList
 * CLASS		: CS1B
 * SECTION		: T/TH 8am
 * DUE DATE		: 4/9/15
 *************************************************************************/

#include "header.h"
#include "Sheep.h"

/**************************************************************************
* Constructor Sheep
*__________________________________________________________________________
* This function is a constructor that initializes value to Sheep.
* Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*  none
* POST-CONDITIONS
*  only initialize values.
**************************************************************************/
Sheep::Sheep()
{
	age   = 0;
	name  = " ";
};

/**************************************************************************
* Deconstructor ~Sheep
*__________________________________________________________________________
* This function is a deconstructor that terminates the Sheep class.
* Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*  none
* POST-CONDITIONS
*  Terminates the Sheep class
**************************************************************************/
Sheep::~Sheep() {};

/**************************************************************************
* Method SetInitialValues: Class Sheep
*__________________________________________________________________________
* This method will receive a sheep's name and age from main and assign
* them to the name and age of a sheep object accordingly. Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*  sheepName : the name of a sheep
*  sheepAge	 : the age of a sheep
* POST-CONDITIONS
*  Will assign the name and age of a sheep object.
**************************************************************************/
void Sheep::SetInitalValues(string sheepName, // PROC - a sheep's name
		  	  	  	        int    sheepAge)  // PROC - a sheep's age
{
	name = sheepName;
	age  = sheepAge;
}

/**************************************************************************
* Method GetValues: Class Sheep
*__________________________________________________________________________
* This method gets the value of an animal. Returns -> the animal's value
*__________________________________________________________________________
* PRE-CONDITIONS
*  none
* POST-CONDITIONS
*  returns the value of the animal
**************************************************************************/
void Sheep::GetValues(string &sheepName,
		   	   	   	  int	 &sheepAge) const
{
	sheepName = name;
	sheepAge  = age;
}


/**************************************************************************
* Method GetName: Class Sheep
*__________________________________________________________________________
* This method gets the name of an animal. Returns -> the animal's name
*__________________________________________________________________________
* PRE-CONDITIONS
*  none
* POST-CONDITIONS
*  returns the name of the animal
**************************************************************************/
string Sheep::GetName() const
{
	return name;
}

/**************************************************************************
* Method GetAge: Class Sheep
*__________________________________________________________________________
* This method gets the age of an animal. Returns -> the animal's age
*__________________________________________________________________________
* PRE-CONDITIONS
*  none
* POST-CONDITIONS
*  returns the age of the animal
**************************************************************************/
int Sheep::GetAge() const
{
	return age;
}



