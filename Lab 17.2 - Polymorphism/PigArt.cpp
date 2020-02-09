/**************************************************************************
 * AUTHOR		: Kermite & Fireduck
 * LAB #17		: Polymorphism
 * CLASS		: CS1B
 * SECTION		: TTh 0800
 * DUE DATE		: 22APR2015
 *************************************************************************/

#include "Pig.h"

/**************************************************************************
 * Method PigArt : Class Pig
 *_________________________________________________________________________
 *	This method returns the selfie of a pig to the calling function
 *_________________________________________________________________________
 * PRE-CONDITIONS
 *	none
 *
 * POST-CONDITIONS
 * 	returns the selfie through the return line
 *************************************************************************/
string Pig :: Selfie()const
{
	ostringstream pigSelfie;

	pigSelfie << "      \\\n";
	pigSelfie << " _   ,---\'-\'---.\n";
	pigSelfie << "(('  \\  /-~-\\  /\n";
	pigSelfie << " \\`./ )\' a a `( \\\n";
	pigSelfie << "   ( (  ,---.  ) )\n";
	pigSelfie << "    \\ `(_o_o_)\' /\n";
	pigSelfie << "     \\   `-\'   /\n";
	pigSelfie << "      | |---| |\n";
	pigSelfie << "      [_]   [_]";

	return pigSelfie.str();
}
