/**************************************************************************
 * AUTHOR		: Kermite & Fireduck
 * LAB #17		: Polymorphism
 * CLASS		: CS1B
 * SECTION		: TTh 0800
 * DUE DATE		: 22APR2015
 *************************************************************************/

#include "Sheep.h"

/**************************************************************************
 * Method GetWoolType : Class Sheep
 *_________________________________________________________________________
 *	This method returns the wool type of a sheep
 *_________________________________________________________________________
 * PRE-CONDITIONS
 *	none
 *
 * POST-CONDITIONS
 * 	returns the wool type of the sheep
 *************************************************************************/
WoolType Sheep :: GetWoolType()const
{
	return type;
}

/**************************************************************************
 * Method GetColor : Class Sheep
 *_________________________________________________________________________
 *	This method gets and returns the color of the sheep
 *_________________________________________________________________________
 * PRE-CONDITIONS
 *	none
 *
 * POST-CONDITIONS
 * 	Returns the Sheeps color
 *************************************************************************/
string   Sheep :: GetColor()const
{
	string thisSheepColor;

	if(color == BLACK)
	{
		thisSheepColor = "Black";
	}
	else
	{
		thisSheepColor = "White";
	}

	return thisSheepColor;
}


/**************************************************************************
 * Method DisplayTable : Class Sheep
 *_________________________________________________________________________
 *	This method calls the Animal Class DisplayTable then adds the
 *	information for the Sheep WoolType and Color to the data list
 *_________________________________________________________________________
 * PRE-CONDITIONS
 *	none
 *
 * POST-CONDITIONS
 * 	returns a string with all the Sheep's info
 *************************************************************************/
string Sheep :: DisplayTable()const
{
	ostringstream table;
	string        sheepInfo;

	table << left;
	table << Animal::DisplayTable();

	sheepInfo = TypeToString(type);

	if(color == BLACK)
	{
		sheepInfo += " Black";
	}
	else
	{
		sheepInfo += " White";
	}

    table << setw(17) << sheepInfo;
	table << right;

	return table.str();
}

/**************************************************************************
 * Method TypeToString : Class Sheep
 *_________________________________________________________________________
 *	This method takes in the sheepWool and converts it to a string
 *_________________________________________________________________________
 * PRE-CONDITIONS
 *	sheepWool : the sheeps WoolType
 *
 * POST-CONDITIONS
 * 	returns the string version of WoolType
 *************************************************************************/
string Sheep :: TypeToString(WoolType sheepWool)const
{
	string myWool;

	switch(sheepWool)
	{
	case LONG : myWool = "Long";
		break;
	case MEDIUM :   myWool = "Medium" ;
		break;
	case FINE :     myWool = "Fine" ;
		break;
	case CARPET :   myWool = "Carpet";
		break;
	}

	return myWool;
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
string Sheep :: Speak()const
{
	return "baa";
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
string Sheep :: JibberJabber()const
{
	ostringstream jabber;

	jabber << "I have " << GetColor() << " wool and it is "
		   << TypeToString(type) << '!';

	return jabber.str();
}
