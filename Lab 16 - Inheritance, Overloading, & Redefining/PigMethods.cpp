/*************************************************************************
 * AUTHOR		: Kermite & Flash Gordon
 * LAB #16      : Inheritance, Overloading, Redefining
 * CLASS		: CS1B
 * SECTION		: T/TH 8am
 * DUE DATE		: 4/21/15
 *************************************************************************/

#include "Pig.h"
#include "header.h"

/**************************************************************************
* Constructor Pig
*__________________________________________________________________________
* This function is a constructor that initializes value to Pig.
* Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*  none
* POST-CONDITIONS
*  only initialize values.
**************************************************************************/
Pig::Pig()
{
	pigTail = STRAIGHT;
};

Pig::Pig(string   pigName,
		 int	  pigAge,
		 TailType newTail)
		 : Animal(pigName, pigAge)
{
	pigTail = newTail;
}

/**************************************************************************
* Deconstructor ~Pig
*__________________________________________________________________________
* This function is a deconstructor that terminates the Pig class.
* Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*  none
* POST-CONDITIONS
*  Terminates the Pig class
**************************************************************************/
Pig::~Pig() {};

/**************************************************************************
* Method SetInitialValues: Class Pig
*__________________________________________________________________________
* This method will receive a Pig's name and age from main and assign
* them to the name and age of a Pig object accordingly. Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*  PigName : the name of a Pig
*  PigAge  : the age of a Pig
* POST-CONDITIONS
*  Will assign the name and age of a Pig object.
**************************************************************************/
void Pig::SetInitialValues(TailType newTail,
						   string   pigName, // PROC - a Pig's name
						   int      pigAge)  // PROC - a Pig's age
{
	pigTail  = newTail;
	Animal::SetInitialValues(pigName, pigAge);
}

/**************************************************************************
* Method GetValues: Class Pig
*__________________________________________________________________________
* This method gets the value of an animal. Returns -> the animal's value
*__________________________________________________________________________
* PRE-CONDITIONS
*  none
* POST-CONDITIONS
*  returns the value of the animal
**************************************************************************/
void Pig::GetValues(string   &pigName,
	   	   	   	   	int	     &pigAge,
	   	   	   	   	TailType &currentTail) const
{
	pigName = GetName();
	pigAge  = GetAge();
	currentTail = pigTail;
}

/**************************************************************************
* Method GetName: Class Pig
*__________________________________________________________________________
* This method gets the name of an animal. Returns -> the animal's name
*__________________________________________________________________________
* PRE-CONDITIONS
*  none
* POST-CONDITIONS
*  returns the name of the animal
**************************************************************************/
string Pig::GetName() const
{
	return Animal::GetName();
}

/**************************************************************************
* Method GetAge: Class Pig
*__________________________________________________________________________
* This method gets the age of an animal. Returns -> the animal's age
*__________________________________________________________________________
* PRE-CONDITIONS
*  none
* POST-CONDITIONS
*  returns the age of the animal
**************************************************************************/
int Pig::GetAge() const
{
	return Animal::GetAge();
}


/**************************************************************************
* Method ChangeAge: Class Pig
*__________________________________________________________________________
* This method will change the age of one of the pig
* Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*  none
* POST-CONDITIONS
*  Will display the header for the output table
**************************************************************************/
void Pig::SetAge(int newAge)
{
	Animal::SetAge(newAge);
}

/**************************************************************************
* Method GetTailType: Class Pig
*__________________________________________________________________________
* This method gets the tail type of an animal. Returns -> the animal's tail
* type
*__________________________________________________________________________
* PRE-CONDITIONS
*  none
* POST-CONDITIONS
*  returns the tail type of the animal
**************************************************************************/
TailType Pig::GetTailType() const
{
	return pigTail;
}

/**************************************************************************
* Method Display: Class Pig
*__________________________________________________________________________
* This method will output the attributes of the pig. Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*  none
* POST-CONDITIONS
*  returns nothing
**************************************************************************/
void Pig::Display() const
{
	cout << left;
	cout << setw(12) << Animal::GetName() << setw(4) << Animal::GetAge()
		 << TailToString(pigTail) << endl;
	cout << right;
}
