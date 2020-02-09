/**********************************************************************
 * AUTHOR		: Kermite
 * Ass #4		: Movie List Intro to Link Lists
 * CLASS		: CS1B
 * SECTION		: TuTh 8:00a - 11:50a
 * DUE DATE		: 3/3/15
 *********************************************************************/

#include "HeaderFile.h"

/**********************************************************************
 * FUNCTION SearchNodeInstance
 *___________________________________________________________________
 * This function will search a link list for the # of times that specified
 * command choice appears for each movie in the list. Everytime a movie is
 * found, it gets outputed to the file.
 * Returns -> variables of type (ofstream, int & bool)
 *___________________________________________________________________
 * PRE-CONDITIONS
 * 		headF		  : the link list of movie
 * 		searchChoiceF : the command choice
 * 		strSrchItem	  : a search item of type string
 * 		outfileF	  : the output file
 * 		intSrchItem	  : a search item of type int
 * 		numInstancesF : a counter that counts the # of occ. of a found movie
 * 		foundF		  : represents whether a movie was found or not
 * POST-CONDITIONS
 * 		This function will output a specific # of movies and it's
 * 		corresponding info to the output file.
 *********************************************************************/
void SearchNodeInstance(DvdNode *headF,	         // IN      - original link list
						CommandMenu searchChoice,// IN&PROC - command choice
						string strSrchItem,		 // PROC	- string search item
						ofstream &outfileF,		 // PROC	- the outfile var
						int intSrchItem,		 // PROC    - int search item
						int &numInstancesF,  	 // PROC    - # of inst. of movie
						bool &foundF)			 // PROC    - a found movie
{
	//Variable declarations go here
	DvdNode *perPtrF;     // PROC   - a node
	int 	 movieCountF; // IN&PROC- the movie number
	bool	 controlBool; // PROC 	- variable that represents all conditions

	//INITIALIZE - assign the original list to pointer, movieCountF to 1,
	//			   and the control boolean variable to false
	perPtrF = headF;
	movieCountF = 1;
/****************************************************************************
 OUTPUT - search a link list of movies for any case where a dvd search choice
 	 	  matches the corresponding movie info you're searching for and will
 	 	  output the node that movie is located in to the output file
 ***************************************************************************/
	while(!foundF && perPtrF != NULL)
	{
		//PROC - will assign a boolean to corresponding command choice
		switch(searchChoice)
		{

		case TITLE: controlBool = perPtrF -> title == strSrchItem;
					  break;
		case GENRE : controlBool = perPtrF -> genre == strSrchItem
								|| perPtrF -> altGenre == strSrchItem;
					  break;
		case ACTOR : controlBool = perPtrF -> leadRole == strSrchItem
				 	 	 	 	|| perPtrF -> supRole  == strSrchItem;
					  break;
		case RATING: controlBool = perPtrF -> rating == intSrchItem;
					  break;
		case YEAR  : controlBool = perPtrF -> year == intSrchItem;
					  break;
		}
		//PROC - will output a node and increment the # of instances of a
		//		 movie occurrence based on controlBool
		if(controlBool)
		{
			//PROC - will end the loop if the dvd menu option chosen was TITLE
			if(searchChoice == TITLE)
			{
				foundF = true;
			}
			 OutputNode(perPtrF, outfileF, searchChoice, strSrchItem,
				   	   intSrchItem, movieCountF);
			 numInstancesF++;
			 movieCountF++;
		 }
		 if(perPtrF -> title != strSrchItem || controlBool)
		 {
			 perPtrF = perPtrF -> next;
		 }
	}
	//PROC - accounts for the instances of a found movie for GENRE, ACTOR,
	//	 	 RATING, and YEAR to be used back in main. This is to save on
	//		 redundancy.
	if(numInstancesF > 0)
	{
		foundF = true;
	}
}
