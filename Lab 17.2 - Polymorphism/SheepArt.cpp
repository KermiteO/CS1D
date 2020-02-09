/**************************************************************************
 * AUTHOR		: Kermite & Fireduck
 * LAB #17		: Polymorphism
 * CLASS		: CS1B
 * SECTION		: TTh 0800
 * DUE DATE		: 22APR2015
 *************************************************************************/

#include "Sheep.h"

/**************************************************************************
 * Method SheepArt : Class Sheep
 *_________________________________________________________________________
 *	This method returns the selfie of a sheep to the calling function
 *_________________________________________________________________________
 * PRE-CONDITIONS
 *	none
 *
 * POST-CONDITIONS
 * 	returns the selfie through the return line
 *************************************************************************/
string Sheep :: Selfie()const
{
	ostringstream sheepSelfie;

	sheepSelfie << "      \\    __ _\n";
	sheepSelfie << "       .-:\'  `; `-._\n";
	sheepSelfie << "      (_,           )\n";
	sheepSelfie << "    ,\'o\"(            )>\n";
	sheepSelfie << "   (__,-'            )\n";
	sheepSelfie << "      (             )\n";
	sheepSelfie << "       `-\'._.--._.-\'\n";
	sheepSelfie << "          |||  |||";

	return sheepSelfie.str();
}
