/**************************************************************************
 * AUTHOR		: Kermite & Fireduck
 * LAB #17		: Polymorphism
 * CLASS		: CS1B
 * SECTION		: TTh 0800
 * DUE DATE		: 22APR2015
 *************************************************************************/

#include "Pig.h"

/**************************************************************************
 * Method GetTailType : Class Pig
 *_________________________________________________________________________
 *	This method returns the pigs tail to the calling function
 *_________________________________________________________________________
 * PRE-CONDITIONS
 *	none
 *
 * POST-CONDITIONS
 * 	returns the pigs tail through the return line
 *************************************************************************/
TailType Pig :: GetTailType()const
{
	return tail;
}

/**************************************************************************
 * Method GetName : Class Pig
 *_________________________________________________________________________
 *	This method calls the animal class method GetName to get the name of
 *	 the pig, it then returns it through the return line
 *_________________________________________________________________________
 * PRE-CONDITIONS
 *	none
 *
 * POST-CONDITIONS
 * 	returns the Pigs name through the return line
 *************************************************************************/
string Pig :: GetName()const
{
	return Animal::GetName();
}

/**************************************************************************
 * Method DisplayTable : Class Pig
 *_________________________________________________________________________
 *	This method calls the Animal Class DisplayTable it also calls the
 *	TailToString method to convert the tail enumerated type to a string
 *	before it adds it to the string
 *_________________________________________________________________________
 * PRE-CONDITIONS
 *	none
 *
 * POST-CONDITIONS
 * 	returns the string with the pigs data as a string
 *************************************************************************/
string Pig :: DisplayTable()const
{
	ostringstream table;

	table << left;
	table << Animal::DisplayTable();
	table << setw(17) << TailToString(tail);
	table << right;

	return table.str();
}

/**************************************************************************
 * Method TailToString : Class Pig
 *_________________________________________________________________________
 *	This method converts the enumerated data type to a string
 *_________________________________________________________________________
 * PRE-CONDITIONS
 *	none
 *
 * POST-CONDITIONS
 * 	returns the string version of the pigs tail
 *************************************************************************/
string Pig :: TailToString(TailType pigTail) const
{
	string myTail;

	switch(pigTail)
	{
	case STRAIGHT : myTail = "Straight";
		break;
	case CORKSCREW : myTail = "CorkScrews" ;
		break;
	case CURL_UP :myTail =  "Curls Up" ;
		break;
	case CURL_RIGHT : myTail = "Curls Right";
		break;
	case CURL_LEFT : myTail = "Curls Left";
		break;
	}

	return myTail;
}

/**************************************************************************
 * Method Speak : Class Pig
 *_________________________________________________________________________
 *	This method returns the sound a pig makes as a string.
 *_________________________________________________________________________
 * PRE-CONDITIONS
 *	none
 *
 * POST-CONDITIONS
 * 	Returns a string containing the sound of a pig
 *************************************************************************/
string Pig :: Speak()const
{
	return "oink";
}

/**************************************************************************
 * Method JibberJabber : Class Pig
 *_________________________________________________________________________
 *	This method returns a string that got converted from an
 *  ostringstream variable that specifies that the pig has a tail
 *  and a certain tail type.
 *_________________________________________________________________________
 * PRE-CONDITIONS
 *	none
 *
 * POST-CONDITIONS
 * 	Returns a string containing the tail specifications of a pig
 *************************************************************************/
string Pig :: JibberJabber()const
{
	ostringstream jabber;

	jabber << "I have a tail that ";

	if(tail == STRAIGHT)
	{
		jabber << "goes Straight!";
	}
	else
	{
		jabber << TailToString(tail) << '!';
	}

	return jabber.str();
}
