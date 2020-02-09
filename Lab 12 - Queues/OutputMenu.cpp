/*************************************************************************
 * AUTHOR		    : Deboogaloo & Kermite
 * LAB #11          : Implementing a Queue
 * CLASS			: CS 1B
 * DUE DATE		    : 03/10/15
 *************************************************************************/

#include "MyHeader.h"

/**************************************************************************
 * FUNCTION OutputMenu
 * _______________________________________________________________________
 * This function will only be specified to only output the menu to the user
 * so the user can select the desired command. Return -> nothing
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *		none
 * POST-CONDITIONS
 * 		This function output the menu of command choice tasks.
 *************************************************************************/
void OutputMenu()
{
	cout << left;
	cout << "1- ENQUEUE (Add a person)\n"
			"2- DEQUEUE (Remove a person)\n"
			"3- ISEMPTY (Is the queue empty?)\n"
			"4- FRONT   (Who is in front?)\n"
			"5- SIZE    (How many people are there?)\n"
			"6- Display Queue\n"
			"7- Clear the Queue\n"
			"0- Exit\n";
	cout << right;
}
