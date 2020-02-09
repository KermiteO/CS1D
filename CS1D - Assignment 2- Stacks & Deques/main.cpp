/**************************************************************
 * PROGRAMMER   : Omar Kermiche
 * ASSIGNMENT #2: Stacks and Deques
 * PROFESSOR    : Jerry Lebowitz
 * CLASS	    : CS1D
 **************************************************************/

#include "Header.h"
#include "StackList.h"
#include "QueueList.h"
#include "DequeueList.h"

int main()
{
	//Constant Declarations go here
	const char   PROJECT_TYPE = 'A';
	const string PROGRAMMER   = "Omar";
	const int	 LAB_NUM      = 2;
	const string LAB_NAME     = "Stacks & Dequeues";

	const char EQUATION_1[17] = {'(','2','x',' ','-',' ', '4',')',' ','(','12',
							     'x',' ','+',' ','6',')'};

	const char EQUATION_2[17] = {'{','2','x',' ','+',' ','5','}',' ','(','6',
								 'x',' ','+',' ','6','}'};

	const char EQUATION_3[23] = {'[','(','5','x',' ','-',' ','5',')',' ','-',
								 ' ','4','x','[','6','x',' ','+',' ','2',
								 ']',']'};

	const char EQUATION_4[23] = {'{','{','8','x',' ','+',' ','5',')',' ','-',' '
			                    ,' ','5','x','(','9','x','+','3',']','}',')'};

	const char EQUATION_5[20] = {'{','(','8','x','+','5',')',' ','-',' ','6',
								 'x','[','9','x','+','3',']',']'};

	const char EQUATION_6[19] = {'(','2','x',' ','-',' ','4',')',' ','(','12',
								 'x',' ','+',' ','6','}'};

	const char EQUATION_7[21] = {'(','(','(','6','x','+','6',')',' ','-',' ',
								 'x','[','9','x','+','3',']',')',')',')'};

	//Variable declarations go here
	stack<string>       nameStl;
	stack<double>       doubleStl;
	StackList<string>   stringList;
	StackList<double>   doubleList;
	QueueList<string>   stringQueue;
	QueueList<double>   doubleQueue;
	DequeueList<string> stringDeq;
	DequeueList<double> doubleDeq;
	string              currName;
	double              currDouble;
	int	                index;
	int                 totStrings;
	int	                totDoubles;

	string prompt = "* This program creates vector stacks, linked list \n"
					"* queues, and Dequeue linked lists using 2 sets of data.\n"
					"* There's a list of strings and a list of doubles. A\n"
					"* stack, queue, and Dequeue are all created for each\n"
					"* list. It also implements a parentheses matching\n"
					"* algorithm";

	cout << PrintHeader(PROJECT_TYPE, PROGRAMMER, LAB_NUM, LAB_NAME, prompt);

	InitializeStackStl(nameStl, doubleStl);

	totStrings = nameStl.size();

	totDoubles = doubleStl.size();

	cout << "NAME STACK USING STL:\n";

	for(int i = 0; i < totStrings; i++)
	{
		currName = nameStl.top();

		cout << currName << ' ';

		nameStl.pop();
	}

	cout << "\n\nDOUBLE STACK USING STL:\n";
	cout << fixed << setprecision(2);

	for(int j = 0; j < totDoubles; j++)
	{
		currDouble = doubleStl.top();

		cout << currDouble << ' ';

		doubleStl.pop();
	}

	InitializeStackStl(nameStl, doubleStl);

	index = 0;

	currName = nameStl.top();

	while(currName != "Cathy" && index < TOT_STRINGS)
	{
		nameStl.pop();

		index++;

		currName = nameStl.top();
	}

	index = 0;

	currDouble = doubleStl.top();

	while(currDouble != 1.20 && index < TOT_NUMS)
	{
		doubleStl.pop();

		index++;

		currDouble = doubleStl.top();
	}

	//deleting Cathy and 1.2 from the two stacks
	nameStl.pop();
	doubleStl.pop();

	totStrings = nameStl.size();
	totDoubles = doubleStl.size();

	//OUTPUT - output the contents of the two STL stacks to the console
	cout << "\n\nAfter deleting Cathy from the name stack stl:\n";
	for(int i = 0; i < totStrings; i++)
	{
		currName = nameStl.top();

		cout << currName << ' ';

		nameStl.pop();
	}

	cout << "\n\nAfter deleting 1.2 from the double stack stl:\n";
	cout << fixed << setprecision(2);

	for(int j = 0; j < totDoubles; j++)
	{
		currDouble = doubleStl.top();

		cout << currDouble << ' ';

		doubleStl.pop();
	}

	//INIT - initialize the two stacks using the input data
	stringList.InitializeStack(NAMES, TOT_STRINGS);

	doubleList.InitializeStack(DOUBLES, TOT_NUMS);

	cout << "\n\nNAME LIST USING A STACK\n";
	stringList.Print();

	cout << "\nDOUBLE LIST USING A STACK\n";
	doubleList.Print();

	//PROC/OUT - find and delete Cathy and 1.2 and display the remaining
	//			 values left in the two linked lists
	cout << "\n\nAFTER DELETING Cathy FROM THE STACK\n";

	stringList.FindAndDeleteData("Cathy");

	stringList.DisplayDataTable();

	cout << "\nAFTER DELETING 1.2 FROM THE STACK\n";

	doubleList.FindAndDeleteData(1.2);

	doubleList.DisplayDataTable();

	stringQueue.InitializeQueueList(NAMES, TOT_STRINGS);

	doubleQueue.InitializeQueueList(DOUBLES, TOT_NUMS);

	cout << "\n\nNAME LIST USING A QUEUE\n";
	stringQueue.Print();

	cout << "\nDOUBLE LIST USING A QUEUE\n";
	doubleQueue.Print();

	//PROC/OUT - FIND AND DELTE Cathy AND 1.2 AND DISPLAY THE REMAINING
	//			 VALUES LEFT IN THE TWO QUEUE LINKED LISTS

	cout << "\n\nAfter deleting Cathy from the Queue list:\n";

	stringQueue.FindAndDelete("Cathy");

	stringQueue.Print();

	cout << "\nAfter deleting 1.2 from the Queue List\n";

	doubleQueue.FindAndDelete(1.2);

	doubleQueue.Print();

	//parts G & H OF THE ASSIGNMENT
	stringDeq.InitializeList(NAMES, TOT_STRINGS);

	doubleDeq.InitializeList(DOUBLES, TOT_NUMS);

	cout << "\n\nNAME LIST USING A DEQUEUE\n";
	stringDeq.Print();

	cout << "\nDOUBLE LIST USING A DEQUEUE\n";
	doubleDeq.Print();

	cout << "\n\nAfter deleting Cathy form the Dequeue list:\n";

	stringDeq.SearchDestroy("Cathy");

	stringDeq.Print();

	cout << "\nAfter deleting 1.2 from the Dequeue list:\n";

	doubleDeq.SearchDestroy(1.2);

	doubleDeq.Print();

	for(int i = 0; i < 7; i++)
	{
		switch(i)
		{
		case 0: IsValid(EQ_1, MatchParentheses(EQUATION_1, 17));
			break;
		case 1: IsValid(EQ_2, MatchParentheses(EQUATION_2, 17));
			break;
		case 2: IsValid(EQ_3, MatchParentheses(EQUATION_3, 23));
			break;
		case 3: IsValid(EQ_4, MatchParentheses(EQUATION_4, 23));
			break;
		case 4: IsValid(EQ_5, MatchParentheses(EQUATION_5, 20));
			break;
		case 5: IsValid(EQ_6, MatchParentheses(EQUATION_6, 19));
			break;
		case 6: IsValid(EQ_7, MatchParentheses(EQUATION_7, 21));
			break;
		}
	}

	return 0;
}
