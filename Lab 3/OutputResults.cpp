/**********************************************************************
 * AUTHOR		: Kermite & User
 * Lab #3		: Supplement: Coin Flip
 * CLASS		: CS1B
 * SECTION		: MW 8:00a - 11:50a
 * DUE DATE		: 2/3/15
 *********************************************************************/
#include "HeaderFile.h"
/**********************************************************************
 * FUNCTION OutputResults
 * ___________________________________________________________________
 * This function outputs the results of the game/program.
 * ___________________________________________________________________
 * PRE-CONDITIONS
 * 		sumCount: the total times the coin was flipped
 * 		averageHead: the average # of times heads was flipped
 * 		headCount: the # of times heads was flipped
 * 		averageTotal: used to call function that calc's the averageHead
 *
 * POST-CONDITIONS
 * 		This function outputs the results of the game/program
 *********************************************************************/
void OuputResults(int &sumCount,		//IN/OUT   - the sum count
				  int &averageHead,		//CALC/OUT - the average # of head
				  						//			 flips
				  int &headCount,		//IN       - the # of instances of
				  	  	  	  	  	  	//			 heads
				  int averageTotal)		//IN/CALC  - the average total
{
	cout << endl;
	cout << "It took you " << sumCount
		 << " tosses to get 3 heads in a row.\n";

	averageTotal = AvgCalc(sumCount, averageHead, headCount);

	cout << "On average you flipped heads " << averageTotal
		 << "% of the time.";
}
