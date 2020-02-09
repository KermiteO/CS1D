/*************************************************************************
 * AUTHOR		    : Kermite & Blue
 * LAB #13          : Creating an Ordered List
 * CLASS			: CS 1B
 * DUE DATE		    : 03/24/15
 *************************************************************************/

#include "MyHeader.h"

/*************************************************************************
 * Creating an Ordered List
 *_____________________________________________________________________
 * In this lab, we are going to use a doubly linked list, pointers and
 * enumerated data types in order to complete this project. The user will
 * be prompted to choose from a menu which command he/she wishes to do, then
 * once the user selects the desired option, the program will then call
 * a specific function that either: creates a doubly linked list of people
 * in alphabetical order, displays all the people in the list in alphabetical
 * or reverse alphabetical, searches for a specific person in the list,
 * removes a person from the list, clears all the nodes in the list, or
 * checks to see if the list is empty. This program will run as long as the
 * user does not enter a 0 as an input command.
 * _____________________________________________________________________
 * INPUT:
 * 	 commandInput: a command choice from the list of menu options
 * 	 getName	 : a name to search for
 * 	 remName	 : a name of a person you want to remove from the link list
 * 	 name		 : a name of a person extracted from the input file
 * 	 gender		 : a gender of a person extracted from the input file
 * 	 age		 : an age of a person extracted from the input file
 *OUTPUT:
 *	 head        : a link list of people/the front of the list
 *	 tail 	     : a link list of people starting at the end
 *	 searchPtrF  : a specific node of a person and his/her info
 ************************************************************************/

int main()
{
	/*********************************************************************
	 * CONSTANTS
	 * -------------------------------------------------------------------
	 * USED FOR OUTPUT FILE - ALL WILL BE OUTPUT
	 * -------------------------------------------------------------------
	 * PROGRAMMER : Programmer's Name
	 * CLASS      : Student's Course
	 * SECTION    : Class Days and Times
	 * LAB_NUM    : Lab/Assignment Number (specific to this lab)
	 * LAB_NAME   : Title of the Lab/Assignment
	 * ------------------------------------------------------------------
	 * USED FOR PROCESSING
	 * ------------------------------------------------------------------
	 * PROJECT_TYPE: the project type
	 * PROGRAMMER  : the name(s) of the programer(s)
	 * LAB_NUM	   : the lab number
	 * LAB_NAME	   : the lab name
	 * ******************************************************************/
	//Constant declarations go here
	const char PROJECT_TYPE = 'L';
	const string PROGRAMMER = "Kermite & Blue";
	const int  LAB_NUM      = 13;
	const string LAB_NAME   = "Creating an Ordered List";

	const int PROMPT_SIZE = 17;

	// VARIABLES DECLERATIONS:
	ListMenu  listChoice;	 // IN            - variable of enum type
	personRec *head;		 // IN & OUT      - represents the front/entire list
	personRec *tail;		 // IN & PROC     - points to last node
	int        commandInput; // IN/CALC/OUT   - used to determine the search
	int		   bound1;		 // PROC	  	  - the 1st boundary value
	int		   bound2;		 // PROC    	  - the 2nd boundary value
	string	   prompt;		 // PROC & OUT 	  - the input prompt
	string	   getName;		 // IN & PROC     - a name
	string     remName;		 // IN & PROC     - a name of a person wanted remove
	ifstream   infile;		 // PROC		  - the infile variable

	// INITIALIZATION:
	bound1 = 0;
	bound2 = 7;
	prompt = "Enter a command (0 to exit)? ";

	//Creates an empty link list
	head = NULL;
	tail = head;

	// Output the print heading to the console
	cout << left;
	cout << PrintHeader(PROJECT_TYPE, PROGRAMMER, LAB_NUM, LAB_NAME);

/*************************************************************************
 INPUT - the command choice and convert that integer into an enum
**************************************************************************/
	OutputMenu();

	commandInput = GetAndCheckIntResponse(bound1, bound2, prompt, PROMPT_SIZE);

	listChoice = ConvertIntToEnumType(commandInput);

/*************************************************************************
 PROCESSING - determines which task to implement and which
 function to execute based on the specified command. It loops so long as
 the command inputed isn't exit.
**************************************************************************/
	while(commandInput != EXIT)
	{
		switch(listChoice)
		{
			case CREATE    : CreateDoubleList(head, tail);
						      break;
			case DISPLAY   : DisplayList(head);
						      break;
			case DISPLAYREV: DisplayReverseList(tail);
							  break;
			case ISEMPTY   : IsEmpty(head);
							 //PROC - will specify if the list is empty or not
						     if(head == NULL)
						     {
						  	     cout << "\nYes, the list is empty.\n";
						     }
						     else
						     {
							     cout << "\nNo, the list is NOT empty.\n";
						     }
						      break;
			case SEARCH	   : if(!(IsEmpty(head)))
							 {
							 	 //INPUT - a name to search for
								 cout << "\nWho would you like to search for? ";
								 getline(cin, getName);
								 cout << "\nSearching for " << getName << "...\n";

								 //CALL - Function call that searches for name in list
								 SearchName(head, getName);
							 }
							 else
							 {
								 cout << "\nCan't search an empty list\n";
							 }
							  break;
			case REMOVE   : if(!(IsEmpty(head)))
							{
								cout << "\nWho would you like to remove? ";
								getline(cin, remName);

								//CALL - Function that removes name & returns new list
								head = RemoveNode(head, tail, remName);
							}
							else
							{
								cout << "\nCan't remove from an empty list!\n";
							}

							  break;
			case CLEAR	  : ClearList(head, tail);
							  break;
			default		  : break;
		}//END switch

	    //Update the LCV
		cout << endl << endl;
	    OutputMenu();
	    commandInput = GetAndCheckIntResponse(bound1, bound2, prompt,PROMPT_SIZE);
	    listChoice = ConvertIntToEnumType(commandInput);
	}//END while

	//Close the input file
	infile.close();

	return 0;
}
