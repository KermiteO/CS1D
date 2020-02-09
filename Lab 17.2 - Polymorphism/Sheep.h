/**************************************************************************
 * AUTHOR		: Kermite & Fireduck
 * LAB #17		: Polymorphism
 * CLASS		: CS1B
 * SECTION		: TTh 0800
 * DUE DATE		: 22APR2015
 *************************************************************************/

#ifndef SHEEP_H_
#define SHEEP_H_

#include "Animal.h"
#include <string>
using namespace std;

//Enum Declarations for wool and color type
enum WoolType
{
	LONG,
	MEDIUM,
	FINE,
	CARPET
};

enum ColorType
{
	BLACK,
	WHITE
};

class Sheep : public Animal
{
public:
	/*******************************
	 ** CONSTRUCTOR & DESTRUCTORS **
	 *******************************/
	Sheep();
	Sheep(string         sheepName,
		  unsigned short sheepAge,
		  WoolType       woolType,
		  ColorType      woolColor);
	virtual ~Sheep();

	/**************
	 ** MUTATORS **
	 **************/
	void SetWool(WoolType  sheepWool,
				 ColorType sheepColor);

	/***************
	 ** ACCESSORS **
	 ***************/
	WoolType GetWoolType()const;

	string GetColor()const;

	virtual string DisplayTable()const;

	virtual string Selfie()const;

	virtual	string Speak()const;

	virtual string JibberJabber()const;

private:
	WoolType	type;
	ColorType	color;

	string TypeToString(WoolType sheepWool)const;
};

/***********************************************************************
 * Sheep Class : public Animal
 *   This class represents a sheep object derived from an animal
 *   	It manages 2 attributes: WoolType and color
 ***********************************************************************/

/*******************************
 ** CONSTRUCTOR & DESTRUCTORS **
 *******************************/

/***********************************************************************
 ** Sheep();
 **   Constructor; Initializes class attributes
 **   Parameter: None
 **   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 ** Sheep();
 **   Constructor; Initializes class attributes to the specified values,
 **   	calls the animal non-default constructor
 **
 **   Parameter: animalName, animalAge, animalWool, animalColor
 **   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 ** ~Sheep();
 **   Destructor; Does not perform any specific function
 **   Parameter: None
 **   Returns: Nothing
 ***********************************************************************/

/**************
 ** MUTATORS **
 **************/

/***********************************************************************
 ** SetWool
 **
 **   Mutator; This function changes the wool type and color of the sheep
 **---------------------------------------------------------------------
 **   Parameter: sheepWool and sheepColor
 **---------------------------------------------------------------------
 **   Returns: Nothing
 ***********************************************************************/

/***************
 ** ACCESSORS **
 ***************/

/***********************************************************************
 ** GetWoolType
 **
 **   Accessor; This gets the wool type of the sheep and returns it
 **---------------------------------------------------------------------
 **   Parameter: none
 **---------------------------------------------------------------------
 **   Returns: wool type of the sheep
 ***********************************************************************/

/***********************************************************************
 ** GetColor
 **
 **   Accessor; This method returns the color of the sheep
 **---------------------------------------------------------------------
 **   Parameter: none
 **---------------------------------------------------------------------
 **   Returns: the color of the sheep as a string
 ***********************************************************************/

/***********************************************************************
 ** DisplayTable
 **
 **   Accessor; This method returns a formated line of the table
 **   	containing the name age wooltype and color of the sheep
 **---------------------------------------------------------------------
 **   Parameter: none
 **---------------------------------------------------------------------
 **   Returns: a string the name age wooltype and color
 ***********************************************************************/

/***********************************************************************
 ** Selfie
 **
 **   Accessor; This method returns the image of a pig to the calling
 **     function as a string.
 **---------------------------------------------------------------------
 **   Parameter: none
 **---------------------------------------------------------------------
 **   Returns: the image of a pig as a string
 ***********************************************************************/

/***********************************************************************
 ** Speak
 **
 **   Accessor; This method returns the sound a pig makes as a string.
 **---------------------------------------------------------------------
 **   Parameter: none
 **---------------------------------------------------------------------
 **   Returns: a string containing the sound of a pig
 ***********************************************************************/

/***********************************************************************
 ** JibberJabber
 **
 **   Accessor; This method returns a string that got converted from an
 **     ostringstream variable that specifies that the pig has a tail
 **     and a certain tail type.
 **---------------------------------------------------------------------
 **   Parameter: none
 **---------------------------------------------------------------------
 **   Returns: a string containing the tail specifications of a pig
 ***********************************************************************/

/***********************************************************************
 ** TypeToString
 **
 **   Accessor; This method converts the enumerated type wool to a string
 **   	and returns it through the return line
 **---------------------------------------------------------------------
 **   Parameter: none
 **---------------------------------------------------------------------
 **   Returns: the wool type of the sheep as a string
 ***********************************************************************/


#endif /* SHEEP_H_ */
