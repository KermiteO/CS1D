/*************************************************************************
 * AUTHOR		: Kermite & Flash Gordon
 * LAB #16      : Inheritance, Overloading, Redefining
 * CLASS		: CS1B
 * SECTION		: T/TH 8am
 * DUE DATE		: 4/21/15
 *************************************************************************/

#include "Sheep.h"
#include "Header.h"

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
	wool = LONG;
};

/**************************************************************************
* Non-Default Constructor Sheep
*__________________________________________________________________________
* This function is a non default constructor that initializes all the
* attributes in sheep.
* Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*  none
* POST-CONDITIONS
*  only initialize values.
**************************************************************************/
Sheep::Sheep(string   sheepName,
			 int	  sheepAge,
			 string   sheepColor,
			 WoolType sheepWool)
		     : Animal(sheepName, sheepAge)
{
	color = sheepColor;
	wool  = sheepWool;

	Animal::SetInitialValues(sheepName, sheepAge);

}

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
*  sheepColor: the wool color of a sheep
*  sheepWool : the wool type of a sheep
*  sheepName : the name of a sheep
*  sheepAge	 : the age of a sheep
* POST-CONDITIONS
*  Will assign the name and age of a sheep object.
**************************************************************************/
void Sheep::SetInitialValues(string   sheepColor,// PROC - a sheep's color
						     WoolType sheepWool, // PROC - a sheep's wool
						     string   sheepName, // PROC - a sheep's name
						     int      sheepAge)  // PROC - a sheep's age
{
	color = sheepColor;
	wool  = sheepWool;

	Animal::SetInitialValues(sheepName, sheepAge);
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
void Sheep::GetValues(string   &sheepName,
		   	   	   	  int	   &sheepAge,
		   	   	   	  string   &sheepColor,
		   	   	   	  WoolType &sheepWool) const
{
	sheepName = GetName();
	sheepAge  = GetAge();
	sheepColor= color;
	sheepWool = wool;
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
	return Animal::GetName();
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
	return Animal::GetAge();
}

/**************************************************************************
* Method GetColor: Class Sheep
*__________________________________________________________________________
* This method gets the wool color of an animal. Returns -> the animal's
* wool color
*__________________________________________________________________________
* PRE-CONDITIONS
*  none
* POST-CONDITIONS
*  returns the wool color of the animal
**************************************************************************/
string Sheep::GetColor() const
{
	return color;
}

/**************************************************************************
* Method GetWool: Class Sheep
*__________________________________________________________________________
* This method gets the wool type of an animal. Returns -> the animal's
* wool type
*__________________________________________________________________________
* PRE-CONDITIONS
*  none
* POST-CONDITIONS
*  returns the wool type of the animal
**************************************************************************/
WoolType Sheep::GetWool() const
{
	return wool;
}

/**************************************************************************
* Method Display: Class Sheep
*__________________________________________________________________________
* This method will output the attributes of the sheep. Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*  none
* POST-CONDITIONS
*  returns nothing
**************************************************************************/
void Sheep::Display() const
{
	cout << left;
	cout << setw(12) << Animal::GetName() << setw(4) << Animal::GetAge()
		 << setw(10) << WoolToString(wool) << color << endl;
	cout << right;
}
