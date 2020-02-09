/*************************************************************************
 * AUTHOR		    : Hamodi & Kermite
 * LAB #11          : Implementing a stack
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
	cout << "1- Add a person (PUSH)\n"
			"2- Remove a person (POP)\n"
			"3- Is the stack empty? (ISEMPTY)\n"
			"4- Who is on top? (PEEK)\n"
			"5- How many people are there? (SIZE)\n"
			"6- Display Stack\n"
			"0- to Exit\n";
	cout << right;
}
