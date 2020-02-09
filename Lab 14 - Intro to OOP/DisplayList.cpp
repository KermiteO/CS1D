/*************************************************************************
 * AUTHOR		: Kermite & ChickenLips
 * LAB #13      : Creating an Ordered List
 * CLASS		: CS1B
 * SECTION		: T/TH 8am
 * DUE DATE		: 3/19/15
 *************************************************************************/

#include "header.h"
#include "Animals.h"

/**************************************************************************
* FUNCTION DisplayList
*__________________________________________________________________________
* This function displays all the animals and their corresponding attributes.
* Returns -> a string
*__________________________________________________________________________
* PRE-CONDITIONS
*	fluffy : represents the sheep Fluffy
*	maa	   : represents the second sheep Maa
*	babe   : represents the pig Babe
* POST-CONDITIONS
*  This function will return & output a formatted string containing all animal
*  info.
**************************************************************************/
string DisplayList(Animals &fluffy, // OUT - current info for animal fluffy
				   Animals &maa,    // OUT - current info for animal maa
				   Animals &babe)	// OUT - current info for animal fluffy
{
	ostringstream output; // PROC - represents where you want to output to

/****************************************************************************
 * OUTPUT - will output all the animals and their corresponding info and
 * 			format the information accordingly so all the data lines up
 ****************************************************************************/
	output << left;
	output << setw(GEN_COL) << "ANIMAL" << setw(NAME_COL + 2)
		   << "NAME" << setw(7) << "AGE" << "VALUE" << endl
	       << setfill('-') << setw(NUM_COL) << '-' << ' ' << setw(NAME_COL)
		   << '-' << "  " << setw(AGE_COL) << '-' << ' ' << setw(GEN_COL) << '-'
		   << ' ' << setfill(' ') << endl;

	output << setw(11) << fluffy.GetType() << setw(18) << fluffy.GetName()
		   << fluffy.GetAge() << right << setw(12) << fixed << setprecision(2)
		   << fluffy.GetValue() << endl;
	output << left << setw(11) << maa.GetType() << setw(18) << maa.GetName()
		   << maa.GetAge() << right << setw(12) << fixed << setprecision(2)
		   << maa.GetValue() << endl;
	output << left << setw(11) << babe.GetType() << setw(18) << babe.GetName()
		   << babe.GetAge() << right << setw(12) << fixed << setprecision(2)
		   << babe.GetValue() << endl << endl << endl;

	return output.str();
}
