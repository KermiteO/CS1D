/**********************************************************************
 * AUTHOR		: Kermite & User
 * Lab #3		: Supplement: Coin Flip
 * CLASS		: CS1B
 * SECTION		: MW 8:00a - 11:50a
 * DUE DATE		: 2/3/15
 *********************************************************************/
#include "HeaderFile.h"
/**********************************************************************
 * FUNCTION AverageCalc
 * ___________________________________________________________________
 * This function calculates the average time the coin flipped heads.
 * ___________________________________________________________________
 * PRE-CONDITIONS
 * 		sumCount   : the total times the coin was flipped
 * 		averageHead: the average # of times heads was flipped
 * 		headCount  : the # of times heads was flipped
 *
 * POST-CONDITIONS
 * 		This function calculates and returns the average # of times
 * 		heads was flipped
 *********************************************************************/
int AvgCalc(int &sumCount,			//IN	   - sum # of coin flips
			float averageHead,		//CALC/OUT - average % of heads
			int &headCount)			//IN	   - sum # of head coin flips
{
	averageHead = (headCount/float(sumCount)) * 100;
	return averageHead;
}
