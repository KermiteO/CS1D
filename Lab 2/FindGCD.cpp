/***********************************************************************
 * AUTHOR		  : BEAK & Kermite
 * LAB #2 		  : Intro to Functions - GCD
 * CLASS		  : CS1B
 * SECTION		  : TTH 0800
 * DUE DATE		  : 3FEB2015
 ***********************************************************************/
#include "LAB2_HEADER.h"
/*************************************************************************
 * FindGCD
 *________________________________________________________________________
 * 		This function receives two integers and finds the Greatest Common
 * 		Divisor. The function does this using the euclidean algorithm, or
 * 		by repeatedly modding whichever number is largest by the smaller
 * 		number.
 * 		- returns integer -> Returns GCD to the calling function
 *________________________________________________________________________
 * This function receives an assignment name, type, number, and programmer
 * 		name(s) then returns the appropriate class header as a string
 * 		- returns string -> returns the class heading as a string
 *________________________________________________________________________
 * PRE-CONDITIONS
 * 		num1  : contains an integer number
 * 		num2  : contains an integer number
 *
 * POST-CONDITIONS
 * 		This function will return the GCD to the calling function
 *************************************************************************/
int FindGCD(int num1, 	//IN - integer number 1
			int num2)	//IN - integer number 2
{
	//CALC - Make sure both numbers are not zero
	while(num1 != 0 && num2 != 0)
	{
		//CALC - Find out which number is currently bigger, and use that num
		if(num1 > num2)
		{
			num1 %= num2;
		}
		else
		{
			num2 %= num1;
		}
	}//END WHILE LOOP
	return (num1 > num2? num1: num2);
}
