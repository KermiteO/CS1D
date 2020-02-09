/**************************************************************
 * PROGRAMMER   : Omar Kermiche
 * ASSIGNMENT #8: Skip Lists
 * PROFESSOR    : Jerry Lebowitz
 * CLASS	    : CS1D
 **************************************************************/

#include "Header.h"
#include "Dictionary.h"

int main()
{
	//Constant Declarations go here
	const char   PROJECT_TYPE = 'A';
	const string PROGRAMMER   = "Omar Kermiche";
	const int	 LAB_NUM      = 8;
	const string LAB_NAME     = "Skip Lists";

	//Variable declarations
	string prompt = "*This program implements a dictionary using a skip list.\n"
					"*All entries are supposed to be sorted and if an entry \n"
					"*has a key that already exists in the list, that entry \n"
					"*gets replaced.";
	Entry e1 = {18, "Laguna Niguel"};
	Entry e2 = {41, "Mission Viejo"};
	Entry e3 = {22, "San Clemente"};
	Entry e4 = {44, "Irvine"};
	Entry e9 = {58, "Lake Forest"};
	Entry e10= {32 ,"San Diego"};
	Entry e11= {49 ,"Anaheim"};
	Entry e12= {31 ,"Los Angeles"};
	Entry e13= {17 ,"Orange"};
	Entry e14= {72 ,"Palms Springs"};
	Entry e15= {41 ,"Riverside"};
	Entry e16= {19 ,"Brea"};
	Entry e17= {60 ,"Santa Ana"};
	Entry e18= {35 ,"Tustin"};
	Entry e19= {103, "Oceanside"};
	Entry e20= {11 ,"La Jolla"};
	Entry e21= {18 ,"Del Mar"};
	Entry e22= {22 ,"Aliso Viejo"};
	Entry e23= {49, "Laguna Beach"};
	Entry e24= {42, "Vista"};
	Entry e25= {49 ,"San Diego"};
	Entry e26= {99 ,"San Juan"};
	Entry e27= {29 ,"Dana Point"};
	Entry e28= {88 ,"El Segundo"};
	Entry e29= {41 ,"San Clemente"};
	Entry e30= {62 ,"Laguna Hills"};
	Dictionary skipList;

	cout << PrintHeader(PROJECT_TYPE, PROGRAMMER, LAB_NUM, LAB_NAME, prompt);

	if(skipList.empty())
		cout << "The skip list is EMPTY!\n\n";
	else
		cout << "The skip list is NOT EMPTY!\n";

	    skipList.Insert(e1);
	    skipList.Insert(e2);
	    skipList.Insert(e3);
	    skipList.Insert(e4);
	    skipList.Erase(41);
	    skipList.Insert(e9);
	    skipList.Insert(e10);
	    skipList.Insert(e11);
	    skipList.Erase(58);
	    skipList.Insert(e12);
	    skipList.Insert(e13);
	    skipList.Insert(e14);
	    skipList.Insert(e15);
	    skipList.Erase(73);
	    skipList.Insert(e16);
	    skipList.Insert(e17);
	    skipList.Insert(e18);
	    skipList.Insert(e19);
	    skipList.Insert(e20);
	    skipList.Insert(e21);
	    skipList.Insert(e22);
	    skipList.Insert(e23);
	    skipList.Erase(41);
	    skipList.Insert(e24);
	    skipList.Insert(e25);
	    skipList.Insert(e26);
	    skipList.Insert(e27);
	    skipList.Insert(e28);
	    skipList.Insert(e29);
	    skipList.Insert(e30);

	    skipList.LinkNodesAbove();

	    cout << "After deleting Mission Viejo, Lake Forest, & Riverside:\n";
	    skipList.PrintHeaders();
	    skipList.PrintList();

	    cout <<"\n\n This program utilized 2 random number generators: one was\n"
	    	 << " used to decide whether to create a new level & utilized a \n"
			 << " true/false. The other was used to decide how many times the\n"
			 << " new node would be copied 2 each level & it copied a certain #"
			 << "\n of times based on a number generated between 0 & the max\n"
			 << " number of levels.";
	return 0;
}

