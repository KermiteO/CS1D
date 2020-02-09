/**************************************************************
 * PROGRAMMER   : Omar Kermiche
 * ASSIGNMENT #3: Queue/Deque
 * PROFESSOR    : Jerry Lebowitz
 * CLASS	    : CS1D
 **************************************************************/

#include "Header.h"
#include "LinkedQueue.h"
#include "DLinkedList.h"
#include "LinkedDeque.h"

int main()
{
	//Constant Declarations go here
	const char   PROJECT_TYPE = 'A';
	const string PROGRAMMER   = "Omar Kermiche";
	const int	 LAB_NUM      = 3;
	const string LAB_NAME     = "Queue/Deque";

	//Variable Declarations
	string prompt = "* This lab comes in two parts. The first part is to\n"
					"* implement a queue using a dequeue and a double linked\n"
					"* list. In that, the dequeue and dlinkedlist are both \n"
					"* wrapper classes for the queue list. Part 2 of this lab\n"
					"* is to implement a vector ADT using an extendable array\n"
					"* in a circular fashion so that both insertions and\n"
					"* deletions occur in constant time. Print the circular\n"
					"* array before and after each insertion and deletion.";

	string string1 = "A man, a plan, a canal, Panama";
	string string2 = "Was it a car or a cat I saw?";
	string string3 = "Sit on a potato pan, Otis";
	string string4 = "No lemon, no melon";
	LinkedQueue strQueue;
	int n =3;
	int newNum;
	int front = 0;
	int rear = n -1;
	int maxElem = rear;
	int newMaxElem;
	int *numArr = new int[n];
	int *extArr;
	int *newExt;
	int *extraExt;

	cout << PrintHeader(PROJECT_TYPE, PROGRAMMER, LAB_NUM, LAB_NAME, prompt);

	//OUT - if the list is empty or not
	if(strQueue.Empty())
	{
		cout << "\nThe queue is EMPTY\n\n";
	}
	else
	{
		cout << "The queue is NOT EMPTY\n";
	}

	//IN add 4 strings to the end of the string queue
	strQueue.Enqueue(string1);
	cout << "After adding 1 string to the queue: " << strQueue.Print();
	strQueue.Enqueue(string2);
	cout << "\n\nAfter adding 2 strings to the queue: " << strQueue.Print();
	strQueue.Enqueue(string3);
	cout << "\n\nAfter adding 3 strings to the queue: " << strQueue.Print();
	strQueue.Enqueue(string4);
	cout << "\n\nAfter adding 4 strings to the queue: " << strQueue.Print();

	//OUT - Output the size of the list, the string at the front of the list
	cout << "\n\nThe SIZE of the list is " << strQueue.Size() << endl << endl;

	cout << "The string at the FRONT of the list is: " << strQueue.Front();
	cout << endl << endl;

	//PROC - delete the string at the front of the queue
	strQueue.Dequeue();

	cout << "After DEQUEUEING from the list, the queue is: "
		 << strQueue.Print();

	//Populate the array
	for(int i = 0; i < n; i++)
	{
		numArr[i] = i + 1;
	}

	cout << "\n\nBefore any insertions to circular array:\n";

	Print(numArr, n);

	cout << "\n\nEnter a new number to the front: ";
	cin   >> newNum;

	AddFront(numArr,extArr,newNum,front,rear,maxElem,newMaxElem);

	cout << "\n\nAdd a new number to the rear: ";
	cin  >> newNum;

	AddRear(extArr,newExt,newNum,front,rear,maxElem,newMaxElem);

	cout << "\n\nEnter another new number to the front: ";
	cin  >> newNum;

	AddFront(extArr,newExt,newNum,front,rear,maxElem,newMaxElem);

	cout << "\n\nEnter another new number to the front: ";
	cin  >> newNum;

	AddFront(extArr,extraExt,newNum,front,rear,maxElem,newMaxElem);

	cout << "\n\nAfter deleting from the front of the array: ";
	DeleteFront(extraExt,front,rear,maxElem);

	Print(extraExt, maxElem);

	cout << "\n\nAfter deleting from the rear of the array: ";

	DeleteRear(extraExt,front,rear,maxElem);

	Print(extraExt,maxElem);

	delete [] numArr;
	delete [] extArr;
	delete [] newExt;
	delete [] extraExt;

	return 0;

	cerr << "\n";
}


