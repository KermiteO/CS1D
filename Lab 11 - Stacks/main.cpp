/*************************************************************************
 * AUTHOR		    : Hamodi & Kermite
 * LAB #11          : Implementing a stack
 * CLASS			: CS 1B
 * DUE DATE		    : 03/10/15
 *************************************************************************/

#include "MyHeader.h"

/*************************************************************************
 * LAB TITLE:
 *
 * 					***IMPLEMENTING A STACK***
 *	___________________________________________________________________
 * LAB DESCRIPTION:
 * 	In this lab, we are going to used stack, pointers and enumerated data
 * 	type in order to complete this project. The user will be prompted to
 * 	choose from a menu which command he/she wishes to do, then once the
 * 	user selects the desired option, the program will execute that specific
 * 	 piece of code. This program will run as long as the user does not enter
 * 	 a o as an input command.
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
	const char PROJECT_TYPE    = 'L';
	const char PROGRAMMER [30] = "Kermite & Hamodi";
	const int  LAB_NUM         = 11;
	const char LAB_NAME   [50] = "Implementing a Stack";

	const int PROMPT_SIZE = 17;

	// VARIABLES DECLERATIONS:
	StackMenu  stackChoice;	 // IN            - variable of enum type
	personRec *head;		 // IN & OUT      - pointer of type personRec
	int        commandInput; // IN/CALC/OUT   - used to determine the search
	int		   personCount;  // PROC & OUT    - the number of people in l.l
	int		   bound1;		 // PROC	  	  - the 1st boundary value
	int		   bound2;		 // PROC    	  - the 2nd boundary value
	string	   prompt;		 // PROC & OUT 	  - the input prompt

	// INITIALIZATION:
	bound1 = 0;
	bound2 = 6;
	prompt = "Enter a command? ";

	head = NULL;
	cout << left;

	// Output the print heading to the console
	cout << PrintHeader(PROJECT_TYPE, PROGRAMMER, LAB_NUM, LAB_NAME);

/*************************************************************************
 INPUT - the command choice and convert that integer into an enum
**************************************************************************/
	OutputMenu();
	commandInput = GetAndCheckIntResponse(bound1, bound2, prompt, PROMPT_SIZE);

	stackChoice = ConvertIntToEnumType(commandInput);

/*************************************************************************
 PROCESSING & OUTPUT - determines which task to implement based on the
 command inputed. It loops so long as the command inputed isn't exit.
**************************************************************************/
	while(commandInput != EXIT)
	{
		switch(stackChoice)
		{
			case PUSH: head = PushUser(head);
						break;
			case POP: IsEmpty(head);
			//Determines whether to pop a user or not
			if(IsEmpty(head))
			{
				cout << "\nCan't POP from an empty stack!\n\n";
			}
			else
			{
				cout << "\nPOPPING at\n";
				head = PopUser(head);
			}
						break;
			case ISEMPTY: IsEmpty(head);
			//Determines whether the stack is empty or not
			if(IsEmpty(head))
			{
				cout << "\nYes, the stack is empty\n\n";
			}
			else
			{
				cout << "\nThe stack is NOT empty.\n\n";
			}
						break;
			case PEEK: IsEmpty(head);
			//Determines if there's anybody to peek at in the link list
			if(IsEmpty(head))
			{
				cout << "\nThere is nobody to PEEK at!\n\n";
			}
			else
			{
				cout << "\nPEEKING at\n";
				PeekUser(head);
			}
						break;
			case SIZE: personCount = SizeUser(head);

			//OUTPUT - how many people are currently in the stack.
			if(personCount == 0)
			{
				cout << "\nNobody is on the stack!\n\n";
			}
			else if(personCount == 1)
			{
				cout << "\nThere is one person on the stack.\n\n";
			}
			else
			{
				cout << "\nThere are " << personCount
						<< " on the stack.\n\n";
			}
						break;
			case DISPLAY: DisplayStack(head);
						break;
		}//END switch

		//Update the LCV
		OutputMenu();
		commandInput = GetAndCheckIntResponse(bound1, bound2, prompt,PROMPT_SIZE);

		stackChoice = ConvertIntToEnumType(commandInput);
	}//END while

	return 0;
}
