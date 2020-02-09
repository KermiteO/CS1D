/***********************************************************************
 * AUTHOR		: The Oz & Fireduck
 * LAB #16		: Inheritance, Overloading, & Redefining
 * CLASS		: CS1B
 * SECTION		: TTh 0800
 * DUE DATE		: 22APR2015
 ***********************************************************************/

#include "Animal.h"

/**************************************************************************
 * Method GetValues : Class Animal
 *_________________________________________________________________________
 *	This method gets and returns an animals age and name by reference
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	none
 *
 * POST-CONDITIONS
 * 	animalName    location to store the name of the animal
 *  animalAge     location to store the age of the animal
 *
 *  returns the name and age by reference
 *************************************************************************/
void Animal::GetValues(string         &animalName,
					   unsigned short &animalAge)const
{

	animalAge  = age;
	animalName = name;

}

/**************************************************************************
 * Method GetName : Class Animal
 *_________________________________________________________________________
 *	This method returns the name of the animal
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	none
 *
 * POST-CONDITIONS
 *
 * 	returns the name of an animal through the return line
 *************************************************************************/
string Animal::GetName() const
{
	return name;
}

/**************************************************************************
 * Method GetAge : Class Animal
 *_________________________________________________________________________
 *	This method returns the age of an animal
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	none
 *
 * POST-CONDITIONS
 * 	returns the age of an animal through the return line
 *************************************************************************/
unsigned short Animal::GetAge() const
{
	return age;
}


/**************************************************************************
 * Method DisplayTable : Class Animal
 *_________________________________________________________________________
 *	This Method stores the name and age into an ostringstream variable
 *	and returns it to the calling function as a string
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	none
 *
 * POST-CONDITIONS
 * 	returns a string containing the name and age of an animal
 *************************************************************************/
string Animal::DisplayTable()const
{
	ostringstream table;
	string 		  animalType;

	if(Speak() == "oink")
	{
		animalType = "Pig";
	}
	else
	{
		animalType = "Sheep";
	}
	table << left;
	table << setw(8) << animalType << setw(14) << name;
	table << right   << setw(3) << age << "  ";

	return table.str();
}

/**************************************************************************
 * Method Speak : Class Animal
 *_________________________________________________________________________
 *	This Method returns a string that displays the animal that's speaking
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	none
 *
 * POST-CONDITIONS
 * 	returns a string containing the speak of an animal
 *************************************************************************/
string Animal::Speak()const
{
	return "I am Speaking!";
}

/**************************************************************************
 * Method Display : Class Animal
 *_________________________________________________________________________
 *	This Method returns a string that displays the default image of an
 *	animal.
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	none
 *
 * POST-CONDITIONS
 * 	returns a default string of an animal
 *************************************************************************/
string Animal::Selfie()const
{
	return "No selfie available!";
}

/**************************************************************************
 * Method JibberJabber : Class Animal
 *_________________________________________________________________________
 *	This Method returns a string that displays the default jibber jabber of
 *	an animal.
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 	none
 *
 * POST-CONDITIONS
 * 	returns a default string of an animal
 *************************************************************************/
string Animal::JibberJabber()const
{
	ostringstream jabber;
	jabber << "I know not my details!!!";

	return jabber.str();
}

