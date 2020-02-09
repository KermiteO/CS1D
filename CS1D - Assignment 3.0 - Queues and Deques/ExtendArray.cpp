/**************************************************************
 * PROGRAMMER   : Omar Kermiche
 * ASSIGNMENT #3: Queue/Deque
 * PROFESSOR    : Jerry Lebowitz
 * CLASS	    : CS1D
 **************************************************************/

#include "Header.h"

int *ExtendArray(int *&array,
				 int n,
				 int &front,
				 int &rear,
				 int &maxElem)
{
	int j = 1;

	maxElem = (n * 2) - 1;

	int *extArr = new int[n*2];
	//Initialize empty elements to 0
	for(int i = 0; i <= maxElem; i++)
	{
		extArr[i] = 0;
	}
	//If the front = 0 and rear = n, then copy proportionally to extended
	//array from data array
	if(front == 0 && rear == n - 1)
	{
		for(int i = 0; i < n; i++)
		{
			extArr[i + 1] = array[i];
		}
	}
	else
	{
		//PROC - populate extended array starting at array index front &
		//		 ending at index rear
		for(int i = front; i < n; i++)
		{
			extArr[j] = array[i];

			j++;
		}
		for(int i = 0; i <= rear; i++)
		{
			extArr[j] = array[i];

			j++;
		}
	}

	return extArr;
}
