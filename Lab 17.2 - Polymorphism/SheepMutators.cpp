/**************************************************************************
 * AUTHOR		: Kermite & Fireduck
 * LAB #17		: Polymorphism
 * CLASS		: CS1B
 * SECTION		: TTh 0800
 * DUE DATE		: 22APR2015
 *************************************************************************/

#include "Sheep.h"

/**************************************************************************
 * Method SetWool : Class Sheep
 *_________________________________________________________________________
 *	This method will take in a wool type and color for a sheep, and update
 *	the information for the sheep
 *_________________________________________________________________________
 * PRE-CONDITIONS
 *	sheepWool  : the new wool type for the Sheep
 *	sheepColor : the new color for the Sheep
 *
 * POST-CONDITIONS
 * 	updates the wool type and color for the Sheep
 *************************************************************************/
void Sheep :: SetWool(WoolType  sheepWool,
					  ColorType sheepColor)
{
	type  = sheepWool;
	color = sheepColor;
}
