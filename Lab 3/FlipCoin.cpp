/**********************************************************************
 * AUTHOR		: Kermite & User
 * Lab #3		: Supplement: Coin Flip
 * CLASS		: CS1B
 * SECTION		: MW 8:00a - 11:50a
 * DUE DATE		: 2/3/15
 *********************************************************************/
#include "HeaderFile.h"
/**********************************************************************
 * FUNCTION FlipCoin
 * ___________________________________________________________________
 * This function generates the flip of a coin and displays results of the
 * coin toss.
 * ___________________________________________________________________
 * PRE-CONDITIONS
 * 		flip     : used to store a random value (t/f)
 * 		result	 : the boolean value being returned to main
 * 		headCount: the # of times heads was flipped
 * 		sumCount : the total times the coin was flipped
 *
 * POST-CONDITIONS
 * 		This function outputs the results of the coin toss and
 * 		returns a boolean value of true or false.
 *********************************************************************/

int FlipCoin(int flip,			//CALC		 - used for random number
								//			   generator
			bool result,		//OUT 		 - a bool value of true or
								//			   false
			int &headCount,		//CALC & OUT - the # of instances of heads
			int &sumCount)		//CALC & OUT - the total number of flips
{
	flip = rand()%2+1;

	switch(flip)
	{
	case 1: result = true;
			cout << "HEADS\n";
			break;
	case 2: result = false;
			cout << "TAILS\n";
			break;
	default: cout << "ERROR\n";
	}

	return result;
}
