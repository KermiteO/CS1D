/*************************************************************************
 * AUTHOR		    : Deboogaloo & Kermite
 * LAB #12          : Implementing a Queue
 * CLASS			: CS 1B
 * DUE DATE		    : 03/10/15
 *************************************************************************/

#include "MyHeader.h"

/*************************************************************************
 * LAB TITLE:
 *
 * 					*** IMPLEMENTING A QUEUE ***
 *	___________________________________________________________________
 * LAB DESCRIPTION:
 * 	In this lab, we are going to use queues, pointers and enumerated data
 * 	type in order to complete this project. The user will be prompted to
 * 	choose from a menu which command he/she wishes to do, then once the
 * 	user selects the desired option, the program will execute that specific
 * 	 piece of code. This program will run as long as the user does not enter
 * 	 a 0 as an input command.
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
	const string PROGRAMMER    = "Kermite & Deboogaloo";
	const int  LAB_NUM         = 12;
	const string LAB_NAME      = "Implementing a Queue";

	const int PROMPT_SIZE = 17;

	// VARIABLES DECLERATIONS:
	QueueMenu  queueChoice;	 // IN            - variable of enum type
	personRec *head;		 // IN & OUT      - pointer of type personRec
	personRec *tail;		 // IN & OUT      - pointer of type personRec
	int        commandInput; // IN/CALC/OUT   - used to determine the search
	int		   personCount;  // PROC & OUT    - the number of people in l.l
	int		   bound1;		 // PROC	  	  - the 1st boundary value
	int		   bound2;		 // PROC    	  - the 2nd boundary value
	string	   prompt;		 // PROC & OUT 	  - the input prompt

	// INITIALIZATION:
	bound1 = 0;
	bound2 = 7;
	prompt = "Enter a command? ";
	//Creates an empty link list
	head = NULL;

	// Output the print heading to the console
	cout << left;
	cout << PrintHeader(PROJECT_TYPE, PROGRAMMER, LAB_NUM, LAB_NAME);

/*************************************************************************
 INPUT - the command choice and convert that integer into an enum
**************************************************************************/
	OutputMenu();

	commandInput = GetAndCheckIntResponse(bound1, bound2, prompt, PROMPT_SIZE);

	queueChoice = ConvertIntToEnumType(commandInput);

/*************************************************************************
 PROCESSING & OUTPUT - determines which task to implement based on the
 command inputed. It loops so long as the command inputed isn't exit.
**************************************************************************/
	while(commandInput != EXIT)
	{
		switch(queueChoice)
		{
			case 1: Enqueue(head, tail);
					cout << endl;
					 break;
			case 2: if(!IsEmpty(head))
					{
						cout << "\nDEQUEUEING\n";
						FrontUser(head);
					}
					Dequeue(head, tail);
					 break;
			case 3: if(IsEmpty(head))
					{
						cout << "\nYes, the QUEUE is empty.\n\n\n";
					}
					else
					{
						cout << "\nThe QUEUE is NOT empty.\n\n\n";
					}
					 break;
			case 4: if(!IsEmpty(head))
					{
						cout << "\nThe first person in the queue is:\n";
					}
					FrontUser(head);
					 break;
			case 5:
			case 6: personCount = SizeUser(head);

					//OUTPUT - how many people are currently in the queue.
					if(personCount == 0)
					{
						cout << "\nNobody is in the queue!\n";
					}
					else if(personCount == 1)
					{
						cout << "\nThere is one person in the queue.\n";
					}
					else
					{
						cout << "\nThere are " << personCount
								<< " in the queue.\n";
					}
					if(queueChoice == 6)
					{
						DisplayQueue(head);
					}
					else
					{
						cout << endl << endl;
					}
					 break;
			case 7: if(!IsEmpty(head))
					{
						cout << "\nCLEARING...\n";
					}
				    ClearQueue(head, tail);
				     break;
			case 0: commandInput = EXIT;
					 break;
		}//END switch

		//Update the LCV
		OutputMenu();
	   commandInput = GetAndCheckIntResponse(bound1, bound2, prompt, PROMPT_SIZE);

		queueChoice = ConvertIntToEnumType(commandInput);
	}//END while

	return 0;
}
