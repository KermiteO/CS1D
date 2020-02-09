/**********************************************************************
 * AUTHOR		: Kermite
 * Ass #4		: Movie List Intro to Link Lists
 * CLASS		: CS1B
 * SECTION		: TuTh 8:00a - 11:50a
 * DUE DATE		: 3/3/15
 *********************************************************************/

#include "HeaderFile.h"

/**********************************************************************
 * FUNCTION StringParse
 *___________________________________________________________________
 * This function will determine whether the title should be parsed or
 * not so that it fits within the column - returns nothing
 *___________________________________________________________________
 * PRE-CONDITIONS
 * 		title	 : the title of the movie
 * 		actor	 : the lead actor in a movie
 * 		supActor : the supporting actor in a movie
 * 		outfile  : the output file variable
 * POST-CONDITIONS
 * 		It will parse the title, actor, or supActor if need be.
 *********************************************************************/
void StringParse(string &title,		//PROC&OUT - the title of the movie
				 string &actor,		//PROC&OUT - the lead actor
				 string &supActor,  //PROC&OUT - the supporting actor
				 ofstream &outfile) //PROC	   - the output file variable
{
	int strLength1;	//PROC - the size of the title
	int strLength2; //PROC - the size of the actor's name
	int strLength3; //PROC - the size of the supporting actor's name

	//CALC - the string length and assign it to corresponding variable
	strLength1 = title.length();
	strLength2 = actor.length();
	strLength3 = supActor.length();

	//Outputs to a substring only if the string length exceeds the limit
	if(strLength1 > TITLE_SIZE)
	{
		title = title.substr(0, 44) + ELLIPSE;
	}
	else if(strLength2 > PROMPT_COL)
	{
		actor = actor.substr(0, 15) + ELLIPSE;
	}
	else if(strLength3 > PROMPT_COL)
	{
		supActor = supActor.substr(0, 15) + ELLIPSE;
	}
}
