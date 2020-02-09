/**********************************************************************
 * AUTHOR		: Kermite
 * Ass #4		: Movie List Intro to Link Lists
 * CLASS		: CS1B
 * SECTION		: TuTh 8:00a - 11:50a
 * DUE DATE		: 3/3/15
 *********************************************************************/

#include "HeaderFile.h"

/**********************************************************************
 * FUNCTION CreateLinkList
 *___________________________________________________________________
 * This function receives an input file and uses all the information
 * found in that file to create a link list of movies - returns the head
 * of the link list by value
 *___________________________________________________________________
 * PRE-CONDITIONS
 * 		getInputFile : the name of the input file specified in main
 * POST-CONDITIONS
 * 		This function will create a link list of movies that each
 * 		has its own node of specified information.
 * 		<Post-conditions are the changed outputs either passed
 * 		by value or by reference OR anything affected by the function>
 *********************************************************************/
DvdNode *CreateLinkList(string &getInputFile) // IN - the input file name
{
	ifstream infile;  // PROC - the infile variable
	DvdNode *headF;   // PROC - the variable that points to the head of
					  // 		the link list
	DvdNode *perPtrF; // PROC - the pointer variable that accounts for
					  //		each node in the link list

	//Open the input file
	infile.open(getInputFile.c_str());

	//Initialize - head to NULL and assigns a node for perPtr
	headF = NULL;
	perPtrF = new DvdNode;

	//Check - that not at end of input file and perPtr hasn't reached
	//		  NULL
	while(infile && perPtrF != NULL)
	{
		getline(infile, perPtrF -> title);
		getline(infile, perPtrF -> leadRole);
		getline(infile, perPtrF -> supRole);
		getline(infile, perPtrF -> genre);
		getline(infile, perPtrF -> altGenre);
		infile >> perPtrF -> year;
		infile >> perPtrF -> rating;
		infile.clear();
		infile.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(infile, perPtrF -> synopsis);
		infile.ignore(numeric_limits<streamsize>::max(), '\n');

		//Change - points to the next node assigned to head, assigns head
		//		   to perPtrF and assigns a new node to perPtrF
		perPtrF -> next = headF;
		headF = perPtrF;
		perPtrF = new DvdNode;
	}
	//Deallocates the extra memory space reserved for perPtrF
	delete perPtrF;
	perPtrF = NULL;

	//Close the input file
	infile.close();

	return headF;
}

