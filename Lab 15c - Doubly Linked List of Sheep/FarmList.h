/*************************************************************************
 * AUTHOR		: Kermite & Clover
 * LAB #15      : Arrays & Linked Lists for FarmList
 * CLASS		: CS1B
 * SECTION		: T/TH 8am
 * DUE DATE		: 4/9/15
 *************************************************************************/
#ifndef FARMLIST_CPP_
#define FARMLIST_CPP_

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <ios>
#include <sstream>
#include <cstdlib>
#include <fstream>
using namespace std;

// Global Constants go here
const int AR_SIZE 	 = 9;
const int NAME_SPACE = 14;
const int AGE_SPACE  = 3;

class FarmList
{
	public:
		/*********************************
		 ** CONSTRUCTOR & DECONSTRUCTOR **
		 *********************************/
		FarmList();		// Constructor
		~FarmList();	// Deconstructor

		/****************
		 **  MUTATORS  **
		 ****************/
		void AddSheep(Sheep newSheep);
		void RemoveSheep(string remSheep);
		void ClearList();

		/*****************
		 **  ACCESSORS  **
		 *****************/
		Sheep GetFirstSheep() const;
		Sheep FindSheep(string searchSheep) const;
		int	  TotalSheep() const;
		void  DisplaySheepTable() const;

	private:
		struct AnimalNode
		{
			Sheep	   newSheep;
			AnimalNode *next;
			AnimalNode *prev;
		};
		AnimalNode *head;		// PROC		- a whole link list/front of list
		AnimalNode *tail;		// PROC		- the end of a list
		int	  sheepCounter;		// PROC&OUT - represents the # of sheep
};

#endif /* FARMLIST_CPP_ */
