/**************************************************************************
 * AUTHOR		: Kermite & Fireduck
 * LAB #17		: Polymorphism
 * CLASS		: CS1B
 * SECTION		: TTh 0800
 * DUE DATE		: 22APR2015
 *************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

//Preprocessor directives go here
#include <iostream>		//for cin/cout
#include <iomanip>		//for IO manipulators
#include <string>		//for strings
#include <limits>		//limits
#include <ios>			//streamsize
#include <fstream>		//for file stream
#include "InputCheck.h" //for error checking functions
#include "Sheep.h"		//sheep object
#include "Pig.h"		//pig object
#include "FarmList.h"   //animal node
#include "Animal.h"	    //animal object

using namespace std;

//User Defined Types
enum MenuOptions
{
	EXIT,
	ADD,
	REMOVE,
	OUTPUT,
	FIND,
	SIZE,
	DISPLAY,
	CLEAR
};

/*************************************************************************
 * PrintHeaderString
 *  This function receives an ostream variable, assignment name, type,
 * 	number, and programmers name. The function then returns the
 * 	appropriate header via reference through the ostream variable.
 * 	- returns nothing
 *************************************************************************/
void PrintHeaderOstream(ostream &output,	// OUT - output stream
						string  assName,	// IN - Assignment Name
						char    assType,	// IN - assignment Type
			 	 	 						//     (Lab or Assignment)
						string  assNum,		// IN - assignment number
						string  progName);	// IN - Programmers Name

/**************************************************************************
 * FUNCTION AddSheep
 *_________________________________________________________________________
 *	This function will perform certain actions that will add a sheep to the
 *	link list of farm animals and then return the new list by reference.
 *************************************************************************/
void AddSheep(FarmList &currentFarm);

/**************************************************************************
 * FUNCTION AddPig
 *_________________________________________________________________________
 *	This function will perform certain actions that will add a pig to the
 *	link list of farm animals and then return the new list by reference.
 *************************************************************************/
void AddPig(FarmList &currentFarm);


#endif /* HEADER_H_ */
