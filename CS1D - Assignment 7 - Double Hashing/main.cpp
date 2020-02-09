/**************************************************************
 * PROGRAMMER   : Omar Kermiche
 * ASSIGNMENT #7: Double Hashing
 * PROFESSOR    : Jerry Lebowitz
 * CLASS	    : CS1D
 **************************************************************/

#include "Header.h"
#include "Map.h"

int main()
{
	//Constant Declarations go here
	const char   PROJECT_TYPE = 'A';
	const string PROGRAMMER   = "Omar Kermiche";
	const int	 LAB_NUM      = 7;
	const string LAB_NAME     = "Double Hashing";


	//variable declarations go here
	string prompt = "* This software stores the following keys\n"
					"* and values into a data structure(s) of\n"
					"* using the double hashing algorithm. \n"
					"* Output what data structure you choose.\n"
					"* Implement the hash table with a map adt\n"
					"* that you make yourself. Print out your data \n"
					"* structure after storing all the entries.";
	Map hashTable;
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

	cout << PrintHeader(PROJECT_TYPE, PROGRAMMER, LAB_NUM, LAB_NAME, prompt);

	cout << "Adding entries to hash table using an array:";
	hashTable.Put(e1);
	hashTable.Put(e2);
	hashTable.Put(e3);
	hashTable.Put(e4);
	hashTable.Erase(41);
	hashTable.Put(e9);
	hashTable.Put(e10);
	hashTable.Put(e11);
	hashTable.Erase(58);
	hashTable.Put(e12);
	hashTable.Put(e13);
	hashTable.Put(e14);
	hashTable.Put(e15);
	hashTable.Erase(73);
	hashTable.Put(e16);
	hashTable.Put(e17);
	hashTable.Put(e18);
	hashTable.Put(e19);
	hashTable.Put(e20);
	hashTable.Put(e21);
	hashTable.Put(e22);
	hashTable.Put(e23);
	hashTable.Erase(41);
	hashTable.Put(e24);
	hashTable.Put(e25);
	hashTable.Put(e26);
	hashTable.Put(e27);
	hashTable.Put(e28);
	hashTable.Put(e29);
	hashTable.Put(e30);

	cout << "\n\n	   .\n"
		 << "           .\n"
		 << "           .\n";

	cout << "\nAll entries added to hash table!\n";

	cout << "\nAfter deleting Mission Viejo, Lake Forest, & Riverside:"
		 << "\n\n";

	hashTable.Print();

	return 0;
}


